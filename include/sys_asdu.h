/****************************************************************
 * FileName :sys_asdu.h
 * Description:
 *
 * Modify Log:
 *      
 *      
 ****************************************************************/
#ifndef _ASDU_H_
#define _ASDU_H_

#include "sys/types.h"

#define EXT_HEAD_LEN 16
typedef struct EXT_HEAD EXT_HEAD;

struct  EXT_HEAD                                            /*103报文扩展报文头,所有发送到实时数据库和实时数据库发出的报文都有加该头*/
{
    u_char   source_factory_addr[2];                /*源厂站地址*/
    u_char   source_dev_addr[2];                        /*源设备地址*/
    u_char   destination_factory_addr[2];       /*目的厂站地址*/
    u_char   destination_dev_addr[2];               /*目的设备地址*/
    u_char   return_id[4];                                  
    u_char   cpu_no;                                                /*cpu号,从1编号 0为不关心*/
    u_char   sec_no;                                                /*区号,从1编号 0为当前区号或不关心*/
    u_char   reserve[2];                                       /*备用*/
};
struct  ASDU_HEAD
{
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
};

struct  ASDU1
{
    u_char  asdu_type;
    u_char  vsq;            
    u_char  cot;            
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  dpi;
    u_char  time[4];
    u_char  sin;
};
struct  ASDU2
{
    u_char  asdu_type;
    u_char  vsq;            
    u_char  cot;            
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  dpi;
    u_char  relative_time[2];
    u_char  fan[2];
    u_char  time[4];
    u_char  sin;
};
struct  ASDU5
{
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  col;
    u_char  asc[8];
    u_char  data[4];
};
struct  ASDU6
{
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  time[7];
};
struct  asdu7
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  scan_no;
};
struct  ASDU10
{
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  RII;
    u_char  NGD;
    u_char  GIN[2];
    u_char  KOD;
    u_char  GDD0;
    u_char  GDD1;
    u_char  GDD2;
    u_char  GID[1];
};
struct  ASDU11
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  RII;
    u_char  GIN[2];
    u_char  NDE;
    u_char  KOD;
    u_char  GDD0;
    u_char  GDD1;
    u_char  GDD2;
    u_char  GID;
};
struct  ASDU20      
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  dco;
    u_char  rii;
};
struct  ASDU21
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  RII;
    u_char  NOG;
    u_char  GIN[2];
    u_char  KOD;
};
struct  ASDU23
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse;  
    u_char  FAN[2]; 
    u_char  SOF;    
    u_char  time[7];
};
struct  ASDU24
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse;
    u_char  TOO;
    u_char  TOV;
    u_char  FAN[2];
    u_char  ACC;
};
struct  ASDU24_25
{
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse;
    u_char  TOO;
    u_char  TOV;
    u_char  FAN[2];
    u_char  ACC;
};
struct  ASDU26
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse[2];
    u_char  TOV;
    u_char  FAN[2];
    u_char  NOF[2];
    u_char  NOC;
    u_char  NOE[2];
    u_char  INT_TIME[2];
    u_char  time[4];
};
struct  ASDU27
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse[2];
    u_char  TOV;
    u_char  FAN[2];
    u_char  ACC;
    u_char  C1[4];
    u_char  C2[4];
    u_char  K[4];   
};
struct  ASDU28
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse[3];   
    u_char  FAN[2]; 
};
struct  ASDU29
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse;  
    u_char  FAN[2]; 
    u_char  NOT;    
    u_char  TAP[2]; 
    u_char  FUN;    
    u_char  INF;    
    u_char  DPI;    
};
struct  ASDU30
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse[2];   
    u_char  TOV;    
    u_char  FAN[2]; 
    u_char  ACC;    
    u_char  NDV;    
    u_char  NFE[2];     
    u_char  SDV[2];     
};
struct  ASDU31
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse;      
    u_char  TOO;        
    u_char  TOV;    
    u_char  FAN[2]; 
    u_char  ACC;            
}; 
struct  ASDU36      
{
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;    
    u_char  data[5];
};
struct  ASDU40      
{
    u_char  asdu_type;
    u_char  vsq;    
    u_char  cot;    
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  spi;
    u_char  sin;
};
struct  ASDU43          
{
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  dpi;
    u_char  time[4];
    u_char  sin;
};
struct  ASDU46          
{
    u_char  asdu_type;
    u_char  vsq;        
    u_char  cot;        
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  st[2];
    u_char  cd[2];
    u_char  qds;
};
struct  ASDU50  
{
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  mea[1];
};
struct  ASDU64  
{
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  dcc;
    u_char  rii;
};
struct	ASDU220
{
	u_char	asdu_type;
	u_char	vsq;
	u_char	cot;
	u_char	address;
	u_char	fun;
	u_char	inf;	
	u_char	type;	
	u_char  start_time[7];
	u_char  end_time[7];
	u_char  RII;
};


struct  ASDU221 
{
	u_char	asdu_type;
	u_char	vsq;
	u_char	cot;
	u_char	address;
	u_char	fun;
	u_char	inf;	
	u_char  FNAM[2];
	u_char  SNAM;
	u_char  SCQ;
};

struct  ASDU222 
{
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;    
    u_char  FNAM[2];
    u_char  FLEN[4];
    u_char  SOF;
    u_char  time[7];
};

struct  ASDU223
{
 	u_char	asdu_type;
	u_char	vsq;
	u_char	cot;
	u_char	address;
	u_char	fun;
	u_char	inf;	
	u_char  FNAM[2];
	u_char  FLEN[4];
	u_char  FRQ;
};

struct  ASDU224
{	
	u_char	asdu_type;
	u_char	vsq;
	u_char	cot;
	u_char	address;
	u_char	fun;
	u_char	inf;	
	u_char  FNAM[2];
	u_char  SNAM;
	u_char  FLEN[4];
	u_char  SRQ;
};

struct  ASDU225
{	
	u_char	asdu_type;
	u_char	vsq;
	u_char	cot;
	u_char	address;
	u_char	fun;
	u_char	inf;	
	u_char  FNAM[2];	
	u_char  SNAM;	
	u_char  DLEN[2];
	u_char  data[1];
};

struct  ASDU226
{	
	u_char	asdu_type;
	u_char	vsq;
	u_char	cot;
	u_char	address;
	u_char	fun;
	u_char	inf;	
	u_char  FNAM[2];	
	u_char  LSQ;
};

struct  ASDU227
{	
	u_char	asdu_type;
	u_char	vsq;
	u_char	cot;
	u_char	address;
	u_char	fun;
	u_char	inf;	
	u_char  FNAM[2];	
	u_char  SNAM;	
	u_char  AFQ;
};


struct  ASDU230
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;        
    u_char  NOF[2];     
    u_char  LEN1[4];    
    u_char  LEN2[4];    
    u_char  LEN3[4];    
    u_char  time[7];
}; 
struct  ASDU231
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;        
    u_char  NOF[2]; 
    u_char  LEN1[4];    
    u_char  LEN2[4];    
    u_char  LEN3[4];    
    u_char  time[7];
}; 
struct  ASDU232
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;        
    u_char  NOF[2]; 
    u_char  FTYPE;
    u_char  FRAME_NO[2];
    u_char  LEN;
    u_char  data[1];
}; 
struct  ASDU233
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;        
    u_char  NOF[2]; 
    u_char  FTYPE;
    u_char  FRAME_NO[2];    
}; 
struct  ASDU235
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;        
    u_char  TOO;    
    u_char  NOF[2];
}; 
struct  ASDU240
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;        
    u_char  ETYPE;  
    u_char  start_time[7];
    u_char  end_time[7];
}; 
struct  ASDU241
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;        
    u_char  ETYPE;  
    u_char  num[2];
}; 
struct  ASDU242
{   
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;        
    u_char  ETYPE;  
    u_char  start_time[7];
    u_char  end_time[7];
}; 


/******************** ext asdu start *************/
struct  EXT_ASDU
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
};
struct  EXT_ASDU1
{
    EXT_HEAD head;  
    u_char  asdu_type;
    u_char  vsq;            
    u_char  cot;            
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  dpi;
    u_char  time[4];
    u_char  sin;
};
struct  EXT_ASDU2
{
    EXT_HEAD head;  
    u_char  asdu_type;
    u_char  vsq;            
    u_char  cot;            
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  dpi;
    u_char  relative_time[2];
    u_char  fan[2];
    u_char  time[4];
    u_char  sin;
};
struct	EXT_ASDU3
{
	EXT_HEAD head;	
	u_char	asdu_type;
	u_char	vsq;			
	u_char	cot;			
	u_char	address;
	u_char	fun;
	u_char	inf;
	u_char	mea[2];
};
struct	EXT_ASDU4
{
	EXT_HEAD head;	
	u_char	asdu_type;
	u_char	vsq;			
	u_char	cot;			
	u_char	address;
	u_char	fun;
	u_char	inf;
	u_char	val[4];
	u_char	relative_time[2];
	u_char  fan[2];
	u_char  time[4];
};
struct  EXT_ASDU5
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  col;
    u_char  asc[8];
    u_char  data[4];
};
struct  EXT_ASDU6
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  time[7];
};
struct  EXT_ASDU7
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  scan_no;
};
struct  EXT_ASDU10
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  RII;
    u_char  NGD;
    u_char  GIN[2];
    u_char  KOD;
    u_char  GDD0;
    u_char  GDD1;
    u_char  GDD2;
    u_char  GID[1];
};
struct  EXT_ASDU11
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  RII;
    u_char  GIN[2];
    u_char  NDE;
    u_char  KOD;
    u_char  GDD0;
    u_char  GDD1;
    u_char  GDD2;
	u_char	GID[1];
};
struct  EXT_ASDU20      
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  dco;
    u_char  rii;
};
struct  EXT_ASDU21
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  RII;
    u_char  NOG;
    u_char  GIN[2];
    u_char  KOD;
};
struct  EXT_ASDU36      
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;    
    u_char  data[5];
};
struct  EXT_ASDU38              /*步位置*/
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  vti;
    u_char  qds;
};
struct  EXT_ASDU39              /*步位置+时标*/
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;            
    u_char  cot;            
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  vti;
    u_char  qds;
	u_char	time[4];
};
struct  EXT_ASDU40      
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;    
    u_char  cot;    
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  spi;
    u_char  sin;
};
struct  EXT_ASDU41              /*SOE*/
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;            
    u_char  cot;            
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  spi;
    u_char  time[4];
    u_char  sin;
};
struct  EXT_ASDU42              /*双点变位遥信*/
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;            
    u_char  cot;            
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  dpi;
    u_char  sin;
};
struct  EXT_ASDU43          
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  dpi;
    u_char  time[4];
    u_char  sin;
};
struct  EXT_ASDU46          
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;        
    u_char  cot;        
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  st[2];
    u_char  cd[2];
    u_char  qds;
};
struct  EXT_ASDU50  
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  mea[1];
};
struct  EXT_ASDU64  
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  inf;
    u_char  dcc;
    u_char  rii;
};
/********扰动数据**********/
struct  EXT_ASDU23
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse;  
    u_char  FAN[2]; 
    u_char  SOF;    
    u_char  time[7];
};
struct  EXT_ASDU24
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse;
    u_char  TOO;
    u_char  TOV;
    u_char  FAN[2];
    u_char  ACC;
};
struct  EXT_ASDU26
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse[2];
    u_char  TOV;
    u_char  FAN[2];
    u_char  NOF[2];
    u_char  NOC;
    u_char  NOE[2];
    u_char  INT_TIME[2];
    u_char  time[4];
};
struct  EXT_ASDU27
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse[2];
    u_char  TOV;
    u_char  FAN[2];
    u_char  ACC;
    u_char  C1[4];
    u_char  C2[4];
    u_char  K[4];   
};
struct  EXT_ASDU28
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse[3];   
    u_char  FAN[2]; 
};
struct  EXT_ASDU29
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse;  
    u_char  FAN[2]; 
    u_char  NOT;    
    u_char  TAP[2]; 
    u_char  FUN;    
    u_char  INF;    
    u_char  DPI;    
};
struct  EXT_ASDU30
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse[2];   
    u_char  TOV;    
    u_char  FAN[2]; 
    u_char  ACC;    
    u_char  NDV;    
    u_char  NFE[2];     
    u_char  SDV[2];     
};
struct  EXT_ASDU31
{
    EXT_HEAD head;
    u_char  asdu_type;
    u_char  vsq;
    u_char  cot;
    u_char  address;
    u_char  fun;
    u_char  nouse;      
    u_char  TOO;        
    u_char  TOV;    
    u_char  FAN[2]; 
    u_char  ACC;            
}; 

struct GDD18
{
    u_char  DPI;
    u_char  time[4];
    u_char  SIN;
};

struct GDD19
{
    u_char  DPI;
    u_char  relative_time[2];
    u_char  FAN[2];
    u_char  time[4];
    u_char  SIN;
};

struct GDD20
{
    u_char  VAL[4];
    u_char  RET[2];
    u_char  FAN[2];
    u_char  time[4];
};
struct GDD202
{
    u_char  BCD[4];
    u_char  time[4];
};
struct GDD203
{
	u_char DPI;
	u_char time[7];
	u_char SIN;
};
struct GDD204
{
	u_char DPI;
	u_char  relative_time[2];
	u_char FAN[2];
	u_char time[7];
	u_char SIN;
};
struct GDD205
{
    u_char  VAL[4];
    u_char  RET[2];
    u_char  FAN[2];
    u_char  time[7];
};

struct GDD207
{
    u_char  BCD[4];
    u_char  time[7];
};


struct GDD23_19				
{
		u_char  phase_gdd[3];
    u_char  phase;
    u_char  time_gdd[3];
    u_char  time[7];
    u_char  FAN_gdd[3];
    u_char  FAN[2];
};

struct GDD23_22
{
		u_char  val_gdd[3];
    u_char  val[4];
    u_char  time_gdd[3];
    u_char  time[7];
    u_char  FAN_gdd[3];
    u_char  FAN[2];
};

struct GDD23_27
{
		u_char  val_gdd[3];
    u_char  val[4];
    u_char  RET_gdd[3];
    u_char  RET[2];
    u_char  time_gdd[3];
    u_char  time[7];
    u_char  FAN_gdd[3];
    u_char  FAN[2];
};

struct GDD23_18_2N
{
    u_char  time_gdd[3];
    u_char  time[7];
    u_char  FAN_gdd[3];
    u_char  FAN[2];
};
 
/******************** ext asdu end *************/
#endif
