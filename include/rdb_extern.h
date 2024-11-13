 /****************************************************************
 * FileName:      mdl_rdb_extern.h
 * Description:   组件接口实现函数的外部声明(组件内部使用)
 *
 * Modify Log:
 * 
 ****************************************************************/
 
#ifndef _RDB_EXTERN_H_
#define _RDB_EXTERN_H_ 

#include "rdb_define.h"
//#include "rdb_prop.h"
//extern MSG_Q_ID   dispatch_top_id;
//extern MSG_Q_ID   dispatch_bottom_id;
//extern MSG_Q_ID   dispatch_other_id;
//extern SEM_ID     ccu_ini_sem;                      /* 组态文本信号量*/
//extern SEM_ID     database_sem;

extern struct     DATABASE  *rdbPtr;                /*实时数据库指针*/
extern struct     DEV_TAB *dev_tab_ptr;             /*装置总表指针*/
extern struct     INDEX_LIST *index_head;           /*规约引用表头指针*/
extern struct     TIME_SOURCES *time_ptr;           /*对时源*/
extern struct    EQUIPMENT_TAB * rdb_equip_ptr;/*间隔配置指针*/
extern struct    LIST_OWNER_LIST * list_owner_head; /*引用表参考对象列表头指针*/
extern struct    RDB_PROPERTY_TABLE rdb_prop_table;
extern struct    SET_CHANGE_HOOK *set_hook_head;    /*定值变化注册链表头指针*/

//extern u_char     dev_sta[SYS_DEV_NUM];             /*设备状态  */
                                                    /*bit0-3: 装置运行工况 0:停运  1:运行 2:调试  3:检修 4-63:其他*/  
                                                    /*bit4-5: A网状态 0:断  1:通 */  
                                                    /*bit6-7: B网状态 0:断  1:通 */
//extern u_char    dev_sta_b[SYS_DEV_NUM];
extern struct    RDB_CONFIG_DATA   rdb_config_data;                                  
extern u_char     configed;       
//extern u_int      proj_name[80];                    /*工程名称*/

extern u_char     ccu_sta;
extern u_char     ccu_sta_b;
extern u_char     master;
extern u_char     single;

//extern u_int 		g_rdb_location;
//extern u_int 		g_rdb_invokeID;                  /*每次函数调用加1*/

extern struct  RDB_REG_STRUCT * reg_dev_sta_head;
extern struct	 RDB_MON_STRUCT * mon_msg_head;

extern struct  ELEMENT* searchEntry(u_int index);
extern struct  DEV_DATA* searchDev(u_int index);
extern struct  HOOK *search_hook_with_addr(struct ELEMENT *dp,u_int app_id,u_int task_id,u_int return_id);
extern struct  HOOK *search_hook_with_type(struct ELEMENT *dp,u_int app_id,u_int task_id,u_int return_id,u_char type);
extern struct  GROUP_DATA* searchGroup(u_int index);
extern void    active_timesource(u_int app_id,int period);
extern u_char  check_valid_timesource(u_int app_id);
//extern void    sys_exitpro();
extern u_char  compare_time(int last_time,int current_time,int compare_value);
extern struct  ELEMENT* search_FunInf(u_short dev_addr,u_char cpu_no,u_char fun,u_char inf);
extern struct  ELEMENT* search_FunInf_cpu_no(u_short dev_addr,u_char cpu_no,u_char fun,u_char inf);
extern void    check_hooks(struct ELEMENT *item,struct GDD_GID *datap,u_char type);
extern struct  SET_CHANGE_HOOK *  search_set_hook(u_int app_id,u_int task_id,u_int return_id);
extern u_char  take_database_sem(void);
extern u_char  give_database_sem(void);


#endif  

