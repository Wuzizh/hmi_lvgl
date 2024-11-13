 /***************************************************************************
 * Description:	规约模块接口文件实现模块
 *
 *			1. 对于函数入口参数: 对于b_xxx变量，表明其为布尔量，只有两
 *                      种状态: true 或者 false，以CM_YES代表true，而CM_NO表示false
 *                      对于返回值有两种状态(成功或者失败),以CM_OK表示成功,CM_ERROR
 *                      表示失败。
 *
 *                      对于临时变量,推荐使用CM_YES表示成功，CM_NO表示失败
 *
 * Modify Log:
 *		1.很多模块没有经过验证,等待在后续工作中进一步细化(07年5月23日)
 *
 ***************************************************************************/
 
#ifndef _SYS_PROTOCOL_INTERFACE_H_
#define _SYS_PROTOCOL_INTERFACE_H_

#ifndef _WIN32
#include <arpa/inet.h>
#include <netinet/tcp.h>
#else
#include <WinSock2.h>
#endif

#include "os_func.h"
#include "sys_dir.h"

#include "sys_extern.h"
#include "sys_func.h"
#include "sys_asdu.h"
#include "softbus.h"
#include "board_manage_itf.h"
#include "rdb_itf.h"
#include "rdb_init.h"
#include "sys_stream.h"
#include "sys_sio.h"
#include "fbufcircle.h"

/*****************************数据结构定义部分*****************************/

#define MAX_SEND_BUFFER_SIZE	512
#define MAX_DISP_BUFFER_SIZE	256
#define SIZE_1K                 1024 
#define MAX_INI_TXT_LEN	       (SIZE_1K * 8)

enum	ENUM_NET_USED
{
	NET_A_USED		=	0x01,
	NET_B_USED		=	0x02,
};

enum	ENUM_ASDU64_CTL
{
	ASDU10_CTL	= 0,
	ASDU64_CTL	= 1
};

enum	ENUM_CALL_BACK_ID		/* 回调函数返回ID */
{
	PERIOD_CALLBACK_ID	=	0,
	COM_CALLBACK_ID	=	1
};

enum	CTRL_TYPE		/* 控制命令属性 */
{
	CTRL_SEL_TYPE ,
	CTRL_EXE_TYPE ,
	CTRL_CANCEL_TYPE ,
	CTRL_NONE_TYPE
};

enum	DATA_TYPE		/* 基本数据类型 */
{
	PE_ASCII_TYPE ,
	PE_FLOAT_TYPE ,
	PE_INT8_TYPE ,
	PE_INT16_TYPE ,
	PE_INT32_TYPE ,
	PE_UINT8_TYPE ,
	PE_UINT16_TYPE ,
	PE_UINT32_TYPE ,
	PE_BIT_STRING_TYPE	/* 位串类型, 具体数据类型参见BIT_STRING_DATA */
};
extern u_char g_aDTlen[];

enum	QUALITY_TYPE	/* 品质描述 */
{
	OVERFLOW_TYPE,	/* 溢出 */
	ERROR_TYPE,		/* 差错 */
	VALID_TYPE,		/* 有效 */
	INVALID_TYPE,	/* 无效 */
	OTHER_TYPE		/* 其他 */
};

enum	S_COT_TYPE		/* 监视方向传送原因 */
{
	S_CHANGE_CODE			= 	1,	
	S_PERIOD_SEND_CODE		= 	2,
	S_RESET_FCB_CODE		= 	3,
	S_RESET_CU_CODE		= 	4,
	S_RE_START_CODE		= 	5,
	S_POWER_ON_CODE		= 	6,
	S_TEST_MODE_CODE		= 	7,
	S_SYN_TIME_CODE		= 	8,
	S_ALL_CALL_CODE		= 	9,
	S_ALL_CALL_STOP_CODE 	= 	10,
	S_LOCAL_OPER_CODE		=	11,
	S_REMOTE_OPER_CODE		=	12,
	S_CMD_ACK_CODE		=	20,
	S_CMD_NCK_CODE		=	21,
	S_WAVE_TRANS_CODE		=	31,
	S_GEN_WRITE_CMD_ACK_CODE	=	40,
	S_GEN_WRITE_CMD_NCK_CODE	=	41,
	S_READ_CMD_VALID_CODE	=	42,
	S_READ_CMD_INVALID_CMD	=	43,
	S_GEN_WRITE_CMD_OK_CODE	=	44
};

enum	M_COT_TYPE		/* 控制方向传送原因 */
{
	M_SYS_TIME_CODE		=	8,
	M_ALL_CALL_CODE		=	9,
	M_NORMAL_CMD_CODE		=	20,
	M_WAVE_CMD_CODE		=	31,
	M_GEN_WRITE_CMD_CODE		=	40,
	M_GEN_READ_CMD_CODE		=	42
};

enum	GIN_CONTINUE_TYPE	/* GIN是否连续 */
{
	CONTINUE_TYPE,	/* GIN连续 */
	NOT_CONTINUE_TYPE	/* GIN不连续 */
};

enum	KOD_OF_DATA_TYPE
{
	KOD_OF_ACTUAL_VALUE_TYPE	=	0x01,
	KOD_OF_RANGE_TYPE		=	0x03,
	KOD_OF_PRECISION_TYPE	=	0x05,
	KOD_OF_DIMENSION_TYPE	=	0x09,
	KOD_OF_DESCRIPTION_TYPE	=	0x0a
};

enum	PHASE_TYPE	/* 故障相别 */
{
	A_PHASE,
	B_PHASE,
	C_PHASE,
	CA_PHASE,
	AB_PHASE,
	BC_PHASE,
	ABC_PHASE,
	OTHER_PHASE
};

enum	DPI_TYPE
{
	DPI_ZERO_TYPE		=	0x00,
	DPI_OFF_TYPE		=	0x01,
	DPI_ON_TYPE		=	0x02,
	DPI_UNKNOWN_TYPE	=	0x03
};

enum	FAULT_INTERFACE_ID	/* 故障接口ENUM */
{
	FAULT_PHASE ,
	FAULT_DISTANCE,
	FAULT_MAX_ZERO_CURRENT,
	FAULT_TABLE,
	OTHER_FAULT
};

struct ACT_DATA_STRU		/* 保护动作信号数据结构 */
{
	u_char	dpi;
	u_char	rel_time[2];		/* 相对时间 */	
	u_char	fault_no[2]; 	/* 故障序号*/
	u_char  ms_l;		/* 七字节时标	*/
	u_char	ms_h;
	u_char  minute;
	u_char  hour;	
	u_char  day;
	u_char  month;
	u_char  year_l;
};

struct	BIT_STRING_DATA	/* 位串数据结构 */
{
	int	num;		/* bit位的个数 */
	u_char	data[16];	/* bit数据，8位占一个字节 */
};

struct PROTOCOL_YC_DATA	/* 遥测数据结构 */
{
	u_char	group;
	u_char	entry;  //从1开始
	union
	{
		short      sval;
		int      s_value;	/* 整数遥测 */
		float    f_value;	/* 浮点数遥测 */
		u_char   avalue[4];
	}data;
	enum	QUALITY_TYPE	quality; /* 品质描述队列 */
};

struct PROTOCOL_YM_DATA	/* 遥脉数据结构 */
{
	u_char	group;
	u_char	entry;
	u_int	data;	
	enum	QUALITY_TYPE	quality; /*品质描述队列*/
};	

struct PROTOCOL_YX_DATA	/* 遥信数据结构 */
{
	u_char	group;
	u_char	entry;
	u_char	dpi;
	struct	SYS_TIME	t;	/*时标*/
	enum	QUALITY_TYPE	quality; /* 品质描述队列 */
};	

struct PROTOCOL_YT_DATA	/* 设点数据结构 主要用于对上规约向数据库下发遥调命令 */
{
	u_char			group;
	u_char 		entry;
	u_char			rii;
	enum	M_COT_TYPE 	cot;
	enum	CTRL_TYPE 	ctrl_type;
	enum	DATA_TYPE	data_type;
	union
	{
		int		i_value;	/*有符号整数设点命令*/
		u_int		ui_value;	/*无符号整数设点命令*/
		float		f_value;	/*浮点值设点命令*/
	}input;
};


struct PROTOCOL_RESET_DATA	/* 复归数据结构 主要用于对上规约向数据库下发命令 */
{
	enum	M_COT_TYPE cot;	
	u_char	fun;
	u_char inf;
	u_char dco;
	u_char rii;
};

struct PROTOCOL_YK_DATA	/* 遥控数据结构 对上规约,对下规约均可用 */
{
	u_char	group;
	u_char	entry;
	u_char	dpi;
	u_char rii;
	int 	cot;  /*传送原因*/
	enum	CTRL_TYPE 	ctrl_type;
};	

struct PROTOCOL_ACT_DATA	 /* 动作信号数据结构 */
{
	u_char		group;
	u_char		entry;
	enum		S_COT_TYPE cot;  /*传送原因*/
	struct		ACT_DATA_STRU	data;
};

struct PROTOCOL_WAVE_DATA	/* 波形数据结构 */
{	
	char 	source_file_path[MDL_HTDB_FILE_NAME_LENGTH]; 
	char 	dest_file_path[MDL_HTDB_FILE_NAME_LENGTH]; 
	int		NOF;
	struct 	SYS_TIME t;
};	

struct PROTOCOL_SETTING_NO_DATA	/* 定值区号数据结构 */
{
	u_char	group;
	u_char	entry;
	u_char 	rii;
	enum	S_COT_TYPE cot;				
	u_char	data;
};	

struct PROTOCOL_SETTING_DATA	/* 定值(保护测量也可以复用)数据结构 */
{
	u_char	group;
	u_char	entry;
	enum	DATA_TYPE  type;	/*数据类型*/
	union
	{
		union
		{
			int	i_value;				/* 有符号整数定值 */
			u_int	ui_value;				/* 无符号整数定值 */
			float	f_value;				/* 浮点数整数定值 */
			char	str[128];				/* 字符串定值 */
			struct  BIT_STRING_DATA bit_string;	/* 位串定值 */
		}actual_value;
						/*实际值*/
		
		union
		{
			int	i_value[3];
			float	f_value[3];
		}range;			/*量程*/

		int	precision[2];	/*精度*/
		char	dimension[32];	/*量纲*/
		char	description[128];	/*描述*/
	}data;
};	

struct PROTOCOL_FAULT_DATA		/* 故障信息数据结构 */
{
	u_char	group;
	u_char	entry;	
	
	u_short nof;

	u_char  fan_num;
	u_short fan[32];
	
	enum	FAULT_INTERFACE_ID	interface_id;
	union
	{
		enum	PHASE_TYPE	fault_phase;	/*故障相别*/
		enum	PHASE_TYPE	trip_phase;	/*跳闸相别*/
		float	fault_distance;		/*故障测距*/	
		float	max_zero_current;		/* 最大零序电流 */
		float	max_fault_current;		/*最大故障相电流*/
		float	max_fault_voltage;		/*最大故障相电压*/
	}fault_para;
	struct	SYS_TIME	t;	/*时标*/
}; 

#pragma pack(push,1)
struct  PROTOCOL_REQ_ASDU_DATA	/* 双机之间传送数据 */
{
	u_short	dev_addr;
	int		data_length;
	u_char		data[1];
};

struct	PROTOCOL_REQ_DATA		/* 双机之间相互传送报文 */
{	
	int	interface_id;
	union
	{		
		struct  PROTOCOL_REQ_ASDU_DATA  data;
	}req;
};
#pragma pack(pop)

struct PROTOCOL_GROUP_DESC		/*组标题数据结构*/
{
	u_char	group;
	char	desc[32];
};

/* 用来读取枚举变量 */ 
#define STRING_MODE_NUM	64

struct STRING_MODE
{
	char mode[STRING_MODE_NUM];
};

#define MODE_RANGE(mode)	(sizeof(mode) / STRING_MODE_NUM)

extern struct STRING_MODE true_false_mode[2];
extern struct STRING_MODE yes_no_enum[2];

#pragma pack(push,1)
struct ASDU_STRU
{
	u_char type;
	u_char vsq;
	u_char cot;
	u_char addr;
	u_char fun;
	u_char inf;
	u_char data[1];
};

struct FIX_103
{
	u_char start;
	u_char code;
	u_char dev_addr;
	u_char cs;
	u_char end;
};

struct UNFIX_103
{
	u_char start1;
	u_char len1;
	u_char len2;
	u_char start2;
	u_char code;
	u_char dev_addr;

	struct ASDU_STRU asdu;
};

union UNION_CONT 
{
	struct FIX_103	fix;
	struct UNFIX_103	unfix;
	u_char			buf[4 * 1024];
};

#pragma pack(pop)

struct	CALLBACK_FUNC_DATA
{
	struct	CALLBACK_FUNC_DATA	*prev;
	struct	CALLBACK_FUNC_DATA	*next;
	void	(*callback)(void *);
	void	*callback_data;		
	int	period_callback_id;
};	

struct	SYS_CALLBACK_DATA
{
	u_char		b_is_init_ok;
	
//	MSG_Q_ID	msg_id;
	FBufCircle		msg_cc;
	int		com_no;
//	SEM_ID  task_sem;
	
	int		timerId;
	int		period_callback_id;		
	struct	CALLBACK_FUNC_DATA	*perioid_callback_head;
	
	void	(*dispatch_callback)(void *,u_char *buf,int length);
	void	*dispatch_callback_data;		
	
	int		comId;
	void	(*com_callback)(void *,u_char *buf,int length);
	void	*com_callback_data;	
	
	char	protocol_name[256];
};

#define MAX_CONFIG_GROUP_NUM	128
struct DEVICE_GROUP_ATTR_STRU
{
	u_char	group_num;
	u_char config_group[MAX_CONFIG_GROUP_NUM];
	u_char original_group[MAX_CONFIG_GROUP_NUM];
	u_char	entry[MAX_CONFIG_GROUP_NUM];
	char	description[MAX_CONFIG_GROUP_NUM][64];
	u_char cpu[MAX_CONFIG_GROUP_NUM];
};


#define SYS_MAX_QUE_SIZE         8192
#define SYS_MAX_QUE_NODE_LEN     4096

/*
	动态队列
*/
struct SYS_QUE_NODE
{
	u_int len;
	u_char *buffer;
};

struct SYS_QUE
{
	sem_t  lock_id;	
	u_int  lock_flag;	
	
	u_int  size;
	u_int  head;
	u_int  tail;
	struct SYS_QUE_NODE **node;
}; 

/*
	在嵌入式操作系统中,为避免内存碎片,以下优先级队列采用静态分配原则.
	由于采用静态分配,某些拷贝性能可能不是很好,但暂时不考虑统一的内存
	管理功能
*/
struct SYS_STATIC_QUE_NODE
{
	u_int len;
	u_char *buffer;
};

struct SYS_STATIC_QUE
{
	sem_t   lock_id;
	u_int   lock_flag;	

	u_int	que_size;
	u_int	que_node_size;
	u_int	head;
	u_int	tail;

	struct SYS_STATIC_QUE_NODE **node;
};

/*****************************数据结构定义部分结束*****************************/


/********************************接口函数的定义********************************/
/*发送报文数据到串口*/
extern void sys_send_sio_msg
(
	u_char com_no, 
	u_char *data, 
	int len, 
	u_short src_dev_addr, /*监视参数填写*/
	u_short des_dev_addr
);
 
/* 发送遥测 */
extern	void sys_send_yc
(
	struct	SB_HEAD *sb_head,
	u_short	dev_addr,	
	int		num,				/*个数*/
	enum	DATA_TYPE		data_type,
	enum	S_COT_TYPE		cot,
	enum	GIN_CONTINUE_TYPE	type, /*当GIN连续时，PROTOCOL_YC_DATA 中的组号条目号仅仅填写第一个即可*/
	struct 	PROTOCOL_YC_DATA	*data,/*数据列表*/
	u_char	watch_type,
	u_char	watch_no
);

/* 发送遥信 */
extern	void sys_send_yx
(
	struct 	SB_HEAD *sb_head,
	u_short	dev_addr,	
	int		num,	/*个数*/
	enum	S_COT_TYPE		cot,
	enum	GIN_CONTINUE_TYPE	type, /*当GIN连续时，PROTOCOL_YX_DATA 中的组号条目号仅仅填写第一个即可*/
	struct 	PROTOCOL_YX_DATA	*data,/*数据列表*/
	u_char	watch_type,
	u_char	watch_no
);

extern void sys_compare_yc
(
	struct SB_HEAD* p_sb_head,
	u_short	dev_addr,
	u_char num,
	int* p_first_send_flag,
	u_char	group,
	u_char	base_item,
	float* p_old_data,
	struct PROTOCOL_YC_DATA* p_new_data,
	u_char	watch_type,
	u_char	watch_no
);

/* 比较遥信状态, 产生全遥信或者变位遥信 */
extern void sys_compare_yx 
(
	struct SB_HEAD *p_sb_head, 
	u_short	dev_addr,
	u_char num, 
	int	*p_first_send_flag,
	u_char	group,
	u_char	base_item,
	u_char *p_old_dpi, 
	u_char *p_new_dpi,
	u_char	watch_type,
	u_char	watch_no	
);

/* 发送遥脉 */
extern	void sys_send_ym
(
	struct 	SB_HEAD *sb_head ,
	u_short	dev_addr ,	
	int		num,	/*个数*/
	enum	S_COT_TYPE		cot,
	enum	GIN_CONTINUE_TYPE	type, /*当GIN连续时，PROTOCOL_YM_DATA 中的组号条目号仅仅填写第一个即可*/
	struct 	PROTOCOL_YM_DATA	*data,/*数据列表*/
	u_char	watch_type,
	u_char	watch_no
);

/*发送保护动作信号*/
extern	void sys_send_act
(
	struct	SB_HEAD *sb_head,
	u_short	dev_addr,
	struct 	PROTOCOL_ACT_DATA	*data,	
	int	b_event_add_ret,	/* 是否添加延时返回信号 */	
	u_char	watch_type,
	u_char	watch_no
);

/* 发送遥控反校 */
extern	void sys_send_yk
(
	struct 	SB_HEAD *sb_head,
	u_short	dev_addr,
	struct 	PROTOCOL_YK_DATA *data,
	u_char	watch_type,
	u_char	watch_no
);

/*定值区号的上送*/
extern int sys_send_setting_no
(
	struct	SB_HEAD *sb_head,
	u_short	dev_addr,
	struct	PROTOCOL_SETTING_NO_DATA	*data, /*定值区号数值*/
	u_char	watch_type,
	u_char	watch_no
);

/*
	Function:	定值上送
	Parameter:
	1.	num
		个数
	2.	enum	GIN_CONTINUE_TYPE	type
		当GIN连续时，PROTOCOL_SETTING_DATA 中的组号条目号仅仅填写第一个即可
	3.	struct 	PROTOCOL_SETTING_DATA	*data
		定值队列	
*/
extern void sys_send_setting
(
	struct	SB_HEAD *sb_head,
	u_short	dev_addr,	
	int		num,
	u_char	rii,
	enum	S_COT_TYPE cot,
	enum	GIN_CONTINUE_TYPE	type,
	enum	KOD_OF_DATA_TYPE	kod,
	struct 	PROTOCOL_SETTING_DATA	**pp_data,
	u_char	watch_type,
	u_char	watch_no
);

/*保护测量上送*/
extern void sys_send_analog
(
	struct	SB_HEAD *sb_head,
	u_short	dev_addr,	
	int		num,/*个数*/
	u_char	rii,
	enum	S_COT_TYPE cot,
	enum	GIN_CONTINUE_TYPE	type, /*当GIN连续时，PROTOCOL_SETTING_DATA 中的组号条目号仅仅填写第一个即可*/
	struct 	PROTOCOL_SETTING_DATA	*data, /*保护测量队列*/	
	u_char	watch_type,
	u_char	watch_no
);

/* 故障信息上送:包括故障选相、故障测距、最大故障零序电流 */
extern void sys_send_fault_data
(
	struct 	SB_HEAD *sb_head,
	u_short	dev_addr,
	struct		PROTOCOL_FAULT_DATA	*data,
	enum	S_COT_TYPE cot,
	u_char		watch_type,
	u_char		watch_no	
);

/* 波形文件上送 */
extern int sys_send_wave
(
	struct 	SB_HEAD *sb_head,
	u_short	dev_addr,			
	struct 	PROTOCOL_WAVE_DATA	*data 
);

/*回复给数据库组标题*/
extern void sys_send_group_desc
(
	struct		SB_HEAD *sb_head,
	struct		EXT_HEAD *ext_head_p,
	u_short	dev_addr,	
	int		num,/*个数*/
	u_char		rii,
	enum	S_COT_TYPE cot,
	struct 	PROTOCOL_GROUP_DESC	*data, /*组标题队列*/	
	u_char		watch_type,
	u_char		watch_no
);

/*
	向备机发送数据
*/
//extern int sys_send_slave_machine_data
//(
//	struct SB_HEAD *sb_head,
//	u_short dev_addr, 
//	u_char *data, 
//	u_short len,
//	u_char  watch_type,
//	u_char  watch_no
//);

/* 实现时间的偏移计算，可以进行加减操作，精度到秒 */
extern void sys_adjust_time 
(
	struct SYS_TIME *time_p, 
	u_int second, 
	int sign_flag
);

/* 填送包头, 对于定值区号，定值等特别注意填写source_head_p, 对上调度规约也可以用此填写报头 */
extern void sys_fill_ext_head
(
	struct EXT_HEAD *target_head_p, 
	struct EXT_HEAD *source_head_p, 
	u_short dev_addr, 
	int b_dispatch_top		/*CM_YES 调度规约填写, CM_NO 对下规约填写*/
);

/*
	对上规约调用此模块向数据库发送遥控报文
*/
extern	int sys_dispatch_top_yk
(
	struct 	SB_HEAD *sb_head,
	u_short	dev_addr,
	struct 	PROTOCOL_YK_DATA *data,
	u_char		*p_ret,	/*返回包装报文头指针, 用于规约模块中反校校验*/
	u_char		watch_type,
	u_char		watch_no
);

/* 对上规约向数据库发送复归命令 */
extern	void sys_dispatch_top_reset
(
	struct 	SB_HEAD *sb_head,
	struct 	PROTOCOL_RESET_DATA *data,
	u_char		watch_type,
	u_char		watch_no
);


/* 对上规约向数据库发送设点命令命令 */
extern	int sys_dispatch_top_yt
(
	struct 	SB_HEAD *sb_head,
	u_short	dev_addr ,
	struct 	PROTOCOL_YT_DATA *data,
	u_char		*p_ret,
	u_char		watch_type,
	u_char		watch_no
);

/* 对上规约向数据库发送过路命令, 主要用于读写定值等通用分类服务命令 */
extern	void sys_dispatch_top_pass
(
	struct 	SB_HEAD *sb_head,
	u_short	dev_addr ,
	u_char		*asdu_send_buf,	/*填写ASDU内容*/
	int		asdu_len,
	u_char		watch_type,
	u_char		watch_no
);

extern	void sys_dispatch_bottom_pass
(
	struct 	SB_HEAD *sb_head,
	struct EXT_HEAD *source_head_p, 
	u_short	dev_addr ,
	u_char		*asdu_send_buf,	/*填写ASDU内容*/
	int		asdu_len,
	u_char		watch_type,
	u_char		watch_no
);


/*等待实时数据库就绪*/
extern void sys_suspend_for_rdb(struct SB_HEAD *sb_head);

/*等待历史数据库就绪*/
//extern void sys_suspend_for_htdb_ready (struct SB_HEAD *sb_head);

/*等待主备机同步模块就绪*/
//extern void sys_suspend_for_dccu_ready (struct SB_HEAD *sb_head);

/*判断调试工具是否打开本规约的调试开关*/
extern int sys_can_disp_infor
(
	u_char watch_type, 
	u_char watch_no
);


/*判断调试信息是否可以输出*/
extern int sys_can_disp_dbg_infor
(
	u_char watch_type, 
	u_char watch_no, 
	int *p_old_dbg_state
);

/*向规约信息打印字符*/
extern void sys_disp_str
(
	u_char watch_type, 
	u_char watch_no, 
	const char *out_str
);

extern void sys_disp_language_str
(
	u_char watch_type,
	u_char watch_no,
	const char *chinese_out_str,
	const char *english_out_str
);

extern void sys_disp_language_data
(
	u_char watch_type,
	u_char watch_no,
	int data,
	const char *chinese_note,
	const char *english_note,
	int b_is_sign
);


extern void sys_disp_language_buf
(
	u_char watch_type,
	u_char watch_no,
	u_char *buf,
	int len,
	const char *chinese_note,
	const char *english_note,
	int b_disp_asci
);


/*向规约信息打印IP地址*/
extern void sys_disp_ip_addr 
(
	u_char watch_type, 
	u_char watch_no, 
	char *note, 
	u_int ip_addr
);

/*向规约信息打印数据*/
extern void sys_disp_data
(
	u_char watch_type, 
	u_char watch_no, 
	int data, 
	const char *note, 
	int b_is_sign
);

/*向规约信息打印成串字符*/
extern void sys_disp_buf
(
	u_char watch_type, 
	u_char watch_no, 
	u_char *buf, 
	int len, 
	const char *note, 
	int b_disp_asci
);

/*向规约信息打印成串数字(浮点数, 整数)*/
extern void sys_disp_ini_data_type_array
(
	u_char watch_type, u_char watch_no, 
	int disp_num, u_char *disp_code, 
	enum DATA_TYPE data_type, const char *note
);

/*恢复组态文件指针到正确位置*/
extern int sys_restore_ini_fp
(
	struct SYS_STRSTREAM *strp
);

/*获得装置信息*/
extern int sys_get_dev_cfg
(
	struct SYS_STRSTREAM *strp, 
	int dev_addr, 
	char *p_ret, 
	int cfg_max_len
);

/*获得装置组号特征*/
extern int sys_get_dev_group_attr
(
	struct SYS_STRSTREAM *strp, 
	int dev_addr, 
	struct DEVICE_GROUP_ATTR_STRU *p_dev_cfg
);

/*获取以太网装置的组特征*/
extern int sys_get_dev_protocol_infor
(
	struct DEVICE_GROUP_ATTR_STRU *p_dev_cfg,	/*装置库*/
	u_short dev_addr, 				/*装置地址*/
	const char *key_name, 			/*关键字: 遥测，遥信等*/
	u_char *p_ret_num, 				/*读取的组个数*/
	u_char *p_ret_group,				/*具体每组的组号*/
	u_char *p_ret_entry,				/*具体每组条目的个数*/
	u_char default_group,			/*若读取不成功, 默认组号*/
	u_int max_ret_num				/*最大返回长度，防止越限*/
);

/*获得以太网装置的原始组号*/
extern int sys_find_original_group
(
	struct DEVICE_GROUP_ATTR_STRU *p_dev_cfg,	/*装置库*/
	u_short dev_addr, 
	u_char map_group, 
	u_char *cpu_no, 
	u_char *original_group
);

/*获得规约信息 此处com理解为common, 不是串口*/
extern int sys_get_com_cfg
(
	struct SYS_STRSTREAM *strp, 
	char *p_ret, 
	int cfg_max_len
);

/*从组态中读取整数*/
extern int sys_read_ini_int_var
(
	char *name, 
	char *ini_str, 
	int default_value
);

/*从组态中读取浮点数*/
extern float sys_read_ini_float_var 
(
	char *name, 
	char *ini_str, 
	float default_value
);

/*从组态中读取字符串*/
extern int sys_read_ini_str_var
(
	char *name, 
	char *ini_str, 
	char *p_ret
);

/*从组态中读取装置地址*/
extern int sys_read_ini_dev_addr
(
	char *name, 
	char *ini_str, 
	int *p_addr, 
	u_char no
);

/*从组态中读取一组整数*/
extern int sys_read_ini_int_array
(
	char *name, 
	char *ini_str, 
	u_char *p_ret, 
	int  max_num, 
	int  b_read_as_hex, 
	int  b_cvt_word
);

/*从组态中读取一组字符串*/
extern int sys_read_ini_str_array
(
	char *name, 
	char *ini_str, 
	char *end_char, 
	char **p_ret, 
	int  max_num, 
	int b_just_get_num
);

/* 从组态中读取IP地址
   RETURN: CM_OK, CM_ERROR
*/
extern int sys_read_ini_ip_addr
(
	char *name, 
	char *ini_str, 
	u_int *ip_addr
);

/*从组态中读取枚举变量*/
extern u_char sys_read_ini_enum_var
(
	char *name, 
	char *ini_str, 
	const struct STRING_MODE *p_mode, 
	u_char str_num
);

/* 客户端与服务器端建立连接
   RETURN：成功socket_id; 失败-1
*/
extern int sys_get_tcp_connected_id
(
	int port,
	u_int ip
);

/*从ASCII码得到十六进制数字*/
extern u_char sys_get_hex(u_char ascii_code);

/*从ASCII码得到二进制数字*/
extern u_char sys_get_dig_code(u_char asci_code);

/*从二进制数字得到ASCII码*/
extern u_char sys_get_ascii_code(u_char dig_code);

/*BCD和十进制数字转换*/
extern u_char sys_bcd_to_dec(u_char bcd_code);

/*十进制->BCD*/
extern u_char sys_dec_to_bcd(u_char dec_code);

/*计算累加和*/
u_short sys_calc_short_sum(u_char *p_code, u_short len);
u_char sys_calc_char_sum(u_char *p_code, u_short len);

/*计算异或和*/
extern u_char sys_calc_chk_of_xor(u_char *p_code, u_short len);

/*计算modbus和*/
extern u_short sys_calc_chk_of_modbus(u_char *p_code, u_short len);

/*初始化规约回调函数*/
extern	struct	SYS_CALLBACK_DATA *init_protocol_callback
(
	u_int app_id,
	u_int group_id,
	u_int task_id,
	u_int msg_num,
	u_int stack_size,
	sem_t	*semID,
	char	*protocol_name	/*规约的名称*/
);

/*注册定时回调函数*/
extern	int sys_register_period_callback
(
	struct	SYS_CALLBACK_DATA *ndp, 
	void(*callback)(void *), 
	void *callback_data, 
	struct SYS_TIME *t
);

/*注册串口回调函数*/
extern	int sys_register_com_callback
(
	struct SYS_CALLBACK_DATA *ndp, 
	int com_no, 
	void (*com_callback)(void *,u_char *buf,int length), 
	void *com_callback_data
);

/*注册对下规约回调函数*/
extern	int sys_register_dispatchdown_callback
(
	struct	SYS_CALLBACK_DATA *ndp, 
	u_int app_id,	
	u_int task_id,
	int dev_num, 
	u_short *dev_addr,
	u_char  *ctrl_type,
	void (*dispatchdown_callback)(void *,u_char *buf,int length),
	void *dispatchdown_callback_data
);

/*注册对上规约回调函数*/
extern int sys_register_dispatchtop_callback
(
	struct SYS_CALLBACK_DATA *ndp, 
	void (*dispatchtop_callback)(void *,u_char *buf, int length), 
	void *dispatchtop_callback_data
);

/*UDP组波*/
extern int sys_get_group_udp_id (u_int port, u_int group_addr);

/*UDP广播*/
extern int sys_get_special_udp_id_by_port (u_int port, BOOL b_do_recv);

/* 外部函数,暴露给用户使用 
   FUNCTION: 生成队列, que_size--->队列大小, 
             b_thread_safe: CM_YES(产生互斥); CM_NO(不产生互斥)
*/

extern struct SYS_QUE *sys_create_que
(
	u_int que_size, 
	int b_thread_safe
);

/* 外部函数,暴露给用户使用 
   FUNCTION: 生成队列节点, len--->数据长度, buffer--->数据内容
*/
extern struct SYS_QUE_NODE *sys_create_que_node
(
	u_int len, 
	u_char *buffer
);

/* 外部函数,暴露给用户使用 
   FUNCTION: 释放队列节点
*/
extern void sys_free_que_node
(
	struct SYS_QUE_NODE *node_p
);

/* 涉及互斥操作,暴露给用户使用 
   FUNCTION: 获取队列的使用情况
   RETURN:   队列已经使用数据区
*/
extern int sys_get_que_used_size
(
	struct SYS_QUE *que_p
);


/* 涉及互斥操作,暴露给用户使用 
   FUNCTION: 获取队列的使用情况
   RETURN:   队列已经空闲数据区
*/
extern int sys_get_que_free_size
(
	struct SYS_QUE *que_p
);

/* 涉及互斥操作,暴露给用户使用 
   FUNCTION: 将数据添加到队列头端
   RETURN:   CM_ERROR, CM_OK   
*/

extern int sys_push_que_front
(
	struct SYS_QUE *que_p, 
	struct SYS_QUE_NODE *node_p
);

/* 涉及互斥操作,暴露给用户使用 
   FUNCTION: 将数据添加到队列末端
   RETURN:   CM_ERROR, CM_OK   
*/

extern int sys_push_que_back
(
	struct SYS_QUE *que_p, 
	struct SYS_QUE_NODE *node_p
);


/* 涉及互斥操作,暴露给用户使用 
   FUNCTION: 将数据PEEK, 不删除数据
   RETURN:   CM_OK OR CM_ERROR
   index取0到usedSize - 1之间, 取0为tail + 1,
   取usedSize - 1为head内容   
*/
extern int sys_peek_que 
(
	struct SYS_QUE *que_p, 
	u_int index,
	struct SYS_QUE_NODE *p_ret
);


/* 涉及互斥操作,暴露给用户使用 
   FUNCTION: 从队列头获取数据
*/

extern struct SYS_QUE_NODE *sys_pop_que_front
(
	struct SYS_QUE *que_p
);


/* 涉及互斥操作,暴露给用户使用 
   FUNCTION: 从队列尾巴读取数据
*/

extern struct SYS_QUE_NODE *sys_pop_que_back
(
	struct SYS_QUE *que_p
);

/* 涉及互斥操作,暴露给用户使用 
   FUNCTION: 清除队列
*/
extern void sys_clear_que
(
	struct SYS_QUE *que_p
);


/*
	在嵌入式操作系统中,为避免内存碎片,以下优先级队列采用静态分配原则.
	由于采用静态分配,某些拷贝性能可能不是很好,但暂时不考虑统一的内存
	管理功能
*/

/* 外部函数,暴露给用户使用 
   FUNCTION: 生成队列, que_size--->队列大小, que_node_size--->数据node数据块大小 
             b_thread_safe: CM_YES(产生互斥); CM_NO(不产生互斥)
*/
extern struct SYS_STATIC_QUE *sys_create_static_que
(
	u_int que_size, 
	u_int que_node_size, 
	int b_thread_safe
);

extern void sys_free_static_que
(
	struct SYS_STATIC_QUE *p_que
);

extern int sys_get_static_que_used_size
(
	struct SYS_STATIC_QUE *que_p
);

extern int sys_get_static_que_free_size 
(
	struct SYS_STATIC_QUE *que_p
);

extern int sys_push_static_que_front
(
	struct SYS_STATIC_QUE *que_p, 
	struct SYS_STATIC_QUE_NODE *node_p
);

extern int sys_push_static_que_back 
(
	struct SYS_STATIC_QUE *que_p, 
	struct SYS_STATIC_QUE_NODE *node_p
);

extern int sys_peek_static_que 
(
	struct SYS_STATIC_QUE *que_p, 
	u_int index,
	struct SYS_STATIC_QUE_NODE *p_ret
);

extern int sys_pop_static_que_front
(
	struct SYS_STATIC_QUE *que_p, 
	struct SYS_STATIC_QUE_NODE *ret_node_p
);


extern int sys_pop_static_que_back
(
	struct SYS_STATIC_QUE *que_p,
	struct SYS_STATIC_QUE_NODE *ret_node_p
);

extern int sys_pop_static_que_by_index
(
	struct SYS_STATIC_QUE *p_que, 
	int    index,
	struct SYS_STATIC_QUE_NODE *ret_p_node
);

extern void sys_clear_static_que
(
	struct SYS_STATIC_QUE *que_p
);

/********************************接口函数的定义结束********************************/
struct TIME_7_BYTE
{
	u_char ms_l;
	u_char ms_h;
	u_char minute;
	u_char hour;
	u_char day;
	u_char month;
	u_char year;
};

#define SYS_MAX_BYTE_QUE_SIZE    (8 * 1024)

struct SYS_BYTE_QUE
{
	u_short  size;
	u_short  head;
	u_short  tail;
	u_char   *buffer;
};
 
extern u_short sys_get_dnp_crc(u_char *data, u_char len);

extern void sys_tool_fill_uchar_by_ushort(u_char *dest, u_int ushort_var, BOOL reverse_flag);

extern void sys_tool_fill_uchar_by_uint(u_char *dest, u_int uint_var, BOOL reverse_flag);

extern void sys_tool_fill_uchar_by_float(u_char *dest, float float_var, BOOL reverse_flag);

extern u_short sys_tool_uchar_to_ushort(u_char *src, BOOL reverse_flag);

extern u_int sys_tool_uchar_to_uint(u_char *src, BOOL reverse_flag);

extern struct SYS_BYTE_QUE *sys_create_byte_que(u_short size);

extern void sys_free_byte_que(struct SYS_BYTE_QUE *p_que);

extern u_short sys_get_byte_que_used_size(struct SYS_BYTE_QUE *p_que);

extern u_short sys_get_byte_que_free_size(struct SYS_BYTE_QUE *p_que);

extern u_short sys_push_byte_que_back(struct SYS_BYTE_QUE *p_que, u_char *buffer, u_short len);

extern u_short sys_push_byte_que_front(struct SYS_BYTE_QUE *p_que, u_char *buffer, u_short len);

extern u_short sys_pop_byte_que_front(struct SYS_BYTE_QUE *p_que, u_char *buffer, u_short max_len);

extern u_short sys_pop_byte_que_back(struct SYS_BYTE_QUE *p_que, u_char *buffer, u_short max_len);

extern u_short sys_peek_byte_que_front(struct SYS_BYTE_QUE *p_que, u_char *buffer, u_short max_len);

extern u_short sys_peek_byte_que_back(struct SYS_BYTE_QUE *p_que, u_char *buffer, u_short max_len);

extern void sys_clear_byte_que(struct SYS_BYTE_QUE *p_que);

extern time_t sys_tool_get_calendar_time(u_char *time, BOOL year_flag);

extern void sys_convert_calendar_time_to_7timestamp(struct SYS_TIME *p_sys_time, time_t seconds, u_short ms); 
 
extern char *sys_get_key_str_point(char *src_str, const char *english_key_str, const char *chinese_key_str); 

extern int sys_tool_get_max(int *p_data, int num);

int socketConnectStatus(u_int hSock);
 
/*------------------规约模块中选择下一装置和查找装置的宏定义-----------------*/

#define SYS_GET_DEV_ADDR(dp, dev_addr, DEV_FORMAT)				\
{											\
	int i = 0;									\
	DEV_FORMAT *dev_p;								\
											\
	dev_p = dp->dev_head;							\
	while (i < dp->dev_num)							\
	{										\
		dev_addr[i++] = dev_p->dev_addr;					\
		dev_p = dev_p->next;						\
	}										\
}


#define SYS_SEARCH_DEV(dp, search_dev_addr, ret_dev_p, DEV_FORMAT)		\
{											\
	int i = 0;									\
	BOOL find_flag = CM_FALSE;							\
	DEV_FORMAT *search_dev_p;							\
											\
	search_dev_p = dp->dev_head;						\
	while (i++ < dp->dev_num)							\
	{										\
		if (search_dev_addr == search_dev_p->dev_addr)			\
		{									\
			find_flag = CM_TRUE;						\
			ret_dev_p = search_dev_p;					\
			break;							\
		}									\
		search_dev_p = search_dev_p->next;				\
	}										\
											\
	if (!find_flag)	ret_dev_p = NULL;					\
}

#define SYS_GET_DEV(dp, dev_ix, cur_dev_p, DEV_FORMAT)				\
{											\
	u_char		shadow_ix;							\
	DEV_FORMAT *get_dev_p;							\
											\
	shadow_ix = dev_ix;								\
	if (1 == dp->dev_num)							\
	{										\
		cur_dev_p = dp->dev_head;						\
	}										\
	else										\
	{										\
		get_dev_p = dp->dev_head;						\
		while (shadow_ix-- > 0)						\
		{									\
			get_dev_p = get_dev_p->next;				\
		}									\
		cur_dev_p = get_dev_p;						\
	}										\
}

#define SYS_GET_ON_DEV(dp, cur_dev_p, DEV_FORMAT) 				\
{											\
	u_char		ix;								\
	DEV_FORMAT	*on_dev_p;							\
											\
	if (1 == dp->dev_num)							\
	{										\
		cur_dev_p = dp->dev_head;						\
	}										\
	else										\
	{										\
		for (ix = dp->sel_on_dev_ix; ix < dp->dev_num; ix++)		\
		{									\
			SYS_GET_DEV (dp, ix, on_dev_p, DEV_FORMAT);		\
			if (RDB_RET_NORMAL == on_dev_p->dev_state)		\
				break;						\
		}									\
											\
		if (ix < dp->dev_num)						\
		{									\
			dp->sel_on_dev_ix = ix + 1;				\
			cur_dev_p = on_dev_p;					\
		}									\
		else									\
		{									\
			dp->sel_on_dev_ix = 0;					\
			cur_dev_p = NULL;						\
		}									\
	}										\
}											

#define SYS_GET_OFF_DEV(dp, cur_dev_p, DEV_FORMAT) 				\
{											\
	BOOL		find_flag;							\
	u_char		i, num;							\
	DEV_FORMAT*	off_dev_p;							\
											\
	num = 0;									\
	i = dp->sel_off_dev_ix;							\
	find_flag = CM_FALSE;								\
	while (1) 									\
	{										\
		if (i >= dp->dev_num)	i = 0;				\
											\
		SYS_GET_DEV (dp, i, off_dev_p, DEV_FORMAT);			\
		if (off_dev_p->dev_state != RDB_RET_NORMAL)			\
		{									\
			find_flag = CM_TRUE;						\
			dp->sel_off_dev_ix = i + 1;				\
			break;							\
		}									\
		i++;	num++;							\
		if(num >= dp->dev_num)	break;				\
	}										\
											\
	if (find_flag)	cur_dev_p = off_dev_p;				\
	else			cur_dev_p = NULL;					\
}


#define SYS_GET_NEXT_DEV(dp, cur_dev_p, DEV_FORMAT)				\
{											\
	DEV_FORMAT *next_dev_p;							\
											\
	SYS_GET_ON_DEV (dp, next_dev_p, DEV_FORMAT);				\
	if (NULL == next_dev_p)							\
	{										\
		SYS_GET_OFF_DEV (dp, next_dev_p, DEV_FORMAT);			\
		if (NULL == next_dev_p)						\
		{									\
			SYS_GET_ON_DEV (dp, next_dev_p, DEV_FORMAT);		\
		}									\
	}										\
											\
	if (NULL == next_dev_p)							\
	{										\
		cur_dev_p = dp->dev_head;						\
	}										\
	else										\
	{										\
		cur_dev_p = next_dev_p;						\
	}										\
}									

#define SYS_INIT_PROTOCOL_PARA(dp, type, app_id, group_id)			\
{											\
	dp->protocol_type			=	type;				\
	dp->board_addr			=	sys_get_board_addr();	\
	dp->app_id				=	app_id;			\
	dp->group_id				=	group_id;			\
	dp->task_id				=	1;				\
											\
	dp->sb_head.source_app_id		=	app_id;			\
	dp->sb_head.source_task_id		=	1;				\
	dp->sb_head.destination_app_id	=	RDB_APP_ID;			\
	dp->sb_head.destination_task_id	=	1;				\
}

#define SYS_DBG_OUT_INFOR(dp, watch_type, watch_no)							\
{														\
	if (dp->dbg_out_infor_count < dp->dbg_out_infor_set)						\
	{													\
		dp->dbg_out_infor_count++;									\
	}else													\
	{													\
		dp->dbg_out_infor_count = 0;								\
		if (CM_OK == sys_can_disp_dbg_infor (watch_type, watch_no, &dp->dbg_out_state))		\
		{												\
			dbg_out_infor(dp);									\
		}												\
	}													\
}

#define SYS_PERIOD_SEND_DEV_STATE(dp, DEV_FORMAT)										\
{																	\
	u_char ix = 0;														\
	DEV_FORMAT *dev_p;														\
																	\
	dev_p = dp->dev_head;													\
	while (ix++ < dp->dev_num)													\
	{																\
		rdb_proc_set_dev_net_sta(&dp->sb_head, dev_p->dev_addr, NET_A_USED | NET_B_USED, dev_p->dev_state);	\
		dev_p = dev_p->next;												\
	}																\
}

#define SYS_IS_DEV_STATE_ON(dev_p)						\
{										\
	if (RDB_RET_DISCONN == dev_p->dev_state)	return;		\
}										\


int connectQuick(u_long ip, u_short port);

int connectWithTimeout(int sockfd, struct sockaddr *servaddr, int client_addr_length, struct timeval *timeout);

void mdl_pro_printf(const char *format,...);

typedef struct
{
	u_char iType;
	u_char quality;
	union UINT_FLOAT  uVal;
	struct SYS_TIME sysTime;
}iec103_gdd;

int decode_103gdd(u_char *pbuf, int ilen, iec103_gdd *pGdd);

#endif
