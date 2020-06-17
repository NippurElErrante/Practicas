set sql_mode=(SELECT REPLACE(@@sql_mode,'ONLY_FULL_GROUP_BY',''));
set @fecha_inicio = '2020-05-01 00:00:00';
set @fecha_fin = '2020-06-01 00:00:00';
/* set @id_caso_testigo = ''; */
/* set @id_caso_testigo = 11503; */
select tabla1.Proyecto
      ,tabla1.Nro
      ,tabla1.Id
      ,tabla1.Ci_id
      ,(select round(cstmfldvle.numbervalue)
        from   customfieldvalue cstmfldvle
        where  cstmfldvle.customfield = 21940 /* 'FSD - Estimacion' */
        and    cstmfldvle.issue       = tabla1.Id) Estimacion
      ,tabla1.Fecha_creacion
      ,tabla1.Fecha_cierre
      ,tabla1.Fecha_cierre_chg
      ,tabla1.Tipo
      ,tabla1.Estado
      ,tabla1.Fecha_inicio
      ,tabla1.Fecha_fin
      /* ,tabla1.Fecha_fin_real */
      ,(select MIN(case tabla1.priority
                   when 1 then concat('1-',jprty.pname)
                   else
                     case jistp_f.pname
                     when 'Gestión Proyecto' then '2-Project'
                     when 'Proyecto' then '2-Project'
                     else ifnull((select min(asa.name)
                                  from   customfieldvalue cfv
                                         ,customfield      cf
                                         ,AO_60DB71_SPRINT asa
                                  where  asa.id    = cfv.stringvalue
                                  and   cf.cfname = 'Sprint'
                                  and   cf.id     = cfv.customfield
                                  and   cfv.issue   = jis_f.id),'Y Sin Sprint')
                     end
                   end) PRIORIDAD
        from   issuetype   jistp_f
              ,project     jpr_f
              ,jiraissue   jis_f
              ,(select jisld.destination issue_link_id
                      ,jisld.source issue_related_id
                from   issuelink jisld
                union all 
                select jisls.source issue_link_id
                      ,jisls.destination issue_related_id
                  from issuelink jisls ) jisl
              ,priority    jprty
        where  1=1
        and    jisl.issue_related_id = jis_f.id
        and    jis_f.project         = jpr_f.id
        and    jis_f.issuetype       = jistp_f.id
        and    jpr_f.pkey            = 'FST'
        and    jprty.id              = tabla1.priority
        and    jisl.issue_link_id    = tabla1.Id
        ) Tipo2
from (
/* ---------- Cantidad de dias en Open sin cambios de estado---------- */
select jpr.pkey                                     Proyecto
      ,jis.issuenum                                 Nro
      ,jis.id                                       Id
      ,null                                         Ci_id
      ,jis.priority                                 Priority
      ,jis.created                                  Fecha_creacion
      ,jis.resolutiondate                           Fecha_cierre
      ,null                                         Fecha_cierre_chg
      ,jistp.pname                                  Tipo
      ,'Open'                                       Estado
      ,jis.created                                  Fecha_inicio
      ,STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s') Fecha_fin
from   issuetype   jistp
      ,jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jis.issuetype     = jistp.id
and    jpr.pkey          = 'FSD' /* Proyecto */
and    jis.id            = ifnull(@id_caso_testigo,jis.id)
and    not exists  (select 1 /* Que no registre cambios de estado */
                    from   changeitem  jci_st_2
                          ,changegroup jcg_st_2
                    where  jcg_st_2.issueid   = jis.id
                    and    jcg_st_2.id        = jci_st_2.groupid
                    and    jci_st_2.field     = 'status'
                    and    jcg_st_2.created   < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s'))
and    jis.created  < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
union all
/* ---------- Cantidad de dias en Open ---------- */
select jpr.pkey           Proyecto
      ,jis.issuenum       Nro
      ,jis.id             Id
      ,jci_st.id          Ci_id
      ,jis.priority       Priority
      ,jis.created        Fecha_creacion
      ,jis.resolutiondate Fecha_cierre
      ,(select max(jcg2.created)
        from   changeitem  jci2
               ,changegroup jcg2
        where  jcg2.id       = jci2.groupid
        and    jci2.field    = 'status'
        and    jci2.newvalue = 6 /* Closed como estado actual */
        and    jcg2.issueid  = jis.id) Fecha_cierre_chg
      ,jistp.pname  Tipo
      ,replace(replace(replace(jci_st.oldstring,'ORCL - Analisis Tecnico','FS - Analisis Tecnico'),'FS - Pendiente de Analisis Funcional','FS - Analisis Funcional'),'FS -','FSD -') Estado
      ,jis.created Fecha_inicio
      ,ifnull((select min(jcg2.created) /* Para Open tomo la fecha de creacion */
               from   changeitem  jci2
                     ,changegroup jcg2
               where  jcg2.id       = jci2.groupid
               and    jci2.field    = 'status'
               and    jci2.oldvalue = 1 /* Open como estado anterior */
               and    jcg2.issueid  = jcg_st.issueid
               and    jcg2.created  > jis.created
               and    jcg2.created  < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')),STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')) Fecha_fin
from   changeitem  jci_st
      ,changegroup jcg_st
      ,issuetype   jistp
      ,jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jis.id            = jcg_st.issueid
and    jis.issuetype     = jistp.id
and    jcg_st.id         = jci_st.groupid
and    jpr.pkey          = 'FSD' /* Proyecto */
and    jci_st.field      = 'status'
and    jci_st.oldvalue   = 1     /* 'Open' -- Para Open tomo el oldvalue */
and    jis.id            = ifnull(@id_caso_testigo,jis.id)
and    not exists  (select 1
                    from   changeitem  jci_st_2
                          ,changegroup jcg_st_2
                    where  jcg_st_2.issueid   = jis.id
                    and    jcg_st_2.id        = jci_st_2.groupid
                    and    jci_st_2.field     = 'status'
                    and    jci_st_2.newvalue  = 6
                    and    jcg_st_2.created   < STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s'))
and    jis.created    < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
and    jcg_st.created < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
union all
/* ---------- Cantidad de dias en FSD - Analisis Tecnico ---------- */
select jpr.pkey           Proyecto
      ,jis.issuenum       Nro
      ,jis.id             Id
      ,jci_st.id          Ci_id
      ,jis.priority       Priority
      ,jis.created        Fecha_creacion
      ,jis.resolutiondate Fecha_cierre
      ,(select max(jcg2.created)
        from   changeitem  jci2
               ,changegroup jcg2
        where  jcg2.id       = jci2.groupid
        and    jci2.field    = 'status'
        and    jci2.newvalue = 6 /* Closed como estado actual */
        and    jcg2.issueid  = jis.id) Fecha_cierre_chg
      ,jistp.pname      Tipo
      ,replace(replace(replace(jci_st.newstring,'ORCL - Analisis Tecnico','FS - Analisis Tecnico'),'FS - Pendiente de Analisis Funcional','FS - Analisis Funcional'),'FS -','FSD -') Estado
      ,jcg_st.created Fecha_inicio
      ,ifnull((select min(jcg2.created)
               from   changeitem  jci2
                     ,changegroup jcg2
               where  jcg2.id       = jci2.groupid
               and    jci2.field    = 'status'
               and    jci2.oldvalue = jci_st.newvalue
               and    jcg2.issueid  = jcg_st.issueid
               and    jcg2.created  > jcg_st.created
               and    jcg2.created  < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')),STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')) Fecha_fin
from   changeitem  jci_st
      ,changegroup jcg_st
      ,issuetype   jistp
      ,jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jis.id            = jcg_st.issueid
and    jis.issuetype     = jistp.id
and    jcg_st.id         = jci_st.groupid
and    jpr.pkey          = 'FSD' /* Proyecto */
and    jci_st.field      = 'status'
and    jci_st.newvalue   = 11913 /* 'FSD - Analisis Tecnico' */
and    jis.id            = ifnull(@id_caso_testigo,jis.id)
and    not exists  (select 1
                    from   changeitem  jci_st_2
                          ,changegroup jcg_st_2
                    where  jcg_st_2.issueid   = jis.id
                    and    jcg_st_2.id        = jci_st_2.groupid
                    and    jci_st_2.field     = 'status'
                    and    jci_st_2.newvalue  = 6
                    and    jcg_st_2.created   < STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s'))
and    jis.created    < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
and    jcg_st.created < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
union all
/* ---------- Cantidad de dias en FSD - ON HOLD ---------- */
select jpr.pkey           Proyecto
      ,jis.issuenum       Nro
      ,jis.id             Id
      ,jci_st.id          Ci_id
      ,jis.priority       Priority
      ,jis.created        Fecha_creacion
      ,jis.resolutiondate Fecha_cierre
      ,(select max(jcg2.created)
        from   changeitem  jci2
               ,changegroup jcg2
        where  jcg2.id       = jci2.groupid
        and    jci2.field    = 'status'
        and    jci2.newvalue = 6 /* Closed como estado actual */
        and    jcg2.issueid  = jis.id) Fecha_cierre_chg
      ,jistp.pname      Tipo
      ,replace(replace(replace(jci_st.newstring,'ORCL - Analisis Tecnico','FS - Analisis Tecnico'),'FS - Pendiente de Analisis Funcional','FS - Analisis Funcional'),'FS -','FSD -') Estado
      ,jcg_st.created Fecha_inicio
      ,ifnull((select min(jcg2.created)
               from   changeitem  jci2
                     ,changegroup jcg2
               where  jcg2.id       = jci2.groupid
               and    jci2.field    = 'status'
               and    jci2.oldvalue = jci_st.newvalue
               and    jcg2.issueid  = jcg_st.issueid
               and    jcg2.created  > jcg_st.created
               and    jcg2.created  < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')),STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')) Fecha_fin
from   changeitem  jci_st
      ,changegroup jcg_st
      ,issuetype   jistp
      ,jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jis.id            = jcg_st.issueid
and    jis.issuetype     = jistp.id
and    jcg_st.id         = jci_st.groupid
and    jpr.pkey          = 'FSD' /* Proyecto */
and    jci_st.field      = 'status'
and    jci_st.newvalue   = 15598 /* 'FSD - ON HOLD' */
and    jis.id            = ifnull(@id_caso_testigo,jis.id)
and    not exists  (select 1
                    from   changeitem  jci_st_2
                          ,changegroup jcg_st_2
                    where  jcg_st_2.issueid   = jis.id
                    and    jcg_st_2.id        = jci_st_2.groupid
                    and    jci_st_2.field     = 'status'
                    and    jci_st_2.newvalue  = 6
                    and    jcg_st_2.created   < STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s'))
and    jis.created    < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
and    jcg_st.created < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
union all
/* ---------- Cantidad de dias en FSD - DESA ---------- */
select jpr.pkey           Proyecto
      ,jis.issuenum       Nro
      ,jis.id             Id
      ,jci_st.id          Ci_id
      ,jis.priority       Priority
      ,jis.created        Fecha_creacion
      ,jis.resolutiondate Fecha_cierre
      ,(select max(jcg2.created)
        from   changeitem  jci2
               ,changegroup jcg2
        where  jcg2.id       = jci2.groupid
        and    jci2.field    = 'status'
        and    jci2.newvalue = 6 /* Closed como estado actual */
        and    jcg2.issueid  = jis.id) Fecha_cierre_chg
      ,jistp.pname      Tipo
      ,replace(replace(replace(jci_st.newstring,'ORCL - Analisis Tecnico','FS - Analisis Tecnico'),'FS - Pendiente de Analisis Funcional','FS - Analisis Funcional'),'FS -','FSD -') Estado
      ,jcg_st.created Fecha_inicio
      ,ifnull((select min(jcg2.created)
               from   changeitem  jci2
                     ,changegroup jcg2
               where  jcg2.id       = jci2.groupid
               and    jci2.field    = 'status'
               and    jci2.oldvalue = jci_st.newvalue
               and    jcg2.issueid  = jcg_st.issueid
               and    jcg2.created  > jcg_st.created
               and    jcg2.created  < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')),STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')) Fecha_fin
from   changeitem  jci_st
      ,changegroup jcg_st
      ,issuetype   jistp
      ,jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jis.id            = jcg_st.issueid
and    jis.issuetype     = jistp.id
and    jcg_st.id         = jci_st.groupid
and    jpr.pkey          = 'FSD' /* Proyecto */
and    jci_st.field      = 'status'
and    jci_st.newvalue   = 11914 /* 'FSD - DESA' */
and    jis.id            = ifnull(@id_caso_testigo,jis.id)
and    not exists  (select 1
                    from   changeitem  jci_st_2
                          ,changegroup jcg_st_2
                    where  jcg_st_2.issueid   = jis.id
                    and    jcg_st_2.id        = jci_st_2.groupid
                    and    jci_st_2.field     = 'status'
                    and    jci_st_2.newvalue  = 6
                    and    jcg_st_2.created   < STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s'))
and    jis.created    < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
and    jcg_st.created < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
union all
/* ---------- Cantidad de dias en FSD - Analisis Funcional ---------- */
select jpr.pkey           Proyecto
      ,jis.issuenum       Nro
      ,jis.id             Id
      ,jci_st.id          Ci_id
      ,jis.priority       Priority
      ,jis.created        Fecha_creacion
      ,jis.resolutiondate Fecha_cierre
      ,(select max(jcg2.created)
        from   changeitem  jci2
               ,changegroup jcg2
        where  jcg2.id       = jci2.groupid
        and    jci2.field    = 'status'
        and    jci2.newvalue = 6 /* Closed como estado actual */
        and    jcg2.issueid  = jis.id) Fecha_cierre_chg
      ,jistp.pname      Tipo
      ,replace(replace(replace(jci_st.newstring,'ORCL - Analisis Tecnico','FS - Analisis Tecnico'),'FS - Pendiente de Analisis Funcional','FS - Analisis Funcional'),'FS -','FSD -') Estado
      ,jcg_st.created Fecha_inicio
      ,ifnull((select min(jcg2.created)
               from   changeitem  jci2
                     ,changegroup jcg2
               where  jcg2.id       = jci2.groupid
               and    jci2.field    = 'status'
               and    jci2.oldvalue = jci_st.newvalue
               and    jcg2.issueid  = jcg_st.issueid
               and    jcg2.created  > jcg_st.created
               and    jcg2.created  < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')),STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')) Fecha_fin
from   changeitem  jci_st
      ,changegroup jcg_st
      ,issuetype   jistp
      ,jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jis.id            = jcg_st.issueid
and    jis.issuetype     = jistp.id
and    jcg_st.id         = jci_st.groupid
and    jpr.pkey          = 'FSD' /* Proyecto */
and    jci_st.field      = 'status'
and    jci_st.newvalue   = 11912 /* 'FSD - Analisis Funcional' */
and    jis.id            = ifnull(@id_caso_testigo,jis.id)
and    not exists  (select 1
                    from   changeitem  jci_st_2
                          ,changegroup jcg_st_2
                    where  jcg_st_2.issueid   = jis.id
                    and    jcg_st_2.id        = jci_st_2.groupid
                    and    jci_st_2.field     = 'status'
                    and    jci_st_2.newvalue  = 6
                    and    jcg_st_2.created   < STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s'))
and    jis.created    < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
and    jcg_st.created < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
union all
/* ---------- Cantidad de dias en FSD - Promocion a TEST ---------- */
select jpr.pkey           Proyecto
      ,jis.issuenum       Nro
      ,jis.id             Id
      ,jci_st.id          Ci_id
      ,jis.priority       Priority
      ,jis.created        Fecha_creacion
      ,jis.resolutiondate Fecha_cierre
      ,(select max(jcg2.created)
        from   changeitem  jci2
               ,changegroup jcg2
        where  jcg2.id       = jci2.groupid
        and    jci2.field    = 'status'
        and    jci2.newvalue = 6 /* Closed como estado actual */
        and    jcg2.issueid  = jis.id) Fecha_cierre_chg
      ,jistp.pname      Tipo
      ,replace(replace(replace(jci_st.newstring,'ORCL - Analisis Tecnico','FS - Analisis Tecnico'),'FS - Pendiente de Analisis Funcional','FS - Analisis Funcional'),'FS -','FSD -') Estado
      ,jcg_st.created Fecha_inicio
      ,ifnull((select min(jcg2.created)
               from   changeitem  jci2
                     ,changegroup jcg2
               where  jcg2.id       = jci2.groupid
               and    jci2.field    = 'status'
               and    jci2.oldvalue = jci_st.newvalue
               and    jcg2.issueid  = jcg_st.issueid
               and    jcg2.created  > jcg_st.created
               and    jcg2.created  < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')),STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')) Fecha_fin
from   changeitem  jci_st
      ,changegroup jcg_st
      ,issuetype   jistp
      ,jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jis.id            = jcg_st.issueid
and    jis.issuetype     = jistp.id
and    jcg_st.id         = jci_st.groupid
and    jpr.pkey          = 'FSD' /* Proyecto */
and    jci_st.field      = 'status'
and    jci_st.newvalue   = 11916 /* 'FSD - Promocion a TEST' */
and    jis.id            = ifnull(@id_caso_testigo,jis.id)
and    not exists  (select 1
                    from   changeitem  jci_st_2
                          ,changegroup jcg_st_2
                    where  jcg_st_2.issueid   = jis.id
                    and    jcg_st_2.id        = jci_st_2.groupid
                    and    jci_st_2.field     = 'status'
                    and    jci_st_2.newvalue  = 6
                    and    jcg_st_2.created   < STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s'))
and    jis.created    < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
and    jcg_st.created < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
union all
/* ---------- Cantidad de dias en FSD - TEST ---------- */
select jpr.pkey           Proyecto
      ,jis.issuenum       Nro
      ,jis.id             Id
      ,jci_st.id          Ci_id
      ,jis.priority       Priority
      ,jis.created        Fecha_creacion
      ,jis.resolutiondate Fecha_cierre
      ,(select max(jcg2.created)
        from   changeitem  jci2
               ,changegroup jcg2
        where  jcg2.id       = jci2.groupid
        and    jci2.field    = 'status'
        and    jci2.newvalue = 6 /* Closed como estado actual */
        and    jcg2.issueid  = jis.id) Fecha_cierre_chg
      ,jistp.pname      Tipo
      ,replace(replace(replace(jci_st.newstring,'ORCL - Analisis Tecnico','FS - Analisis Tecnico'),'FS - Pendiente de Analisis Funcional','FS - Analisis Funcional'),'FS -','FSD -') Estado
      ,jcg_st.created Fecha_inicio
      ,ifnull((select min(jcg2.created)
               from   changeitem  jci2
                     ,changegroup jcg2
               where  jcg2.id       = jci2.groupid
               and    jci2.field    = 'status'
               and    jci2.oldvalue = jci_st.newvalue
               and    jcg2.issueid  = jcg_st.issueid
               and    jcg2.created  > jcg_st.created
               and    jcg2.created  < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')),STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')) Fecha_fin
from   changeitem  jci_st
      ,changegroup jcg_st
      ,issuetype   jistp
      ,jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jis.id            = jcg_st.issueid
and    jis.issuetype     = jistp.id
and    jcg_st.id         = jci_st.groupid
and    jpr.pkey          = 'FSD' /* Proyecto */
and    jci_st.field      = 'status'
and    jci_st.newvalue   = 11918 /* 'FSD - TEST' */
and    jis.id            = ifnull(@id_caso_testigo,jis.id)
and    not exists  (select 1
                    from   changeitem  jci_st_2
                          ,changegroup jcg_st_2
                    where  jcg_st_2.issueid   = jis.id
                    and    jcg_st_2.id        = jci_st_2.groupid
                    and    jci_st_2.field     = 'status'
                    and    jci_st_2.newvalue  = 6
                    and    jcg_st_2.created   < STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s'))
and    jis.created    < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
and    jcg_st.created < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
union all
/* ---------- Cantidad de dias en FSD - Promocion a UAT ---------- */
select jpr.pkey           Proyecto
      ,jis.issuenum       Nro
      ,jis.id             Id
      ,jci_st.id          Ci_id
      ,jis.priority       Priority
      ,jis.created        Fecha_creacion
      ,jis.resolutiondate Fecha_cierre
      ,(select max(jcg2.created)
        from   changeitem  jci2
               ,changegroup jcg2
        where  jcg2.id       = jci2.groupid
        and    jci2.field    = 'status'
        and    jci2.newvalue = 6 /* Closed como estado actual */
        and    jcg2.issueid  = jis.id) Fecha_cierre_chg
      ,jistp.pname      Tipo
      ,replace(replace(replace(jci_st.newstring,'ORCL - Analisis Tecnico','FS - Analisis Tecnico'),'FS - Pendiente de Analisis Funcional','FS - Analisis Funcional'),'FS -','FSD -') Estado
      ,jcg_st.created Fecha_inicio
      ,ifnull((select min(jcg2.created)
               from   changeitem  jci2
                     ,changegroup jcg2
               where  jcg2.id       = jci2.groupid
               and    jci2.field    = 'status'
               and    jci2.oldvalue = jci_st.newvalue
               and    jcg2.issueid  = jcg_st.issueid
               and    jcg2.created  > jcg_st.created
               and    jcg2.created  < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')),STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')) Fecha_fin
from   changeitem  jci_st
      ,changegroup jcg_st
      ,issuetype   jistp
      ,jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jis.id            = jcg_st.issueid
and    jis.issuetype     = jistp.id
and    jcg_st.id         = jci_st.groupid
and    jpr.pkey          = 'FSD' /* Proyecto */
and    jci_st.field      = 'status'
and    jci_st.newvalue   = 11920 /* 'FSD - Promocion a UAT' */
and    jis.id            = ifnull(@id_caso_testigo,jis.id)
and    not exists  (select 1
                    from   changeitem  jci_st_2
                          ,changegroup jcg_st_2
                    where  jcg_st_2.issueid   = jis.id
                    and    jcg_st_2.id        = jci_st_2.groupid
                    and    jci_st_2.field     = 'status'
                    and    jci_st_2.newvalue  = 6
                    and    jcg_st_2.created   < STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s'))
and    jis.created    < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
and    jcg_st.created < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
union all
/* ---------- Cantidad de dias en FSD - UAT ---------- */
select jpr.pkey           Proyecto
      ,jis.issuenum       Nro
      ,jis.id             Id
      ,jci_st.id          Ci_id
      ,jis.priority       Priority
      ,jis.created        Fecha_creacion
      ,jis.resolutiondate Fecha_cierre
      ,(select max(jcg2.created)
        from   changeitem  jci2
               ,changegroup jcg2
        where  jcg2.id       = jci2.groupid
        and    jci2.field    = 'status'
        and    jci2.newvalue = 6 /* Closed como estado actual */
        and    jcg2.issueid  = jis.id) Fecha_cierre_chg
      ,jistp.pname      Tipo
      ,replace(replace(replace(jci_st.newstring,'ORCL - Analisis Tecnico','FS - Analisis Tecnico'),'FS - Pendiente de Analisis Funcional','FS - Analisis Funcional'),'FS -','FSD -') Estado
      ,jcg_st.created Fecha_inicio
      ,ifnull((select min(jcg2.created)
               from   changeitem  jci2
                     ,changegroup jcg2
               where  jcg2.id       = jci2.groupid
               and    jci2.field    = 'status'
               and    jci2.oldvalue = jci_st.newvalue
               and    jcg2.issueid  = jcg_st.issueid
               and    jcg2.created  > jcg_st.created
               and    jcg2.created  < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')),STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')) Fecha_fin
from   changeitem  jci_st
      ,changegroup jcg_st
      ,issuetype   jistp
      ,jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jis.id            = jcg_st.issueid
and    jis.issuetype     = jistp.id
and    jcg_st.id         = jci_st.groupid
and    jpr.pkey          = 'FSD' /* Proyecto */
and    jci_st.field      = 'status'
and    jci_st.newvalue   = 11922 /* 'FSD - UAT' */
and    jis.id            = ifnull(@id_caso_testigo,jis.id)
and    not exists  (select 1
                    from   changeitem  jci_st_2
                          ,changegroup jcg_st_2
                    where  jcg_st_2.issueid   = jis.id
                    and    jcg_st_2.id        = jci_st_2.groupid
                    and    jci_st_2.field     = 'status'
                    and    jci_st_2.newvalue  = 6
                    and    jcg_st_2.created   < STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s'))
and    jis.created    < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
and    jcg_st.created < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
union all
/* ---------- Cantidad de dias en FSD - Promocion a PROD ---------- */
select jpr.pkey           Proyecto
      ,jis.issuenum       Nro
      ,jis.id             Id
      ,jci_st.id          Ci_id
      ,jis.priority       Priority
      ,jis.created        Fecha_creacion
      ,jis.resolutiondate Fecha_cierre
      ,(select max(jcg2.created)
        from   changeitem  jci2
               ,changegroup jcg2
        where  jcg2.id       = jci2.groupid
        and    jci2.field    = 'status'
        and    jci2.newvalue = 6 /* Closed como estado actual */
        and    jcg2.issueid  = jis.id) Fecha_cierre_chg
      ,jistp.pname      Tipo
      ,replace(replace(replace(jci_st.newstring,'ORCL - Analisis Tecnico','FS - Analisis Tecnico'),'FS - Pendiente de Analisis Funcional','FS - Analisis Funcional'),'FS -','FSD -') Estado
      ,jcg_st.created Fecha_inicio
      ,ifnull((select min(jcg2.created)
               from   changeitem  jci2
                     ,changegroup jcg2
               where  jcg2.id       = jci2.groupid
               and    jci2.field    = 'status'
               and    jci2.oldvalue = jci_st.newvalue
               and    jcg2.issueid  = jcg_st.issueid
               and    jcg2.created  > jcg_st.created
               and    jcg2.created  < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')),STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')) Fecha_fin
from   changeitem  jci_st
      ,changegroup jcg_st
      ,issuetype   jistp
      ,jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jis.id            = jcg_st.issueid
and    jis.issuetype     = jistp.id
and    jcg_st.id         = jci_st.groupid
and    jpr.pkey          = 'FSD' /* Proyecto */
and    jci_st.field      = 'status'
and    jci_st.newvalue   = 11924 /* 'FSD - Promocion a PROD' */
and    jis.id            = ifnull(@id_caso_testigo,jis.id)
and    not exists  (select 1
                    from   changeitem  jci_st_2
                          ,changegroup jcg_st_2
                    where  jcg_st_2.issueid   = jis.id
                    and    jcg_st_2.id        = jci_st_2.groupid
                    and    jci_st_2.field     = 'status'
                    and    jci_st_2.newvalue  = 6
                    and    jcg_st_2.created   < STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s'))
and    jis.created    < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
and    jcg_st.created < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
union all
/* ---------- Cantidad de dias en FSD - PROD  ---------- */
select jpr.pkey           Proyecto
      ,jis.issuenum       Nro
      ,jis.id             Id
      ,jci_st.id          Ci_id
      ,jis.priority       Priority
      ,jis.created        Fecha_creacion
      ,jis.resolutiondate Fecha_cierre
      ,(select max(jcg2.created)
        from   changeitem  jci2
               ,changegroup jcg2
        where  jcg2.id       = jci2.groupid
        and    jci2.field    = 'status'
        and    jci2.newvalue = 6 /* Closed como estado actual */
        and    jcg2.issueid  = jis.id) Fecha_cierre_chg
      ,jistp.pname      Tipo
      ,replace(replace(replace(jci_st.newstring,'ORCL - Analisis Tecnico','FS - Analisis Tecnico'),'FS - Pendiente de Analisis Funcional','FS - Analisis Funcional'),'FS -','FSD -') Estado
      ,jcg_st.created Fecha_inicio
      ,ifnull((select min(jcg2.created)
               from   changeitem  jci2
                     ,changegroup jcg2
               where  jcg2.id       = jci2.groupid
               and    jci2.field    = 'status'
               and    jci2.oldvalue = jci_st.newvalue
               and    jcg2.issueid  = jcg_st.issueid
               and    jcg2.created  > jcg_st.created
               and    jcg2.created  < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')),STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')) Fecha_fin
from   changeitem  jci_st
      ,changegroup jcg_st
      ,issuetype   jistp
      ,jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jis.id            = jcg_st.issueid
and    jis.issuetype     = jistp.id
and    jcg_st.id         = jci_st.groupid
and    jpr.pkey          = 'FSD' /* Proyecto */
and    jci_st.field      = 'status'
and    jci_st.newvalue   = 14201 /* 'FSD - PROD' */
and    jis.id            = ifnull(@id_caso_testigo,jis.id)
and    not exists  (select 1
                    from   changeitem  jci_st_2
                          ,changegroup jcg_st_2
                    where  jcg_st_2.issueid   = jis.id
                    and    jcg_st_2.id        = jci_st_2.groupid
                    and    jci_st_2.field     = 'status'
                    and    jci_st_2.newvalue  = 6
                    and    jcg_st_2.created   < STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s'))
and    jis.created    < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
and    jcg_st.created < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
union all
/* ---------- Cantidad de dias en Closed  ---------- */
select jpr.pkey           Proyecto
      ,jis.issuenum       Nro
      ,jis.id             Id
      ,jci_st.id          Ci_id
      ,jis.priority       Priority
      ,jis.created        Fecha_creacion
      ,jis.resolutiondate Fecha_cierre
      ,(select max(jcg2.created)
        from   changeitem  jci2
               ,changegroup jcg2
        where  jcg2.id       = jci2.groupid
        and    jci2.field    = 'status'
        and    jci2.newvalue = 6 /* Closed como estado actual */
        and    jcg2.issueid  = jis.id) Fecha_cierre_chg
      ,jistp.pname      Tipo
      ,replace(replace(replace(jci_st.newstring,'ORCL - Analisis Tecnico','FS - Analisis Tecnico'),'FS - Pendiente de Analisis Funcional','FS - Analisis Funcional'),'FS -','FSD -') Estado
      ,jcg_st.created Fecha_inicio
      ,ifnull((select min(jcg2.created)
               from   changeitem  jci2
                     ,changegroup jcg2
               where  jcg2.id       = jci2.groupid
               and    jci2.field    = 'status'
               and    jci2.oldvalue = jci_st.newvalue
               and    jcg2.issueid  = jcg_st.issueid
               and    jcg2.created  > jcg_st.created
               and    jcg2.created  < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')),STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')) Fecha_fin
from   changeitem  jci_st
      ,changegroup jcg_st
      ,issuetype   jistp
      ,jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jis.id            = jcg_st.issueid
and    jis.issuetype     = jistp.id
and    jcg_st.id         = jci_st.groupid
and    jpr.pkey          = 'FSD' /* Proyecto */
and    jci_st.field      = 'status'
and    jci_st.newvalue   = 6     /* 'Closed' */
and    jis.id            = ifnull(@id_caso_testigo,jis.id)
and    not exists  (select 1
                    from   changeitem  jci_st_2
                          ,changegroup jcg_st_2
                    where  jcg_st_2.issueid   = jis.id
                    and    jcg_st_2.id        = jci_st_2.groupid
                    and    jci_st_2.field     = 'status'
                    and    jci_st_2.newvalue  = 6
                    and    jcg_st_2.created   < STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s'))
and    jis.created    < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
and    jcg_st.created < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
) tabla1
order by 2,4