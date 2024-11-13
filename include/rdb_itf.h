
#ifndef _ITF_RDB_H_
#define _ITF_RDB_H_
#include "sys_asdu.h"

#define SOFT_BUS_HEAD_LEN                 52        /*�����߱���ͷ����*/
#define RESP_HEAD_LEN                     8         /*���ز����ṹ�Ĺ���ͷ����*/
#define RDB_NET_MAX_MSG_LEN               10240      /*���Ľӿڱ�����󳤶�*/
#define RDB_ITF_MAX_GID_LEN               20        /*gid������󳤶�*/

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


/*----�첽����ID------*/
#define RDB_PROC_COS_HOOK_MSG             ((u_int)79)
#define RDB_PROC_COS_DATA_HOOK_MSG        ((u_int)80)
#define RDB_PROC_PERIOD_HOOK_MSG          ((u_int)81)
#define RDB_PROC_DEV_STA_MSG              ((u_int)82)
#define RDB_PROC_CONN_STA_MSG             ((u_int)83)
#define RDB_PROC_MON_MSG									((u_int)84)

/*----�ļ�����ӿ�-----*/
#define RDB_PROC_CALL_DIR									((u_int)85)
#define RDB_PROC_CALL_DIR_ACK							((u_int)86)
#define RDB_PROC_CALL_FILE								((u_int)87)
#define RDB_PROC_CALL_FILE_ACK						((u_int)88)
#define RDB_PROC_GET_NO_IN_LIST						((u_int)89)
/*----ע��ң�ر�������-----*/
#define RDB_PROC_REGISTER_YKBS						((u_int)90)

#define  NONE_TYPE       0x00
#define  COS_TYPE        0x01
#define  PERIOD_TYPE     0x02
#define  ASK_TYPE        0x04
#define  FILTER_COS_TYPE 0x08         /*�������仯���� */
#define  COS_DATA_TYPE   0x10         /*��λ����,��������Ϊ���ݽṹ*/
#define  EXPCALC_TYPE    0x20         /*�����ź� */    
#define  YP_CHG_TYPE     0x40
#define  ORIGIN_GROUP_TYPE    0x80         /*��ԭʼ������� */ 

#define  OV              0x01         /*0:�����  1:���*/
#define  BL              0x10         /*0:δ����  1:����*/
#define  SB              0x20         /*0:δȡ��  1:ȡ��*/
#define  NT              0x40         /*0:��ǰֵ  1:�ǵ�ǰֵ*/
#define  IV              0x80         /*0:��Ч    1:��Ч*/


enum   GROUP_TYPE{YC,YX,YM,YK,YT,YP,YXYK,OTHER};
enum   RDB_RET_CODE{RDB_RET_NOTCARE, RDB_RET_INACTIVE, RDB_RET_NORMAL, RDB_RET_DISCONN, RDB_RET_CHKERR};
enum   {RDB_INACTIVE,RDB_ACTIVE};
enum   {RDB_MASTER,RDB_SLAVE};
enum   {RDB_SINGLE,RDB_DOUBLE};
enum   {RDB_COS_HOOK,RDB_PERIOD_HOOK};
enum DEV_STA{                         /*װ������״̬*/
  DEV_STA_STOP,                       /*ͣ��*/
  DEV_STA_RUN,                        /*Ͷ��*/
  DEV_STA_REPAIR,                     /*����*/
  DEV_STA_OTHER                       /*����*/
};                                    
                                      
enum RDB_ERROR_NO                     
{                                     
  RDB_ERR_NONE,                       /*û�д���*/
  RDB_ERR_NO_DEV,                     /*�Ҳ���װ��*/
  RDB_ERR_NO_GROUP,                   /*�Ҳ�����*/
  RDB_ERR_NO_ENTRY,                   /*�Ҳ�����Ŀ*/
  RDB_ERR_DEV_NOT_DONE,               /*װ������δ�������*/
  RDB_ERR_GROUP_NOT_DONE,             /*������δ�������*/
  RDB_ERR_ENTRY_NOT_DONE,             /*��Ŀ����δ�������*/
  RDB_ERR_UNKNOW,                     /*δ֪����*/
};

enum  RDB_EVENT_TYPE{ 
  YC_CH,                              /*ң���λ*/
  YX_CH,                              /*ң�ű�λ*/
  YM_CH,                              /*ң����λ*/
  YP_CH,                              /*ң����λ*/
  YC_SOE,                             /*ң���¼�*/
  YX_SOE,                             /*ң���¼�*/
  YM_SOE,                             /*ң���¼�*/
  YP_SOE,                             /*ң���¼�*/
  SET_CH,                             /*��ֵ�仯*/
  OTHER_EVENT,
  NOT_SAVE
};

#pragma pack(push,1)
struct  INDEX_GDD_DATA                /*�����ñ���ķ��ر��Ľṹ*/
{
  u_int   len;                        /*��addr ��ʼ���㳤��*/
  u_int   app_id;                     /*��Լ��APP_ID*/
  u_int   list_no;                    /*���ñ��*/
  u_int   begin_no;                   /*��Ŀ��*/  /*��0��ʼ���*/
  u_short num;                        /*��ȡ��Ŀ*//*���λ��ʾ����״̬λ 0:û�к������� 1:�к�������*/
  u_char  addr[2];                    /*װ�õ�ַ*/
  u_char  gin[2];
  u_char  kod;  
  u_char  gdd[3];                                                                               
  u_char  gid[1];   
};

struct SB_HEAD
{
  u_int source_app_id;                /*Դappid*/
  u_int source_task_id;               /*Դtaskid*/
  u_int destination_app_id;           /*Ŀ��appid*/
  u_int destination_task_id;          /*Ŀ��taskid*/
} ;

typedef struct SB_HEAD SB_HEAD;

struct PROP_DATA                                                                                 
{          
  u_int   id;                         /*����id*/                                                                   
  u_char  flag;                       /*��Ч��־*/                                                            
  u_char  gdd[3];                                                                               
  u_char  gid[1];                                                                                 
};   


/*�˹�����������*/
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

/*�˹��������ؽ��*/
struct MANUAL_SET_RESULT                                                                                 
{          
  u_int   num;                                                                                         
  u_char  result[1];                                                                                           
};  


struct DEV_NET_STA                                                                                 
{ 
	u_short addr;
	u_char no;              						/*0x01:A��  0x02:B��   0x03: ˫��(װ��״̬) */
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
	u_char type;											 /*  1:����  0������*/
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
/**********************�ӿں������� *******************/

/*ʵʱ���ݿ�ӿڳ�ʼ��*/
extern int rdb_proc_init(void);
/*����װ��ͨ��״̬���ͷ�ʽ*/
extern int rdb_proc_set_devStaMode(u_char mode);
/*������װ��״̬(����˫��ͨѶ״̬������״̬)*/
extern int rdb_proc_get_dev_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_short addr,
/*out*/u_char *state          /*bit0-3:װ������״̬  bit4-5:A��ͨѶ״̬(dpi) bit6-7:B��ͨѶ״̬(dpi)*/
);

/*������װ��״̬(����˫��ͨѶ״̬������״̬)*/
extern int rdb_proc_get_all_dev_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   period					/*��������(ms) 0:��������*/
);

/*����������״̬(��������״̬�ʹ���״̬)*/
extern int rdb_proc_get_all_conn_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   period					/*��������(ms) 0:��������*/
);

/*д����װ��ͨѶ״̬*/
extern int rdb_proc_set_dev_net_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_short addr,
/*in*/u_char no,              /*0x01:A��  0x02:B��   0x03: ˫��(װ��״̬) */
/*in*/u_char state
);

/*д���װ��ͨѶ״̬*/
extern int rdb_proc_set_devs_net_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/struct  DEVS_NET_STA * devs_sta
);

/*д����װ������״̬*/
extern int rdb_proc_set_dev_run_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_short addr,
/*in*/u_char state
);
/*����������ͨѶ״̬*/
extern int rdb_proc_get_com_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_char board_no,
/*in*/u_char com_no,
/*out*/u_char *state
);
/*д��������ͨѶ״̬*/
extern int rdb_proc_set_com_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_char board_no,
/*in*/u_char com_no,
/*in*/u_char state
);
/*�����������ͨѶ״̬*/
extern int rdb_proc_get_con_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_char board_no,
/*in*/u_char con_no,
/*out*/u_char *state
);
/*д���������ͨѶ״̬*/
extern int rdb_proc_set_con_sta
(
/*in*/SB_HEAD *sb_head,
/*in*/u_char board_no,
/*in*/u_char con_no,
/*in*/u_char state
);

/*��ȡ��ǰͨѶװ�õ���������״̬*/
extern int rdb_proc_get_M_S_sta
(
/*in*/SB_HEAD *sb_head,
/*out*/u_char *state
);


/*��ȡ��ǰʱ��*/
extern int rdb_proc_get_time
(
/*in*/SB_HEAD *sb_head,
/*out*/struct SYS_TIME *t
);

/*���õ�ǰʱ��*/  
extern int rdb_proc_set_time
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   appid,                      /*ʱ��Դ��appid*/
/*in*/struct SYS_TIME *t,
/*in*/int  period                         /*��ʱ����*/
);  



/*-----����ң��Ϣ�ļ򵥽ӿ�-----*/     

/*��ң��*/
extern int rdb_proc_readYX
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   appid,                      /*��Լ��APP_ID*/
/*in*/u_int   list_no,                    /*���ñ��*/
/*in*/u_int   begin_no,                   /*��Ŀ��*/  /*��0��ʼ���*/
/*in*/u_int   num,                        /*��ȡ��Ŀ*/
/*out*/u_int  *back_num,                  /*������Ŀ��Ŀ*/
/*out*/u_char   *data
);

/*��ң��*/
extern int rdb_proc_readYC
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   appid,                      /*��Լ��APP_ID*/
/*in*/u_int   list_no,                    /*���ñ��*/
/*in*/u_int   begin_no,                   /*��Ŀ��*/  /*��0��ʼ���*/
/*in*/u_int   num,                        /*��ȡ��Ŀ*/
/*out*/u_int  *back_num,                  /*������Ŀ��Ŀ*/
/*out*/u_short  *data
);

/*��ң��*/
extern int rdb_proc_readYM
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   appid,                      /*��Լ��APP_ID*/
/*in*/u_int   list_no,                    /*���ñ��*/
/*in*/u_int   begin_no,                   /*��Ŀ��*/  /*��0��ʼ���*/
/*in*/u_int   num,                        /*��ȡ��Ŀ*/
/*out*/u_int  *back_num,                  /*������Ŀ��Ŀ*/
/*out*/u_char  *data                      /*num*5*/
);

/*��ң��*/
extern int rdb_proc_readYP
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   appid,                      /*��Լ��APP_ID*/
/*in*/u_int   list_no,                    /*���ñ��*/
/*in*/u_int   begin_no,                   /*��Ŀ��*/  /*��0��ʼ���*/
/*in*/u_int   num,                        /*��ȡ��Ŀ*/
/*out*/u_int  *back_num,                  /*������Ŀ��Ŀ*/
/*out*/u_char   *data 
);

/*��ң��(����������)*/
extern int rdb_proc_readYC_float
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   appid,                      /*��Լ��APP_ID*/
/*in*/u_int   list_no,                    /*���ñ��*/
/*in*/u_int   begin_no,                   /*��Ŀ��*/  /*��0��ʼ���*/
/*in*/u_int   num,                        /*��ȡ��Ŀ*/
/*out*/u_int  *back_num,                  /*������Ŀ��Ŀ*/
/*out*/float  *data,
/*out*/u_char *quality										/*Ʒ������*/
);

/*��ȡ���ñ��������Ŀ��Ŀ*/
extern int rdb_proc_get_list_num
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   app_id,                     /*��Լ��APP_ID*/
/*in*/u_int   list_no,                    /*���ñ��*/
/*out*/u_short   *num                     /*���ñ���Ŀ��*/
);

/*�����ñ��*/
extern int rdb_proc_read_list
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   app_id,                     /*��Լ��APP_ID*/
/*in*/u_int   list_no,                    /*���ñ��*/
/*in*/u_int   begin_no,                   /*��Ŀ��*/  /*��0��ʼ���*/
/*in*/u_int   num,                        /*��ȡ��Ŀ*/
/*in*/u_char  kod,
/*in*/u_short len,                        /*����ĳ���*/
/*out*/u_char   *data                     
);


/*��ȡ������Ŀ*/
extern int rdb_proc_get_relate
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   index,
/*out*/u_int* relate
);


/*��ȡFUN INF*/
extern int rdb_proc_getFunInf
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   index,
/*out*/u_char *fun,
/*out*/u_char *inf
);


/*ע�������Ŀ*/
extern int rdb_proc_registerRelate
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int index,
/*in*/u_int relate
); 

extern int rdb_proc_register_hook
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int app_id,                 /*ע���ߵ�app_id*/
/*in*/u_int task_id,                /*ע���ߵ�task_id*/
/*in*/u_int return_id,              /*ע���ߵ�return_id*/
/*in*/u_int list_app_id,            /*���ñ��app_id*/
/*in*/u_short list_no,              /*���ñ�ı��*/
/*in*/u_short no,                   /*���ñ��е���Ŀ���,0��ʼ*/
/*in*/u_short send_period,          /*��������ʱ��*/
/*in*/u_char type,                  /*�¼�����*/  /* 0x01:�仯 */
                                                  /* 0x02:��ʱ  */  
                                                  /* 0x04:�ʴ�  */  
                                                  /* 0x08:�������仯���� */   
/*in*/u_short len,                  /*�������ͱ��ʽ�ĳ���*/
/*in*/u_char* expression            /*�������ͱ��ʽ*/
);

/*ע��һ�����ñ��������Ŀ��hook*/
extern int rdb_proc_register_list_hook
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int app_id,                 /*ע���ߵ�app_id*/
/*in*/u_int task_id,                /*ע���ߵ�task_id*/
/*in*/u_int return_id,              /*ע���ߵ�return_id*/
/*in*/u_int list_app_id,            /*���ñ��app_id*/
/*in*/u_short list_no,              /*���ñ�ı��*/
/*in*/u_char type,                  /*�¼�����*/  /* 0x01:�仯 */
                                                  /* 0x02:��ʱ  */  
                                                  /* 0x04:�ʴ�  */  
                                                  /* 0x08:�������仯���� */   
/*in*/u_short send_period,  
/*in*/u_short len,
/*in*/u_char* expression            /*�����仯���ͱ��ʽ*/ 
);

/*ע��������Ŀ���¼�*/
/*���ñ��Ӧ��ע���ߵ�app_id,list_no�̶�Ϊ0xffff*/
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
/*in*/u_char* expression            /*�����仯���ͱ��ʽ*/ 
);

/*ע�����ñ����ö���*/
extern int rdb_proc_add_list_owner
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int source_appid,   
/*in*/u_int source_taskid,                       
/*in*/u_int return_id,
/*in*/u_int appid,                        /*��Լ��APP_ID*/                
/*in*/u_short list_no                     /*���ñ��*/                
);    

/*ɾ�����ñ����ö���*/
extern int rdb_proc_delete_list_owner
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int source_appid,   
/*in*/u_int source_taskid,                       
/*in*/u_int return_id,
/*in*/u_int appid,                        /*��Լ��APP_ID*/
/*in*/u_short list_no                     /*���ñ��*/
);  

/*----װ�ÿ��ѯ�ӿ� ---------*/
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

/*---�Ŷ�����˵����ѯ�ӿ� ----*/

/*�����Ŷ�����˵��*/
extern int rdb_proc_search_distub
(
/*in*/SB_HEAD *sb_head,
/*in*/u_short addr,
/*in*/u_char  fun,
/*in*/u_char  inf,
/*out*/u_int  *index, 
/*out*/u_char   *description
);  

/*�����Ŷ�����˵��*/
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

/*------- ���Ľӿ� -----------*/
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


/*����ʵ�����ñ���Ŀ���������Ŀ��*/
extern int rdb_proc_get_group_entry
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int app_id,                       /*���ñ��app_id*/
/*in*/u_short list_no,                    /*���ñ��*/              
/*in*/u_short no,                         /*�������*/  
/*out*/u_int *index                 
);

/*��ȡװ�õĸ�����������װ��*/
extern int rdb_proc_get_dev_num
(
/*in*/SB_HEAD *sb_head,
/*out*/u_short *num                 
);

/*ע��װ��״̬��Ϣ*/
extern int rdb_proc_register_dev_stat
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int  app_id,
/*in*/u_int  task_id,
/*in*/u_int  return_id
);

/*ע�������Ϣ����*/
extern int rdb_proc_register_mon_msg
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int  app_id,
/*in*/u_int  task_id,
/*in*/u_int  return_id
);

/*����װ��no��ȡװ�õ�ַ*/
extern int rdb_proc_get_dev_addr
(
/*in*/SB_HEAD *sb_head,
/*in*/u_short  dev_no,
/*out*/u_short  *real_addr,
/*out*/u_short  *dummy_addr
);


/*ͬ�����Ĳ�ѯ*/
extern int rdb_proc_get_data_synch
(
/*in*/SB_HEAD *sb_head,
/*in*/u_int   app_id,
/*in*/u_int   task_id,
/*in*/u_int   object_id,
/*in*/struct  EXT_ASDU21 *asdu_p,         /*װ����ʵ��ַ*/
/*in*/u_char  filter_flag,                /*���˱��  =YES:���˷�ʽ*/
/*in*/u_short max_len,                    /*���з��ر�����󳤶�*/
/*out*/int    *error_no,                  /* 0:δ֪  
                                             1:��װ�ò����� 
                                             2:��װ������δ������� 
                                             3:
                                                         */
/*out*/u_short *len,                      /*asdu���ĳ���*/
/*out*/u_char  *buf                       /*asdu����*/
);


/*��ȡ�����*/
extern int rdb_proc_get_group_name
(
/*in*/SB_HEAD  *sb_head,
/*in*/u_short  dev_addr,
/*in*/u_char   group_no,
/*out*/u_char  *group_name                /*��󳤶�40���ֽ�*/
);

/*��ȡ������*/
extern int rdb_proc_get_group_type
(
/*in*/SB_HEAD  *sb_head,
/*in*/u_short  dev_addr,
/*in*/u_char   group_no,
/*out*/u_char  *type
);

/*��ȡλ������*/
extern int rdb_proc_get_bit_decs
(
/*in*/SB_HEAD  *sb_head,
/*in*/u_short  dev_addr,
/*in*/u_char   group_no,
/*in*/u_char   entry_no,
/*in*/u_char   no,                        /*λ��� 0��ʼ*/
/*out*/u_char  *decs                      /*��noλ������ ��󳤶�40���ֽ�*/ 
);

/*��ȡλ������(һ��)*/
extern int rdb_proc_get_bits_decs
(
/*in*/SB_HEAD  *sb_head,
/*in*/u_short  dev_addr,
/*in*/u_char   group_no,
/*in*/u_char   entry_no,
/*out*/u_char   *num,                     /*λ����������*/
/*out*/u_char  *decs                      /*λ���������� ���32��λ ÿ��������󳤶�40���ֽ� ���鳤�ȱ����� 32*40*/ 
);
/*---------������Ϣ-----------*/

/*ͨ��id��������б�*/
extern int rdb_proc_get_prop_list_by_id
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_int     id,                       /*������id*/
/*out*/u_int    *num,                     /*������Ŀ*/
/*out*/u_int    *props                    /*����id���� ���50������*/
);

/*ͨ������������������б�*/
extern int rdb_proc_get_prop_list_by_name
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_char    *name,                    /*�������� ����Ϊ40*/
/*out*/u_int    *num,                     /*������Ŀ*/
/*out*/u_int    *props                    /*����id����*/
);

/*ͨ��id�������*/
extern int rdb_proc_get_prop_by_id
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_int     filed_id,                 /*������id*/     
/*in*/u_int     no,                       /*�豸��˳��� 0��ʼ*/ 
/*in*/u_int     prop_id,                  /*����id*/            
/*out*/struct   PROP_DATA *prop_data
);

/*ͨ�����ƻ������*/
extern int rdb_proc_get_prop_by_name
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_char    *filed_name,              /*�������� ����Ϊ40*/  
/*in*/u_int     no,                       /*�豸��˳��� 0��ʼ*/ 
/*in*/u_char    *prop_name,               /*������ ����Ϊ40*/            
/*out*/struct   PROP_DATA *prop_data
);

/*ͨ��id��������*/
extern int rdb_proc_set_prop_by_id
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_int     filed_id,                 /*������id*/     
/*in*/u_int     no,                       /*�豸��˳��� 0��ʼ*/ 
/*in*/u_int     prop_id,                  /*����id*/            
/*in*/struct    PROP_DATA *prop_data
);

/*ͨ��������������*/
extern int rdb_proc_set_prop_by_name
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_char    *filed_name,              /*�������� ����Ϊ40*/  
/*in*/u_int     no,                       /*�豸��˳��� 0��ʼ*/ 
/*in*/u_char    *prop_name,               /*�������� ����Ϊ40*/            
/*in*/struct    PROP_DATA *prop_data
);

/*ͨ��id���һ���豸��Ŀ*/
extern int rdb_proc_get_equip_num_by_id
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_int     filed_id,                 /*������id*/   
/*out*/u_int    *num                      /*������Ŀ*/
);

/*ͨ�����ƻ��һ���豸��Ŀ*/
extern int rdb_proc_get_equip_num_by_name
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_char    *filed_name,              /*�������� ����Ϊ40*/  
/*out*/u_int    *num                      /*������Ŀ*/
);

/*�˹�����*/
extern int rdb_proc_manual_set
(
/*in*/SB_HEAD   *sb_head,
/*in*/struct MANUAL_SET_DATA *set_data,         /*�˹���������*/
/*out*/struct MANUAL_SET_RESULT *result
);

/*����Ŀ����˹�����*/
extern int rdb_proc_manual_clear
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_short   dev_addr, 
/*in*/u_char    group_no, 
/*in*/u_char    entry_no, 
/*out*/u_char   *result                   /*���ؽṹ NO ʧ��  YES �ɹ�*/
);

/*��װ������˹�����*/
extern int rdb_proc_manual_clear_dev
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_short   dev_addr,
/*out*/u_char   *result                   /*���ؽṹ NO ʧ��  YES �ɹ�*/
);

/*���ȫ���˹�����*/
extern int rdb_proc_manual_clear_all
(
/*in*/SB_HEAD   *sb_head,
/*out*/u_char   *result                   /*���ؽṹ NO ʧ��  YES �ɹ�*/
);             

/*�����ñ�����˹�����*/
extern int rdb_proc_manual_clear_list
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_int     list_appid,               /*���ñ��appid*/
/*in*/u_int     list_no,                  /*���ñ��*/
/*out*/u_char   *result                   /*���ؽṹ NO ʧ��  YES �ɹ�*/
);    



/*��ȡ��Ŀ���˹�����״̬*/
extern int rdb_proc_get_manual_sta
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_short   dev_addr, 
/*in*/u_char    group_no, 
/*in*/u_char    entry_no, 
/*out*/u_char   *state   
);


/*��ȡң�����*/
extern int rdb_proc_get_ym_group_no
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_short   dev_addr,
/*out*/u_char   *num,
/*out*/u_char   *group_no                 /*ң�����  ���10��*/
);



/*��ȡװ�ý������״̬*/
extern int rdb_proc_dev_done_sta
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_short   dev_addr, 
/*out*/u_char   *state   
);



/*��ȡ���ݿ�ģ�����״̬*/
extern int rdb_proc_get_rdb_sta
(
/*in*/SB_HEAD   *sb_head,
/*out*/u_char   *state   
);

/*��ȡƷ������*/
extern int rdb_proc_get_entry_qds
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_short   dev_addr, 
/*in*/u_char    group_no, 
/*in*/u_char    entry_no, 
/*out*/u_char   *qds   
);

/*ע�ᶨֵ�仯����*/
extern int rdb_proc_login_set_change
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_int     app_id,
/*in*/u_int     task_id,
/*in*/u_int     return_id,
/*in*/u_char    type
);

/*����GPS״̬*/
extern int rdb_proc_set_gps_sta
(
/*in*/SB_HEAD   *sb_head,
/*in*/u_char    state
);

/*��ȡGPS״̬*/
extern int rdb_proc_get_gps_sta
(
/*in*/SB_HEAD   *sb_head,
/*out*/u_char   *state
);

/*��ȡװ��CPU��Ϣ*/
extern int rdb_proc_get_cpu_info
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*out*/u_char   *cpu_num, 
/*out*/u_char   *cpu_no		
);

#if 0
/*ң�����*/
extern int rdb_proc_write_yx
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     begin_no, 
/*in*/u_int     num, 
/*in*/u_char    *data
);

/*ң�����(�����*/
extern int rdb_proc_write_packed_yx
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     begin_no, 
/*in*/u_int     num, 
/*in*/u_int     byte_num, 
/*in*/u_char    *data
);

/*ң�����*/
extern int rdb_proc_write_yc
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     begin_no, 
/*in*/u_int     num, 
/*in*/u_char    *data	
);

/*ң�����*/
extern int rdb_proc_write_ym
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     begin_no, 
/*in*/u_int     num, 
/*in*/u_char    *data		
);


#endif


/*�ٻ��ļ�Ŀ¼*/
extern int rdb_proc_call_dir
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     cmd_id, 									/*�л������ʶ�����ڸ�����ƥ�� ÿ��ģ��ʹ��һ��ΨһID*/
/*in*/u_char    type, 										/*�ļ�����  0:�����ļ� 1:�����ļ� 3-244:�����ļ� 255:�����ļ�*/
/*in*/u_int     name_len,	
/*in*/u_char    *dir_name,			
/*out*/int      *error_no 								/*��Ӧ��� 0:��ȷ��Ӧ 1:���ڵȴ���һ�ε��÷��� 2:����*/	
);

/*��Ӧ�ٻ��ļ�Ŀ¼*/
extern int rdb_proc_call_dir_ack
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     cmd_id, 									/*�л������ʶ�����ڸ�����ƥ��*/
/*in*/int       result, 									/*��Ӧ��� 0:��ȷ��Ӧ 1:��֧�ָ����� 2:�����ٻ����� 3:����*/
/*in*/u_char    type, 										/*�ļ�����  0:�����ļ� 1:�����ļ� 3-244:�����ļ� 255:�����ļ�*/
/*in*/u_int     name_len,	
/*in*/u_char    *dir_name			
);

/*�ٻ��ļ�*/
extern int rdb_proc_call_file
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     cmd_id, 									/*�л������ʶ�����ڸ�����ƥ��*/
/*in*/u_int     name_len,	
/*in*/u_char    *file_name,
/*out*/int      *error_no 								/*��Ӧ��� 0:��ȷ��Ӧ 1:���ڵȴ���һ�ε��÷��� 2:����*/			
);

/*��Ӧ�ٻ��ļ�*/
extern int rdb_proc_call_file_ack
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_short   dev_addr, 
/*in*/u_int     cmd_id, 									/*�л������ʶ�����ڸ�����ƥ��,ÿ��ģ��ʹ��һ��ΨһID*/
/*in*/int       result, 									/*��Ӧ��� 0:��ȷ��Ӧ 1:��֧�ָ����� 2:�����ٻ����� 3:����*/
/*in*/u_int     name_len,	
/*in*/u_char    *file_name			
);

/*��ȡ��Ŀ��Ӧ�ñ��е����*/
extern int rdb_proc_get_no_in_list
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_int     list_appid,               /*���ñ��appid*/
/*in*/u_int     list_no,                  /*���ñ��*/
/*in*/u_int     index,                  	/*��Ŀ*/
/*out*/int     	*no												/*��Ŀ��Ӧ�ñ��е���� >=0��Ч -1δ�ҵ�*/	
);

/*ע��ң�ر�������*/
extern int rdb_proc_register_ykbs
(
/*in*/SB_HEAD   *sb_head,	
/*in*/u_int     appid,               			/*ң��Դ��appid*/
/*in*/u_int     yk_index,                 
/*in*/u_int     yx_index,                 /*����ң��*/
/*in*/u_char    type,                  		/*1:ң�ط� 2ң�غ� 3ң�طֺ�*/
/*in*/u_char   	condition									/*bit1=0:ң�ŷֱ���ң��  bit1>0:ң�źϱ���ң�� bit8=0:ң����Ч����ң�� bit8=1:ң����Ч������ң�� */
);

extern	struct	SYS_INDEX_LIST *sys_createIndexlist(struct SYS_STRSTREAM *strp,u_int app_id,u_int  task_id,u_int user_id,int event_type);

/************************�����ṹ*************************/
#pragma pack(push,1)
/*------------------------*/
struct READ_YX_REQ                        /*��ң����������ṹ*/
{
/*in*/u_int   appid;                      /*��Լ��APP_ID*/
/*in*/u_int   list_no;                    /*���ñ��*/
/*in*/u_int   begin_no;                   /*��Ŀ��*/  /*��0��ʼ���*/
/*in*/u_int   num;                        /*��ȡ��Ŀ*/
};

struct READ_YX_RESP                       /*��ң�ŷ��ز����ṹ*/
{
/*out*/u_int  back_num;                   /*������Ŀ��Ŀ*/
/*out*/u_char   data[1];
};

/*------------------------*/
struct READ_YC_REQ                        /*��ң����������ṹ*/
{
/*in*/u_int   appid;                      /*��Լ��APP_ID*/
/*in*/u_int   list_no;                    /*���ñ��*/
/*in*/u_int   begin_no;                   /*��Ŀ��*/  /*��0��ʼ���*/
/*in*/u_int   num;                        /*��ȡ��Ŀ*/
};

struct READ_YC_RESP                       /*��ң�ⷵ�ز����ṹ*/
{
/*out*/u_int  back_num;                   /*������Ŀ��Ŀ*/
/*out*/u_short  data[1];
};

/*------------------------*/
struct READ_YM_REQ                        /*��ң����������ṹ*/
{
/*in*/u_int   appid;                      /*��Լ��APP_ID*/
/*in*/u_int   list_no;                    /*���ñ��*/
/*in*/u_int   begin_no;                   /*��Ŀ��*/  /*��0��ʼ���*/
/*in*/u_int   num;                        /*��ȡ��Ŀ*/
};

struct READ_YM_RESP                       /*��ң�����ز����ṹ*/
{
/*out*/u_int  back_num;                   /*������Ŀ��Ŀ*/
/*out*/u_char  data[1];
};

/*------------------------*/
struct READ_YP_REQ                        /*��ң����������ṹ*/
{
/*in*/u_int   appid;                      /*��Լ��APP_ID*/
/*in*/u_int   list_no;                    /*���ñ��*/
/*in*/u_int   begin_no;                   /*��Ŀ��*/  /*��0��ʼ���*/
/*in*/u_int   num;                        /*��ȡ��Ŀ*/
};

struct READ_YP_RESP                       /*��ң�����ز����ṹ*/
{
/*out*/u_int  back_num;                   /*������Ŀ��Ŀ*/
/*out*/u_char   data[1];
};

/*------------------------*/
struct READ_YC_FLOAT_REQ                  /*��ң����������ṹ*/
{
/*in*/u_int   appid;                      /*��Լ��APP_ID*/
/*in*/u_int   list_no;                    /*���ñ��*/
/*in*/u_int   begin_no;                   /*��Ŀ��*/  /*��0��ʼ���*/
/*in*/u_int   num;                        /*��ȡ��Ŀ*/
};

struct READ_YC_FLOAT_RESP                 /*��ң�ⷵ�ز����ṹ*/
{
/*out*/u_int  back_num;                   /*������Ŀ��Ŀ*/
/*out*/u_char data[1];
};
/*------------------------*/

struct READ_LIST_REQ                      /*�����ñ���������*/
{
/*in*/u_int   app_id;                     /*��Լ��APP_ID*/
/*in*/u_int   list_no;                    /*���ñ��*/
/*in*/u_int   begin_no;                   /*��Ŀ��*/  /*��0��ʼ���*/
/*in*/u_int   num;                        /*��ȡ��Ŀ*/
/*in*/u_char  kod;
/*in*/u_short len;                        /*����ĳ���*/
};

struct READ_LIST_RESP                     /*�����ñ���������*/
{
/*out*/struct INDEX_GDD_DATA  data; 
};
/*------------------------*/

struct DISPATCH_TOP_REQ                   /*�·�������������ṹ*/                                                                        
{                                                                                                               
/*in*/u_int   app_id;                                                                                           
/*in*/u_int   task_id;            
/*in*/u_int   return_id;                                                                          
/*in*/u_short len;                                                                                              
/*in*/u_char    buf[1];                                                                                         
};           

struct DISPATCH_TOP_RESP                  /*���ر��Ĳ����ṹ*/                                                                        
{                                                                                                               
/*out*/u_int  return_id;   
/*out*/u_short  len;                                                                                      
/*out*/u_char   buf[1];                                                                                          
};                                                                             
/*------------------------*/                                                                                    
                                                                                                                
struct DISPATCH_BOTTOM_REQ                /*�Ϸ�������������ṹ*/                                                                        
{                                                                                                               
/*in*/u_short len;                                                                                              
/*in*/u_char    buf[1];                                                                                          
};       

struct DISPATCH_BOTTOM_RESP               /*���ر��Ĳ����ṹ*/                                                                        
{                      
/*out*/u_short  len;                                                                                           
/*out*/u_char   buf[1];                                                                                            
};                                                                                     
/*------------------------*/                                                                                    
                                                                                                                
struct REGISTER_HOOK_REQ                  /*ע���¼�*/                                                                        
{    
/*in*/u_int app_id;                       /*ע���ߵ�app_id*/
/*in*/u_int task_id;                      /*ע���ߵ�task_id*/
/*in*/u_int return_id;                    /*ע���ߵ�return_id*/
/*in*/u_int list_app_id;                  /*���ñ��app_id*/
/*in*/u_short list_no;                    /*���ñ�ı��*/
/*in*/u_short no;                         /*���ñ��е���Ŀ���,0��ʼ*/
/*in*/u_short send_period;                /*��������ʱ��*/
/*in*/u_char type;                        /*�¼�����*/  /* 0x01:�仯 */
                                                        /* 0x02:��ʱ  */  
                                                        /* 0x04:�ʴ�  */  
                                                        /* 0x08:�������仯���� */   
/*in*/u_short len;                        /*�������ͱ��ʽ�ĳ���*/
/*in*/u_char expression[1];               /*�������ͱ��ʽ*/
};                                                                                         
/*------------------------*/   

struct REGISTER_HOOKA_REQ                 /*ע��ȫ���¼�*/                                                                        
{    
/*in*/u_int  app_id;
/*in*/u_int  task_id;
/*in*/u_int  return_id;
/*in*/u_char list_type;
/*in*/u_char hook_type;
/*in*/u_short send_period;  
/*in*/u_short len;
/*in*/u_char expression[1];               /*�����仯���ͱ��ʽ*/ 
};                                                                                         
/*------------------------*/  
                                                                            
                                                                                                                
struct REGISTER_DEV_MSG_REQ               /*ע��װ����Ϣ*/                                                                        
{                                                                                                               
/*in*/u_int app_id;
/*in*/u_int task_id;
/*in*/u_short dev_addr;    
/*in*/u_char type;                        /*����ң������ 0:asdu10   1:asdu64 */                                                                           
};                 

                                                                          
/*------------------------*/                                                                                    
                                                                                                                
struct REGISTER_RELATE_REQ                /*ע�������Ŀ*/                                                                        
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
/*in*/u_int appid;                        /*��Լ��APP_ID*/                
/*in*/u_short list_no;                    /*���ñ��*/                
};
/*------------------------*/          

struct DELETE_LIST_OWNER_REQ                    
{
/*in*/u_int source_appid;   
/*in*/u_int source_taskid;                       
/*in*/u_int return_id;
/*in*/u_int appid;                        /*��Լ��APP_ID*/
/*in*/u_short list_no;                    /*���ñ��*/  
};
/*------------------------*/  

  
struct SET_STA_REQ                        /*дͨѶ״̬*/
{
/*in*/u_char board_no;
/*in*/u_char no;
/*in*/u_char state;
};
/*------------------------*/  
  
struct SET_DEV_NET_STA_REQ                /*дװ��ͨѶ״̬*/
{
/*in*/u_short addr;
/*in*/u_char no;                          /*0x01:A��  0x02:B��   0x03: ˫��(װ��״̬) */
/*in*/u_char state;
};
/*------------------------*/  

struct SET_DEVS_NET_STA_REQ               /*д��װ��ͨѶ״̬*/
{
/*in*/struct  DEVS_NET_STA devs_sta;
};
/*------------------------*/  

struct SET_DEV_RUN_STA_REQ                /*дװ������״̬*/
{
/*in*/u_short addr;
/*in*/u_char state;
};
/*------------------------*/  

struct GET_STA_REQ                        /*��ͨѶ״̬*/
{
/*in*/u_char board_no;  
/*in*/u_char no;
};

struct GET_STA_RESP                       
{
/*out*/u_char state;
};
/*------------------------*/
struct GET_DEV_STA_REQ                    /*��װ��״̬*/
{
/*in*/u_short addr;
};

struct GET_DEV_STA_RESP                       
{
/*out*/u_char state;                      /*bit0-3:װ������״̬  bit4-5:A��ͨѶ״̬(dpi) bit6-7:B��ͨѶ״̬(dpi)*/
};
/*------------------------*/

struct GET_ALL_DEV_STA_REQ                /*��װ��״̬*/
{
/*in*/u_int app_id;
/*in*/u_int task_id;
/*in*/u_int period; 
};

/*------------------------*/
struct GET_ALL_CONN_STA_REQ               /*����������״̬*/
{
/*in*/u_int app_id;
/*in*/u_int task_id;
/*in*/u_int period;           					  /*��������(ms)*/
};


struct CONN_STA_MSG_RESP               
{     
/*out*/u_int  return_id;                                    
/*out*/struct CONN_STA conn_sta;
};  
/*------------------------*/

struct GET_TIME_RESP                      /*��ȡ��ǰʱ���������*/        
{
/*out*/struct SYS_TIME t;
};
/*------------------------*/
struct SET_TIME_REQ                       /*��ȡ��ǰʱ���������*/  
{
/*in*/u_int   appid;                      /*ʱ��Դ��appid*/
/*in*/struct SYS_TIME t;
/*in*/int  period;                        /*��ʱ����*/
};
/*------------------------*/

struct SEARCH_WITH_ACC_REQ                /*�����Ŷ�����(ģ����)*/
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

struct SEARCH_DISTUB_REQ                  /*�����Ŷ�����(״̬��)*/
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

struct GET_RELATE_REQ                     /*��ȡ������Ŀ�������*/
{                                         
/*in*/u_int   index;                      
};                 
                                          
struct GET_RELATE_RESP                    /*��ȡ������Ŀ�������*/        
{                                         
/*out*/u_int relate;                      
};                 
/*------------------------*/              
                                          
struct GET_FUNINF_REQ                     /*��ȡFUN INF�������*/
{                                         
/*in*/u_int   index;                      
};                 
                                          
struct GET_FUNINF_RESP                    /*��ȡFUN INF�������*/       
{
/*out*/u_char fun;
/*out*/u_char inf;
};
/*------------------------*/

/*------------------------*/              
                                          
struct GET_LIST_NUM_REQ                   /*��ȡ���ñ��������Ŀ�� �������*/
{                                          
/*in*/u_int   app_id;                     /*��Լ��APP_ID*/
/*in*/u_int   list_no;                    /*���ñ��*/               
};                  
                                           
struct GET_LIST_NUM_RESP                  /*��ȡ���ñ��������Ŀ�� �������*/       
{                                         
/*out*/u_short   num;                     /*���ñ���Ŀ��*/
};                 
/*------------------------*/              
struct REGISTER_LIST_HOOK_REQ             /*ע��һ�����ñ�������Ŀ��hook �������*/
{                                          
/*in*/u_int app_id;                       /*ע���ߵ�app_id*/
/*in*/u_int task_id;                      /*ע���ߵ�task_id*/
/*in*/u_int return_id;                    /*ע���ߵ�return_id*/
/*in*/u_int list_app_id;                  /*���ñ��app_id*/
/*in*/u_short list_no;                    /*���ñ�ı��*/
/*in*/u_char type;                        /*�¼�����*/  /* 0x01:�仯 */
                                                  /* 0x02:��ʱ  */  
                                                  /* 0x04:�ʴ�  */  
                                                  /* 0x08:�������仯���� */   
/*in*/u_short send_period;  
/*in*/u_short len;
/*in*/u_char expression[1];              /*�����仯���ͱ��ʽ*/ 
};                 
                                          
/*------------------------*/

struct CREATE_DEV_LIST_REQ               /*ע��װ��ȫ������ �������*/
{                                         
/*in*/u_int app_id;                       /*���ñ��APP_ID*/                
/*in*/u_short list_no;                   /*���ñ��*/   
/*in*/u_char list_type;                  /*���ñ�����*/    
/*in*/u_short dev_addr;                  /*װ�õ�ַ*/
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

struct COS_HOOK_MSG_RESP                    /*��λhook��Ϣ*/    
{                                         
/*out*/u_char type;                         /*enum RDB_EVENT_TYPE*/
/*out*/u_int  return_id;   
/*out*/u_int  list_app_id;                  /*���ñ�app_id*/
/*out*/u_short list_no;                                 
/*out*/u_short no;
/*out*/u_short  len;                                                                                      
/*out*/u_char   buf[1];                       /*asdu10����*/
};          
                                          
/*------------------------*/

struct COS_DATA_HOOK_MSG_RESP               /*��λhook��Ϣ �����ݽṹ����*/    
{                                         
/*out*/u_char type;                         /*enum RDB_EVENT_TYPE*/
/*out*/u_int  return_id;   
/*out*/u_int  list_app_id;                  /*���ñ�app_id*/
/*out*/u_short list_no;                                 
/*out*/u_short no;
/*out*/u_char  dpi;                                                                                      
/*out*/u_char  time[7];                     /*ʱ��*/
/*out*/u_short dev_addr;
/*out*/u_char  group_no;
/*out*/u_char  entry_no;

};          
                                          
/*------------------------*/

struct PERIOD_HOOK_MSG_RESP                 /*����hook��Ϣ*/    
{                                         
/*out*/u_int  return_id;   
/*out*/u_short  len;                                                                                      
/*out*/u_char   buf[1];                       /*asdu10����*/
};          
                                          
/*------------------------*/

struct GET_DEV_NUM_RESP                     /*��ȡװ�õĸ�����������װ��*/    
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
/*in*/struct  EXT_ASDU21 asdu_p;          /*װ����ʵ��ַ*/
/*in*/u_char  filter_flag;                /*���˱��  =YES:���˷�ʽ*/
/*in*/u_short max_len;                    /*���з��ر�����󳤶�*/
};         

struct GET_DATA_SYNCH_RESP                
{     
/*out*/int     error_no;                  /* 0:δ֪  
                                             1:��װ�ò����� 
                                             2:��װ������δ������� 
                                             3:
                                          */
/*out*/u_short len;                       /*asdu���ĳ���*/                                          
/*out*/u_char  buf[1];                        /*asdu����*/
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
/*in*/u_char   no;                        /*λ��� 0��ʼ*/
};         

struct GET_BIT_DECS_RESP               
{     
/*out*/u_char  decs[1];                  /*��noλ������ ��󳤶�40���ֽ�*/ 
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
/*out*/u_char  decs[1];                 /*λ���������� ���32��λ ÿ��������󳤶�40���ֽ� ���鳤�ȱ����� 32*40*/ 
};          
                                          
/*------------------------*/
struct GET_PROP_LIST_BY_ID_REQ             
{
/*in*/u_int     id;                     /*������id*/
};         

struct GET_PROP_LIST_BY_ID_RESP               
{
/*out*/u_int    num;                     /*������Ŀ*/
/*out*/u_int    props[1];                /*����id���� ���50������*/
};          
                                          
/*------------------------*/

struct GET_PROP_LIST_BY_NAME_REQ               
{
/*in*/u_char    name[40];                /*��������*/
};         

struct GET_PROP_LIST_BY_NAME_RESP               
{
/*out*/u_int    num;                     /*������Ŀ*/
/*out*/u_int    props[1];                /*����id���� ���50������*/
};          
                                          
/*------------------------*/

struct GET_PROP_BY_ID_REQ             
{
/*in*/u_int     filed_id;                 /*������id*/     
/*in*/u_int     no;                       /*�豸��˳��� 0��ʼ*/ 
/*in*/u_int     prop_id;                  /*����id*/   
};         

struct GET_PROP_BY_ID_RESP               
{
/*out*/struct   PROP_DATA prop_data;
};          
                                          
/*------------------------*/

struct GET_PROP_BY_NAME_REQ             
{
/*in*/u_char    filed_name[40];           /*�������� ����Ϊ40*/  
/*in*/u_int     no;                       /*�豸��˳��� 0��ʼ*/ 
/*in*/u_char    prop_name[40];            /*�������� ����Ϊ40*/  
};         

struct GET_PROP_BY_NAME_RESP               
{
/*out*/struct   PROP_DATA prop_data;
};          
                                          
/*------------------------*/

struct SET_PROP_BY_ID_REQ             
{
/*in*/u_int     filed_id;                 /*������id*/     
/*in*/u_int     no;                       /*�豸��˳��� 0��ʼ*/ 
/*in*/u_int     prop_id;                  /*����id*/            
/*in*/struct    PROP_DATA prop_data;
};         
                                          
/*------------------------*/
struct SET_PROP_BY_NAME_REQ             
{
/*in*/u_char    filed_name[40];           /*�������� ����Ϊ40*/  
/*in*/u_int     no;                       /*�豸��˳��� 0��ʼ*/ 
/*in*/u_char    prop_name[40];            /*�������� ����Ϊ40*/            
/*in*/struct    PROP_DATA prop_data;
};         
       
/*------------------------*/

struct GET_EQUIP_NUM_BY_ID_REQ             
{
/*in*/u_int     filed_id;                 /*������id*/   
};         

struct GET_EQUIP_NUM_BY_ID_RESP               
{
/*out*/u_int    num;                      /*������Ŀ*/
};          
                                          
/*------------------------*/

struct GET_EQUIP_NUM_BY_NAME_REQ             
{
/*in*/u_char     filed_name[40];          /*���������� ����Ϊ40*/   
};         

struct GET_EQUIP_NUM_BY_NAME_RESP               
{
/*out*/u_int    num;                      /*������Ŀ*/
};          
                                          
/*------------------------*/


struct MANUAL_SET_REQ             
{
/*in*/struct MANUAL_SET_DATA set_data;  /*�˹���������*/
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
/*out*/u_char   result;                 /*���ؽ�� NO ʧ��  YES �ɹ�*/
};          
                                          
/*------------------------*/

struct MANUAL_CLEAR_DEV_REQ             
{
/*in*/u_short   dev_addr; 
};         

struct MANUAL_CLEAR_DEV_RESP               
{
/*out*/u_char   result;                 /*���ؽ�� NO ʧ��  YES �ɹ�*/
};          
                                          
/*------------------------*/

struct MANUAL_CLEAR_ALL_RESP               
{
/*out*/u_char   result;                 /*���ؽ�� NO ʧ��  YES �ɹ�*/
};          
                                          
/*------------------------*/
struct MANUAL_CLEAR_LIST_REQ             
{
/*in*/u_int     list_appid;               /*���ñ��appid*/
/*in*/u_int     list_no;                  /*���ñ��*/
};         

struct MANUAL_CLEAR_LIST_RESP               
{
/*out*/u_char   result;                 /*���ؽ�� NO ʧ��  YES �ɹ�*/
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
/*out*/u_char   group_no[10];           /*ң�����  ���10��*/
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

struct CALL_DIR_REQ              /*�ٻ��ļ�Ŀ¼*/
{
/*in*/u_short   dev_addr;
/*in*/u_int     cmd_id; 									/*�л������ʶ�����ڸ�����ƥ��*/
/*in*/u_char    type; 										/*�ļ�����  0:�����ļ� 1:�����ļ� 3-244:�����ļ� 255:�����ļ�*/
/*in*/u_int     name_len;	
/*in*/u_char    dir_name[1];	
};  

struct CALL_DIR_RESP             /*�ٻ��ļ�Ŀ¼*/
{
/*out*/int      error_no; 								/*��Ӧ��� 0:��ȷ��Ӧ 1:���ڵȴ���һ�ε��÷��� 2:����*/	
};  

/*------------------------*/

struct CALL_DIR_ACK_REQ          /*��Ӧ�ٻ��ļ�Ŀ¼*/
{
/*in*/u_short   dev_addr;
/*in*/u_int     cmd_id; 									/*�л������ʶ�����ڸ�����ƥ��*/
/*in*/int       result; 									/*��Ӧ��� 0:��ȷ��Ӧ 1:��֧�ָ����� 2:�����ٻ����� 3:����*/
/*in*/u_char    type; 										/*�ļ�����  0:�����ļ� 1:�����ļ� 3-244:�����ļ� 255:�����ļ�*/
/*in*/u_int     name_len;	
/*in*/u_char    dir_name[1];	
};  

/*------------------------*/

struct CALL_FILE_REQ              /*�ٻ��ļ�*/
{
/*in*/u_short   dev_addr;
/*in*/u_int     cmd_id; 									/*�л������ʶ�����ڸ�����ƥ��*/
/*in*/u_int     name_len;	
/*in*/u_char    file_name[1];	
};  

struct CALL_FILE_RESP             /*�ٻ��ļ�*/
{
/*out*/int      error_no; 								/*��Ӧ��� 0:��ȷ��Ӧ 1:���ڵȴ���һ�ε��÷��� 2:����*/	
};  

/*------------------------*/

struct CALL_FILE_ACK_REQ              /*�ٻ��ļ�*/
{
/*in*/u_short   dev_addr;
/*in*/u_int     cmd_id; 									/*�л������ʶ�����ڸ�����ƥ��*/
/*in*/int       result; 									/*��Ӧ��� 0:��ȷ��Ӧ 1:��֧�ָ����� 2:�����ٻ����� 3:����*/
/*in*/u_int     name_len;	
/*in*/u_char    file_name[1];	
};  

/*------------------------*/

struct GET_NO_IN_LIST_REQ              /*��ȡ��Ŀ��Ӧ�ñ��е����*/
{
/*in*/u_int     list_appid;               /*���ñ��appid*/
/*in*/u_int     list_no;                  /*���ñ��*/
/*in*/u_int     index;                  	/*��Ŀ*/
};  

struct GET_NO_IN_LIST_RESP             /*�ٻ��ļ�*/
{
/*out*/int     	no;												/*��Ŀ��Ӧ�ñ��е���� >=0��Ч -1δ�ҵ�*/	
};  

/*------------------------*/
struct REGISTER_YKBS_REQ              /*ע��ң�ر�������*/
{
/*in*/u_int     appid;               			/*ң��Դ��appid*/
/*in*/u_int     yk_index;
/*in*/u_int     yx_index;                  	/*����ң��*/
/*in*/u_char    type;                  		/*1:ң�ط� 2ң�غ� 3ң�طֺ�*/
/*in*/u_char   	condition;								/*bit1=0:ң�ŷֱ���ң��  bit1>0:ң�źϱ���ң�� bit8=0:ң����Ч����ң�� bit8=1:ң����Ч������ң�� */
}; 



/***************����/Ӧ�� �����ṹ*******************/

/*�������ݽṹ*/
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

/*Ӧ�����ݽṹ*/
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
