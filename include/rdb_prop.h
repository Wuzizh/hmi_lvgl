 /****************************************************************
 * Description:   属性类型定义文件 
 *
 * Modify Log:
 * 
 ****************************************************************/
#ifndef _RDB_RDB_PROP_H_
#define _RDB_RDB_PROP_H_

#define RDB_TYPE_NUM        50          /*类型定义最大条目个数*/
#define RDB_FILED_NUM       4           /*属性域个数*/
#define RDB_TYPE_NAME_LEN   20          /*类型关键词最大长度*/
#define RDB_PROP_NAME_LEN   40          /*属性关键词最大长度*/
#define RDB_FILED_NAME_LEN  40          /*属性域最大长度*/
#define RDB_MAX_FILED_NUM   40          /*属性域的最大个数*/
#define RDB_MAX_PROP_NUM    50          /*属性的最大个数*/


struct RDB_TYPE                         /*数据类型定义条目*/
{
  char name[RDB_TYPE_NAME_LEN];       /*数据类型关键词*/
  u_char gdd0;                          
  u_char gdd1;
  u_char gdd2;
};

struct RDB_TYPE_TABLE                   /*数据类型定义表*/
{
  int num;                              /*定义类型数目*/
  struct RDB_TYPE type[RDB_TYPE_NUM];
};

struct RDB_PROPERTY                     /*属性定义条目*/
{
  u_int id;
  char name[RDB_PROP_NAME_LEN];       /*属性类型关键词*/
  char ENname[RDB_PROP_NAME_LEN];    /*属性类型关键词*/
  u_char read_only;                     /*只读标志*/
};

struct RDB_PROPERTY_FILED               /*属性域*/
{
  u_int id;                             /*属性域id*/
  char name[RDB_FILED_NAME_LEN];      /*属性域名称 中文*/
  char ENname[RDB_FILED_NAME_LEN];
  int num;                              /*属性数目*/
  struct RDB_PROPERTY prop[RDB_MAX_PROP_NUM];
};

struct RDB_PROPERTY_TABLE               /*属性域定义表*/
{
  int num;                              /*属性域数目*/
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

/*电压等级*/
static struct RDB_PROPERTY_FILED rdb_prop_vol_set=
{
  0x0001,                               /*属性域id*/      
  "电压等级",                           /*属性域名称 中文*/   
  "",
  2,                                    /*属性个数*/
  {
    {01,"id","",CM_YES},                      /*电压等级id */        
    {02,"名称","",CM_YES}                     /*电压等级名称 */          
  }
};

/*间隔*/
static struct RDB_PROPERTY_FILED rdb_prop_bay_set=
{
  0x0002,                               /*属性域id*/      
  "间隔",                               /*属性域名称 中文*/  
  "",
  2,                                    /*属性个数*/
  {
    {01,"id","",CM_YES},                      /*电压等级id */        
    {02,"名称","",CM_YES}                     /*电压等级名称 */        
  }
};

/*装置配置的属性*/
static struct RDB_PROPERTY_FILED rdb_prop_dev_set=
{
  0x5500,                               /*属性域id*/      
  "装置配置",                           /*属性域名称*/
  "",    
  33,                                   /*属性个数*/
  {
    {1,"板卡地址","",CM_YES},                 /* 属性id,属性类型关键词,只读标志 */
    {2,"通讯口类型","",CM_YES},           
    {3,"通讯口号","",CM_YES},
    {4,"实际地址","",CM_YES},
    {5,"映射地址","",CM_YES},
    {6,"类型","",CM_YES},
    {7,"版本号","",CM_YES},
    {8,"型号","",CM_YES},            
    {0x5501,"装置标识",    "Identifier of Device",CM_NO},
    {0x5502,"装置类型编号","Type ID of Device",   CM_NO},           /*子站内所有线路统一编号*/
    {0x5503,"装置名称",    "Name of Device",      CM_NO},           /*0: 子站；1: 继电保护装置；2: 故障录波器；3: 测控装置；4: 安全自动装置；5：一般IED 装置；其它：保留用于扩展*/
    {0x5504,"所属线路编号","No. of Line",         CM_NO},           /*0: 停用；1: 运行；2: 调试中；3:检修；其它：未定义*/
    {0x5505,"装置版本号",  "Version of Device",   CM_NO},           /*装置所在线路名称*/
    {0x5506,"装置CPU数目", "Number of CPU",       CM_NO},                /*装置CPU数目*/
    {0x5507,"CPU1的CPU号", "No. of CPU1",         CM_NO},            
    {0x5508,"CPU1的描述",  "Description of CPU1", CM_NO},               
    {0x5509,"CPU1的版本号","Version of CPU1",     CM_NO},               
    {0x550a,"CPU2的CPU号", "No. of CPU2",         CM_NO},            
    {0x550b,"CPU2的描述",  "Description of CPU2", CM_NO},               
    {0x550c,"CPU2的版本号","Version of CPU2",     CM_NO}, 
    {0x550d,"CPU3的CPU号", "No. of CPU3",         CM_NO},            
    {0x550e,"CPU3的描述",  "Description of CPU3", CM_NO},               
    {0x550f,"CPU3的版本号","Version of CPU3",     CM_NO}, 
    {0x5510,"CPU4的CPU号", "No. of CPU4",         CM_NO},            
    {0x5511,"CPU4的描述",  "Description of CPU4", CM_NO},               
    {0x5512,"CPU4的版本号","Version of CPU4",     CM_NO}, 
    {0x5513,"CPU5的CPU号", "No. of CPU5",         CM_NO},            
    {0x5514,"CPU5的描述",  "Description of CPU5", CM_NO},               
    {0x5515,"CPU5的版本号","Version of CPU5",     CM_NO}, 
    {0x5516,"所在线路名称","Line Name",           CM_NO},
    {0x5517,"IP地址1",     "IP Adrress1",         CM_NO},
    {0x5518,"IP地址2",     "IP Adrress2",         CM_NO},
    {0x5519,"LD名称",      "Name of LD",          CM_NO},
    {0x551a,"备用IP1",     "Spare IP Adrress1",   CM_NO},   
    {0x551b,"备用IP2",     "Spare IP Adrress2",   CM_NO}   
  }
}; 

/*线路配置的属性*/
static struct RDB_PROPERTY_FILED rdb_prop_line_set=
{
  0x6600,                               /*属性域id*/      
  "线路",                               /*属性域名称*/
  "Line",
  16,                                   /*属性个数*/  
  {
    {1,"id","",CM_YES},                       /*设备id */        
    {2,"名称","",CM_YES},                     /*设备名称 */         
    {0x6601,"线路编号","",CM_NO},                 /*子站内所有线路统一编号,0 保留为空   */               
    {0x6602,"运行状态","",CM_NO},                 /*0: 停用；1: 运行；2: 调试中；其它：未定义   */       
    {0x6603,"线路开关编号1","",CM_NO},                                                               
    {0x6604,"线路电压等级","",CM_NO},             /*单位为Kv */                                          
    {0x6605,"线路长度","",CM_NO},                 /*单位为Km */                                          
    {0x6606,"单位正序电阻","",CM_NO},             /*单位为Ω  */                                         
    {0x6607,"单位正序电抗","",CM_NO},             /*单位为Ω */                                                    
    {0x6608,"单位零序电阻","",CM_NO},             /*单位为Ω */                                                    
    {0x6609,"单位零序电抗","",CM_NO},             /*单位为Ω  */                                                   
    {9,"正序容抗","",CM_NO},                                                                 
    {10,"零序容抗","",CM_NO},                                                                 
    {0x660a,"CT变比","",CM_NO},                                                                   
    {0x660b,"二次侧最大负荷电流","",CM_NO} ,      /*1：1A；5:5A; 其它：未定义  */  
    {0x660c,"线路开关编号2","",CM_NO},
  }
};

/*母线配置的属性*/
static struct RDB_PROPERTY_FILED rdb_prop_busline_set=
{
  0x6700,                               /*属性域id*/      
  "母线",                               /*属性域名称*/
  "BusLine",
  6,                                    /*属性个数*/  
  {
    {1,"id","",CM_YES},                       /*设备id */        
    {2,"名称","",CM_YES},                     /*设备名称 */         
    {0x6701,"母线编号","",CM_NO},             /*子站内所有线路统一编号,0 保留为空   */               
    {0x6702,"运行状态","",CM_NO},             /*0: 停用；1: 运行；2: 调试中；其它：未定义   */       
    {0x6703,"电压等级","",CM_NO},             /*单位为Kv */                                          
    {0x6704,"接线方式","",CM_NO}              /*0：3/2接线；1：双母接线；2：双母带旁路接线；3：单母接线；4：单母线分段接线；5：其它接线 */                                          
  }
};

/*开关配置的属性*/
static struct RDB_PROPERTY_FILED rdb_prop_breaker_set=
{
  0x6800,                               /*属性域id*/      
  "开关",                               /*属性域名称*/ 
  "Switch",
  6,                                    /*属性个数*/  
  {
    {1,"id","",CM_YES},                       /*设备id */        
    {2,"名称","",CM_YES},                     /*设备名称 */         
    {0x6801,"开关编号","",CM_NO},             /*子站内所有线路统一编号,0 保留为空   */               
    {0x6802,"运行状态","",CM_NO},             /*0: 停用；1: 运行；2: 调试中；其它：未定义   */       
    {0x6803,"电压等级","",CM_NO},             /*单位为Kv */                                          
    {0x6804,"开关类型","",CM_NO}              /*0：3/2母线侧开关;1：3/2中间开关;2：双母母联开关;3：旁路开关;4：单母分段开关;5：线路开关 */                                          
  }
};

/*变压器配置的属性*/
static struct RDB_PROPERTY_FILED rdb_prop_transformer_set=
{
  0x6900,                               /*属性域id*/      
  "变压器",                             /*属性域名称*/ 
  "Transformer",
  9,                                    /*属性个数*/  
  {
    {1,"id","",CM_YES},                       /*设备id */        
    {2,"名称","",CM_YES},                     /*设备名称 */         
    {0x6901,"变压器编号","",CM_NO},           /*子站内所有线路统一编号,0 保留为空   */   
    {0x6902,"变压器类型","",CM_NO},           /*0：0: 双绕组 1:三绕组  */              
    {0x6903,"运行状态","",CM_NO},             /*0: 停用；1: 运行；2: 调试中；其它：未定义   */       
    {0x6904,"高压侧电压等级","",CM_NO},       /*单位为Kv */  
    {0x6905,"低压侧电压等级","",CM_NO},       /*单位为Kv */  
    {0x6906,"中压侧电压等级","",CM_NO},       /*单位为Kv */  
    {0x6907,"额定容量","",CM_NO}        			/*单位兆伏安(MVA)*/                                          
  }
};

/*发电机配置的属性*/
static struct RDB_PROPERTY_FILED rdb_prop_generator_set=
{
  0x6a00,                               /*属性域id*/      
  "发电机",                             /*属性域名称*/  
  "Generator", 
  6,                                    /*属性个数*/  
  {
    {1,"id","",CM_YES},                       /*设备id */        
    {2,"名称","",CM_YES},                     /*设备名称 */         
    {0x6a01,"发电机编号","",CM_NO},           /*子站内所有线路统一编号,0 保留为空   */   
    {0x6a02,"运行状态","",CM_NO},             /*0: 停用；1: 运行；2: 调试中；其它：未定义   */       
    {0x6a03,"电压等级","",CM_NO},             /*单位为Kv */  
    {0x6a04,"额定容量","",CM_NO}        			/*单位兆伏安(MW)*/                                          
  }
};

/*电抗器配置的属性*/
static struct RDB_PROPERTY_FILED rdb_prop_reactor_set=
{
  0x6b00,                               /*属性域id*/      
  "电抗器",                             /*属性域名称*/ 
  "Reactor",
  6,                                    /*属性个数*/  
  {
    {1,"id","",CM_YES},                       /*设备id */        
    {2,"名称","",CM_YES},                     /*设备名称 */         
    {0x6b01,"电抗器编号","",CM_NO},           /*子站内所有线路统一编号,0 保留为空   */   
    {0x6b02,"运行状态","",CM_NO},             /*0: 停用；1: 运行；2: 调试中；其它：未定义   */       
    {0x6b03,"电压等级","",CM_NO},             /*单位为Kv */  
    {0x6b04,"额定容量","",CM_NO}        			/*单位兆伏安(MVar)*/                                          
  }
};

/*电容器配置的属性*/
static struct RDB_PROPERTY_FILED rdb_prop_capacitor_set=
{
  0x6c00,                               /*属性域id*/      
  "电容器",                             /*属性域名称*/
  "Capcitor",    
  6,                                    /*属性个数*/  
  {
    {1,"id","",CM_YES},                       /*设备id */        
    {2,"名称","",CM_YES},                     /*设备名称 */         
    {0x6c01,"电容器编号","",CM_NO},           /*子站内所有线路统一编号,0 保留为空   */   
    {0x6c02,"运行状态","",CM_NO},             /*0: 停用；1: 运行；2: 调试中；其它：未定义   */       
    {0x6c03,"电压等级","",CM_NO},             /*单位为Kv */  
    {0x6c04,"额定容量","",CM_NO}        			/*单位兆伏安(MVar)*/                                          
  }
};

/*刀闸配置的属性*/
static struct RDB_PROPERTY_FILED rdb_prop_switch_set=
{
  0x6d00,                               /*属性域id*/      
  "刀闸",                               /*属性域名称*/ 
  "Gear",   
  6,                                    /*属性个数*/  
  {
    {1,"id","",CM_YES},                       /*设备id */        
    {2,"名称","",CM_YES},                     /*设备名称 */         
    {0x6d01,"刀闸编号","",CM_NO},             /*子站内所有线路统一编号,0 保留为空   */  
    {0x6d02,"刀闸类型","",CM_NO},       			/*0: 非地刀；1:地刀 其它：未定义*/  
    {0x6d03,"运行状态","",CM_NO},             /*0: 停用；1: 运行；2: 调试中；其它：未定义   */       
    {0x6d04,"电压等级","",CM_NO}              /*单位为Kv */  
                                         
  }
};

/*CT配置的属性*/
static struct RDB_PROPERTY_FILED rdb_prop_ct_set=
{
  0x0012,                               /*属性域id*/      
  "CT配置",                             /*属性域名称*/ 
  "CT Config", 
  2,                                    /*属性个数*/
  {
    {0,"id","",CM_YES},                     /*设备id */        
    {1,"名称","",CM_YES},                   /*设备名称 */         
      
  }
};

struct RDB_PROPERTY_TABLE rdb_prop_table =
{
	12,                                   /*属性域数目*/
	{
		&rdb_prop_vol_set,                  /*电压等级*/
		&rdb_prop_bay_set,                  /*间隔*/
	&rdb_prop_dev_set,                  /*装置配置*/
	&rdb_prop_line_set,                 /*线路配置*/
	&rdb_prop_busline_set,							/*母线配置*/
	&rdb_prop_breaker_set,							/*开关配置*/
	&rdb_prop_transformer_set,					/*变压器配置*/
	&rdb_prop_generator_set,						/*发电机配置*/
	&rdb_prop_reactor_set,							/*电抗器配置*/
	&rdb_prop_capacitor_set,						/*电容器配置*/
	&rdb_prop_switch_set,								/*刀闸配置*/
	&rdb_prop_ct_set,                   /*CT配置*/
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
