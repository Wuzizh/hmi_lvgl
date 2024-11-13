 /****************************************************************
 * FileName:      mdl_rdb_extern.h
 * Description:   ����ӿ�ʵ�ֺ������ⲿ����(����ڲ�ʹ��)
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
//extern SEM_ID     ccu_ini_sem;                      /* ��̬�ı��ź���*/
//extern SEM_ID     database_sem;

extern struct     DATABASE  *rdbPtr;                /*ʵʱ���ݿ�ָ��*/
extern struct     DEV_TAB *dev_tab_ptr;             /*װ���ܱ�ָ��*/
extern struct     INDEX_LIST *index_head;           /*��Լ���ñ�ͷָ��*/
extern struct     TIME_SOURCES *time_ptr;           /*��ʱԴ*/
extern struct    EQUIPMENT_TAB * rdb_equip_ptr;/*�������ָ��*/
extern struct    LIST_OWNER_LIST * list_owner_head; /*���ñ�ο������б�ͷָ��*/
extern struct    RDB_PROPERTY_TABLE rdb_prop_table;
extern struct    SET_CHANGE_HOOK *set_hook_head;    /*��ֵ�仯ע������ͷָ��*/

//extern u_char     dev_sta[SYS_DEV_NUM];             /*�豸״̬  */
                                                    /*bit0-3: װ�����й��� 0:ͣ��  1:���� 2:����  3:���� 4-63:����*/  
                                                    /*bit4-5: A��״̬ 0:��  1:ͨ */  
                                                    /*bit6-7: B��״̬ 0:��  1:ͨ */
//extern u_char    dev_sta_b[SYS_DEV_NUM];
extern struct    RDB_CONFIG_DATA   rdb_config_data;                                  
extern u_char     configed;       
//extern u_int      proj_name[80];                    /*��������*/

extern u_char     ccu_sta;
extern u_char     ccu_sta_b;
extern u_char     master;
extern u_char     single;

//extern u_int 		g_rdb_location;
//extern u_int 		g_rdb_invokeID;                  /*ÿ�κ������ü�1*/

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

