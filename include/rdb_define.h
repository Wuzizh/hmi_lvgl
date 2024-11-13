
 /****************************************************************
 * FileName:      mdl_rdb_define.h
 * Description:   ����
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

#define  CMD_EXECUTING  1               /*����ִ������*/
#define  CMD_NOTSUPPORT 2               /*��֧������*/

#define  TOP_WAY        0               /*���ķ���:���Ʒ���*/
#define  BOTTOM_WAY     1               /*���ķ���:���ӷ���*/

#define  DUMMY_DEV      65530           /*���豸��ַ*/

#define MAX_DECS_LEN    40
#define RDB_NServers    1               /*ʵʱ���ݿ�ӿڷ���Ĭ���������*/
#define RDB_PriorityDefault 100         /*ʵʱ���ݿ�ӿڷ���Ĭ���������ȼ�*/

#define DEV_NET_A_MASK  0x30            /*װ��A��ͨѶ״̬*/
#define DEV_NET_B_MASK  0xc0            /*װ��B��ͨѶ״̬*/

#define SHIGUZHONG      0xfffb0a02      /*�¹�����Ŀ��*/
#define YUGAOZHONG      0xfffb0a01      /*Ԥ������Ŀ��*/

#define SOFT_BUS_TAG_LEN 12             /*������ͷtag����*/

#define DEV_DUMMY       40              /* 40: ����װ��*/
#define DEV_BH          41              /* 41: ����װ��*/
#define DEV_CK          42              /* 42: ���װ��*/
#define DEV_BH_CK       43              /* 43: �������װ��*/
#define DEV_LUBO        44              /* 44: ����¼��װ��*/
#define DEV_JILIANG     45              /* 45: ����װ��*/
#define DEV_FW          46              /* 46: ����У��װ��*/
#define DEV_OTHER       49              /* 49: ����*/

#define RDB_HOOK_PERIOD 1               /*�������ͼ������*/
#define RDB_SOCKET_CHECK_PERIOD   2     /*������ʱ������*/

#define RDB_MAX_PROP_NUM 50             /*ÿ���豸������ӵ�е����Ը���*/
#define RDB_MAX_GID_LEN  40             /*gid������󳤶�*/
#define RDB_SET_CHECK_PERIOD  5         /*��ֵ�ȶ����ڣ�Сʱ��*/

#define RDB_MAX_CPU_NUM  32         		/*װ�����CPU��Ŀ*/

enum CMD_TYPE
{
  CMD_YK_SELECT=1,    /*1=ң��ѡ��*/
  CMD_YK_EXEC,        /*2=ң��ִ��*/
  CMD_YK_CANCLE,      /*3=ң�س���*/
  CMD_YT_SELECT,      /*4=ң��ѡ��*/
  CMD_YT_EXEC,        /*5=ң��ִ��*/
  CMD_YT_CANCLE,      /*6=ң������*/  
  CMD_DZQH_WRITE,     /*7=д��ֵ����*/    
  CMD_DZQH_EXEC,      /*8=д��ֵ����ִ��*/
  CMD_DZQH_CANCLE,    /*9=д��ֵ���ų���*/
  CMD_DZ_WRITE,       /*10=д��ֵ*/
  CMD_DZ_EXEC,        /*11=д��ִֵ��*/
  CMD_DZ_CANCLE,      /*12=д��ֵ���� */    
  CMD_OTHER,       /*13=δ֪ */   
  CMD_RYB_WRITE,   /*14=�޸���ѹ��ѡ��*/
  CMD_RYB_EXEC,    /*15=�޸���ѹ��ִ��*/
  CMD_RYB_CANCLE   /*16=�޸���ѹ�峷��*/   
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
  u_char  flag;                     /*��Ч��־*/                                                            
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
  u_int   app_id;                   /*ע���ߵ�appid*/
  u_int   task_id;                  /*ע���ߵ�taskid*/
  u_int   return_id;
  u_int   list_app_id;              /*���ñ�ӵ���ߵ�appid*/
  u_short list_no;                  /*���ñ���,�޶�Ӧ���ñ���Ϊ0xffff*/
  u_short no;                       /*���ñ�����Ŀ�����,��0��ʼ*/
  short   time;                     /*��������ʱ��*/
  short   time_save;  
  u_char  type;                     /*�¼�����*/  /* 0x01:�仯 */
                                                  /* 0x02:��ʱ  */  
                                                  /* 0x04:�ʴ�  */  
                                                  /* 0x08:�������仯���� */   
                                                  /* 0x10:�����ź�*/                                       
  void    *object;                  /*�����źű��ʽ ���� �����仯���ʽ */
};    

struct YK_RULE
{
	struct YK_RULE *next;
	u_int  app_id;										/*ң��Դ��appid*/
	u_int  index;											/*����ң��*/
	u_char condition;									/*bit1=0:ң�ŷֱ���ң��  bit1>0:ң�źϱ���ң�� bit8=0:ң����Ч����ң�� bit8=1:ң����Ч������ң�� */
};
                          
struct ELEMENT                      
{ 
  u_int   index;                    /*ID  */  
  struct  GROUP_DATA *group_p;      /*������ָ��*/
  u_char  type;                     /*������  */  /* 0: YX 1:YC 2:YM 3YK 4:YT 5:YB 6:����*/
  u_char  cpu_no;                   /*CPU��*/
  u_char  group_old;                /*ԭ���*/
  u_char  entry_old;                /*ԭ��Ŀ��*/
  u_char  fun;                      
  u_char  inf;        
  u_int   device_no;                /*һ���豸���*//* device_no=��ѹ�ȼ�*10000000+���*10000+�豸*/
  u_char  done_flag;                /*����Ŀ����״̬*/  /*0: δ���  1:���*/
  u_char  QDS;                      /*Ʒ������*/
  struct  GDD_DATA  description;    /*����*/
  struct  GDD_DATA  actual_value;   /*ʵ��ֵ*/
  u_int   iFFNo;                    //��Ƶ���,��1��ʼ
  u_int   relate;                   /*������Ŀ  */         
  struct YK_RULE    *off_rule;      /*ң�طֹ���  */     
  struct YK_RULE    *on_rule;       /*ң�غϹ��� */      
  struct  GDD_DATA *gdd_data_head;  /*������������*/      
  struct  HOOK *first;              /*�¼�����*/
  u_char  manual_flag;              /*�˹�������־*/
  u_char  manual_gid[32];			/*�˹���������*/
  u_char  goose_inf[32];
};                                    
                                    


struct  GROUP_DATA
{   
  char    description[MAX_DECS_LEN];/*�����������ַ���������*/
  struct  DEV_DATA* devp;           /*����װ��ָ��*/
  u_char  type;                     /*������  */  /* 0: YC 1:YX 2:YM 3YK 4:YT 5:YP 6:����*/
  u_char  trans_flag;               /*ת�����־*/ /*0:��ת����   1:ת����*/
  u_char  update_flag;              /*��Ҫ���±�־*/
  u_char  done_flag;                /*���齨��״̬*/  /*0: δ���  1:���*/
  u_char  group_no;                 /*���*/
  u_char  group_no_old;          		/*ԭʼ���*/
  u_char  cpu_no;                   /*CPU��*/
  u_short element_num;              /*��Ŀ��Ŀ*/
  u_short total_num;                /*ָ�����鳤��*/
  struct  ELEMENT  **element; 
};

struct  DEV_DATA
{ 
  char    description[MAX_DECS_LEN];/*�����������ַ���������*/
  u_short dev_addr;                 /*װ�õ�ַ*/
  u_char  cpu_num;                  /*CPU��Ŀ*/
  u_char  cpu_flag[RDB_MAX_CPU_NUM];/*CPUʹ�ñ�־*/
  u_char  setting_num;              /*��ֵ����Ŀ*/
  u_char  setting_no;               /*��ǰ��ֵ����*/
  u_char  setting_run;              /*���ж�ֵ��*/
  u_char  done_flag;                /*װ�����ݿ⽨��״̬*/  /*0: δ���  1:���*/
  u_short group_num;                /*����Ŀ*/
  u_short total_num;                /*ָ�����鳤��*/
  struct  GROUP_DATA  **group_data; /*������*/
  struct  BIT *bit_desc_head;       /*λ��ͷָ��*/
};

struct  DATABASE
{ 
  u_short dev_num;                  /*װ������*/
  u_short total_num;                /*ָ�����鳤��*/
  struct  DEV_DATA  **dev_data;     /*װ������*/
};

struct  YC_K
{
	float b;									
	float k;
};

struct  LIST                  
{ 
  struct  LIST  *next;
  u_int   list_no;                  /*���ñ���*/
  u_char  list_type;                /* ���ñ�����  0:YC  1:YX  2:YM  3:YK  4:YT  5:YP 6:other*/
  char  	name[50];
  u_int   entry_num;                /*������Ŀ��*/
  u_char  k_flag;										/*ϵ����־*/
  struct  YC_K* k_p;								/*ģ����ϵ���ṹ����ָ��*/
  struct ELEMENT *entry[1];         /*������Ŀָ������*/  
  /*��߸���(entry_num-1)*sizoef(struct ELEMENT*)���ڴ�*/
};

struct  INDEX_LIST
{ 
  struct  INDEX_LIST *next;
  u_int app_id;                     /*���ù�Լ��appid*/
  struct LIST* lists;               /*���ñ�ָ��*/
};


struct  LIST_OWNER
{ 
  struct  LIST_OWNER *next;
  u_int   app_id;                   
  u_int   task_id;                  
  u_int   return_id;
};

/*��¼�������ñ�Ķ��������*/
struct  LIST_OWNER_LIST
{ 
  struct  LIST_OWNER_LIST *next;
  u_int   list_app_id;              /*���ñ�ӵ���ߵ�appid*/
  u_short list_no;                  /*���ñ���*/
  struct  LIST_OWNER * owner_head;
};


/******************װ�ÿⶨ��*******************/
struct  DEV_TAB_DATA
{
  u_short addr;                     /*װ�õ�ַ*/
  u_short dummy_addr;               /*ӳ���ַ*/
  u_short dev_no;                   /*�豸���*/
  u_char  board_addr;               /*�忨��ַ*/
  u_char  com_type;                 /*ͨѶ������*/
  u_char  com_no;                   /*ͨѶ�ڱ��*/
  char  version[40];              /*�汾��*/
  char  type_name[60];            /*װ���ͺ�*/
  char  description[60];          /*װ������*/
  u_char  dev_type;                 /*װ������*/
                                    /* 40: ����װ��*/
                                    /* 41: ����װ��*/
                                    /* 42: ���װ��*/
                                    /* 43: �������װ��*/
                                    /* 44: ����¼��װ��*/
                                    /* 45: ����װ��*/
                                    /* 46: ����У��װ��*/
                                    /* 49: ����*/
};

struct  DEV_TAB
{
  u_int dev_num;
  struct  DEV_TAB_DATA  dev[1];
};
/*******************�������********************/


struct  PROPERTY
{
  u_int  id;                        /*����id*/
  u_char gdd[3];                    /*������������*/
  u_char gid[RDB_MAX_GID_LEN];    
};

struct  EQUIPMENT_DATA
{
  u_int   id;                       /*�豸����id*/
  u_char  num;                      /* ������Ŀ*/
  struct  PROPERTY *prop[RDB_MAX_PROP_NUM];
};

struct  EQUIPMENT
{
  u_int   id;                       /*�豸����id*/
  char  type_name[40];            /*�豸��������*/
  u_int   num;                      /*�豸��Ŀ*/
  struct  EQUIPMENT_DATA *equip_data[1];
};


struct  EQUIPMENT_TAB
{
  u_int   num;                      /*�豸��Ŀ*/
  struct  EQUIPMENT *equip[1];
};




/*********************��ʱԴ*********************/
struct TIME_SOURCE
{
  u_int app_id;     
  int time_out;                       /*��ʱʱ��*/
  int time_remain;                    /*ʣ��ʱ��*/              
  u_char priority;                    /*��ʱԴ�����ȼ�*//* 0-255  0���ȼ����*/
  u_char flag;                        /*��Ч��־*/
  u_char active;                      /*���־*/
};

struct TIME_SOURCES
{
  u_char num;
  struct TIME_SOURCE sources[1];
};
                                        
/*λ��*/      
struct BIT
{
  struct BIT *next;
  u_int index;
  u_char bit_num;                     /*λ����*/
  char *bitDes[1];                  /*λ������*/
};

     
struct   RDB_BOARD_DATA
{
  int con_num;
  int com_num;
  u_char con_sta[SYS_CON_NUM];             /*���ڿ�ͨѶ״̬*/
  u_char con_sta_b[SYS_CON_NUM];
  u_char con_count[SYS_CON_NUM];             
  u_char com_sta[SYS_COM_NUM];             /*����ͨѶ״̬*/
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
      

#define RDB_HOOK_PERIOD             1   //�������ͼ������
#define RDB_SOCKET_CHECK_PERIOD     2   //������ʱ������
#define RDB_SET_CHECK_PERIOD        5   //��ֵ�ȶ����ڣ�Сʱ��

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

