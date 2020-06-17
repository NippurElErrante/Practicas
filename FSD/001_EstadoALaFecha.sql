select concat(jpr_f.pkey,'-',jis_f.issuenum) FST
      ,concat(jpr.pkey,'-',jis.issuenum) FSD
      ,case jis.priority
       when 1 then concat('1-',p_f.pname)
       else
          case jistp_f.pname
          when 'Gestión Proyecto' then '2-Project'
          when 'Proyecto' then '2-Project'
          else ifnull((select min(asa.name)
                        from customfieldvalue cfv
                            ,customfield      cf
                            ,AO_60DB71_SPRINT asa
                        where asa.id    = cfv.stringvalue
                        and   cf.cfname = 'Sprint'
                        and   cf.id     = cfv.customfield
                        and cfv.issue   = jis_f.id)
                       ,'Y Sin Sprint')
         end
       end PRIORIDAD
      ,case jistp_f.pname
       when 'Proyecto' then concat(jpr_f.pkey,'-',jis_f.issuenum)
       else (select group_concat(concat(jpr_p.pkey,'-',jis_p.issuenum))
             from   (select jisld.destination issue_link_id
                           ,jisld.source      issue_related_id
                     from issuelink jisld
                     union all 
                     select jisls.source      issue_link_id
                           ,jisls.destination issue_related_id
                     from issuelink jisls) jisl_p  -- Link
                   ,issuetype              jistp_p -- Tipo Proyecto
                   ,jiraissue              jis_p   -- FST
                   ,project                jpr_p   -- Proyecto
             where  jpr_p.id             = jis_p.project           -- Relacion con proyecto
             and    jis_p.issuetype      = jistp_p.id              -- Relacion con tipo
             and    jpr_p.pkey           = 'FST'                   -- Proyecto funcional
             and    jistp_p.pname        = 'Proyecto'              -- Solo tipo proyecto
             and    jis_p.id             = jisl_p.issue_related_id -- Relacion
             and    jisl_p.issue_link_id = jis_f.id)                -- Relacion
       end PROYECTO
      ,case 
       -- when jiss.pname = 'Closed' then 'Y'
       when (select asa.name
               from customfieldvalue cfv
                   ,customfield cf
                   ,AO_60DB71_SPRINT asa
              where asa.started is true
                and asa.closed is false
                and asa.id = cfv.stringvalue
                and cf.cfname = 'Sprint'
                and cf.id = cfv.customfield
                and cfv.issue = jis.id) IS NULL THEN 'N'
      else 'Y'
      end EN_SPRINT_ACTIVO
      ,case 
       when jiss.pname = 'Closed' then 'Y'
       when (select asa.name
               from customfieldvalue cfv
                   ,customfield cf
                   ,AO_60DB71_SPRINT asa
              where asa.complete_date is null 
                and asa.id = cfv.stringvalue
                and cf.cfname = 'Sprint'
                and cf.id = cfv.customfield
                and cfv.issue = jis.id) IS NULL THEN 'N'
      else 'Y'
      end EN_SPRINT_TECNICO
      ,jiss_f.pname ESTADO_FUNCIONAL
      ,jiss.pname ESTADO_TECNICO
      ,ifnull((select max(cg.group_name)
                from   cwd_group        cg
                      ,cwd_membership   cm
                      ,cwd_user         cu
                      ,app_user         apu
                where  apu.lower_user_name = cu.lower_user_name
                and    cu.id               = cm.child_id
                and    cm.parent_id        = cg.id
                and    cu.directory_id     > 1
                and    apu.user_key        = jis.reporter
                and    cg.group_name       in ('FST-AAA','FST-OTC','FST-P2P')),'N/A') VERTICAL
      ,case jiss.id
       when 1 then timestampdiff(day,jis.created,sysdate())
      else
        (select timestampdiff(day,max(jcg_st.created),sysdate())
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status')
       end AGING_ULT_ESTADO
      ,(select max(cu.display_name)
        from   cwd_user         cu
              ,app_user         apu
        where  apu.lower_user_name    = cu.lower_user_name
        and    apu.user_key           = jis.reporter) Responsable_Funcional
      ,(select max(cu.display_name)
        from   cwd_user         cu
              ,app_user         apu
              ,customfieldvalue cstmfldvle
        where  cstmfldvle.customfield = 16645 -- 'Responsable Seguimiento'
        and    apu.lower_user_name    = cu.lower_user_name
        and    apu.user_key           = cstmfldvle.stringvalue
        and    cstmfldvle.issue       = jis.id) Responsable_Tecnico
      ,ifnull( (select round(cstmfldvle.numbervalue)
                from   customfieldvalue cstmfldvle
                where  cstmfldvle.customfield = 21940 -- 'FSD - Estimacion'
                and    cstmfldvle.issue       = jis.id),0) Estimacion
      ,timestampdiff(day,jis_f.created,sysdate()) FST_AGING
      ,timestampdiff(day,jis.created,sysdate()) FSD_AGING
      ,jis_f.summary FST_DESCRIPCION
      ,ifnull(timestampdiff(day,jis.created, ifnull((select min(jcg2.created)
                                               from   changeitem  jci2
                                                     ,changegroup jcg2
                                               where  jcg2.id       = jci2.groupid
                                               and    jci2.field    = 'status'
                                               and    jci2.oldvalue = 1 -- Open como estado anterior
                                               and    jcg2.issueid  = jis.id
                                               and    jcg2.created  > jis.created),sysdate())),0) DIAS_OPEN
      ,(select count(jci_st_2.id)
        from   changeitem  jci_st_2
              ,changegroup jcg_st_2
        where  jcg_st_2.issueid   = jis.id
        and    jcg_st_2.id        = jci_st_2.groupid
        and    jci_st_2.newvalue  = 11913 /*'FSD - Analisis Tecnico'*/
        and    jci_st_2.field     = 'status')  ITERACIONES_ANALISIS_TECNICO
       ,ifnull((select sum(timestampdiff(day,jcg_st.created, ifnull((select min(jcg2.created)
                                                              from   changeitem  jci2
                                                                    ,changegroup jcg2
                                                              where  jcg2.id        = jci2.groupid
                                                              and    jci2.field     = 'status'
                                                              and    jci2.oldvalue = jci_st.newvalue
                                                              and    jcg2.issueid   = jcg_st.issueid
                                                              and    jcg2.created   > jcg_st.created),sysdate()))) dias_totales
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status'
         and    jci_st.newvalue   = 11913 /*'FSD - Analisis Tecnico'*/),0) DIAS_ANALISIS_TECNICO
      ,(select count(jci_st_2.id)
        from   changeitem  jci_st_2
              ,changegroup jcg_st_2
        where  jcg_st_2.issueid   = jis.id
        and    jcg_st_2.id        = jci_st_2.groupid
        and    jci_st_2.newvalue  = 11914 /*'FSD - DESA'*/
        and    jci_st_2.field     = 'status')  ITERACIONES_DESA
       ,ifnull((select sum(timestampdiff(day,jcg_st.created, ifnull((select min(jcg2.created)
                                                              from   changeitem  jci2
                                                                    ,changegroup jcg2
                                                              where  jcg2.id        = jci2.groupid
                                                              and    jci2.field     = 'status'
                                                              and    jci2.oldvalue = jci_st.newvalue
                                                              and    jcg2.issueid   = jcg_st.issueid
                                                              and    jcg2.created   > jcg_st.created),sysdate()))) dias_totales
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status'
         and    jci_st.newvalue   = 11914 /*'FSD - DESA'*/),0) DIAS_DESA
      ,(select count(jci_st_2.id)
        from   changeitem  jci_st_2
              ,changegroup jcg_st_2
        where  jcg_st_2.issueid   = jis.id
        and    jcg_st_2.id        = jci_st_2.groupid
        and    jci_st_2.newvalue  = 11912 /*'FSD - Analisis Funcional'*/
        and    jci_st_2.field     = 'status')  ITERACIONES_ANALISIS_FUNCIONAL
       ,ifnull((select sum(timestampdiff(day,jcg_st.created, ifnull((select min(jcg2.created)
                                                              from   changeitem  jci2
                                                                    ,changegroup jcg2
                                                              where  jcg2.id        = jci2.groupid
                                                              and    jci2.field     = 'status'
                                                              and    jci2.oldvalue = jci_st.newvalue
                                                              and    jcg2.issueid   = jcg_st.issueid
                                                              and    jcg2.created   > jcg_st.created),sysdate())))
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status'
         and    jci_st.newvalue   =  11912 /*'FSD - Analisis Funcional'*/),0) DIAS_ANALISIS_FUNCIONAL
      ,(select count(jci_st_2.id)
        from   changeitem  jci_st_2
              ,changegroup jcg_st_2
        where  jcg_st_2.issueid   = jis.id
        and    jcg_st_2.id        = jci_st_2.groupid
        and    jci_st_2.newvalue  = 15598 /*'FSD - ON HOLD'*/
        and    jci_st_2.field     = 'status') ITERACIONES_ON_HOLD
       ,ifnull((select sum(timestampdiff(day,jcg_st.created, ifnull((select min(jcg2.created)
                                                              from   changeitem  jci2
                                                                    ,changegroup jcg2
                                                              where  jcg2.id        = jci2.groupid
                                                              and    jci2.field     = 'status'
                                                              and    jci2.oldvalue = jci_st.newvalue
                                                              and    jcg2.issueid   = jcg_st.issueid
                                                              and    jcg2.created   > jcg_st.created),sysdate()))) dias_totales
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status'
         and    jci_st.newvalue   =  15598 /*'FSD - ON HOLD'*/),0) DIAS_ON_HOLD
      ,(select count(jci_st_2.id)
        from   changeitem  jci_st_2
              ,changegroup jcg_st_2
        where  jcg_st_2.issueid   = jis.id
        and    jcg_st_2.id        = jci_st_2.groupid
        and    jci_st_2.newvalue  = 11918 /*'FSD - TEST'*/
        and    jci_st_2.field     = 'status') ITERACIONES_TEST
       ,ifnull((select sum(timestampdiff(day,jcg_st.created, ifnull((select min(jcg2.created)
                                                              from   changeitem  jci2
                                                                    ,changegroup jcg2
                                                              where  jcg2.id        = jci2.groupid
                                                              and    jci2.field     = 'status'
                                                              and    jci2.oldvalue = jci_st.newvalue
                                                              and    jcg2.issueid   = jcg_st.issueid
                                                              and    jcg2.created   > jcg_st.created),sysdate()))) dias_totales
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status'
         and    jci_st.newvalue   =  11918 /*'FSD - TEST'*/),0) DIAS_TEST
      ,(select count(jci_st_2.id)
        from   changeitem  jci_st_2
              ,changegroup jcg_st_2
        where  jcg_st_2.issueid   = jis.id
        and    jcg_st_2.id        = jci_st_2.groupid
        and    jci_st_2.newvalue  = 11922 /*'FSD - UAT'*/
        and    jci_st_2.field     = 'status') ITERACIONES_UAT
       ,ifnull((select sum(timestampdiff(day,jcg_st.created, ifnull((select min(jcg2.created)
                                                              from   changeitem  jci2
                                                                    ,changegroup jcg2
                                                              where  jcg2.id        = jci2.groupid
                                                              and    jci2.field     = 'status'
                                                              and    jci2.oldvalue = jci_st.newvalue
                                                              and    jcg2.issueid   = jcg_st.issueid
                                                              and    jcg2.created   > jcg_st.created),sysdate()))) dias_totales
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status'
         and    jci_st.newvalue   =  11922 /*'FSD - UAT'*/),0) DIAS_UAT
      ,(select count(jci_st_2.id)
        from   changeitem  jci_st_2
              ,changegroup jcg_st_2
        where  jcg_st_2.issueid   = jis.id
        and    jcg_st_2.id        = jci_st_2.groupid
        and    jci_st_2.newvalue  = 14201 /*'FSD - PROD'*/
        and    jci_st_2.field     = 'status') ITERACIONES_PROD
       ,ifnull((select sum(timestampdiff(day,jcg_st.created, ifnull((select min(jcg2.created)
                                                              from   changeitem  jci2
                                                                    ,changegroup jcg2
                                                              where  jcg2.id        = jci2.groupid
                                                              and    jci2.field     = 'status'
                                                              and    jci2.oldvalue = jci_st.newvalue
                                                              and    jcg2.issueid   = jcg_st.issueid
                                                              and    jcg2.created   > jcg_st.created),sysdate()))) dias_totales
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status'
         and    jci_st.newvalue   =  14201 /*'FSD - PROD'*/),0) DIAS_PROD
      ,jis.id
      ,jis.summary FSD_DESCRIPCION
  FROM project     jpr
      ,jiraissue   jis 
      ,issuestatus jiss
      ,(select jisld.destination issue_link_id
              ,jisld.source issue_related_id
          from issuelink jisld
        union all 
        select jisls.source issue_link_id
              ,jisls.destination issue_related_id
          from issuelink jisls 
       ) jisl
      ,jiraissue   jis_f
      ,project     jpr_f
      ,issuestatus jiss_f
      ,issuetype   jistp_f
      ,priority    p_f
 WHERE p_f.id        = jis.priority
   AND jistp_f.id    = jis_f.issuetype
   AND jiss_f.id     = jis_f.issuestatus 
   AND jpr_f.pkey    IN ('FST') 
   AND jpr_f.id      = jis_f.project
   AND jis_f.id      = jisl.issue_related_id 
   AND jisl.issue_link_id = jis.id
   AND jiss.id       = jis.issuestatus
   AND jis.project   = jpr.id  
   AND jpr.pkey      = 'FSD' 
   AND (   (jiss.pname   != 'Closed') -- FSD Abiertos
        -- or (jiss_f.pname != 'Closed') -- FST Abiertos
        or (exists (select 1
                    from   changeitem  jci_st
                          ,changegroup jcg_st
                    where  jcg_st.issueid   = jis.id
                    and    jcg_st.id        = jci_st.groupid
                    and    jci_st.field     = 'status'
                    and    jci_st.newvalue  = 6
                    and    jcg_st.created   > date_sub(curdate(),interval 14 day)
                    and    jcg_st.created   = (select max(jcg2.created) -- Que sea el ultimo estado por si se reabrio
                                               from   changeitem  jci2
                                                     ,changegroup jcg2
                                               where  jcg2.id        = jci2.groupid
                                               and    jcg2.issueid   = jis.id
                                               and    jci2.field     = 'status'))))
union all
select null FST
      ,concat(jpr.pkey,'-',jis.issuenum) FSD
      ,case jis.priority
       when 1 then concat('1-',p_f.pname)
       else 'Z Sin FST'
       end PRIORIDAD
      ,null PROYECTO
      ,case 
       -- when jiss.pname = 'Closed' then 'Y'
       when (select asa.name
               from customfieldvalue cfv
                   ,customfield cf
                   ,AO_60DB71_SPRINT asa
              where asa.started is true
                and asa.closed is false
                and asa.id = cfv.stringvalue
                and cf.cfname = 'Sprint'
                and cf.id = cfv.customfield
                and cfv.issue = jis.id) IS NULL THEN 'N'
      else 'Y'
      end EN_SPRINT_ACTIVO
      ,case 
       when jiss.pname = 'Closed' then 'Y'
       when (select asa.name
               from customfieldvalue cfv
                   ,customfield cf
                   ,AO_60DB71_SPRINT asa
              where asa.complete_date is null 
                and asa.id = cfv.stringvalue
                and cf.cfname = 'Sprint'
                and cf.id = cfv.customfield
                and cfv.issue = jis.id) IS NULL THEN 'N'
      else 'Y'
      end EN_SPRINT_TECNICO
      ,null ESTADO_FUNCIONAL
      ,jiss.pname ESTADO_TECNICO
      ,ifnull((select max(cg.group_name)
                from   cwd_group        cg
                      ,cwd_membership   cm
                      ,cwd_user         cu
                      ,app_user         apu
                where  apu.lower_user_name = cu.lower_user_name
                and    cu.id               = cm.child_id
                and    cm.parent_id        = cg.id
                and    cu.directory_id     > 1
                and    apu.user_key        = jis.reporter
                and    cg.group_name       in ('FST-AAA','FST-OTC','FST-P2P')),'N/A') VERTICAL
      ,case jiss.id
       when 1 then timestampdiff(day,jis.created,sysdate())
      else
        (select timestampdiff(day,max(jcg_st.created),sysdate())
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status')
       end AGING_ULT_ESTADO
      ,(select max(cu.display_name)
        from   cwd_user         cu
              ,app_user         apu
        where  apu.lower_user_name    = cu.lower_user_name
        and    apu.user_key           = jis.reporter) Responsable_Funcional
      ,(select max(cu.display_name)
        from   cwd_user         cu
              ,app_user         apu
              ,customfieldvalue cstmfldvle
        where  cstmfldvle.customfield = 16645 -- 'Responsable Seguimiento'
        and    apu.lower_user_name    = cu.lower_user_name
        and    apu.user_key           = cstmfldvle.stringvalue
        and    cstmfldvle.issue       = jis.id) Responsable_Tecnico
      ,ifnull( (select round(cstmfldvle.numbervalue)
                from   customfieldvalue cstmfldvle
                where  cstmfldvle.customfield = 21940 -- 'FSD - Estimacion'
                and    cstmfldvle.issue       = jis.id),0) Estimacion
      ,null FST_AGING
      ,timestampdiff(day,jis.created,sysdate()) FSD_AGING
      ,jis.summary FST_DESCRIPCION
      ,ifnull(timestampdiff(day,jis.created, ifnull((select min(jcg2.created)
                                               from   changeitem  jci2
                                                     ,changegroup jcg2
                                               where  jcg2.id       = jci2.groupid
                                               and    jci2.field    = 'status'
                                               and    jci2.oldvalue = 1 -- Open como estado anterior
                                               and    jcg2.issueid  = jis.id
                                               and    jcg2.created  > jis.created),sysdate())),0) DIAS_OPEN
      ,(select count(jci_st_2.id)
        from   changeitem  jci_st_2
              ,changegroup jcg_st_2
        where  jcg_st_2.issueid   = jis.id
        and    jcg_st_2.id        = jci_st_2.groupid
        and    jci_st_2.newvalue  = 11913 /*'FSD - Analisis Tecnico'*/
        and    jci_st_2.field     = 'status')  ITERACIONES_ANALISIS_TECNICO
       ,ifnull((select sum(timestampdiff(day,jcg_st.created, ifnull((select min(jcg2.created)
                                                              from   changeitem  jci2
                                                                    ,changegroup jcg2
                                                              where  jcg2.id        = jci2.groupid
                                                              and    jci2.field     = 'status'
                                                              and    jci2.oldvalue = jci_st.newvalue
                                                              and    jcg2.issueid   = jcg_st.issueid
                                                              and    jcg2.created   > jcg_st.created),sysdate()))) dias_totales
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status'
         and    jci_st.newvalue   = 11913 /*'FSD - Analisis Tecnico'*/),0) DIAS_ANALISIS_TECNICO
      ,(select count(jci_st_2.id)
        from   changeitem  jci_st_2
              ,changegroup jcg_st_2
        where  jcg_st_2.issueid   = jis.id
        and    jcg_st_2.id        = jci_st_2.groupid
        and    jci_st_2.newvalue  = 11914 /*'FSD - DESA'*/
        and    jci_st_2.field     = 'status')  ITERACIONES_DESA
       ,ifnull((select sum(timestampdiff(day,jcg_st.created, ifnull((select min(jcg2.created)
                                                              from   changeitem  jci2
                                                                    ,changegroup jcg2
                                                              where  jcg2.id        = jci2.groupid
                                                              and    jci2.field     = 'status'
                                                              and    jci2.oldvalue = jci_st.newvalue
                                                              and    jcg2.issueid   = jcg_st.issueid
                                                              and    jcg2.created   > jcg_st.created),sysdate()))) dias_totales
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status'
         and    jci_st.newvalue   = 11914 /*'FSD - DESA'*/),0) DIAS_DESA
      ,(select count(jci_st_2.id)
        from   changeitem  jci_st_2
              ,changegroup jcg_st_2
        where  jcg_st_2.issueid   = jis.id
        and    jcg_st_2.id        = jci_st_2.groupid
        and    jci_st_2.newvalue  = 11912 /*'FSD - Analisis Funcional'*/
        and    jci_st_2.field     = 'status')  ITERACIONES_ANALISIS_FUNCIONAL
       ,ifnull((select sum(timestampdiff(day,jcg_st.created, ifnull((select min(jcg2.created)
                                                              from   changeitem  jci2
                                                                    ,changegroup jcg2
                                                              where  jcg2.id        = jci2.groupid
                                                              and    jci2.field     = 'status'
                                                              and    jci2.oldvalue = jci_st.newvalue
                                                              and    jcg2.issueid   = jcg_st.issueid
                                                              and    jcg2.created   > jcg_st.created),sysdate())))
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status'
         and    jci_st.newvalue   =  11912 /*'FSD - Analisis Funcional'*/),0) DIAS_ANALISIS_FUNCIONAL
      ,(select count(jci_st_2.id)
        from   changeitem  jci_st_2
              ,changegroup jcg_st_2
        where  jcg_st_2.issueid   = jis.id
        and    jcg_st_2.id        = jci_st_2.groupid
        and    jci_st_2.newvalue  = 15598 /*'FSD - ON HOLD'*/
        and    jci_st_2.field     = 'status') ITERACIONES_ON_HOLD
       ,ifnull((select sum(timestampdiff(day,jcg_st.created, ifnull((select min(jcg2.created)
                                                              from   changeitem  jci2
                                                                    ,changegroup jcg2
                                                              where  jcg2.id        = jci2.groupid
                                                              and    jci2.field     = 'status'
                                                              and    jci2.oldvalue = jci_st.newvalue
                                                              and    jcg2.issueid   = jcg_st.issueid
                                                              and    jcg2.created   > jcg_st.created),sysdate()))) dias_totales
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status'
         and    jci_st.newvalue   =  15598 /*'FSD - ON HOLD'*/),0) DIAS_ON_HOLD
      ,(select count(jci_st_2.id)
        from   changeitem  jci_st_2
              ,changegroup jcg_st_2
        where  jcg_st_2.issueid   = jis.id
        and    jcg_st_2.id        = jci_st_2.groupid
        and    jci_st_2.newvalue  = 11918 /*'FSD - TEST'*/
        and    jci_st_2.field     = 'status') ITERACIONES_TEST
       ,ifnull((select sum(timestampdiff(day,jcg_st.created, ifnull((select min(jcg2.created)
                                                              from   changeitem  jci2
                                                                    ,changegroup jcg2
                                                              where  jcg2.id        = jci2.groupid
                                                              and    jci2.field     = 'status'
                                                              and    jci2.oldvalue = jci_st.newvalue
                                                              and    jcg2.issueid   = jcg_st.issueid
                                                              and    jcg2.created   > jcg_st.created),sysdate()))) dias_totales
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status'
         and    jci_st.newvalue   =  11918 /*'FSD - TEST'*/),0) DIAS_TEST
      ,(select count(jci_st_2.id)
        from   changeitem  jci_st_2
              ,changegroup jcg_st_2
        where  jcg_st_2.issueid   = jis.id
        and    jcg_st_2.id        = jci_st_2.groupid
        and    jci_st_2.newvalue  = 11922 /*'FSD - UAT'*/
        and    jci_st_2.field     = 'status') ITERACIONES_UAT
       ,ifnull((select sum(timestampdiff(day,jcg_st.created, ifnull((select min(jcg2.created)
                                                              from   changeitem  jci2
                                                                    ,changegroup jcg2
                                                              where  jcg2.id        = jci2.groupid
                                                              and    jci2.field     = 'status'
                                                              and    jci2.oldvalue = jci_st.newvalue
                                                              and    jcg2.issueid   = jcg_st.issueid
                                                              and    jcg2.created   > jcg_st.created),sysdate()))) dias_totales
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status'
         and    jci_st.newvalue   =  11922 /*'FSD - UAT'*/),0) DIAS_UAT
      ,(select count(jci_st_2.id)
        from   changeitem  jci_st_2
              ,changegroup jcg_st_2
        where  jcg_st_2.issueid   = jis.id
        and    jcg_st_2.id        = jci_st_2.groupid
        and    jci_st_2.newvalue  = 14201 /*'FSD - PROD'*/
        and    jci_st_2.field     = 'status') ITERACIONES_PROD
       ,ifnull((select sum(timestampdiff(day,jcg_st.created, ifnull((select min(jcg2.created)
                                                              from   changeitem  jci2
                                                                    ,changegroup jcg2
                                                              where  jcg2.id        = jci2.groupid
                                                              and    jci2.field     = 'status'
                                                              and    jci2.oldvalue = jci_st.newvalue
                                                              and    jcg2.issueid   = jcg_st.issueid
                                                              and    jcg2.created   > jcg_st.created),sysdate()))) dias_totales
         from   changeitem  jci_st
               ,changegroup jcg_st
         where  jcg_st.issueid    = jis.id
         and    jcg_st.id         = jci_st.groupid
         and    jci_st.field      = 'status'
         and    jci_st.newvalue   =  14201 /*'FSD - PROD'*/),0) DIAS_PROD
      ,jis.id
      ,jis.summary FSD_DESCRIPCION
  FROM project     jpr
      ,jiraissue   jis 
      ,issuestatus jiss
      ,priority    p_f
 WHERE NOT EXISTS (select 1
                   from   (select jisld.destination issue_link_id
                                 ,jisld.source issue_related_id
                           from issuelink jisld
                           union all
                           select jisls.source issue_link_id
                                 ,jisls.destination issue_related_id
                           from issuelink jisls) jisl
                          ,jiraissue   jis2
                          ,project     jpr2
                   where jpr2.pkey    IN ('FST')
                   and   jpr2.id = jis2.project
                   and   jis2.id = jisl.issue_related_id
                   and jisl.issue_link_id     = jis.id)
   AND p_f.id        = jis.priority
   AND jiss.id       = jis.issuestatus
   AND jis.project   = jpr.id  
   AND jpr.pkey      = 'FSD' 
   AND (   (jiss.pname   != 'Closed')
        or (exists (select 1
                    from   changeitem  jci_st
                          ,changegroup jcg_st
                    where  jcg_st.issueid   = jis.id
                    and    jcg_st.id        = jci_st.groupid
                    and    jci_st.field     = 'status'
                    and    jci_st.newvalue  = 6
                    and    jcg_st.created   > date_sub(curdate(),interval 14 day)
                    and    jcg_st.created   = (select max(jcg2.created) -- Que sea el ultimo estado por si se reabrio
                                               from   changeitem  jci2
                                                     ,changegroup jcg2
                                               where  jcg2.id        = jci2.groupid
                                               and    jcg2.issueid   = jis.id
                                               and    jci2.field     = 'status'))))
order by 3,2,1
;