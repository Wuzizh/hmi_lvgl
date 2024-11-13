
#ifndef _ITF_RDB_H_
#define _ITF_RDB_H_
#include "sys_asdu.h"

#define SOFT_BUS_HEAD_LEN                 52        /*软总线报文头长度*/
#define RESP_HEAD_LEN                     8         /*返回参数结构的公共头长度*/
#define RDB_NET_MAX_MSG_LEN               10240      /*报文接口报文最大长度*/
#define RDB_ITF_MAX_GID_LEN               20        /*gid数据最大长度*/

#define RDB_APP_ID                        ((u_int)8193+sys_appid_segment)
#define RDB_APP_ID_B                      ((u_int)8193+sys_appid_segment_b)
#define RDB_YK_APP_ID                     ((u_int)8194+sys_appid_segment)
#define RDB_YK_APP_ID_B                   ((u_int)8194+sys_appid_segment_b)

#define RDB_GROUP_ID                      ((u_int)1)
#define RDB_YK_GROUP_ID                   ((u_int)10)

#define RDB_PROC_READ_YX                  ((u_int)1)
#define RDB_PROC_READ_YC                  ((u_int)2)
#define RDB_PROC_READ_YM                  ((u_int)3)
#define RDB_PROC_READ_YP                  ((u_int)4)
#define RDB_PROC_READ_YC_FLOAT            ((u_int)5)
#define RDB_PROC_GET_DEV_STA              ((u_int)6)
#define RDB_PROC_GET_SELF_DEV_STA         ((u_int)7)
#define RDB_PROC_SET_DEV_NET_STA          ((u_int)8)
#define RDB_PROC_SET_DEV_RUN_STA          ((u_int)9)  
#define RDB_PROC_GET_COM_STA              ((u_int)10)  
#define RDB_PROC_GET_SELF_COM_STA         ((u_int)11) 
#define RDB_PROC_SET_COM_STA              ((u_int)12)  
#define RDB_PROC_GET_CON_STA              ((u_int)13) 
#define RDB_PROC_GET_SELF_CON_STA         ((u_int)14) 
#define RDB_PROC_SET_CON_STA              ((u_int)15) 
#define RDB_PROC_GET_M_S_STA              ((u_int)16) 
#define RDB_PROC_GET_TIME                 ((u_int)17) 
#define RDB_PROC_SET_TIME                 ((u_int)18) 
#define RDB_PROC_DISPATCH_TOP             ((u_int)19) 
#define RDB_PROC_DISPATCH_BOTTOM          ((u_int)20)            
#define RDB_PROC_REGISTER_HOOK            ((u_int)21) 
#define RDB_PROC_REGISTER_DEVMSG          ((u_int)22) 
#define RDB_PROC_REGISTER_RELATE          ((u_int)23) 
#define RDB_PROC_ADD_LIST_OWNER           ((u_int)24) 
#define RDB_PROC_DELETE_LIST_OWNER        ((u_int)25) 
#define RDB_PROC_SEARCH_DISTUB            ((u_int)26) 
#define RDB_PROC_SEARCH_WITH_ACC          ((u_int)27) 
#define RDB_PROC_GET_RELATE               ((u_int)28)    
#define RDB_PROC_GET_FUNINF               ((u_int)29)    
#define RDB_PROC_READ_LIST                ((u_int)30)        
#define RDB_PROC_GET_LIST_NUM             ((u_int)31)   
#define RDB_PROC_REGISTER_LIST_HOOK       ((u_int)32) 
#define RDB_PROC_REGISTER_HOOKA           ((u_int)33)                  
#define RDB_PROC_CREATE_DEV_LIST          ((u_int)34)   
#define RDB_PROC_GET_REAL_ADDR            ((u_int)35)
#define RDB_PROC_GET_MAP_ADDR             ((u_int)36)
#define RDB_PROC_GET_GROUP_ENTRY          ((u_int)37)
#define RDB_PROC_GET_DEV_NUM              ((u_int)38)
#define RDB_PROC_REGISTER_DEV_STAT        ((u_int)39)
#define RDB_PROC_GET_DEV_ADDR             ((u_int)40)
#define RDB_PROC_GET_DATA_SYNCH           ((u_int)41)
#define RDB_PROC_GET_GROUP_NAME           ((u_int)42)     
#define RDB_PROC_GET_GROUP_TYPE           ((u_int)43)    
#define RDB_PROC_GET_BIT_DECS             ((u_int)44)  
#define RDB_PROC_GET_BITS_DECS            ((u_int)45)  
#define RDB_PROC_GET_PROP_LIST_BY_ID      ((u_int)46)  
#define RDB_PROC_GET_PROP_LIST_BY_NAME    ((u_int)47)  
#define RDB_PROC_GET_PROP_BY_ID           ((u_int)48) 
#define RDB_PROC_GET_PROP_BY_NAME         ((u_int)49) 
#define RDB_PROC_SET_PROP_BY_ID           ((u_int)50) 
#define RDB_PROC_SET_PROP_BY_NAME         ((u_int)51) 
#define RDB_PROC_GET_EQUIP_NUM_BY_ID      ((u_int)52) 
#define RDB_PROC_GET_EQUIP_NUM_BY_NAME    ((u_int)53) 
#define RDB_PROC_MANUAL_SET               ((u_int)54) 
#define RDB_PROC_MANUAL_CLEAR             ((u_int)55) 
#define RDB_PROC_MANUAL_CLEAR_DEV         ((u_int)56) 
#define RDB_PROC_MANUAL_CLEAR_ALL         ((u_int)57) 
#define RDB_PROC_MANUAL_CLEAR_LIST        ((u_int)58)
#define RDB_PROC_GET_MANUAL_STA           ((u_int)59)
#define RDB_PROC_GET_YM_GROUP_NO          ((u_int)60)
#define RDB_PROC_SEND_RDB_SYN_DATA        ((u_int)61)
#define RDB_PROC_DEV_DONE_STA             ((u_int)62)
#define RDB_PROC_GET_RDB_STA              ((u_int)63)
#define RDB_PROC_GET_ENTRY_QDS            ((u_int)64)
#define RDB_PROC_LOGIN_SET_CHANGE         ((u_int)65)
#define RDB_PROC_SET_HOOK_DATA            ((u_int)66)
#define RDB_PROC_SET_DEVS_NET_STA					((u_int)67)
#define RDB_PROC_GET_ALL_DEV_STA          ((u_int)68)
#define RDB_PROC_GET_ALL_CONN_STA         ((u_int)69)
#define RDB_PROC_SET_GPS_STA          		((u_int)70)
#define RDB_PROC_GET_GPS_STA          		((u_int)71)
#define RDB_PROC_SEND_RDB_SYN_CON_STA     ((u_int)72)
#define RDB_PROC_SEND_RDB_SYN_DEV_STA     ((u_int)73)
#define RDB_PROC_REGISTER_MON_MSG					((u_int)74)
#define RDB_PROC_WRITE_YX									((u_int)75)
#define RDB_PROC_WRITE_YC									((u_int)76)
#define RDB_PROC_WRITE_YM									((u_int)77)
#define RDB_PROC_GET_CPU_INFO							((u_int)78)


/*----异步返回ID------*/
#define RDB_PROC_COS_HOOK_MSG             ((u_int)79)
#define RDB_PROC_COS_DATA_HOOK_MSG        ((u_int)80)
#define RDB_PROC_PERIOD_HOOK_MSG          ((u_int)81)
#define RDB_PROC_DEV_STA_MSG              ((u_int)82)
#define RDB_PROC_CONN_STA_MSG             ((u_int)83)
#define RDB_PROC_MON_MSG									((u_int)84)

/*----文件传输接口-----*/
#define RDB_PROC_CALL_DIR									((u_int)85)
#define RDB_PROC_CALL_DIR_ACK							((u_int)86)
#define RDB_PROC_CALL_FILE								((u_int)87)
#define RDB_PROC_CALL_FILE_ACK						((u_int)88)
#define RDB_PROC_GET_NO_IN_LIST						((u_int)89)
/*----注册遥控闭锁条件-----*/
#define RDB_PROC_REGISTER_YKBS						((u_int)90)

#define  NONE_TYPE       0x00
#define  COS_TYPE        0x01
#define  PERIOD_TYPE     0x02
#define  ASK_TYPE        0x04
#define  FILTER_COS_TYPE 0x08         /*有条件变化上送 */
#define  COS_DATA_TYPE   0x10         /*变位上送,返回数据为数据结构*/
#define  EXPCALC_TYPE    0x20         /*复合信号 */    
#define  YP_CHG_TYPE     0x40
#define  ORIGIN_GROUP_TYPE    0x80         /*以原始组号上送 */ 

#define  OV              0x01         /*0:无溢出  1:溢出*/
#define  BL              0x10         /*0:未闭锁  1:闭锁*/
#define  SB              0x20         /*0:未取代  1:取代*/
#define  NT              0x40         /*0:当前值  1:非当前值*/
#define  IV              0x80         /*0:有效    1:无效*/


enum   GROUP_TYPE{YC,YX,YM,YK,YT,YP,YXYK,OTHER};
enum   RDB_RET_CODE{RDB_RET_NOTCARE, RDB_RET_INACTIVE, RDB_RET_NORMAL, RDB_RET_DISCONN, RDB_RET_CHKERR};
enum   {RDB_INACTIVE,RDB_ACTIVE};
enum   {RDB_MASTER,RDB_SLAVE};
enum   {RDB_SINGLE,RDB_DOUBLE};
enum   {RDB_COS_HOOK,RDB_PERIOD_HOOK};
enum DEV_STA{                         /*装置运行状态*/
  DEV_STA_STOP,                       /*停运*/
  DEV_STA_RUN,                        /*投运*/
  DEV_STA_REPAIR,                     /*检修*/
  DEV_STA_OTHER                       /*其他*/
};                                    
                                      
enum RDB_ERROR_NO                     
{                                     
  RDB_ERR_NONE,                       /*没有错误*/
  RDB_ERR_NO_DEV,                     /*找不到装置*/
  RDB_ERR_NO_GROUP,                   /*找不到组*/
  RDB_ERR_NO_ENTRY,                   /*找不到条目*/
  RDB_ERR_DEV_NOT_DONE,               /*装置数据未建立完成*/
  RDB_ERR_GROUP_NOT_DONE,             /*组数据未建立完成*/
  RDB_ERR_ENTRY_NOT_DONE,             /*条目数据未建立完成*/
  RDB_ERR_UNKNOW,                     /*未知错误*/
};

enum  RDB_EVENT_TYPE{ 
  YC_CH,                              /*遥测变位*/
  YX_CH,                              /*遥信变位*/
  YM_CH,                              /*遥脉变位*/
  YP_CH,                              /*遥步变位*/
  YC_SOE,                             /*遥测事件*/
  YX_SOE,                             /*遥信事件*/
  YM_SOE,                             /*遥脉事件*/
  YP_SOE,                             /*遥步事件*/
  SET_CH,                             /*定值变化*/
  OTHER_EVENT,
  NOT_SAVE
};

#pragma pack(push,1)
struct  INDEX_GDD_DATA                /*按引用表读的返回报文结构*/
{
  u_int   len;                        /*从addr 开始计算长度*/
  u_int   app_id;                     /*规约的APP_ID*/
  u_int   list_no;                    /*引用表号*/
  u_int   begin_no;                   /*条目数*/  /*从0开始编号*/
  u_short num;                        /*读取数目*//*最高位表示后续状态位 0:没有后续数据 1:有后续数据*/
  u_char  addr[2];                    /*装置地址*/
  u_char  gin[2];
  u_char  kod;  
  u_char  gdd[3];                                                                               
  u_char  gid[1];   
};

struct SB_HEAD
{
  u_int source_app_id;                /*源appid*/
  u_int source_task_id;               /*源taskid*/
  u_int destination_app_id;           /*目的appid*/
  u_int destination_task_id;          /*目的taskid*/
} ;

typedef struct SB_HEAD SB_HEAD;

struct PROP_DATA                                                                                 
{          
  u_int   id;                         /*属性id*/                                                                   
  u_char  flag;                       /*有效标志*/                                                            
  u_char  gdd[3];                                                                               
  u_char  gid[1];                                                                                 
};   


/*人工置数的数据*/
struct MANUAL_SET_ENTRY                                                                                 
{          
  u_short dev_addr;
  u_char  group_no;
  u_char  entry_no;                                                               
  u_char  gdd[3];                                                                               
  u_char  gid[RDB_ITF_MAX_GID_LEN];                                                                                 
};  

struct MANUAL_SET_DATA                                                                                 
{          
  u_int   num;                                                                                         
  struct MANUAL_SET_ENTRY set_entry[1];                                                                             
};   

/*人工置数返回结果*/
struct MANUAL_SET_RESULT                                                                                 
{          
  u_int   num;                                                                                         
  u_char  result[1];                                                                                           
};  


struct DEV_NET_STA                                                                                 
{ 
	u_short addr;
	u_char no;              						/*0x01:A网  0x02:B网   0x03: 双网(装置状态) */
	u_char state;
};  

struct DEVS_NET_STA                                                                                 
{ 
	u_int  num;
	struct DEV_NET_STA dev_net_sta[1];
};  

struct DEV_STA_ENTRY                                                                                 
{ 
  u_short dev_addr;
  u_short dev_no;
  u_char state;
}; 

struct DEVS_STA                                                                                 
{ 
  u_int  num;
  struct DEV_STA_ENTRY dev_sta[1];
}; 


struct CONN_STA_ENTRY                                                                                 
{ 
	u_char type;											 /*  1:网络  0：串口*/
  u_char board_no;
  u_char con_no;
  u_char state;
}; 

struct CONN_STA                                                                                 
{ 
  u_int  num;
  struct CONN_STA_ENTRY conn_sta[1];
}; 
#pragma pack(pop)
/**********************接口函数声明 *******************/

/*实时数据库接口初始化*/
extern int rdb_proc_init(void);
/*设置装置通信状态上送方式*/
extern int rdb_proc_set_devStaMode(u_char mode);
/*读单个装置状态(包括双网通讯状态和运行状态)*/
extern int rdb_proc_get_dev_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_short addr,
/*out*/u_char *state          /*bit0-3:装置运行状态  bit4-5:A网通讯状态(dpi) bit6-7:B网通讯状态(dpi)*/
);

/*读所有装置状态(包括双网通讯状态和运行状态)*/
extern int rdb_proc_get_all_dev_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   period					/*上送周期(ms) 0:单次上送*/
);

/*读所有连接状态(包括网络状态和串口状态)*/
extern int rdb_proc_get_all_conn_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   period					/*上送周期(ms) 0:单次上送*/
);

/*写单个装置通讯状态*/
extern int rdb_proc_set_dev_net_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_short addr,
/*in*/u_char no,              /*0x01:A网  0x02:B网   0x03: 双网(装置状态) */
/*in*/u_char state
);

/*写多个装置通讯状态*/
extern int rdb_proc_set_devs_net_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/struct  DEVS_NET_STA * devs_sta
);

/*写单个装置运行状态*/
extern int rdb_proc_set_dev_run_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_short addr,
/*in*/u_char state
);
/*读单个串口通讯状态*/
extern int rdb_proc_get_com_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_char board_no,
/*in*/u_char com_no,
/*out*/u_char *state
);
/*写单个串口通讯状态*/
extern int rdb_proc_set_com_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_char board_no,
/*in*/u_char com_no,
/*in*/u_char state
);
/*读单个网络口通讯状态*/
extern int rdb_proc_get_con_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_char board_no,
/*in*/u_char con_no,
/*out*/u_char *state
);
/*写单个网络口通讯状态*/
extern int rdb_proc_set_con_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_char board_no,
/*in*/u_char con_no,
/*in*/u_char state
);

/*获取当前通讯装置的主备运行状态*/
extern int rdb_proc_get_M_S_sta
(
/*in*/SB_HEAD *sb_head,
/*out*/u_char *state
);


/*获取当前时间*/
extern int rdb_proc_get_time
(
/*in*/SB_HEAD *sb_head,
/*out*/struct SYS_TIME *t
);

/*设置当前时间*/  
extern int rdb_proc_set_time
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   appid,                      /*时间源的appid*/
/*in*/struct SYS_TIME *t,
/*in*/int  period                         /*对时周期*/
);  



/*-----读四遥信息的简单接口-----*/     

/*读遥信*/
extern int rdb_proc_readYX
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   appid,                      /*规约的APP_ID*/
/*in*/u_int   list_no,                    /*引用表号*/
/*in*/u_int   begin_no,                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num,                        /*读取数目*/
/*out*/u_int  *back_num,                  /*返回条目数目*/
/*out*/u_char   *data
);

/*读遥测*/
extern int rdb_proc_readYC
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   appid,                      /*规约的APP_ID*/
/*in*/u_int   list_no,                    /*引用表号*/
/*in*/u_int   begin_no,                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num,                        /*读取数目*/
/*out*/u_int  *back_num,                  /*返回条目数目*/
/*out*/u_short  *data
);

/*读遥脉*/
extern int rdb_proc_readYM
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   appid,                      /*规约的APP_ID*/
/*in*/u_int   list_no,                    /*引用表号*/
/*in*/u_int   begin_no,                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num,                        /*读取数目*/
/*out*/u_int  *back_num,                  /*返回条目数目*/
/*out*/u_char  *data                      /*num*5*/
);

/*读遥步*/
extern int rdb_proc_readYP
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   appid,                      /*规约的APP_ID*/
/*in*/u_int   list_no,                    /*引用表号*/
/*in*/u_int   begin_no,                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num,                        /*读取数目*/
/*out*/u_int  *back_num,                  /*返回条目数目*/
/*out*/u_char   *data 
);

/*读遥测(按浮点数读)*/
extern int rdb_proc_readYC_float
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   appid,                      /*规约的APP_ID*/
/*in*/u_int   list_no,                    /*引用表号*/
/*in*/u_int   begin_no,                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num,                        /*读取数目*/
/*out*/u_int  *back_num,                  /*返回条目数目*/
/*out*/float  *data,
/*out*/u_char *quality										/*品质描述*/
);

/*读取引用表的引用条目数目*/
extern int rdb_proc_get_list_num
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   app_id,                     /*规约的APP_ID*/
/*in*/u_int   list_no,                    /*引用表号*/
/*out*/u_short   *num                     /*引用表条目数*/
);

/*按引用表读*/
extern int rdb_proc_read_list
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   app_id,                     /*规约的APP_ID*/
/*in*/u_int   list_no,                    /*引用表号*/
/*in*/u_int   begin_no,                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num,                        /*读取数目*/
/*in*/u_char  kod,
/*in*/u_short len,                        /*缓冲的长度*/
/*out*/u_char   *data                     
);


/*获取关联条目*/
extern int rdb_proc_get_relate
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   index,
/*out*/u_int* relate
);


/*获取FUN INF*/
extern int rdb_proc_getFunInf
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   index,
/*out*/u_char *fun,
/*out*/u_char *inf
);


/*注册关联条目*/
extern int rdb_proc_registerRelate
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int index,
/*in*/u_int relate
); 

extern int rdb_proc_register_hook
(
/*in*/SB_HEAD *sb_head,
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

/*注册一个引用表的所有条目的hook*/
extern int rdb_proc_register_list_hook
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int app_id,                 /*注册者的app_id*/
/*in*/u_int task_id,                /*注册者的task_id*/
/*in*/u_int return_id,              /*注册者的return_id*/
/*in*/u_int list_app_id,            /*引用表的app_id*/
/*in*/u_short list_no,              /*引用表的编号*/
/*in*/u_char type,                  /*事件类型*/  /* 0x01:变化 */
                                                  /* 0x02:定时  */  
                                                  /* 0x04:问答  */  
                                                  /* 0x08:有条件变化上送 */   
/*in*/u_short send_period,  
/*in*/u_short len,
/*in*/u_char* expression            /*条件变化上送表达式*/ 
);

/*注册所有条目的事件*/
/*引用表对应与注册者的app_id,list_no固定为0xffff*/
extern int rdb_proc_register_hookA
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int  app_id,
/*in*/u_int  task_id,
/*in*/u_int  return_id,
/*in*/u_char list_type,
/*in*/u_char hook_type,
/*in*/u_short send_period,  
/*in*/u_short len,
/*in*/u_char* expression            /*条件变化上送表达式*/ 
);

/*注册引用表引用对象*/
extern int rdb_proc_add_list_owner
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int source_appid,   
/*in*/u_int source_taskid,                       
/*in*/u_int return_id,
/*in*/u_int appid,                        /*规约的APP_ID*/                
/*in*/u_short list_no                     /*引用表号*/                
);    

/*删除引用表引用对象*/
extern int rdb_proc_delete_list_owner
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int source_appid,   
/*in*/u_int source_taskid,                       
/*in*/u_int return_id,
/*in*/u_int appid,                        /*规约的APP_ID*/
/*in*/u_short list_no                     /*引用表号*/
);  

/*----装置库查询接口 ---------*/
extern int rdb_proc_search_dev_type
(
/*in*/SB_HEAD *sb_head,
/*in*/u_short addr
);

extern int rdb_proc_search_dummy_addr
(
/*in*/SB_HEAD *sb_head,
/*in*/u_short addr
);

extern int rdb_proc_search_real_addr
(
/*in*/SB_HEAD *sb_head,
/*in*/int addr
);

/*---扰动数据说明查询接口 ----*/

/*查找扰动数据说明*/
extern int rdb_proc_search_distub
(
/*in*/SB_HEAD *sb_head,
/*in*/u_short addr,
/*in*/u_char  fun,
/*in*/u_char  inf,
/*out*/u_int  *index, 
/*out*/u_char   *description
);  

/*查找扰动数据说明*/
extern int rdb_proc_search_with_acc
(
/*in*/SB_HEAD *sb_head,
/*in*/u_short addr,
/*in*/u_char  acc,
/*out*/u_int  *index, 
/*out*/u_char   *dimension,
/*out*/u_char   *description,
/*out*/u_char   *phase
);  

/*------- 报文接口 -----------*/
extern int rdb_proc_dispatch_top
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   return_id,
/*in*/u_short len,
/*in*/u_char  *buf
);

extern int rdb_proc_dispatch_bottom
(
/*in*/SB_HEAD *sb_head,
/*in*/u_short len,
/*in*/u_char  *buf
);


/*根据实际引用表条目查找组号条目号*/
extern int rdb_proc_get_group_entry
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int app_id,                       /*引用表的app_id*/
/*in*/u_short list_no,                    /*引用表号*/              
/*in*/u_short no,                         /*引用序号*/  
/*out*/u_int *index                 
);

/*获取装置的个数，包括虚装置*/
extern int rdb_proc_get_dev_num
(
/*in*/SB_HEAD *sb_head,
/*out*/u_short *num                 
);

/*注册装置状态消息*/
extern int rdb_proc_register_dev_stat
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int  app_id,
/*in*/u_int  task_id,
/*in*/u_int  return_id
);

/*注册故障信息报文*/
extern int rdb_proc_register_mon_msg
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int  app_id,
/*in*/u_int  task_id,
/*in*/u_int  return_id
);

/*根据装置no获取装置地址*/
extern int rdb_proc_get_dev_addr
(
/*in*/SB_HEAD *sb_head,
/*in*/u_short  dev_no,
/*out*/u_short  *real_addr,
/*out*/u_short  *dummy_addr
);


/*同步报文查询*/
extern int rdb_proc_get_data_synch
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   app_id,
/*in*/u_int   task_id,
/*in*/u_int   object_id,
/*in*/struct  EXT_ASDU21 *asdu_p,         /*装置真实地址*/
/*in*/u_char  filter_flag,                /*过滤标记  =YES:过滤方式*/
/*in*/u_short max_len,                    /*运行返回报文最大长度*/
/*out*/int    *error_no,                  /* 0:未知  
                                             1:该装置不存在 
                                             2:该装置数据未建立完成 
                                             3:
                                                         */
/*out*/u_short *len,                      /*asdu报文长度*/
/*out*/u_char  *buf                       /*asdu报文*/
);


/*获取组标题*/
extern int rdb_proc_get_group_name
(
/*in*/SB_HEAD  *sb_head,
/*in*/u_short  dev_addr,
/*in*/u_char   group_no,
/*out*/u_char  *group_name                /*最大长度40个字节*/
);

/*获取组类型*/
extern int rdb_proc_get_group_type
(
/*in*/SB_HEAD  *sb_head,
/*in*/u_short  dev_addr,
/*in*/u_char   group_no,
/*out*/u_char  *type
);

/*获取位串描述*/
extern int rdb_proc_get_bit_decs
(
/*in*/SB_HEAD  *sb_head,
/*in*/u_short  dev_addr,
/*in*/u_char   group_no,
/*in*/u_char   entry_no,
/*in*/u_char   no,                        /*位编号 0起始*/
/*out*/u_char  *decs                      /*第no位的描述 最大长度40个字节*/ 
);

/*获取位串描述(一组)*/
extern int rdb_proc_get_bits_decs
(
/*in*/SB_HEAD  *sb_head,
/*in*/u_short  dev_addr,
/*in*/u_char   group_no,
/*in*/u_char   entry_no,
/*out*/u_char   *num,                     /*位串描述个数*/
/*out*/u_char  *decs                      /*位串描述数组 最多32个位 每个描述最大长度40个字节 数组长度必须是 32*40*/ 
);
/*---------配置信息-----------*/

/*通过id获得属性列表*/
extern int rdb_proc_get_prop_list_by_id
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_int     id,                       /*属性域id*/
/*out*/u_int    *num,                     /*属性数目*/
/*out*/u_int    *props                    /*属性id数组 最大50个属性*/
);

/*通过属性域名获得属性列表*/
extern int rdb_proc_get_prop_list_by_name
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_char    *name,                    /*属性域名 长度为40*/
/*out*/u_int    *num,                     /*属性数目*/
/*out*/u_int    *props                    /*属性id数组*/
);

/*通过id获得属性*/
extern int rdb_proc_get_prop_by_id
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_int     filed_id,                 /*属性域id*/     
/*in*/u_int     no,                       /*设备的顺序号 0起始*/ 
/*in*/u_int     prop_id,                  /*属性id*/            
/*out*/struct   PROP_DATA *prop_data
);

/*通过名称获得属性*/
extern int rdb_proc_get_prop_by_name
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_char    *filed_name,              /*属性域名 长度为40*/  
/*in*/u_int     no,                       /*设备的顺序号 0起始*/ 
/*in*/u_char    *prop_name,               /*属性名 长度为40*/            
/*out*/struct   PROP_DATA *prop_data
);

/*通过id设置属性*/
extern int rdb_proc_set_prop_by_id
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_int     filed_id,                 /*属性域id*/     
/*in*/u_int     no,                       /*设备的顺序号 0起始*/ 
/*in*/u_int     prop_id,                  /*属性id*/            
/*in*/struct    PROP_DATA *prop_data
);

/*通过名称设置属性*/
extern int rdb_proc_set_prop_by_name
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_char    *filed_name,              /*属性域名 长度为40*/  
/*in*/u_int     no,                       /*设备的顺序号 0起始*/ 
/*in*/u_char    *prop_name,               /*属性名称 长度为40*/            
/*in*/struct    PROP_DATA *prop_data
);

/*通过id获得一次设备数目*/
extern int rdb_proc_get_equip_num_by_id
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_int     filed_id,                 /*属性域id*/   
/*out*/u_int    *num                      /*属性数目*/
);

/*通过名称获得一次设备数目*/
extern int rdb_proc_get_equip_num_by_name
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_char    *filed_name,              /*属性域名 长度为40*/  
/*out*/u_int    *num                      /*属性数目*/
);

/*人工置数*/
extern int rdb_proc_manual_set
(
/*in*/SB_HEAD   *sb_head,
/*in*/struct MANUAL_SET_DATA *set_data,         /*人工置数数据*/
/*out*/struct MANUAL_SET_RESULT *result
);

/*按条目清除人工置数*/
extern int rdb_proc_manual_clear
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_short   dev_addr, 
/*in*/u_char    group_no, 
/*in*/u_char    entry_no, 
/*out*/u_char   *result                   /*返回结构 NO 失败  YES 成功*/
);

/*按装置清除人工置数*/
extern int rdb_proc_manual_clear_dev
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_short   dev_addr,
/*out*/u_char   *result                   /*返回结构 NO 失败  YES 成功*/
);

/*清除全部人工置数*/
extern int rdb_proc_manual_clear_all
(
/*in*/SB_HEAD   *sb_head,
/*out*/u_char   *result                   /*返回结构 NO 失败  YES 成功*/
);             

/*按引用表清除人工置数*/
extern int rdb_proc_manual_clear_list
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_int     list_appid,               /*引用表的appid*/
/*in*/u_int     list_no,                  /*引用表号*/
/*out*/u_char   *result                   /*返回结构 NO 失败  YES 成功*/
);    



/*获取条目的人工置数状态*/
extern int rdb_proc_get_manual_sta
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_short   dev_addr, 
/*in*/u_char    group_no, 
/*in*/u_char    entry_no, 
/*out*/u_char   *state   
);


/*获取遥脉组号*/
extern int rdb_proc_get_ym_group_no
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_short   dev_addr,
/*out*/u_char   *num,
/*out*/u_char   *group_no                 /*遥脉组号  最大10个*/
);



/*获取装置建库完成状态*/
extern int rdb_proc_dev_done_sta
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_short   dev_addr, 
/*out*/u_char   *state   
);



/*获取数据库模块就绪状态*/
extern int rdb_proc_get_rdb_sta
(
/*in*/SB_HEAD   *sb_head,
/*out*/u_char   *state   
);

/*获取品质描述*/
extern int rdb_proc_get_entry_qds
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_short   dev_addr, 
/*in*/u_char    group_no, 
/*in*/u_char    entry_no, 
/*out*/u_char   *qds   
);

/*注册定值变化上送*/
extern int rdb_proc_login_set_change
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_int     app_id,
/*in*/u_int     task_id,
/*in*/u_int     return_id,
/*in*/u_char    type
);

/*设置GPS状态*/
extern int rdb_proc_set_gps_sta
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_char    state
);

/*获取GPS状态*/
extern int rdb_proc_get_gps_sta
(
/*in*/SB_HEAD   *sb_head,
/*out*/u_char   *state
);

/*获取装置CPU信息*/
extern int rdb_proc_get_cpu_info
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*out*/u_char   *cpu_num, 
/*out*/u_char   *cpu_no		
);

#if 0
/*遥信入库*/
extern int rdb_proc_write_yx
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     begin_no, 
/*in*/u_int     num, 
/*in*/u_char    *data
);

/*遥信入库(打包）*/
extern int rdb_proc_write_packed_yx
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     begin_no, 
/*in*/u_int     num, 
/*in*/u_int     byte_num, 
/*in*/u_char    *data
);

/*遥测入库*/
extern int rdb_proc_write_yc
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     begin_no, 
/*in*/u_int     num, 
/*in*/u_char    *data	
);

/*遥脉入库*/
extern int rdb_proc_write_ym
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     begin_no, 
/*in*/u_int     num, 
/*in*/u_char    *data		
);


#endif


/*召唤文件目录*/
extern int rdb_proc_call_dir
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     cmd_id, 									/*招唤命令标识，用于跟返回匹配 每个模块使用一个唯一ID*/
/*in*/u_char    type, 										/*文件类型  0:波形文件 1:配置文件 3-244:其他文件 255:所有文件*/
/*in*/u_int     name_len,	
/*in*/u_char    *dir_name,			
/*out*/int      *error_no 								/*响应结果 0:正确响应 1:正在等待上一次调用返回 2:其他*/	
);

/*响应召唤文件目录*/
extern int rdb_proc_call_dir_ack
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     cmd_id, 									/*招唤命令标识，用于跟返回匹配*/
/*in*/int       result, 									/*响应结果 0:正确响应 1:不支持该命令 2:无所召唤内容 3:其他*/
/*in*/u_char    type, 										/*文件类型  0:波形文件 1:配置文件 3-244:其他文件 255:所有文件*/
/*in*/u_int     name_len,	
/*in*/u_char    *dir_name			
);

/*召唤文件*/
extern int rdb_proc_call_file
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     cmd_id, 									/*招唤命令标识，用于跟返回匹配*/
/*in*/u_int     name_len,	
/*in*/u_char    *file_name,
/*out*/int      *error_no 								/*响应结果 0:正确响应 1:正在等待上一次调用返回 2:其他*/			
);

/*响应召唤文件*/
extern int rdb_proc_call_file_ack
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     cmd_id, 									/*招唤命令标识，用于跟返回匹配,每个模块使用一个唯一ID*/
/*in*/int       result, 									/*响应结果 0:正确响应 1:不支持该命令 2:无所召唤内容 3:其他*/
/*in*/u_int     name_len,	
/*in*/u_char    *file_name			
);

/*获取条目在应用表中的序号*/
extern int rdb_proc_get_no_in_list
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_int     list_appid,               /*引用表的appid*/
/*in*/u_int     list_no,                  /*引用表号*/
/*in*/u_int     index,                  	/*条目*/
/*out*/int     	*no												/*条目在应用表中的序号 >=0有效 -1未找到*/	
);

/*注册遥控闭锁条件*/
extern int rdb_proc_register_ykbs
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_int     appid,               			/*遥控源的appid*/
/*in*/u_int     yk_index,                 
/*in*/u_int     yx_index,                 /*关联遥信*/
/*in*/u_char    type,                  		/*1:遥控分 2遥控合 3遥控分合*/
/*in*/u_char   	condition									/*bit1=0:遥信分闭锁遥控  bit1>0:遥信合闭锁遥控 bit8=0:遥信无效闭锁遥控 bit8=1:遥信无效不闭锁遥控 */
);

extern	struct	SYS_INDEX_LIST *sys_createIndexlist(struct SYS_STRSTREAM *strp,u_int app_id,u_int  task_id,u_int user_id,int event_type);

/************************参数结构*************************/
#pragma pack(push,1)
/*------------------------*/
struct READ_YX_REQ                        /*读遥信输入参数结构*/
{
/*in*/u_int   appid;                      /*规约的APP_ID*/
/*in*/u_int   list_no;                    /*引用表号*/
/*in*/u_int   begin_no;                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num;                        /*读取数目*/
};

struct READ_YX_RESP                       /*读遥信返回参数结构*/
{
/*out*/u_int  back_num;                   /*返回条目数目*/
/*out*/u_char   data[1];
};

/*------------------------*/
struct READ_YC_REQ                        /*读遥测输入参数结构*/
{
/*in*/u_int   appid;                      /*规约的APP_ID*/
/*in*/u_int   list_no;                    /*引用表号*/
/*in*/u_int   begin_no;                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num;                        /*读取数目*/
};

struct READ_YC_RESP                       /*读遥测返回参数结构*/
{
/*out*/u_int  back_num;                   /*返回条目数目*/
/*out*/u_short  data[1];
};

/*------------------------*/
struct READ_YM_REQ                        /*读遥脉输入参数结构*/
{
/*in*/u_int   appid;                      /*规约的APP_ID*/
/*in*/u_int   list_no;                    /*引用表号*/
/*in*/u_int   begin_no;                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num;                        /*读取数目*/
};

struct READ_YM_RESP                       /*读遥脉返回参数结构*/
{
/*out*/u_int  back_num;                   /*返回条目数目*/
/*out*/u_char  data[1];
};

/*------------------------*/
struct READ_YP_REQ                        /*读遥步输入参数结构*/
{
/*in*/u_int   appid;                      /*规约的APP_ID*/
/*in*/u_int   list_no;                    /*引用表号*/
/*in*/u_int   begin_no;                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num;                        /*读取数目*/
};

struct READ_YP_RESP                       /*读遥步返回参数结构*/
{
/*out*/u_int  back_num;                   /*返回条目数目*/
/*out*/u_char   data[1];
};

/*------------------------*/
struct READ_YC_FLOAT_REQ                  /*读遥测输入参数结构*/
{
/*in*/u_int   appid;                      /*规约的APP_ID*/
/*in*/u_int   list_no;                    /*引用表号*/
/*in*/u_int   begin_no;                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num;                        /*读取数目*/
};

struct READ_YC_FLOAT_RESP                 /*读遥测返回参数结构*/
{
/*out*/u_int  back_num;                   /*返回条目数目*/
/*out*/u_char data[1];
};
/*------------------------*/

struct READ_LIST_REQ                      /*按引用表读输入参数*/
{
/*in*/u_int   app_id;                     /*规约的APP_ID*/
/*in*/u_int   list_no;                    /*引用表号*/
/*in*/u_int   begin_no;                   /*条目数*/  /*从0开始编号*/
/*in*/u_int   num;                        /*读取数目*/
/*in*/u_char  kod;
/*in*/u_short len;                        /*缓冲的长度*/
};

struct READ_LIST_RESP                     /*按引用表读输出参数*/
{
/*out*/struct INDEX_GDD_DATA  data; 
};
/*------------------------*/

struct DISPATCH_TOP_REQ                   /*下发报文输入参数结构*/                                                                        
{                                                                                                               
/*in*/u_int   app_id;                                                                                           
/*in*/u_int   task_id;            
/*in*/u_int   return_id;                                                                          
/*in*/u_short len;                                                                                              
/*in*/u_char    buf[1];                                                                                         
};           

struct DISPATCH_TOP_RESP                  /*返回报文参数结构*/                                                                        
{                                                                                                               
/*out*/u_int  return_id;   
/*out*/u_short  len;                                                                                      
/*out*/u_char   buf[1];                                                                                          
};                                                                             
/*------------------------*/                                                                                    
                                                                                                                
struct DISPATCH_BOTTOM_REQ                /*上发报文输入参数结构*/                                                                        
{                                                                                                               
/*in*/u_short len;                                                                                              
/*in*/u_char    buf[1];                                                                                          
};       

struct DISPATCH_BOTTOM_RESP               /*返回报文参数结构*/                                                                        
{                      
/*out*/u_short  len;                                                                                           
/*out*/u_char   buf[1];                                                                                            
};                                                                                     
/*------------------------*/                                                                                    
                                                                                                                
struct REGISTER_HOOK_REQ                  /*注册事件*/                                                                        
{    
/*in*/u_int app_id;                       /*注册者的app_id*/
/*in*/u_int task_id;                      /*注册者的task_id*/
/*in*/u_int return_id;                    /*注册者的return_id*/
/*in*/u_int list_app_id;                  /*引用表的app_id*/
/*in*/u_short list_no;                    /*引用表的编号*/
/*in*/u_short no;                         /*引用表中的条目编号,0开始*/
/*in*/u_short send_period;                /*周期上送时间*/
/*in*/u_char type;                        /*事件类型*/  /* 0x01:变化 */
                                                        /* 0x02:定时  */  
                                                        /* 0x04:问答  */  
                                                        /* 0x08:有条件变化上送 */   
/*in*/u_short len;                        /*条件上送表达式的长度*/
/*in*/u_char expression[1];               /*条件上送表达式*/
};                                                                                         
/*------------------------*/   

struct REGISTER_HOOKA_REQ                 /*注册全部事件*/                                                                        
{    
/*in*/u_int  app_id;
/*in*/u_int  task_id;
/*in*/u_int  return_id;
/*in*/u_char list_type;
/*in*/u_char hook_type;
/*in*/u_short send_period;  
/*in*/u_short len;
/*in*/u_char expression[1];               /*条件变化上送表达式*/ 
};                                                                                         
/*------------------------*/  
                                                                            
                                                                                                                
struct REGISTER_DEV_MSG_REQ               /*注册装置消息*/                                                                        
{                                                                                                               
/*in*/u_int app_id;
/*in*/u_int task_id;
/*in*/u_short dev_addr;    
/*in*/u_char type;                        /*接受遥控类型 0:asdu10   1:asdu64 */                                                                           
};                 

                                                                          
/*------------------------*/                                                                                    
                                                                                                                
struct REGISTER_RELATE_REQ                /*注册关联条目*/                                                                        
{                                                                                                               
/*in*/u_int index;                                                                                              
/*in*/u_int relate;                                                                                             
};                                                                                         
/*------------------------*/                                                                                    
                                                                                                                
struct ADD_LIST_OWNER_REQ                                                                                         
{
/*in*/u_int source_appid;   
/*in*/u_int source_taskid;                      
/*in*/u_int return_id;
/*in*/u_int appid;                        /*规约的APP_ID*/                
/*in*/u_short list_no;                    /*引用表号*/                
};
/*------------------------*/          

struct DELETE_LIST_OWNER_REQ                    
{
/*in*/u_int source_appid;   
/*in*/u_int source_taskid;                       
/*in*/u_int return_id;
/*in*/u_int appid;                        /*规约的APP_ID*/
/*in*/u_short list_no;                    /*引用表号*/  
};
/*------------------------*/  

  
struct SET_STA_REQ                        /*写通讯状态*/
{
/*in*/u_char board_no;
/*in*/u_char no;
/*in*/u_char state;
};
/*------------------------*/  
  
struct SET_DEV_NET_STA_REQ                /*写装置通讯状态*/
{
/*in*/u_short addr;
/*in*/u_char no;                          /*0x01:A网  0x02:B网   0x03: 双网(装置状态) */
/*in*/u_char state;
};
/*------------------------*/  

struct SET_DEVS_NET_STA_REQ               /*写多装置通讯状态*/
{
/*in*/struct  DEVS_NET_STA devs_sta;
};
/*------------------------*/  

struct SET_DEV_RUN_STA_REQ                /*写装置运行状态*/
{
/*in*/u_short addr;
/*in*/u_char state;
};
/*------------------------*/  

struct GET_STA_REQ                        /*读通讯状态*/
{
/*in*/u_char board_no;  
/*in*/u_char no;
};

struct GET_STA_RESP                       
{
/*out*/u_char state;
};
/*------------------------*/
struct GET_DEV_STA_REQ                    /*读装置状态*/
{
/*in*/u_short addr;
};

struct GET_DEV_STA_RESP                       
{
/*out*/u_char state;                      /*bit0-3:装置运行状态  bit4-5:A网通讯状态(dpi) bit6-7:B网通讯状态(dpi)*/
};
/*------------------------*/

struct GET_ALL_DEV_STA_REQ                /*读装置状态*/
{
/*in*/u_int app_id;
/*in*/u_int task_id;
/*in*/u_int period; 
};

/*------------------------*/
struct GET_ALL_CONN_STA_REQ               /*读所有连接状态*/
{
/*in*/u_int app_id;
/*in*/u_int task_id;
/*in*/u_int period;           					  /*上送周期(ms)*/
};


struct CONN_STA_MSG_RESP               
{     
/*out*/u_int  return_id;                                    
/*out*/struct CONN_STA conn_sta;
};  
/*------------------------*/

struct GET_TIME_RESP                      /*获取当前时间输出参数*/        
{
/*out*/struct SYS_TIME t;
};
/*------------------------*/
struct SET_TIME_REQ                       /*获取当前时间输入参数*/  
{
/*in*/u_int   appid;                      /*时间源的appid*/
/*in*/struct SYS_TIME t;
/*in*/int  period;                        /*对时周期*/
};
/*------------------------*/

struct SEARCH_WITH_ACC_REQ                /*查找扰动数据(模拟量)*/
{
/*in*/u_short addr;
/*in*/u_char  acc;
};

struct SEARCH_WITH_ACC_RESP                       
{
/*out*/u_int  index; 
/*out*/u_char   dimension[10];
/*out*/u_char   phase[64];
/*out*/u_char   description[1];
};
/*------------------------*/

struct SEARCH_DISTUB_REQ                  /*查找扰动数据(状态量)*/
{
/*in*/u_short addr;
/*in*/u_char  fun;
/*in*/u_char  inf;
};

struct SEARCH_DISTURB_RESP                        
{
/*out*/u_int  index; 
/*out*/u_char   description[1];
};
/*------------------------*/

struct GET_RELATE_REQ                     /*获取关联条目输入参数*/
{                                         
/*in*/u_int   index;                      
};                 
                                          
struct GET_RELATE_RESP                    /*获取关联条目输出参数*/        
{                                         
/*out*/u_int relate;                      
};                 
/*------------------------*/              
                                          
struct GET_FUNINF_REQ                     /*获取FUN INF输入参数*/
{                                         
/*in*/u_int   index;                      
};                 
                                          
struct GET_FUNINF_RESP                    /*获取FUN INF输出参数*/       
{
/*out*/u_char fun;
/*out*/u_char inf;
};
/*------------------------*/

/*------------------------*/              
                                          
struct GET_LIST_NUM_REQ                   /*获取引用表的引用条目数 输入参数*/
{                                          
/*in*/u_int   app_id;                     /*规约的APP_ID*/
/*in*/u_int   list_no;                    /*引用表号*/               
};                  
                                           
struct GET_LIST_NUM_RESP                  /*获取引用表的引用条目数 输出参数*/       
{                                         
/*out*/u_short   num;                     /*引用表条目数*/
};                 
/*------------------------*/              
struct REGISTER_LIST_HOOK_REQ             /*注册一个引用表所有条目的hook 输入参数*/
{                                          
/*in*/u_int app_id;                       /*注册者的app_id*/
/*in*/u_int task_id;                      /*注册者的task_id*/
/*in*/u_int return_id;                    /*注册者的return_id*/
/*in*/u_int list_app_id;                  /*引用表的app_id*/
/*in*/u_short list_no;                    /*引用表的编号*/
/*in*/u_char type;                        /*事件类型*/  /* 0x01:变化 */
                                                  /* 0x02:定时  */  
                                                  /* 0x04:问答  */  
                                                  /* 0x08:有条件变化上送 */   
/*in*/u_short send_period;  
/*in*/u_short len;
/*in*/u_char expression[1];              /*条件变化上送表达式*/ 
};                 
                                          
/*------------------------*/

struct CREATE_DEV_LIST_REQ               /*注册装置全部引用 输入参数*/
{                                         
/*in*/u_int app_id;                       /*引用表的APP_ID*/                
/*in*/u_short list_no;                   /*引用表号*/   
/*in*/u_char list_type;                  /*引用表类型*/    
/*in*/u_short dev_addr;                  /*装置地址*/
};                 
                                          
/*------------------------*/
struct GET_REAL_ADDR_REQ               
{                                         
/*in*/u_short map_addr;
};                 
                                          
struct GET_REAL_ADDR_RESP               
{                                         
/*out*/u_short real_addr;
};                 
                                          
/*------------------------*/

struct GET_MAP_ADDR_REQ               
{                                         
/*in*/u_short real_addr;
};         

struct GET_MAP_ADDR_RESP               
{                                         
/*out*/u_short map_addr;
};          
                                          
/*------------------------*/

struct GET_GROUP_ENTRY_REQ               
{
/*in*/u_int app_id;
/*in*/u_short list_no;                                 
/*in*/u_short no;
};         

struct GET_GROUP_ENTRY_RESP               
{                                         
/*out*/u_int index;
};          
                                          
/*------------------------*/

struct COS_HOOK_MSG_RESP                    /*变位hook消息*/    
{                                         
/*out*/u_char type;                         /*enum RDB_EVENT_TYPE*/
/*out*/u_int  return_id;   
/*out*/u_int  list_app_id;                  /*引用表app_id*/
/*out*/u_short list_no;                                 
/*out*/u_short no;
/*out*/u_short  len;                                                                                      
/*out*/u_char   buf[1];                       /*asdu10报文*/
};          
                                          
/*------------------------*/

struct COS_DATA_HOOK_MSG_RESP               /*变位hook消息 以数据结构返回*/    
{                                         
/*out*/u_char type;                         /*enum RDB_EVENT_TYPE*/
/*out*/u_int  return_id;   
/*out*/u_int  list_app_id;                  /*引用表app_id*/
/*out*/u_short list_no;                                 
/*out*/u_short no;
/*out*/u_char  dpi;                                                                                      
/*out*/u_char  time[7];                     /*时间*/
/*out*/u_short dev_addr;
/*out*/u_char  group_no;
/*out*/u_char  entry_no;

};          
                                          
/*------------------------*/

struct PERIOD_HOOK_MSG_RESP                 /*周期hook消息*/    
{                                         
/*out*/u_int  return_id;   
/*out*/u_short  len;                                                                                      
/*out*/u_char   buf[1];                       /*asdu10报文*/
};          
                                          
/*------------------------*/

struct GET_DEV_NUM_RESP                     /*获取装置的个数，包括虚装置*/    
{                                         
/*out*/u_short num;     
};          
                                          
/*------------------------*/

struct REGISTER_DEV_STA_REQ               
{
/*in*/u_int  app_id;
/*in*/u_int  task_id;
/*in*/u_int  return_id;
};         

struct DEV_STA_MSG_RESP               
{     
/*out*/u_int  return_id;                                    
/*out*/struct DEVS_STA devs_sta;
};          
                                          
/*------------------------*/

struct REGISTER_MON_MSG_REQ               
{
/*in*/u_int  app_id;
/*in*/u_int  task_id;
/*in*/u_int  return_id;
};         
                       
/*------------------------*/

struct GET_DEV_ADDR_REQ               
{
/*in*/u_short  dev_no;
};         

struct GET_DEV_ADDR_RESP               
{     
/*out*/u_short  real_addr;
/*out*/u_short  dummy_addr;
};          
                                          
/*------------------------*/


struct GET_DATA_SYNCH_REQ               
{
/*in*/u_int   app_id;
/*in*/u_int   task_id;
/*in*/u_int   object_id;
/*in*/struct  EXT_ASDU21 asdu_p;          /*装置真实地址*/
/*in*/u_char  filter_flag;                /*过滤标记  =YES:过滤方式*/
/*in*/u_short max_len;                    /*运行返回报文最大长度*/
};         

struct GET_DATA_SYNCH_RESP                
{     
/*out*/int     error_no;                  /* 0:未知  
                                             1:该装置不存在 
                                             2:该装置数据未建立完成 
                                             3:
                                          */
/*out*/u_short len;                       /*asdu报文长度*/                                          
/*out*/u_char  buf[1];                        /*asdu报文*/
};          
                                          
/*------------------------*/

struct GET_GROUP_NAME_REQ               
{
/*in*/u_short   dev_addr;
/*in*/u_char    group_no;
};         

struct GET_GROUP_NAME_RESP               
{     
/*out*/u_char   group_name[1];
};          
                                          
/*------------------------*/


struct GET_GROUP_TYPE_REQ               
{
/*in*/u_short   dev_addr;
/*in*/u_char    group_no;
};         

struct GET_GROUP_TYPE_RESP               
{     
/*out*/u_char   type;
};          
                                          
/*------------------------*/

struct GET_BIT_DECS_REQ               
{
/*in*/u_short  dev_addr;
/*in*/u_char   group_no;
/*in*/u_char   entry_no;
/*in*/u_char   no;                        /*位编号 0起始*/
};         

struct GET_BIT_DECS_RESP               
{     
/*out*/u_char  decs[1];                  /*第no位的描述 最大长度40个字节*/ 
};          
                                          
/*------------------------*/
struct GET_BITS_DECS_REQ               
{
/*in*/u_short  dev_addr;
/*in*/u_char   group_no;
/*in*/u_char   entry_no;
};         

struct GET_BITS_DECS_RESP               
{
/*in*/u_char   num;      
/*out*/u_char  decs[1];                 /*位串描述数组 最多32个位 每个描述最大长度40个字节 数组长度必须是 32*40*/ 
};          
                                          
/*------------------------*/
struct GET_PROP_LIST_BY_ID_REQ             
{
/*in*/u_int     id;                     /*属性域id*/
};         

struct GET_PROP_LIST_BY_ID_RESP               
{
/*out*/u_int    num;                     /*属性数目*/
/*out*/u_int    props[1];                /*属性id数组 最大50个属性*/
};          
                                          
/*------------------------*/

struct GET_PROP_LIST_BY_NAME_REQ               
{
/*in*/u_char    name[40];                /*属性域名*/
};         

struct GET_PROP_LIST_BY_NAME_RESP               
{
/*out*/u_int    num;                     /*属性数目*/
/*out*/u_int    props[1];                /*属性id数组 最大50个属性*/
};          
                                          
/*------------------------*/

struct GET_PROP_BY_ID_REQ             
{
/*in*/u_int     filed_id;                 /*属性域id*/     
/*in*/u_int     no;                       /*设备的顺序号 0起始*/ 
/*in*/u_int     prop_id;                  /*属性id*/   
};         

struct GET_PROP_BY_ID_RESP               
{
/*out*/struct   PROP_DATA prop_data;
};          
                                          
/*------------------------*/

struct GET_PROP_BY_NAME_REQ             
{
/*in*/u_char    filed_name[40];           /*属性域名 长度为40*/  
/*in*/u_int     no;                       /*设备的顺序号 0起始*/ 
/*in*/u_char    prop_name[40];            /*属性名称 长度为40*/  
};         

struct GET_PROP_BY_NAME_RESP               
{
/*out*/struct   PROP_DATA prop_data;
};          
                                          
/*------------------------*/

struct SET_PROP_BY_ID_REQ             
{
/*in*/u_int     filed_id;                 /*属性域id*/     
/*in*/u_int     no;                       /*设备的顺序号 0起始*/ 
/*in*/u_int     prop_id;                  /*属性id*/            
/*in*/struct    PROP_DATA prop_data;
};         
                                          
/*------------------------*/
struct SET_PROP_BY_NAME_REQ             
{
/*in*/u_char    filed_name[40];           /*属性域名 长度为40*/  
/*in*/u_int     no;                       /*设备的顺序号 0起始*/ 
/*in*/u_char    prop_name[40];            /*属性名称 长度为40*/            
/*in*/struct    PROP_DATA prop_data;
};         
       
/*------------------------*/

struct GET_EQUIP_NUM_BY_ID_REQ             
{
/*in*/u_int     filed_id;                 /*属性域id*/   
};         

struct GET_EQUIP_NUM_BY_ID_RESP               
{
/*out*/u_int    num;                      /*属性数目*/
};          
                                          
/*------------------------*/

struct GET_EQUIP_NUM_BY_NAME_REQ             
{
/*in*/u_char     filed_name[40];          /*属性域名称 长度为40*/   
};         

struct GET_EQUIP_NUM_BY_NAME_RESP               
{
/*out*/u_int    num;                      /*属性数目*/
};          
                                          
/*------------------------*/


struct MANUAL_SET_REQ             
{
/*in*/struct MANUAL_SET_DATA set_data;  /*人工置数数据*/
};         

struct MANUAL_SET_RESP               
{
/*out*/struct MANUAL_SET_RESULT result;
};          
                                          
/*------------------------*/

struct MANUAL_CLEAR_REQ             
{
/*in*/u_short   dev_addr; 
/*in*/u_char    group_no; 
/*in*/u_char    entry_no; 
};         

struct MANUAL_CLEAR_RESP               
{
/*out*/u_char   result;                 /*返回结果 NO 失败  YES 成功*/
};          
                                          
/*------------------------*/

struct MANUAL_CLEAR_DEV_REQ             
{
/*in*/u_short   dev_addr; 
};         

struct MANUAL_CLEAR_DEV_RESP               
{
/*out*/u_char   result;                 /*返回结果 NO 失败  YES 成功*/
};          
                                          
/*------------------------*/

struct MANUAL_CLEAR_ALL_RESP               
{
/*out*/u_char   result;                 /*返回结果 NO 失败  YES 成功*/
};          
                                          
/*------------------------*/
struct MANUAL_CLEAR_LIST_REQ             
{
/*in*/u_int     list_appid;               /*引用表的appid*/
/*in*/u_int     list_no;                  /*引用表号*/
};         

struct MANUAL_CLEAR_LIST_RESP               
{
/*out*/u_char   result;                 /*返回结果 NO 失败  YES 成功*/
};          
                                          
/*------------------------*/

struct GET_MANUAL_STA_REQ             
{
/*in*/u_short   dev_addr; 
/*in*/u_char    group_no; 
/*in*/u_char    entry_no; 
};         

struct GET_MANUAL_STA_RESP               
{
/*out*/u_char   state;
};          
                                          
/*------------------------*/


struct GET_YM_GROUP_NO_REQ             
{
/*in*/u_short   dev_addr; 
};  

struct GET_YM_GROUP_NO_RESP               
{
/*out*/u_char   num;
/*out*/u_char   group_no[10];           /*遥脉组号  最大10个*/
};          
                                          
/*------------------------*/

struct SEND_RDB_SYN_DATA_REQ
{
  u_char type;
  u_short dev_addr;
  u_char group_no;
  u_char num;
  u_char data[1];
};
/*------------------------*/
struct SEND_RDB_SYN_CON_STA_REQ
{
  u_char type;
  u_char board_no;
  u_short begin_no;
  u_short num;
  u_char data[1];
};
/*------------------------*/

struct SEND_RDB_SYN_DEV_STA_REQ
{
  u_short begin_no;
  u_short num;
  u_char data[1];
};
/*------------------------*/

struct DEV_DONE_STA_REQ             
{
/*in*/u_short   dev_addr; 
};         

struct DEV_DONE_STA_RESP               
{
/*out*/u_char   state;
};          
                                          
/*------------------------*/
struct GET_RDB_STA_RESP               
{
/*out*/u_char   state;
};          
                                          
/*------------------------*/

struct GET_ENTRY_QDS_REQ             
{
/*in*/u_short   dev_addr; 
/*in*/u_char    group_no; 
/*in*/u_char    entry_no;
};         

struct GET_ENTRY_QDS_RESP               
{
/*out*/u_char   qds;
};          
                                          
/*------------------------*/

struct LOGIN_SET_CHANGE_REQ             
{
/*in*/u_int     app_id;
/*in*/u_int     task_id;
/*in*/u_int     return_id;
/*in*/u_char    type;
};         
                                 
/*------------------------*/

struct SET_HOOK_DATA_RESP               
{
/*out*/u_int    return_id;
/*out*/u_char   type;
/*out*/u_short  dev_addr; 
/*out*/u_char   group_no; 
/*out*/u_char   entry_no;
/*out*/u_char   description[50];
/*out*/u_char   old_data[50];
/*out*/u_char   new_data[50];
/*out*/u_char   time[7];
};          
                                          
/*------------------------*/

struct SET_GPS_STA_REQ             
{
/*in*/u_char    state;
};         
/*------------------------*/

struct GET_CPU_INFO_REQ             
{
/*in*/u_short   dev_addr; 
};         

struct GET_CPU_INFO_RESP              
{
/*out*/u_char   cpu_num;
/*out*/u_char   cpu_no[1];
};          
                                          
/*------------------------*/

struct CALL_DIR_REQ              /*召唤文件目录*/
{
/*in*/u_short   dev_addr;
/*in*/u_int     cmd_id; 									/*招唤命令标识，用于跟返回匹配*/
/*in*/u_char    type; 										/*文件类型  0:波形文件 1:配置文件 3-244:其他文件 255:所有文件*/
/*in*/u_int     name_len;	
/*in*/u_char    dir_name[1];	
};  

struct CALL_DIR_RESP             /*召唤文件目录*/
{
/*out*/int      error_no; 								/*响应结果 0:正确响应 1:正在等待上一次调用返回 2:其他*/	
};  

/*------------------------*/

struct CALL_DIR_ACK_REQ          /*响应召唤文件目录*/
{
/*in*/u_short   dev_addr;
/*in*/u_int     cmd_id; 									/*招唤命令标识，用于跟返回匹配*/
/*in*/int       result; 									/*响应结果 0:正确响应 1:不支持该命令 2:无所召唤内容 3:其他*/
/*in*/u_char    type; 										/*文件类型  0:波形文件 1:配置文件 3-244:其他文件 255:所有文件*/
/*in*/u_int     name_len;	
/*in*/u_char    dir_name[1];	
};  

/*------------------------*/

struct CALL_FILE_REQ              /*召唤文件*/
{
/*in*/u_short   dev_addr;
/*in*/u_int     cmd_id; 									/*招唤命令标识，用于跟返回匹配*/
/*in*/u_int     name_len;	
/*in*/u_char    file_name[1];	
};  

struct CALL_FILE_RESP             /*召唤文件*/
{
/*out*/int      error_no; 								/*响应结果 0:正确响应 1:正在等待上一次调用返回 2:其他*/	
};  

/*------------------------*/

struct CALL_FILE_ACK_REQ              /*召唤文件*/
{
/*in*/u_short   dev_addr;
/*in*/u_int     cmd_id; 									/*招唤命令标识，用于跟返回匹配*/
/*in*/int       result; 									/*响应结果 0:正确响应 1:不支持该命令 2:无所召唤内容 3:其他*/
/*in*/u_int     name_len;	
/*in*/u_char    file_name[1];	
};  

/*------------------------*/

struct GET_NO_IN_LIST_REQ              /*获取条目在应用表中的序号*/
{
/*in*/u_int     list_appid;               /*引用表的appid*/
/*in*/u_int     list_no;                  /*引用表号*/
/*in*/u_int     index;                  	/*条目*/
};  

struct GET_NO_IN_LIST_RESP             /*召唤文件*/
{
/*out*/int     	no;												/*条目在应用表中的序号 >=0有效 -1未找到*/	
};  

/*------------------------*/
struct REGISTER_YKBS_REQ              /*注册遥控闭锁条件*/
{
/*in*/u_int     appid;               			/*遥控源的appid*/
/*in*/u_int     yk_index;
/*in*/u_int     yx_index;                  	/*关联遥信*/
/*in*/u_char    type;                  		/*1:遥控分 2遥控合 3遥控分合*/
/*in*/u_char   	condition;								/*bit1=0:遥信分闭锁遥控  bit1>0:遥信合闭锁遥控 bit8=0:遥信无效闭锁遥控 bit8=1:遥信无效不闭锁遥控 */
}; 



/***************请求/应答 参数结构*******************/

/*请求数据结构*/
struct  RDB_REQ_DATA
{
  u_int interface_id;
  union
  {   
    struct  READ_YX_REQ  read_yx;
    struct  READ_YC_REQ  read_yc;
    struct  READ_YM_REQ  read_ym;
    struct  READ_YP_REQ  read_yp;
    struct  READ_YC_FLOAT_REQ  read_yc_float;
    struct  READ_LIST_REQ read_list;
    struct  DISPATCH_TOP_REQ dispatch_top;
    struct  DISPATCH_BOTTOM_REQ dispatch_bottom;
    struct  REGISTER_HOOK_REQ register_hook;
    struct  REGISTER_HOOKA_REQ register_hookA;
    struct  REGISTER_DEV_MSG_REQ register_dev_msg;
    struct  REGISTER_RELATE_REQ register_relate;
    struct  ADD_LIST_OWNER_REQ add_list_owner;
    struct  DELETE_LIST_OWNER_REQ delete_list_owner;
    struct  SET_STA_REQ  set_sta;
    struct  SET_DEV_NET_STA_REQ set_dev_net_sta;
    struct  SET_DEVS_NET_STA_REQ set_devs_net_sta;
    struct  SET_DEV_RUN_STA_REQ set_dev_run_sta;
    struct  GET_STA_REQ  get_sta;
    struct  GET_DEV_STA_REQ get_dev_sta;
    struct  GET_ALL_DEV_STA_REQ get_all_dev_sta;
    struct  GET_ALL_CONN_STA_REQ get_all_conn_sta;
    struct  SET_TIME_REQ  set_time;
    struct  SEARCH_WITH_ACC_REQ search_with_acc;
    struct  SEARCH_DISTUB_REQ search_disturb;
    struct  GET_RELATE_REQ get_relate;
    struct  GET_FUNINF_REQ get_funinf;
    struct  GET_LIST_NUM_REQ get_list_num;
    struct  REGISTER_LIST_HOOK_REQ register_list_hook;
    struct  CREATE_DEV_LIST_REQ create_dev_list;
    struct  GET_REAL_ADDR_REQ get_real_addr;
    struct  GET_MAP_ADDR_REQ get_map_addr;
    struct  GET_GROUP_ENTRY_REQ get_group_entry;
    struct  REGISTER_DEV_STA_REQ register_dev_sta;
    struct  REGISTER_MON_MSG_REQ register_mon_msg; 
    struct  GET_DEV_ADDR_REQ get_dev_addr;
    struct  GET_DATA_SYNCH_REQ get_data_synch;
    struct  GET_GROUP_NAME_REQ get_group_name; 
    struct  GET_GROUP_TYPE_REQ get_group_type; 
    struct  GET_BIT_DECS_REQ  get_bit_decs; 
    struct  GET_BITS_DECS_REQ  get_bits_decs; 
    struct  GET_PROP_LIST_BY_ID_REQ  get_prop_list_by_id;
    struct  GET_PROP_LIST_BY_NAME_REQ  get_prop_list_by_name;
    struct  GET_PROP_BY_ID_REQ get_prop_by_id;
    struct  GET_PROP_BY_NAME_REQ get_prop_by_name;
    struct  SET_PROP_BY_ID_REQ set_prop_by_id;
    struct  SET_PROP_BY_NAME_REQ  set_prop_by_name;
    struct  GET_EQUIP_NUM_BY_ID_REQ get_equip_num_by_id;
    struct  GET_EQUIP_NUM_BY_NAME_REQ get_equip_num_by_name;
    struct  MANUAL_SET_REQ manual_set;
    struct  MANUAL_CLEAR_REQ manual_clear;
    struct  MANUAL_CLEAR_DEV_REQ manual_clear_dev;
    struct  MANUAL_CLEAR_LIST_REQ manual_clear_list;
    struct  GET_MANUAL_STA_REQ get_manual_sta;
    struct  GET_YM_GROUP_NO_REQ get_ym_group_no;
    struct  SEND_RDB_SYN_DATA_REQ send_rdb_syn_data;
    struct  SEND_RDB_SYN_CON_STA_REQ send_rdb_syn_con_sta;
    struct  SEND_RDB_SYN_DEV_STA_REQ send_rdb_syn_dev_sta;
    struct  DEV_DONE_STA_REQ dev_done_sta;
    struct  GET_ENTRY_QDS_REQ get_entry_qds;            
    struct  LOGIN_SET_CHANGE_REQ login_set_change;
    struct  SET_GPS_STA_REQ  set_gps_sta;
    struct  GET_CPU_INFO_REQ get_cpu_info;
    struct  CALL_DIR_REQ call_dir;
    struct  CALL_DIR_ACK_REQ call_dir_ack;
    struct  CALL_FILE_REQ call_file;
    struct  CALL_FILE_ACK_REQ call_file_ack;
    struct  GET_NO_IN_LIST_REQ get_no_in_list;
    struct  REGISTER_YKBS_REQ  register_ykbs;
  }req;
}; 

/*应答数据结构*/
struct  RDB_RESP_DATA
{
  u_int interface_id;
  int result;
  union
  {   
    struct  READ_YX_RESP read_yx; 
    struct  READ_YC_RESP read_yc; 
    struct  READ_YM_RESP read_ym;
    struct  READ_YP_RESP read_yp;   
    struct  READ_YC_FLOAT_RESP  read_yc_float;
    struct  READ_LIST_RESP read_list;
    struct  DISPATCH_TOP_RESP    dispatch_top;
    struct  DISPATCH_TOP_RESP    mon_msg;
    struct  COS_HOOK_MSG_RESP    cos_hook_msg;
    struct  COS_DATA_HOOK_MSG_RESP    cos_data_hook_msg;
    struct  PERIOD_HOOK_MSG_RESP    period_hook_msg;
    struct  DISPATCH_BOTTOM_RESP dispatch_bottom;   
    struct  DISPATCH_BOTTOM_RESP dev_msg;  
    struct  GET_STA_RESP get_sta;
    struct  GET_DEV_STA_RESP get_dev_sta;
    struct  GET_TIME_RESP get_time;
    struct  SEARCH_WITH_ACC_RESP search_with_acc;
    struct  SEARCH_DISTURB_RESP search_disturb;
    struct  GET_RELATE_RESP get_relate;
    struct  GET_FUNINF_RESP get_funinf;
    struct  GET_LIST_NUM_RESP get_list_num;
    struct  GET_REAL_ADDR_RESP get_real_addr;
    struct  GET_MAP_ADDR_RESP get_map_addr;
    struct  GET_GROUP_ENTRY_RESP get_group_entry;
    struct  GET_DEV_NUM_RESP get_dev_num;
    struct  DEV_STA_MSG_RESP dev_sta_msg;
    struct  CONN_STA_MSG_RESP conn_sta_msg;
    struct  GET_DEV_ADDR_RESP get_dev_addr;
    struct  GET_DATA_SYNCH_RESP get_data_synch;
    struct  GET_GROUP_NAME_RESP get_group_name; 
    struct  GET_GROUP_TYPE_RESP get_group_type; 
    struct  GET_BIT_DECS_RESP  get_bit_decs; 
    struct  GET_BITS_DECS_RESP  get_bits_decs; 
    struct  GET_PROP_LIST_BY_ID_RESP  get_prop_list_by_id;
    struct  GET_PROP_LIST_BY_NAME_RESP  get_prop_list_by_name;
    struct  GET_PROP_BY_ID_RESP get_prop_by_id;
    struct  GET_PROP_BY_NAME_RESP get_prop_by_name;
    struct  GET_EQUIP_NUM_BY_ID_RESP get_equip_num_by_id;
    struct  GET_EQUIP_NUM_BY_NAME_RESP get_equip_num_by_name;
    struct  MANUAL_SET_RESP manual_set;
    struct  MANUAL_CLEAR_RESP manual_clear;
    struct  MANUAL_CLEAR_DEV_RESP manual_clear_dev;
    struct  MANUAL_CLEAR_ALL_RESP manual_clear_all;
    struct  MANUAL_CLEAR_LIST_RESP manual_clear_list;
    struct  GET_MANUAL_STA_RESP get_manual_sta;
    struct  GET_YM_GROUP_NO_RESP get_ym_group_no;
    struct  DEV_DONE_STA_RESP dev_done_sta;
    struct  GET_RDB_STA_RESP get_rdb_sta;
    struct  GET_ENTRY_QDS_RESP get_entry_qds;  
    struct  SET_HOOK_DATA_RESP set_hook_data; 
    struct  GET_STA_RESP get_gps_sta;
    struct  GET_CPU_INFO_RESP get_cpu_info;
    struct  CALL_DIR_RESP call_dir;
    struct  CALL_FILE_RESP call_file;
    struct  GET_NO_IN_LIST_RESP get_no_in_list;
                
  }resp;  
};
#pragma pack(pop)

#endif
