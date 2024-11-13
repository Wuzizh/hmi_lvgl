

#ifndef	_RDB_INIT_H_
#define	_RDB_INIT_H_

#include "os_func.h"
#include "sys_dir.h"
#include "sys_extern.h"
#include "sys_func.h"
#include "softbus.h"
#include "rdb_itf.h"
#include "sys_stream.h"
#include "rdb_define.h"
#include "rdb_extern.h"

//#undef  _MDL_RDB_DEBUG_
//#define  _MDL_RDB_DEBUG_
#define QLEN_PER_SRVR           1000
#define MAX_MSG_LEN             6000
#define SEND_MSG_LEN            10000
#define RECV_MSG_LEN            10000
//#define RDB_STACK_SIZE          50000

#define CHECK_DEV_STA_PERIOD    20
#define CHECK_DEV_STA_TIMEOUT   200

union UINT_FLOAT
{
	char  cVal;
	u_char cuVal;
	short sVal;
	u_short suVal;
	int   ival;
	u_int uint_val;
	float float_val;
	u_char avalue[4];
	u_char *pp;
};

struct SOURCE_ID
{
	struct SOURCE_ID* next;
	u_int app_id;
	u_int task_id;
	u_int period;
	u_char busy_flag;
	int count; /*add by linq*/
};
 
struct  CMD_ID_CHAIN               /**/
{
  struct  CMD_ID_CHAIN * next;
  u_int app_id;
  u_int task_id;
  u_int cmd_id;
};

struct RDB_DATABASE_STR
{
	u_short dev104_send_interval;

	float modbus_tcp_yt;

    sem_t   database_sem;
//    sem_t   ccu_ini_sem;
    
    int     check_dev_sta_timer;
    int     period_send_sta_timer;
    
    u_char  dev_count[SYS_DEV_NUM]; 
    u_char  dev_sta[SYS_DEV_NUM];             /*设备状态  */
                                                    /*bit0-3: 装置运行工况 0:停运  1:运行 2:调试  3:检修 4-63:其他*/  
                                                    /*bit4-5: A网状态 0:断  1:通 */  
                                                    /*bit6-7: B网状态 0:断  1:通 */
    u_char  dev_sta_b[SYS_DEV_NUM];
    
    struct SOURCE_ID* rdb_dev_sta_source_p;
    struct SOURCE_ID* rdb_conn_sta_source_p;
	
	struct  CMD_ID_CHAIN *   cmd_id_head;
};

extern int realDB_Init();
extern u_char  take_database_sem(void);
extern u_char  give_database_sem(void);

extern  struct TIME_SOURCE* search_timesource(u_int app_id);
extern  void  check_timesource(void);
extern  void  active_timesource(u_int app_id,int period);
extern  u_char  check_valid_timesource(u_int app_id);
extern  int search_no_in_dev_tab(u_int addr);
extern int insertDev(struct  DEV_DATA* dev);
extern struct  DEV_DATA* searchDev(u_int index);
extern int insert_bit_decs(struct  DEV_DATA* dev_p, struct  BIT * bit_decs_p);
extern struct  BIT* search_bit_decs(u_int index);
extern int insertGroup(struct  DEV_DATA* dev_p, struct  GROUP_DATA* group_p);
extern struct  GROUP_DATA* searchGroup(u_int index);
extern int insertEntry(struct  GROUP_DATA* group_p, struct ELEMENT* entry_p);
extern struct  ELEMENT* searchEntry(u_int index);
extern struct  ELEMENT* search_FunInf(u_short dev_addr, u_char  cpu_no, u_char fun, u_char inf);
extern struct ELEMENT* search_FunInf_cpu_no_YK(u_short dev_addr, u_char  cpu_no, u_char fun, u_char inf);
extern struct  ELEMENT* search_FunInf_cpu_no(u_short dev_addr, u_char  cpu_no, u_char fun, u_char inf);
extern int insertOneKod(struct ELEMENT* entry_p, struct GDD_DATA* gdd_data);
extern struct  GDD_DATA* searchKod(struct ELEMENT * entry_p,  u_char kod);
extern int insert_list(struct LIST** list_head,struct LIST* list_p);
extern int insert_lists(struct INDEX_LIST** list_head,struct INDEX_LIST *list_p);
extern struct  LIST_OWNER * search_list_owner(u_int list_app_id,u_int list_no);
extern void set_dev_DataValidFlag(u_short dev_addr);
extern void clear_dev_DataValidFlag(u_short dev_addr);
extern  void send_dev_stat_msg(u_short dev_addr,u_char stat);
extern int mdl_rdb_get_item_prop(u_short addr,u_char group_no,u_char entry_no,char *back_msg);
extern int mdl_rdb_get_item_desc(u_short addr,u_char group_no,u_char entry_no,u_char max_len,char *back_msg);
extern int mdl_rdb_find_orgin_group(u_short dev_addr,u_char map_group,u_char *cpu_no,u_char *orgin_group);
extern int mdl_rdb_find_map_group(u_short dev_addr,u_char cpu_no,u_char orgin_group,u_char *map_group);
void save_dev_run_sta(void);

int rdb_proc_get_protocol_infor(
	u_short dev_addr, 		/*装置地址*/
	const char *key_name, 	/*关键字: 遥测，遥信等*/
	u_char *p_ret_num, 		/*读取的组个数*/
	u_char *p_ret_group,		/*具体每组的组号*/
	u_char *p_ret_entry,		/*具体每组条目的个数*/
	u_char default_group,	/*若读取不成功, 默认组号*/
	u_int max_ret_num		/*最大返回长度，防止越限*/
);
int rdb_get_dev_group(u_short dev_addr, 		/*装置地址*/
	const char *key_name, 	/*关键字: 遥测，遥信等*/
    struct  GROUP_DATA  **pRetgroup,		/*具体每组的组号*/
	u_int max_ret_num		/*最大返回长度，防止越限*/
	);
extern  int send_msg_to_caller(u_int  cmd_id, u_char *buf, u_int  length);
extern int rdb_check_ykbs
(
/*in*/u_int     appid,               			/*遥控源的appid*/
/*in*/u_int     yk_index,
/*in*/u_char    type											/*0:分  1：合*/
);

extern void sys_str_trim(char *strToTrim);

extern int rdb_proc_readYX2
(
/*in*/u_int   appid,                      /*规约的APP_ID*/
/*in*/u_int   list_no,                    /*引用表号*/
/*in*/u_int   begin_no,                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num,                        /*读取数目*/
/*out*/u_int  *back_num,                  /*返回条目数目*/
/*out*/u_char *data
);

extern int rdb_proc_readYC2
(
/*in*/u_int   appid,                      /*规约的APP_ID*/
/*in*/u_int   list_no,                    /*引用表号*/
/*in*/u_int   begin_no,                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num,                        /*读取数目*/
/*out*/u_int  *back_num,                  /*返回条目数目*/
/*out*/u_short *data
);

extern int rdb_proc_readYM2
(
/*in*/u_int   appid,                      /*规约的APP_ID*/
/*in*/u_int   list_no,                    /*引用表号*/
/*in*/u_int   begin_no,                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num,                        /*读取数目*/
/*out*/u_int  *back_num,                  /*返回条目数目*/
/*out*/u_char *data
);

extern int rdb_proc_readYP2
(
/*in*/u_int   appid,                      /*规约的APP_ID*/
/*in*/u_int   list_no,                    /*引用表号*/
/*in*/u_int   begin_no,                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num,                        /*读取数目*/
/*out*/u_int  *back_num,                  /*返回条目数目*/
/*out*/u_char *data
);

extern int rdb_proc_readYC_float2
(
/*in*/u_int   appid,                      /*规约的APP_ID*/
/*in*/u_int   list_no,                    /*引用表号*/
/*in*/u_int   begin_no,                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num,                        /*读取数目*/
/*out*/u_int  *back_num,                  /*返回条目数目*/
/*out*/float  *data,
/*out*/u_char *quality										/*品质描述*/
);

extern int rdb_proc_readYC_float3
(
/*in*/u_int   appid,                      /*规约的APP_ID*/
/*in*/u_int   list_no,                    /*引用表号*/
/*in*/u_int   begin_no,                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num,                        /*读取数目*/
/*out*/u_int  *back_num,                  /*返回条目数目*/
/*out*/u_char  *data
);

extern int rdb_proc_get_list_num2
(
/*in*/u_int   app_id,                     /*规约的APP_ID*/
/*in*/u_int   list_no,                    /*引用表号*/
/*out*/u_short   *num                     /*引用表条目数*/
);

extern int rdb_proc_read_list2
(
/*in*/u_int   app_id,                     /*规约的APP_ID*/
/*in*/u_int   list_no,                    /*引用表号*/
/*in*/u_int   begin_no,                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num,                        /*读取数目*/
/*in*/u_char  kod,
/*in*/u_short len,
/*out*/u_char   *data 
);

extern int rdb_proc_dispatch_top2
(
/*in*/u_int   app_id,
/*in*/u_int   task_id,
/*in*/u_int   object_id,
/*in*/u_short len,
/*in*/u_char  *buf

);

extern int rdb_proc_dispatch_bottom2
(
/*in*/u_short len,
/*in*/u_char  *buf
);


extern int rdb_proc_add_list_owner2
(
/*in*/u_int source_appid,   
/*in*/u_int source_taskid,                       
/*in*/u_int return_id,
/*in*/u_int appid,                        /*引用表的APP_ID*/                
/*in*/u_short list_no                     /*引用表号*/   
);

extern int rdb_proc_delete_list_owner2
(
/*in*/u_int source_appid,   
/*in*/u_int source_taskid,                       
/*in*/u_int return_id,
/*in*/u_int appid,                        /*引用表的APP_ID*/
/*in*/u_short list_no                     /*引用表号*/
);

extern int rdb_proc_get_dev_sta2
(
/*in*/u_short addr,
/*out*/u_char *state            
);

extern int rdb_proc_get_all_dev_sta2(u_int app_id,u_int task_id,u_int period);

extern int rdb_proc_get_all_conn_sta2(u_int app_id,u_int task_id,u_int period);

extern int rdb_proc_set_dev_net_sta2
(
/*in*/u_short addr,
/*in*/u_char no,                        /*0x01:A网  0x02:B网   0x03: 双网(装置状态) */
/*in*/u_char state
);

extern int rdb_proc_set_devs_net_sta2(struct  DEVS_NET_STA * devs_sta);

extern int rdb_proc_set_com_sta2
(
/*in*/u_char board_no,
/*in*/u_char com_no,
/*in*/u_char state
);

extern int rdb_proc_get_con_sta2
(
/*in*/u_char board_no,
/*in*/u_char con_no,
/*out*/u_char *state
);

extern int rdb_proc_get_self_con_sta2
(
/*in*/u_char board_no,
/*in*/u_char con_no,
/*out*/u_char *state
);

extern int rdb_proc_set_con_sta2
(
/*in*/u_char board_no,
/*in*/u_char con_no,
/*in*/u_char state
);

extern int rdb_proc_get_M_S_sta2
(
/*out*/u_char *state
);

extern int rdb_proc_get_time2
(
/*out*/struct SYS_TIME *t
);

extern int rdb_proc_set_time2
(
/*in*/u_int   appid,                      /*时间源的appid*/
/*in*/struct SYS_TIME *t,
/*in*/int period
);

extern int rdb_proc_search_distub2
(
/*in*/u_short addr,
/*in*/u_char  fun,
/*in*/u_char  inf,
/*out*/u_int  *index, 
/*out*/u_char   *description
);

extern int rdb_proc_search_with_acc2
(
/*in*/u_short addr,
/*in*/u_char  acc,
/*out*/u_int  *index, 
/*out*/u_char   *dimension,
/*out*/u_char   *description,
/*out*/u_char   *phase
);

extern int rdb_proc_get_relate2
(
/*in*/u_int   index,
/*out*/u_int* relate
);

extern int rdb_proc_getFunInf2
(
/*in*/u_int   index,
/*out*/u_char *fun,
/*out*/u_char *inf
);

extern int rdb_proc_get_real_addr
(
/*in*/u_short map_addr,
/*out*/u_short *real_addr
);

extern int rdb_proc_get_map_addr
(
/*in*/u_short real_addr,
/*out*/u_short *map_addr
);

extern int rdb_proc_register_list_hook2
(
/*in*/u_int app_id,                       /*注册者的app_id*/
/*in*/u_int task_id,                      /*注册者的task_id*/
/*in*/u_int return_id,                    /*注册者的return_id*/
/*in*/u_int list_app_id,                  /*引用表的app_id*/
/*in*/u_short list_no,                    /*引用表的编号*/
/*in*/u_char type,                        /*事件类型*/  /* 0x01:变化 */
                                                        /* 0x02:定时  */  
                                                        /* 0x04:问答  */  
                                                        /* 0x08:有条件变化上送 */   
/*in*/u_short send_period,                /*周期上送时间*/                                                        
/*in*/u_short len,                        /*条件上送表达式的长度*/
/*in*/u_char* expression                  /*条件上送表达式*/
);

extern int rdb_proc_get_group_entry2
(
/*in*/u_int app_id,                       /*引用表的app_id*/
/*in*/u_short list_no,                    /*引用表号*/              
/*in*/u_short no,                         /*引用序号*/  
/*out*/u_int *index                 
);

extern int rdb_proc_register_hook2
(
/*in*/u_int app_id,                 /*注册者的app_id*/
/*in*/u_int task_id,                /*注册者的task_id*/
/*in*/u_int return_id,              /*注册者的return_id*/
/*in*/u_int list_app_id,            /*引用表的app_id*/
/*in*/u_short list_no,              /*引用表的编号*/
/*in*/u_short no,                   /*引用表中的条目编号,0开始*/
/*in*/u_short send_period,          /*周期上送时间*/
/*in*/u_char type,                  /*事件类型*/  /* 0x01:变化 */
                                                  /* 0x02:定时  */  
                                                  /* 0x04:问答  */  
                                                  /* 0x08:有条件变化上送 */   
/*in*/u_short len,                  /*条件上送表达式的长度*/
/*in*/u_char* expression            /*条件上送表达式*/
);

extern int rdb_proc_register_hookA2
(
/*in*/u_int  app_id,
/*in*/u_int  task_id,
/*in*/u_int  return_id,
/*in*/u_char list_type,
/*in*/u_char hook_type,
/*in*/u_short send_period,  
/*in*/u_short len,
/*in*/u_char* expression            /*条件变化上送表达式*/ 
);

extern int rdb_proc_get_dev_num2
(
/*out*/u_short *num                 
);

extern int rdb_proc_register_dev_stat2
(
/*in*/u_int  app_id,
/*in*/u_int  task_id,
/*in*/u_int  return_id
);

extern int rdb_proc_register_mon_msg2
(
/*in*/u_int  app_id,
/*in*/u_int  task_id,
/*in*/u_int  return_id
);

extern int rdb_proc_get_data_synch2
(
/*in*/u_int   app_id,
/*in*/u_int   task_id,
/*in*/u_int   object_id,
/*in*/struct  EXT_ASDU21 *asdu21_p,         /*装置真实地址*/
/*in*/u_char  filter_flag,                /*过滤标记  =CM_YES:过滤方式*/
/*in*/u_short max_len,                    /*运行返回报文最大长度*/
/*out*/int    *error_no,                  /* 0:未知  
                                             1:该装置不存在 
                                             2:该装置数据未建立完成 
                                             3:
                                                         */
/*out*/u_short *len,                      /*asdu报文长度*/
/*out*/u_char  *buf                       /*asdu报文*/
);

extern int rdb_proc_get_group_name2
(
/*in*/u_short  dev_addr,
/*in*/u_char   group_no,
/*out*/u_char  *group_name
);

extern int rdb_proc_get_group_type2
(
/*in*/u_short  dev_addr,
/*in*/u_char   group_no,
/*out*/u_char  *type
);

extern int rdb_proc_get_bit_decs2
(
/*in*/u_short  dev_addr,
/*in*/u_char   group_no,
/*in*/u_char   entry_no,
/*in*/u_char   no,                        /*位编号 0起始*/
/*out*/u_char  *decs                      /*第no位的描述 最大长度40个字节*/ 
);

extern int rdb_proc_get_bits_decs2
(
/*in*/u_short  dev_addr,
/*in*/u_char   group_no,
/*in*/u_char   entry_no,
/*out*/u_char  *num,                      /*位串描述个数*/
/*out*/u_char  *decs                      /*位串描述数组 最多32个位 每个描述最大长度40个字节 数组长度必须是 32*40*/ 
);

extern int rdb_proc_get_prop_list_by_id2
(
/*in*/u_int     id,                       /*属性域id*/
/*out*/u_int    *num,                     /*属性数目*/
/*out*/u_int    *props                    /*属性id数组 最大50个属性*/
);

extern int rdb_proc_get_prop_list_by_name2
(
/*in*/u_char    *name,                    /*属性域名*/
/*out*/u_int    *num,                     /*属性数目*/
/*out*/u_int    *props                    /*属性id数组*/
);

extern int rdb_proc_get_prop_by_id2
(
/*in*/u_int     filed_id,                 /*属性域id*/     
/*in*/u_int     no,                       /*设备的顺序号 0起始*/ 
/*in*/u_int     prop_id,                  /*属性id*/            
/*out*/struct   PROP_DATA *prop_data
);

extern int rdb_proc_get_prop_by_name2
(
/*in*/u_char    *filed_name,              /*属性域名*/  
/*in*/u_int     no,                       /*设备的顺序号 0起始*/ 
/*in*/u_char    *prop_name,               /*属性名称 长度为40*/            
/*out*/struct   PROP_DATA *prop_data
);

extern int rdb_proc_set_prop_by_id2
(
/*in*/u_int     filed_id,                 /*属性域id*/     
/*in*/u_int     no,                       /*设备的顺序号 0起始*/ 
/*in*/u_int     prop_id,                  /*属性id*/            
/*in*/struct    PROP_DATA *prop_data
);

extern int rdb_proc_set_prop_by_name2
(
/*in*/u_char    *filed_name,              /*属性域名 长度为40*/  
/*in*/u_int     no,                       /*设备的顺序号 0起始*/ 
/*in*/u_char    *prop_name,               /*属性名称 长度为40*/            
/*in*/struct    PROP_DATA *prop_data
);

extern int rdb_proc_get_equip_num_by_id2
(
/*in*/u_int     filed_id,                 /*属性域id*/   
/*out*/u_int    *num                      /*属性数目*/
);

extern int rdb_proc_get_equip_num_by_name2
(
/*in*/u_char    *filed_name,              /*属性域名 长度为40*/  
/*out*/u_int    *num                      /*属性数目*/
);

extern int rdb_proc_manual_set2
(
/*in*/struct MANUAL_SET_DATA *set_data,         /*人工置数数据*/
/*out*/struct MANUAL_SET_RESULT *result
);

extern int rdb_proc_manual_clear2
(
/*in*/u_short   dev_addr, 
/*in*/u_char    group_no, 
/*in*/u_char    entry_no, 
/*out*/u_char   *result                   /*返回结构 CM_NO 失败  CM_YES 成功*/
);

extern int rdb_proc_manual_clear_dev2
(
/*in*/u_short   dev_addr,
/*out*/u_char   *result                   /*返回结构 CM_NO 失败  CM_YES 成功*/
);

extern int rdb_proc_manual_clear_all2
(
/*out*/u_char   *result                   /*返回结构 CM_NO 失败  CM_YES 成功*/
);

extern int rdb_proc_manual_clear_list2
(
/*in*/u_int     list_appid,               /*引用表的appid*/
/*in*/u_int     list_no,                  /*引用表号*/
/*out*/u_char   *result                   /*返回结构 CM_NO 失败  CM_YES 成功*/
);

extern int rdb_proc_get_manual_sta2
(
/*in*/u_short   dev_addr, 
/*in*/u_char    group_no, 
/*in*/u_char    entry_no, 
/*out*/u_char   *state   
);

extern int rdb_proc_dev_done_sta2
(
/*in*/u_short   dev_addr, 
/*out*/u_char   *state   
);

extern int rdb_proc_get_rdb_sta2
(
/*out*/u_char   *state   
);

extern int rdb_proc_get_entry_qds2
(
/*in*/u_short   dev_addr, 
/*in*/u_char    group_no, 
/*in*/u_char    entry_no, 
/*out*/u_char   *qds   
);

extern int rdb_proc_get_ym_group_no2
(
/*in*/u_short   dev_addr,
/*out*/u_char   *num,
/*out*/u_char   *group_no                 /*遥脉组号  最大10个*/
);

extern int rdb_proc_login_set_change2
(
/*in*/u_int     app_id,
/*in*/u_int     task_id,
/*in*/u_int     return_id,
/*in*/u_char    type
);

extern int rdb_proc_set_gps_sta2
(
/*in*/u_char    state
);

extern int rdb_proc_get_gps_sta2
(
/*out*/u_char   *state
);

extern int rdb_proc_get_cpu_info2
(
/*in*/u_short   dev_addr, 
/*out*/u_char   *cpu_num, 
/*out*/u_char   *cpu_no		
);

extern int rdb_proc_call_dir2
(
/*in*/u_int     app_id, 
/*in*/u_int     task_id, 
/*in*/u_short   dev_addr, 
/*in*/u_int     cmd_id, 									/*招唤命令标识，用于跟返回匹配 每个模块使用一个唯一ID*/
/*in*/u_char    type, 										/*文件类型  0:波形文件 1:配置文件 3-244:其他文件 255:所有文件*/
/*in*/u_int     name_len,	
/*in*/u_char    *dir_name,			
/*out*/int      *error_no 								/*响应结果 0:正确响应 1:正在等待上一次调用返回 2:其他*/	
);

extern int rdb_proc_call_dir_ack2
(
/*in*/u_short   dev_addr, 
/*in*/u_int     cmd_id, 									/*招唤命令标识，用于跟返回匹配*/
/*in*/int       result, 									/*响应结果 0:正确响应 1:不支持该命令 2:无所召唤内容 3:其他*/
/*in*/u_char    type, 										/*文件类型  0:波形文件 1:配置文件 3-244:其他文件 255:所有文件*/
/*in*/u_int     name_len,	
/*in*/u_char    *dir_name			
);

extern int rdb_proc_call_file2
(
/*in*/u_int     app_id, 
/*in*/u_int     task_id, 
/*in*/u_short   dev_addr, 
/*in*/u_int     cmd_id, 									/*招唤命令标识，用于跟返回匹配*/
/*in*/u_int     name_len,	
/*in*/u_char    *file_name,
/*out*/int      *error_no  								/*响应结果 0:正确响应 1:正在等待上一次调用返回 2:其他*/			
);

extern int rdb_proc_call_file_ack2
(
/*in*/u_short   dev_addr, 
/*in*/u_int     cmd_id, 									/*招唤命令标识，用于跟返回匹配,每个模块使用一个唯一ID*/
/*in*/int       result, 									/*响应结果 0:正确响应 1:不支持该命令 2:无所召唤内容 3:其他*/
/*in*/u_int     name_len,	
/*in*/u_char    *file_name			
);

extern int rdb_proc_get_no_in_list2
(
/*in*/u_int     list_appid,               /*引用表的appid*/
/*in*/u_int     list_no,                  /*引用表号*/
/*in*/u_int     index,                  	/*条目*/
/*out*/int     	*no												/*条目在应用表中的序号 >=0有效 -1未找到*/	
);

extern int rdb_proc_register_ykbs2
(
/*in*/u_int     appid,               			/*遥控源的appid*/
/*in*/u_int     yk_index,
/*in*/u_int     yx_index,                	/*关联遥信*/
/*in*/u_char    type,                  		/*1:遥控分 2遥控合 3遥控分合*/
/*in*/u_char   	condition									/*bit1=0:遥信分闭锁遥控  bit1>0:遥信合闭锁遥控 bit8=0:遥信无效闭锁遥控 bit8=1:遥信无效不闭锁遥控 */
);

extern  struct  SET_CHANGE_HOOK *  search_set_hook
(
/*in*/u_int     app_id,
/*in*/u_int     task_id,
/*in*/u_int     return_id
);

extern int register_exp_hook
(
/*in*/struct ELEMENT *dp, 
/*in*/u_char type,                  /*事件类型*/  
/*in*/void* object
);

extern  struct HOOK *search_hook_with_type(struct ELEMENT *dp,u_int app_id,u_int task_id,u_int return_id,u_char type);

extern  struct HOOK *search_hook_with_addr(struct ELEMENT *dp,u_int app_id,u_int task_id,u_int return_id);

extern  int  search_EntryNum(u_short dev_addr,u_char group,u_int app_id,u_int task_id,u_int return_id,u_char type);

extern  int  search_OneGroupEntryNum(u_int index,u_int app_id,u_int task_id,u_int return_id,u_char type);
//通过顺序号获得设备地址
u_short DevAddrFromSqno(u_int Sqno);

#endif                                        




