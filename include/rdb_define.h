
 /****************************************************************
 * FileName:      mdl_rdb_define.h
 * Description:   定义
 *
 * Modify Log:
 * 
 ****************************************************************/

#ifndef _RDB_DEFINE_H_
#define _RDB_DEFINE_H_

#include "sys_define.h"
#include "os_func.h"
#include "ipcs.h"
#include "fbufcircle.h"

#define  CMD_EXECUTING  1               /*正在执行命令*/
#define  CMD_NOTSUPPORT 2               /*不支持命令*/

#define  TOP_WAY        0               /*报文方向:控制方向*/
#define  BOTTOM_WAY     1               /*报文方向:监视方向*/

#define  DUMMY_DEV      65530           /*虚设备地址*/

#define MAX_DECS_LEN    40
#define RDB_NServers    1               /*实时数据库接口服务默认任务个数*/
#define RDB_PriorityDefault 100         /*实时数据库接口服务默认任务优先级*/

#define DEV_NET_A_MASK  0x30            /*装置A网通讯状态*/
#define DEV_NET_B_MASK  0xc0            /*装置B网通讯状态*/

#define SHIGUZHONG      0xfffb0a02      /*事故总条目号*/
#define YUGAOZHONG      0xfffb0a01      /*预告总条目号*/

#define SOFT_BUS_TAG_LEN 12             /*软总线头tag长度*/

#define DEV_DUMMY       40              /* 40: 虚拟装置*/
#define DEV_BH          41              /* 41: 保护装置*/
#define DEV_CK          42              /* 42: 测控装置*/
#define DEV_BH_CK       43              /* 43: 保护测控装置*/
#define DEV_LUBO        44              /* 44: 故障录波装置*/
#define DEV_JILIANG     45              /* 45: 计量装置*/
#define DEV_FW          46              /* 46: 防误校验装置*/
#define DEV_OTHER       49              /* 49: 其他*/

#define RDB_HOOK_PERIOD 1               /*周期上送检查周期*/
#define RDB_SOCKET_CHECK_PERIOD   2     /*检查命令超时的周期*/

#define RDB_MAX_PROP_NUM 50             /*每个设备最多可以拥有的属性个数*/
#define RDB_MAX_GID_LEN  40             /*gid数据最大长度*/
#define RDB_SET_CHECK_PERIOD  5         /*定值比对周期（小时）*/

#define RDB_MAX_CPU_NUM  32         		/*装置最大CPU数目*/

enum CMD_TYPE
{
  CMD_YK_SELECT=1,    /*1=遥控选择*/
  CMD_YK_EXEC,        /*2=遥控执行*/
  CMD_YK_CANCLE,      /*3=遥控撤消*/
  CMD_YT_SELECT,      /*4=遥调选择*/
  CMD_YT_EXEC,        /*5=遥调执行*/
  CMD_YT_CANCLE,      /*6=遥调撤消*/  
  CMD_DZQH_WRITE,     /*7=写定值区号*/    
  CMD_DZQH_EXEC,      /*8=写定值区号执行*/
  CMD_DZQH_CANCLE,    /*9=写定值区号撤消*/
  CMD_DZ_WRITE,       /*10=写定值*/
  CMD_DZ_EXEC,        /*11=写定值执行*/
  CMD_DZ_CANCLE,      /*12=写定值撤消 */    
  CMD_OTHER,       /*13=未知 */   
  CMD_RYB_WRITE,   /*14=修改软压板选择*/
  CMD_RYB_EXEC,    /*15=修改软压板执行*/
  CMD_RYB_CANCLE   /*16=修改软压板撤销*/   
};

      
          
enum {
  RDB_NONE_MSG,
  RDB_TIMER_MSG,
  RDB_HOOK_MSG,
  RDB_PERIOD_HOOK_MSG,
  RDB_DISPATCH_BOTTOM_MSG,
  RDB_DISPATCH_TOP_MSG,
  RDB_EVENT_MSG,
  RDB_DEV_STAT_MSG,
  RDB_DEV_OVERHAUL_MSG
};

enum {
  RDB_PERIOD_HOOK_ID,
  RDB_SOCKET_CHECK_ID,
  RDB_SEND_EXPCAL_DATA,
  RDB_SEND_DCCU_DATA,
  RDB_SET_HOOK_ID,
  RDB_SET_UPDATA_ID
};

                                                                               
                                                                                                
struct GDD_DATA                                                                                 
{          
  struct  GDD_DATA *next;                                                                       
  u_char  flag;                     /*有效标志*/                                                            
  u_char  kod;                                                                                  
  u_char  gdd[3];                                                                               
  u_char  *gid;                                                                                 
};                                                                                              
                                                                                                
struct GDD_GID                                                                                
{                                                                                               
  u_char  gdd[3];                                                                               
  u_char  *gid;                                                                                 
};                                                                                                    

    
                                                                                            
struct  HOOK                                                                                    
{                                                                                       
  struct  HOOK   *next;       
  u_int   app_id;                   /*注册者的appid*/
  u_int   task_id;                  /*注册者的taskid*/
  u_int   return_id;
  u_int   list_app_id;              /*引用表拥有者的appid*/
  u_short list_no;                  /*引用表编号,无对应引用表是为0xffff*/
  u_short no;                       /*引用表中条目的序号,从0开始*/
  short   time;                     /*周期上送时间*/
  short   time_save;  
  u_char  type;                     /*事件类型*/  /* 0x01:变化 */
                                                  /* 0x02:定时  */  
                                                  /* 0x04:问答  */  
                                                  /* 0x08:有条件变化上送 */   
                                                  /* 0x10:复合信号*/                                       
  void    *object;                  /*复合信号表达式 或者 条件变化表达式 */
};    

struct YK_RULE
{
	struct YK_RULE *next;
	u_int  app_id;										/*遥控源的appid*/
	u_int  index;											/*关联遥信*/
	u_char condition;									/*bit1=0:遥信分闭锁遥控  bit1>0:遥信合闭锁遥控 bit8=0:遥信无效闭锁遥控 bit8=1:遥信无效不闭锁遥控 */
};
                          
struct ELEMENT                      
{ 
  u_int   index;                    /*ID  */  
  struct  GROUP_DATA *group_p;      /*所属组指针*/
  u_char  type;                     /*点类型  */  /* 0: YX 1:YC 2:YM 3YK 4:YT 5:YB 6:其他*/
  u_char  cpu_no;                   /*CPU号*/
  u_char  group_old;                /*原组号*/
  u_char  entry_old;                /*原条目号*/
  u_char  fun;                      
  u_char  inf;        
  u_int   device_no;                /*一次设备编号*//* device_no=电压等级*10000000+间隔*10000+设备*/
  u_char  done_flag;                /*该条目建立状态*/  /*0: 未完成  1:完成*/
  u_char  QDS;                      /*品质描述*/
  struct  GDD_DATA  description;    /*描述*/
  struct  GDD_DATA  actual_value;   /*实际值*/
  u_int   iFFNo;                    //快频点号,从1开始
  u_int   relate;                   /*关联条目  */         
  struct YK_RULE    *off_rule;      /*遥控分规则  */     
  struct YK_RULE    *on_rule;       /*遥控合规则 */      
  struct  GDD_DATA *gdd_data_head;  /*其他属性链表*/      
  struct  HOOK *first;              /*事件链表*/
  u_char  manual_flag;              /*人工置数标志*/
  u_char  manual_gid[32];			/*人工置数备份*/
  u_char  goose_inf[32];
};                                    
                                    


struct  GROUP_DATA
{   
  char    description[MAX_DECS_LEN];/*自我描述，字符串，备用*/
  struct  DEV_DATA* devp;           /*所属装置指针*/
  u_char  type;                     /*组类型  */  /* 0: YC 1:YX 2:YM 3YK 4:YT 5:YP 6:其他*/
  u_char  trans_flag;               /*转发组标志*/ /*0:非转发组   1:转发组*/
  u_char  update_flag;              /*需要更新标志*/
  u_char  done_flag;                /*该组建立状态*/  /*0: 未完成  1:完成*/
  u_char  group_no;                 /*组号*/
  u_char  group_no_old;          		/*原始组号*/
  u_char  cpu_no;                   /*CPU号*/
  u_short element_num;              /*条目数目*/
  u_short total_num;                /*指针数组长度*/
  struct  ELEMENT  **element; 
};

struct  DEV_DATA
{ 
  char    description[MAX_DECS_LEN];/*自我描述，字符串，备用*/
  u_short dev_addr;                 /*装置地址*/
  u_char  cpu_num;                  /*CPU数目*/
  u_char  cpu_flag[RDB_MAX_CPU_NUM];/*CPU使用标志*/
  u_char  setting_num;              /*定值区数目*/
  u_char  setting_no;               /*当前定值区号*/
  u_char  setting_run;              /*运行定值区*/
  u_char  done_flag;                /*装置数据库建立状态*/  /*0: 未完成  1:完成*/
  u_short group_num;                /*组数目*/
  u_short total_num;                /*指针数组长度*/
  struct  GROUP_DATA  **group_data; /*组数据*/
  struct  BIT *bit_desc_head;       /*位串头指针*/
};

struct  DATABASE
{ 
  u_short dev_num;                  /*装置数量*/
  u_short total_num;                /*指针数组长度*/
  struct  DEV_DATA  **dev_data;     /*装置数据*/
};

struct  YC_K
{
	float b;									
	float k;
};

struct  LIST                  
{ 
  struct  LIST  *next;
  u_int   list_no;                  /*引用表编号*/
  u_char  list_type;                /* 引用表类型  0:YC  1:YX  2:YM  3:YK  4:YT  5:YP 6:other*/
  char  	name[50];
  u_int   entry_num;                /*引用条目数*/
  u_char  k_flag;										/*系数标志*/
  struct  YC_K* k_p;								/*模拟量系数结构数组指针*/
  struct ELEMENT *entry[1];         /*引用条目指针数组*/  
  /*后边跟着(entry_num-1)*sizoef(struct ELEMENT*)的内存*/
};

struct  INDEX_LIST
{ 
  struct  INDEX_LIST *next;
  u_int app_id;                     /*引用规约的appid*/
  struct LIST* lists;               /*引用表指针*/
};


struct  LIST_OWNER
{ 
  struct  LIST_OWNER *next;
  u_int   app_id;                   
  u_int   task_id;                  
  u_int   return_id;
};

/*记录关心引用表的对象的链表*/
struct  LIST_OWNER_LIST
{ 
  struct  LIST_OWNER_LIST *next;
  u_int   list_app_id;              /*引用表拥有者的appid*/
  u_short list_no;                  /*引用表编号*/
  struct  LIST_OWNER * owner_head;
};


/******************装置库定义*******************/
struct  DEV_TAB_DATA
{
  u_short addr;                     /*装置地址*/
  u_short dummy_addr;               /*映射地址*/
  u_short dev_no;                   /*设备序号*/
  u_char  board_addr;               /*板卡地址*/
  u_char  com_type;                 /*通讯口类型*/
  u_char  com_no;                   /*通讯口编号*/
  char  version[40];              /*版本号*/
  char  type_name[60];            /*装置型号*/
  char  description[60];          /*装置描述*/
  u_char  dev_type;                 /*装置类型*/
                                    /* 40: 虚拟装置*/
                                    /* 41: 保护装置*/
                                    /* 42: 测控装置*/
                                    /* 43: 保护测控装置*/
                                    /* 44: 故障录波装置*/
                                    /* 45: 计量装置*/
                                    /* 46: 防误校验装置*/
                                    /* 49: 其他*/
};

struct  DEV_TAB
{
  u_int dev_num;
  struct  DEV_TAB_DATA  dev[1];
};
/*******************间隔定义********************/


struct  PROPERTY
{
  u_int  id;                        /*属性id*/
  u_char gdd[3];                    /*属性数据类型*/
  u_char gid[RDB_MAX_GID_LEN];    
};

struct  EQUIPMENT_DATA
{
  u_int   id;                       /*设备类型id*/
  u_char  num;                      /* 属性数目*/
  struct  PROPERTY *prop[RDB_MAX_PROP_NUM];
};

struct  EQUIPMENT
{
  u_int   id;                       /*设备类型id*/
  char  type_name[40];            /*设备类型名称*/
  u_int   num;                      /*设备数目*/
  struct  EQUIPMENT_DATA *equip_data[1];
};


struct  EQUIPMENT_TAB
{
  u_int   num;                      /*设备数目*/
  struct  EQUIPMENT *equip[1];
};




/*********************对时源*********************/
struct TIME_SOURCE
{
  u_int app_id;     
  int time_out;                       /*超时时间*/
  int time_remain;                    /*剩余时间*/              
  u_char priority;                    /*对时源的优先级*//* 0-255  0优先级最高*/
  u_char flag;                        /*有效标志*/
  u_char active;                      /*活动标志*/
};

struct TIME_SOURCES
{
  u_char num;
  struct TIME_SOURCE sources[1];
};
                                        
/*位串*/      
struct BIT
{
  struct BIT *next;
  u_int index;
  u_char bit_num;                     /*位个数*/
  char *bitDes[1];                  /*位串描述*/
};

     
struct   RDB_BOARD_DATA
{
  int con_num;
  int com_num;
  u_char con_sta[SYS_CON_NUM];             /*网口口通讯状态*/
  u_char con_sta_b[SYS_CON_NUM];
  u_char con_count[SYS_CON_NUM];             
  u_char com_sta[SYS_COM_NUM];             /*串口通讯状态*/
  u_char com_sta_b[SYS_COM_NUM];
  u_char com_count[SYS_COM_NUM];
  u_int con_use_flag[SYS_CON_NUM];
  u_int com_use_flag[SYS_COM_NUM];
}; 

struct   RDB_CONFIG_DATA
{
  int board_num;
  struct   RDB_BOARD_DATA board_data[SYS_BOARD_NUM];
};


struct SET_CHANGE_HOOK
{
  struct SET_CHANGE_HOOK *next;
  u_int  app_id;
  u_int  task_id;
  u_int  return_id;
  u_char type;
};     

struct  RDB_REG_STRUCT
{
  struct    RDB_REG_STRUCT * next;
  u_int     app_id;
  u_int     task_id;
  u_int     return_id;
};

struct	RDB_MON_STRUCT
{
	struct	  RDB_MON_STRUCT * next;
  u_int     app_id;
  u_int     task_id;
  u_int     return_id;
};
      

#define RDB_HOOK_PERIOD             1   //周期上送检查周期
#define RDB_SOCKET_CHECK_PERIOD     2   //检查命令超时的周期
#define RDB_SET_CHECK_PERIOD        5   //定值比对周期（小时）

struct RDB_DISPATCH_STR
{
	FBufCircle  dispatch_top_cc;
	FBufCircle  dispatch_btm_cc;
	//FBufCircle  dispatch_oth_cc;
	pthread_mutex_t mx_top;
	pthread_mutex_t mx_btm;
    
    sem_t   p_local_socket_lock_id;
    
    int     update_flag;
    int     update_set_fig;
    int     rdb_update_set_value_dev_no;
    int     rdb_update_set_value_group_no;
    
    struct  DEV_MSG_CHAIN *dev_msg_head;
    struct  SET_TIME_CHAIN  *set_time_head;
    struct  SOCKET_CHAIN *socket_first;
    
    int     (*disp_table_top[256])(u_int appid,u_int taskid,u_int object_id,u_short length,u_char *buf);
    void    (*disp_table_bottom[256])(u_short length,u_char *buf);
};

#endif                                        

