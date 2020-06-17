set @fecha_inicio = '2020-01-12 23:59:59';
set @fecha_fin = '2020-01-20 00:00:00';
select sum(tabla.st_open)         st_open
      ,sum(tabla.st_close)        st_close
      ,sum(tabla.backlog)         backlog
      ,sum(tabla.total_mas_de_90) total_mas_de_90
      ,sum(tabla.blocker)         blocker
      ,sum(tabla.blk_close)       blk_close
      ,sum(tabla.st_af)           st_af
      ,sum(tabla.st_test)         st_test
      ,sum(tabla.st_uat)          st_uat
      ,sum(tabla.st_prod)         st_prod
      ,sum(tabla.st_at)           st_at
      ,sum(tabla.st_hold)         st_hold
      ,sum(tabla.st_desa)         st_desa
      ,sum(tabla.st_promocion)    st_promocion
from (
select count(jis.id) backlog
      ,0 blocker
      ,0 blk_close
      ,0 st_open
      ,0 st_at
      ,0 st_af
      ,0 st_hold
      ,0 st_desa
      ,0 st_promocion
      ,0 st_test
      ,0 st_uat
      ,0 st_prod
      ,0 st_close
      ,0 total_mas_de_90
from   jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jpr.pkey          = 'FSD' /*Proyecto*/
-- and    jis.created       < STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s')
and    jis.created       < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
and    'Y'               = (case ifnull((select max(jcg2.created)
                                         from   changeitem  jci2
                                               ,changegroup jcg2
                                         where  jcg2.id        = jci2.groupid
                                         and    jcg2.issueid   = jis.id
                                         and    jci2.field     = 'status'
                                         and    jci2.newvalue  = 6 -- jci_st.newvalue
                                         -- and    jcg2.created   < STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s')
                                         and    jcg2.created   < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
                                         and    jcg2.created =  (select max(jcg3.created) -- Que sea el ultimo estado por si se reabrio
                                                                 from   changeitem  jci3
                                                                       ,changegroup jcg3
                                                                 where  jcg3.id        = jci3.groupid
                                                                 and    jcg3.issueid   = jis.id
                                                                 and    jci3.field     = 'status')),'Y')
                                         when 'Y' then 'Y'
                                         else 'N' end)
union all
/*Bloqueantes levantados*/
select 0 backlog
      ,count(jis.id) blocker
      ,0 blk_close
      ,0 st_open
      ,0 st_at
      ,0 st_af
      ,0 st_hold
      ,0 st_desa
      ,0 st_promocion
      ,0 st_test
      ,0 st_uat
      ,0 st_prod
      ,0 st_close
      ,0 total_mas_de_90
from   jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jpr.pkey          = 'FSD' /*Proyecto*/
and    jis.created >  STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s')
and    jis.created <  STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
and    (     jis.priority = 1
        or  (exists (select 1
                     from   changeitem  jci
                           ,changegroup jcg
                     where  jcg.id        = jci.groupid
                     and    jci.field     = 'priority'
                     and    jcg.issueid   = jis.id
                     and   (   jci.oldvalue = 1
                            or jci.newvalue = 1))))
union all
/*Blocker cerrados*/
select 0 backlog
      ,0 blocker
      ,count(jis.id) blk_close
      ,0 st_open
      ,0 st_at
      ,0 st_af
      ,0 st_hold
      ,0 st_desa
      ,0 st_promocion
      ,0 st_test
      ,0 st_uat
      ,0 st_prod
      ,0 st_close
      ,0 total_mas_de_90
from   jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jpr.pkey          = 'FSD' /*Proyecto*/
and    exists (select 1 -- Tenga cambios de estado entre fechas
               from   changeitem  jci
                     ,changegroup jcg
               where  jcg.id        = jci.groupid
               and    jcg.issueid   = jis.id
               and    jci.field     = 'status'
               and    jci.newvalue  = 6     /*'Closed'*/
               and    jcg.created   > STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s')
               and    jcg.created   < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s'))
and    (     jis.priority = 1
        or  (exists (select 1
                     from   changeitem  jci
                           ,changegroup jcg
                     where  jcg.id        = jci.groupid
                     and    jci.field     = 'priority'
                     and    jcg.issueid   = jis.id
                     and   (   jci.oldvalue = 1
                            or jci.newvalue = 1))))
union all
/*-- Open --*/
select 0 backlog
      ,0 blocker
      ,0 blk_close
      ,count(jis.id) st_open
      ,0 st_at
      ,0 st_af
      ,0 st_hold
      ,0 st_desa
      ,0 st_promocion
      ,0 st_test
      ,0 st_uat
      ,0 st_prod
      ,0 st_close
      ,0 total_mas_de_90
from   jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jpr.pkey          = 'FSD' /*Proyecto*/
and    jis.created >  STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s')
and    jis.created <  STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
union all
/*'FSD - Analisis Tecnico'*/
select 0 backlog
      ,0 blocker
      ,0 blk_close
      ,0 st_open
      ,count(jis.id) st_at
      ,0 st_af
      ,0 st_hold
      ,0 st_desa
      ,0 st_promocion
      ,0 st_test
      ,0 st_uat
      ,0 st_prod
      ,0 st_close
      ,0 total_mas_de_90
from   jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jpr.pkey          = 'FSD' /*Proyecto*/
and    exists (select 1 -- Tenga cambios de estado entre fechas
               from   changeitem  jci
                     ,changegroup jcg
               where  jcg.id        = jci.groupid
               and    jcg.issueid   = jis.id
               and    jci.field     = 'status'
               and    jci.newvalue  = 11913 /*'FSD - Analisis Tecnico'*/
               and    jcg.created   > STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s')
               and    jcg.created   < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s'))
union all
/*'FSD - Analisis Funcional'*/
select 0 backlog
      ,0 blocker
      ,0 blk_close
      ,0 st_open
      ,0 st_at
      ,count(jis.id) st_af
      ,0 st_hold
      ,0 st_desa
      ,0 st_promocion
      ,0 st_test
      ,0 st_uat
      ,0 st_prod
      ,0 st_close
      ,0 total_mas_de_90
from   jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jpr.pkey          = 'FSD' /*Proyecto*/
and    exists (select 1 -- Tenga cambios de estado entre fechas
               from   changeitem  jci
                     ,changegroup jcg
               where  jcg.id        = jci.groupid
               and    jcg.issueid   = jis.id
               and    jci.field     = 'status'
               and    jci.newvalue  = 11912 /*'FSD - Analisis Funcional'*/
               and    jcg.created   > STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s')
               and    jcg.created   < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s'))
union all
/*'FSD - ON HOLD'*/
select 0 backlog
      ,0 blocker
      ,0 blk_close
      ,0 st_open
      ,0 st_at
      ,0 st_af
      ,count(jis.id) st_hold
      ,0 st_desa
      ,0 st_promocion
      ,0 st_test
      ,0 st_uat
      ,0 st_prod
      ,0 st_close
      ,0 total_mas_de_90
from   jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jpr.pkey          = 'FSD' /*Proyecto*/
and    exists (select 1 -- Tenga cambios de estado entre fechas
               from   changeitem  jci
                     ,changegroup jcg
               where  jcg.id        = jci.groupid
               and    jcg.issueid   = jis.id
               and    jci.field     = 'status'
               and    jci.newvalue  = 15598 /*'FSD - ON HOLD'*/
               and    jcg.created   > STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s')
               and    jcg.created   < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s'))
union all
/*'FSD - DESA'*/
select 0 backlog
      ,0 blocker
      ,0 blk_close
      ,0 st_open
      ,0 st_at
      ,0 st_af
      ,0 st_hold
      ,count(jis.id) st_desa
      ,0 st_promocion
      ,0 st_test
      ,0 st_uat
      ,0 st_prod
      ,0 st_close
      ,0 total_mas_de_90
from   jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jpr.pkey          = 'FSD' /*Proyecto*/
and    exists (select 1 -- Tenga cambios de estado entre fechas
               from   changeitem  jci
                     ,changegroup jcg
               where  jcg.id        = jci.groupid
               and    jcg.issueid   = jis.id
               and    jci.field     = 'status'
               and    jci.newvalue  = 11914 /*'FSD - DESA'*/
               and    jcg.created   > STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s')
               and    jcg.created   < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s'))
union all
/*'FSD - Promocion a TEST' 'FSD - Promocion a UAT' 'FSD - Promocion a PROD'*/
select 0 backlog
      ,0 blocker
      ,0 blk_close
      ,0 st_open
      ,0 st_at
      ,0 st_af
      ,0 st_hold
      ,0 st_desa
      ,count(jis.id) st_promocion
      ,0 st_test
      ,0 st_uat
      ,0 st_prod
      ,0 st_close
      ,0 total_mas_de_90
from   jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jpr.pkey          = 'FSD' /*Proyecto*/
and    exists (select 1 -- Tenga cambios de estado entre fechas
               from   changeitem  jci
                     ,changegroup jcg
               where  jcg.id        = jci.groupid
               and    jcg.issueid   = jis.id
               and    jci.field     = 'status'
               and    jci.newvalue  in (11916,11920,11924) /*'FSD - Promocion a TEST' 'FSD - Promocion a UAT' 'FSD - Promocion a PROD'*/
               and    jcg.created   > STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s')
               and    jcg.created   < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s'))
union all
/*'FSD - TEST'*/
select 0 backlog
      ,0 blocker
      ,0 blk_close
      ,0 st_open
      ,0 st_at
      ,0 st_af
      ,0 st_hold
      ,0 st_desa
      ,0 st_promocion
      ,count(jis.id) st_test
      ,0 st_uat
      ,0 st_prod
      ,0 st_close
      ,0 total_mas_de_90
from   jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jpr.pkey          = 'FSD' /*Proyecto*/
and    exists (select 1 -- Tenga cambios de estado entre fechas
               from   changeitem  jci
                     ,changegroup jcg
               where  jcg.id        = jci.groupid
               and    jcg.issueid   = jis.id
               and    jci.field     = 'status'
               and    jci.newvalue  = 11918 /*'FSD - TEST'*/
               and    jcg.created   > STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s')
               and    jcg.created   < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s'))
union all
/*'FSD - UAT'*/
select 0 backlog
      ,0 blocker
      ,0 blk_close
      ,0 st_open
      ,0 st_at
      ,0 st_af
      ,0 st_hold
      ,0 st_desa
      ,0 st_promocion
      ,0 st_test
      ,count(jis.id) st_uat
      ,0 st_prod
      ,0 st_close
      ,0 total_mas_de_90
from   jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jpr.pkey          = 'FSD' /*Proyecto*/
and    exists (select 1 -- Tenga cambios de estado entre fechas
               from   changeitem  jci
                     ,changegroup jcg
               where  jcg.id        = jci.groupid
               and    jcg.issueid   = jis.id
               and    jci.field     = 'status'
               and    jci.newvalue  = 11922 /*'FSD - UAT'*/
               and    jcg.created   > STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s')
               and    jcg.created   < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s'))
union all
/*'FSD - PROD'*/
select 0 backlog
      ,0 blocker
      ,0 blk_close
      ,0 st_open
      ,0 st_at
      ,0 st_af
      ,0 st_hold
      ,0 st_desa
      ,0 st_promocion
      ,0 st_test
      ,0 st_uat
      ,count(jis.id) st_prod
      ,0 st_close
      ,0 total_mas_de_90
from   jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jpr.pkey          = 'FSD' /*Proyecto*/
and    exists (select 1 -- Tenga cambios de estado entre fechas
               from   changeitem  jci
                     ,changegroup jcg
               where  jcg.id        = jci.groupid
               and    jcg.issueid   = jis.id
               and    jci.field     = 'status'
               and    jci.newvalue  = 14201 /*'FSD - PROD'*/
               and    jcg.created   > STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s')
               and    jcg.created   < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s'))
union all
/*'Closed'*/
select 0 backlog
      ,0 blocker
      ,0 blk_close
      ,0 st_open
      ,0 st_at
      ,0 st_af
      ,0 st_hold
      ,0 st_desa
      ,0 st_promocion
      ,0 st_test
      ,0 st_uat
      ,0 st_prod
      ,count(jis.id) st_close
      ,0 total_mas_de_90
from   jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jpr.pkey          = 'FSD' /*Proyecto*/
-- and    jis.resolutiondate is not null
and    exists (select 1 -- Tenga cambios de estado entre fechas
               from   changeitem  jci
                     ,changegroup jcg
               where  jcg.id        = jci.groupid
               and    jcg.issueid   = jis.id
               and    jci.field     = 'status'
               and    jci.newvalue  = 6     /*'Closed'*/
               and    jcg.created   > STR_TO_DATE(@fecha_inicio, '%Y-%m-%d %H:%i:%s')
               and    jcg.created   < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s'))
union all
/*Mayor a 90*/
select 0 backlog
      ,0 blocker
      ,0 blk_close
      ,0 st_open
      ,0 st_at
      ,0 st_af
      ,0 st_hold
      ,0 st_desa
      ,0 st_promocion
      ,0 st_test
      ,0 st_uat
      ,0 st_prod
      ,0 st_close
      ,count(jis.id) as total_mas_de_90
from   jiraissue   jis
      ,project     jpr
where  jpr.id            = jis.project
and    jpr.pkey          = 'FSD' /*Proyecto*/
and    timestampdiff(day, jis.created,STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')) > 90
and    jis.created       < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
and    'Y'               = (case ifnull((select max(jcg2.created)
                                         from   changeitem  jci2
                                               ,changegroup jcg2
                                         where  jcg2.id        = jci2.groupid
                                         and    jcg2.issueid   = jis.id
                                         and    jci2.field     = 'status'
                                         and    jci2.newvalue  = 6 -- jci_st.newvalue
                                         and    jcg2.created   < STR_TO_DATE(@fecha_fin, '%Y-%m-%d %H:%i:%s')
                                         and    jcg2.created =  (select max(jcg3.created) -- Que sea el ultimo estado por si se reabrio
                                                                 from   changeitem  jci3
                                                                       ,changegroup jcg3
                                                                 where  jcg3.id        = jci3.groupid
                                                                 and    jcg3.issueid   = jis.id
                                                                 and    jci3.field     = 'status')),'Y')
                                         when 'Y' then 'Y'
                                         else 'N' end)
) tabla
;
