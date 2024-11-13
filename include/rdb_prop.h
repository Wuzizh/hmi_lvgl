 /****************************************************************
 * Description:   �������Ͷ����ļ� 
 *
 * Modify Log:
 * 
 ****************************************************************/
#ifndef _RDB_RDB_PROP_H_
#define _RDB_RDB_PROP_H_

#define RDB_TYPE_NUM        50          /*���Ͷ��������Ŀ����*/
#define RDB_FILED_NUM       4           /*���������*/
#define RDB_TYPE_NAME_LEN   20          /*���͹ؼ�����󳤶�*/
#define RDB_PROP_NAME_LEN   40          /*���Թؼ�����󳤶�*/
#define RDB_FILED_NAME_LEN  40          /*��������󳤶�*/
#define RDB_MAX_FILED_NUM   40          /*�������������*/
#define RDB_MAX_PROP_NUM    50          /*���Ե�������*/


struct RDB_TYPE                         /*�������Ͷ�����Ŀ*/
{
  char name[RDB_TYPE_NAME_LEN];       /*�������͹ؼ���*/
  u_char gdd0;                          
  u_char gdd1;
  u_char gdd2;
};

struct RDB_TYPE_TABLE                   /*�������Ͷ����*/
{
  int num;                              /*����������Ŀ*/
  struct RDB_TYPE type[RDB_TYPE_NUM];
};

struct RDB_PROPERTY                     /*���Զ�����Ŀ*/
{
  u_int id;
  char name[RDB_PROP_NAME_LEN];       /*�������͹ؼ���*/
  char ENname[RDB_PROP_NAME_LEN];    /*�������͹ؼ���*/
  u_char read_only;                     /*ֻ����־*/
};

struct RDB_PROPERTY_FILED               /*������*/
{
  u_int id;                             /*������id*/
  char name[RDB_FILED_NAME_LEN];      /*���������� ����*/
  char ENname[RDB_FILED_NAME_LEN];
  int num;                              /*������Ŀ*/
  struct RDB_PROPERTY prop[RDB_MAX_PROP_NUM];
};

struct RDB_PROPERTY_TABLE               /*���������*/
{
  int num;                              /*��������Ŀ*/
  struct RDB_PROPERTY_FILED *filed[RDB_MAX_FILED_NUM];
  struct RDB_TYPE_TABLE *rdb_type_table;
};

static struct RDB_TYPE_TABLE  rdb_type_table=
{
  14,
  {
    {"STRING",1,0,1,},
    {"BYTE"  ,3,1,1,},
    {"WORD"  ,3,2,1,},
    {"DWORD" ,4,4,1,},
    {"INT"   ,4,4,1,},
    {"GIN"   ,15,4,1},    
    {"YC"    ,15,4,1},  
    {"YX"    ,15,4,1},  
    {"YK"    ,15,4,1},  
    {"YM"    ,15,4,1},  
    {"YT"    ,15,4,1},  
    {"YP"    ,15,4,1},  
    {"ENUM"  ,3,1,1},
    {"XSTRING",1,0,1},  
  }
};

/*��ѹ�ȼ�*/
static struct RDB_PROPERTY_FILED rdb_prop_vol_set=
{
  0x0001,                               /*������id*/      
  "��ѹ�ȼ�",                           /*���������� ����*/   
  "",
  2,                                    /*���Ը���*/
  {
    {01,"id","",CM_YES},                      /*��ѹ�ȼ�id */        
    {02,"����","",CM_YES}                     /*��ѹ�ȼ����� */          
  }
};

/*���*/
static struct RDB_PROPERTY_FILED rdb_prop_bay_set=
{
  0x0002,                               /*������id*/      
  "���",                               /*���������� ����*/  
  "",
  2,                                    /*���Ը���*/
  {
    {01,"id","",CM_YES},                      /*��ѹ�ȼ�id */        
    {02,"����","",CM_YES}                     /*��ѹ�ȼ����� */        
  }
};

/*װ�����õ�����*/
static struct RDB_PROPERTY_FILED rdb_prop_dev_set=
{
  0x5500,                               /*������id*/      
  "װ������",                           /*����������*/
  "",    
  33,                                   /*���Ը���*/
  {
    {1,"�忨��ַ","",CM_YES},                 /* ����id,�������͹ؼ���,ֻ����־ */
    {2,"ͨѶ������","",CM_YES},           
    {3,"ͨѶ�ں�","",CM_YES},
    {4,"ʵ�ʵ�ַ","",CM_YES},
    {5,"ӳ���ַ","",CM_YES},
    {6,"����","",CM_YES},
    {7,"�汾��","",CM_YES},
    {8,"�ͺ�","",CM_YES},            
    {0x5501,"װ�ñ�ʶ",    "Identifier of Device",CM_NO},
    {0x5502,"װ�����ͱ��","Type ID of Device",   CM_NO},           /*��վ��������·ͳһ���*/
    {0x5503,"װ������",    "Name of Device",      CM_NO},           /*0: ��վ��1: �̵籣��װ�ã�2: ����¼������3: ���װ�ã�4: ��ȫ�Զ�װ�ã�5��һ��IED װ�ã�����������������չ*/
    {0x5504,"������·���","No. of Line",         CM_NO},           /*0: ͣ�ã�1: ���У�2: �����У�3:���ޣ�������δ����*/
    {0x5505,"װ�ð汾��",  "Version of Device",   CM_NO},           /*װ��������·����*/
    {0x5506,"װ��CPU��Ŀ", "Number of CPU",       CM_NO},                /*װ��CPU��Ŀ*/
    {0x5507,"CPU1��CPU��", "No. of CPU1",         CM_NO},            
    {0x5508,"CPU1������",  "Description of CPU1", CM_NO},               
    {0x5509,"CPU1�İ汾��","Version of CPU1",     CM_NO},               
    {0x550a,"CPU2��CPU��", "No. of CPU2",         CM_NO},            
    {0x550b,"CPU2������",  "Description of CPU2", CM_NO},               
    {0x550c,"CPU2�İ汾��","Version of CPU2",     CM_NO}, 
    {0x550d,"CPU3��CPU��", "No. of CPU3",         CM_NO},            
    {0x550e,"CPU3������",  "Description of CPU3", CM_NO},               
    {0x550f,"CPU3�İ汾��","Version of CPU3",     CM_NO}, 
    {0x5510,"CPU4��CPU��", "No. of CPU4",         CM_NO},            
    {0x5511,"CPU4������",  "Description of CPU4", CM_NO},               
    {0x5512,"CPU4�İ汾��","Version of CPU4",     CM_NO}, 
    {0x5513,"CPU5��CPU��", "No. of CPU5",         CM_NO},            
    {0x5514,"CPU5������",  "Description of CPU5", CM_NO},               
    {0x5515,"CPU5�İ汾��","Version of CPU5",     CM_NO}, 
    {0x5516,"������·����","Line Name",           CM_NO},
    {0x5517,"IP��ַ1",     "IP Adrress1",         CM_NO},
    {0x5518,"IP��ַ2",     "IP Adrress2",         CM_NO},
    {0x5519,"LD����",      "Name of LD",          CM_NO},
    {0x551a,"����IP1",     "Spare IP Adrress1",   CM_NO},   
    {0x551b,"����IP2",     "Spare IP Adrress2",   CM_NO}   
  }
}; 

/*��·���õ�����*/
static struct RDB_PROPERTY_FILED rdb_prop_line_set=
{
  0x6600,                               /*������id*/      
  "��·",                               /*����������*/
  "Line",
  16,                                   /*���Ը���*/  
  {
    {1,"id","",CM_YES},                       /*�豸id */        
    {2,"����","",CM_YES},                     /*�豸���� */         
    {0x6601,"��·���","",CM_NO},                 /*��վ��������·ͳһ���,0 ����Ϊ��   */               
    {0x6602,"����״̬","",CM_NO},                 /*0: ͣ�ã�1: ���У�2: �����У�������δ����   */       
    {0x6603,"��·���ر��1","",CM_NO},                                                               
    {0x6604,"��·��ѹ�ȼ�","",CM_NO},             /*��λΪKv */                                          
    {0x6605,"��·����","",CM_NO},                 /*��λΪKm */                                          
    {0x6606,"��λ�������","",CM_NO},             /*��λΪ��  */                                         
    {0x6607,"��λ����翹","",CM_NO},             /*��λΪ�� */                                                    
    {0x6608,"��λ�������","",CM_NO},             /*��λΪ�� */                                                    
    {0x6609,"��λ����翹","",CM_NO},             /*��λΪ��  */                                                   
    {9,"�����ݿ�","",CM_NO},                                                                 
    {10,"�����ݿ�","",CM_NO},                                                                 
    {0x660a,"CT���","",CM_NO},                                                                   
    {0x660b,"���β���󸺺ɵ���","",CM_NO} ,      /*1��1A��5:5A; ������δ����  */  
    {0x660c,"��·���ر��2","",CM_NO},
  }
};

/*ĸ�����õ�����*/
static struct RDB_PROPERTY_FILED rdb_prop_busline_set=
{
  0x6700,                               /*������id*/      
  "ĸ��",                               /*����������*/
  "BusLine",
  6,                                    /*���Ը���*/  
  {
    {1,"id","",CM_YES},                       /*�豸id */        
    {2,"����","",CM_YES},                     /*�豸���� */         
    {0x6701,"ĸ�߱��","",CM_NO},             /*��վ��������·ͳһ���,0 ����Ϊ��   */               
    {0x6702,"����״̬","",CM_NO},             /*0: ͣ�ã�1: ���У�2: �����У�������δ����   */       
    {0x6703,"��ѹ�ȼ�","",CM_NO},             /*��λΪKv */                                          
    {0x6704,"���߷�ʽ","",CM_NO}              /*0��3/2���ߣ�1��˫ĸ���ߣ�2��˫ĸ����·���ߣ�3����ĸ���ߣ�4����ĸ�߷ֶν��ߣ�5���������� */                                          
  }
};

/*�������õ�����*/
static struct RDB_PROPERTY_FILED rdb_prop_breaker_set=
{
  0x6800,                               /*������id*/      
  "����",                               /*����������*/ 
  "Switch",
  6,                                    /*���Ը���*/  
  {
    {1,"id","",CM_YES},                       /*�豸id */        
    {2,"����","",CM_YES},                     /*�豸���� */         
    {0x6801,"���ر��","",CM_NO},             /*��վ��������·ͳһ���,0 ����Ϊ��   */               
    {0x6802,"����״̬","",CM_NO},             /*0: ͣ�ã�1: ���У�2: �����У�������δ����   */       
    {0x6803,"��ѹ�ȼ�","",CM_NO},             /*��λΪKv */                                          
    {0x6804,"��������","",CM_NO}              /*0��3/2ĸ�߲࿪��;1��3/2�м俪��;2��˫ĸĸ������;3����·����;4����ĸ�ֶο���;5����·���� */                                          
  }
};

/*��ѹ�����õ�����*/
static struct RDB_PROPERTY_FILED rdb_prop_transformer_set=
{
  0x6900,                               /*������id*/      
  "��ѹ��",                             /*����������*/ 
  "Transformer",
  9,                                    /*���Ը���*/  
  {
    {1,"id","",CM_YES},                       /*�豸id */        
    {2,"����","",CM_YES},                     /*�豸���� */         
    {0x6901,"��ѹ�����","",CM_NO},           /*��վ��������·ͳһ���,0 ����Ϊ��   */   
    {0x6902,"��ѹ������","",CM_NO},           /*0��0: ˫���� 1:������  */              
    {0x6903,"����״̬","",CM_NO},             /*0: ͣ�ã�1: ���У�2: �����У�������δ����   */       
    {0x6904,"��ѹ���ѹ�ȼ�","",CM_NO},       /*��λΪKv */  
    {0x6905,"��ѹ���ѹ�ȼ�","",CM_NO},       /*��λΪKv */  
    {0x6906,"��ѹ���ѹ�ȼ�","",CM_NO},       /*��λΪKv */  
    {0x6907,"�����","",CM_NO}        			/*��λ�׷���(MVA)*/                                          
  }
};

/*��������õ�����*/
static struct RDB_PROPERTY_FILED rdb_prop_generator_set=
{
  0x6a00,                               /*������id*/      
  "�����",                             /*����������*/  
  "Generator", 
  6,                                    /*���Ը���*/  
  {
    {1,"id","",CM_YES},                       /*�豸id */        
    {2,"����","",CM_YES},                     /*�豸���� */         
    {0x6a01,"��������","",CM_NO},           /*��վ��������·ͳһ���,0 ����Ϊ��   */   
    {0x6a02,"����״̬","",CM_NO},             /*0: ͣ�ã�1: ���У�2: �����У�������δ����   */       
    {0x6a03,"��ѹ�ȼ�","",CM_NO},             /*��λΪKv */  
    {0x6a04,"�����","",CM_NO}        			/*��λ�׷���(MW)*/                                          
  }
};

/*�翹�����õ�����*/
static struct RDB_PROPERTY_FILED rdb_prop_reactor_set=
{
  0x6b00,                               /*������id*/      
  "�翹��",                             /*����������*/ 
  "Reactor",
  6,                                    /*���Ը���*/  
  {
    {1,"id","",CM_YES},                       /*�豸id */        
    {2,"����","",CM_YES},                     /*�豸���� */         
    {0x6b01,"�翹�����","",CM_NO},           /*��վ��������·ͳһ���,0 ����Ϊ��   */   
    {0x6b02,"����״̬","",CM_NO},             /*0: ͣ�ã�1: ���У�2: �����У�������δ����   */       
    {0x6b03,"��ѹ�ȼ�","",CM_NO},             /*��λΪKv */  
    {0x6b04,"�����","",CM_NO}        			/*��λ�׷���(MVar)*/                                          
  }
};

/*���������õ�����*/
static struct RDB_PROPERTY_FILED rdb_prop_capacitor_set=
{
  0x6c00,                               /*������id*/      
  "������",                             /*����������*/
  "Capcitor",    
  6,                                    /*���Ը���*/  
  {
    {1,"id","",CM_YES},                       /*�豸id */        
    {2,"����","",CM_YES},                     /*�豸���� */         
    {0x6c01,"���������","",CM_NO},           /*��վ��������·ͳһ���,0 ����Ϊ��   */   
    {0x6c02,"����״̬","",CM_NO},             /*0: ͣ�ã�1: ���У�2: �����У�������δ����   */       
    {0x6c03,"��ѹ�ȼ�","",CM_NO},             /*��λΪKv */  
    {0x6c04,"�����","",CM_NO}        			/*��λ�׷���(MVar)*/                                          
  }
};

/*��բ���õ�����*/
static struct RDB_PROPERTY_FILED rdb_prop_switch_set=
{
  0x6d00,                               /*������id*/      
  "��բ",                               /*����������*/ 
  "Gear",   
  6,                                    /*���Ը���*/  
  {
    {1,"id","",CM_YES},                       /*�豸id */        
    {2,"����","",CM_YES},                     /*�豸���� */         
    {0x6d01,"��բ���","",CM_NO},             /*��վ��������·ͳһ���,0 ����Ϊ��   */  
    {0x6d02,"��բ����","",CM_NO},       			/*0: �ǵص���1:�ص� ������δ����*/  
    {0x6d03,"����״̬","",CM_NO},             /*0: ͣ�ã�1: ���У�2: �����У�������δ����   */       
    {0x6d04,"��ѹ�ȼ�","",CM_NO}              /*��λΪKv */  
                                         
  }
};

/*CT���õ�����*/
static struct RDB_PROPERTY_FILED rdb_prop_ct_set=
{
  0x0012,                               /*������id*/      
  "CT����",                             /*����������*/ 
  "CT Config", 
  2,                                    /*���Ը���*/
  {
    {0,"id","",CM_YES},                     /*�豸id */        
    {1,"����","",CM_YES},                   /*�豸���� */         
      
  }
};

struct RDB_PROPERTY_TABLE rdb_prop_table =
{
	12,                                   /*��������Ŀ*/
	{
		&rdb_prop_vol_set,                  /*��ѹ�ȼ�*/
		&rdb_prop_bay_set,                  /*���*/
	&rdb_prop_dev_set,                  /*װ������*/
	&rdb_prop_line_set,                 /*��·����*/
	&rdb_prop_busline_set,							/*ĸ������*/
	&rdb_prop_breaker_set,							/*��������*/
	&rdb_prop_transformer_set,					/*��ѹ������*/
	&rdb_prop_generator_set,						/*���������*/
	&rdb_prop_reactor_set,							/*�翹������*/
	&rdb_prop_capacitor_set,						/*����������*/
	&rdb_prop_switch_set,								/*��բ����*/
	&rdb_prop_ct_set,                   /*CT����*/
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
	},
	&rdb_type_table
};


#endif
