 /***************************************************************************
 * Description:	��Լģ��ӿ��ļ�ʵ��ģ��
 *
 *			1. ���ں�����ڲ���: ����b_xxx������������Ϊ��������ֻ����
 *                      ��״̬: true ���� false����CM_YES����true����CM_NO��ʾfalse
 *                      ���ڷ���ֵ������״̬(�ɹ�����ʧ��),��CM_OK��ʾ�ɹ�,CM_ERROR
 *                      ��ʾʧ�ܡ�
 *
 *                      ������ʱ����,�Ƽ�ʹ��CM_YES��ʾ�ɹ���CM_NO��ʾʧ��
 *
 * Modify Log:
 *		1.�ܶ�ģ��û�о�����֤,�ȴ��ں��������н�һ��ϸ��(07��5��23��)
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

/*****************************���ݽṹ���岿��*****************************/

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

enum	ENUM_CALL_BACK_ID		/* �ص���������ID */
{
	PERIOD_CALLBACK_ID	=	0,
	COM_CALLBACK_ID	=	1
};

enum	CTRL_TYPE		/* ������������ */
{
	CTRL_SEL_TYPE ,
	CTRL_EXE_TYPE ,
	CTRL_CANCEL_TYPE ,
	CTRL_NONE_TYPE
};

enum	DATA_TYPE		/* ������������ */
{
	PE_ASCII_TYPE ,
	PE_FLOAT_TYPE ,
	PE_INT8_TYPE ,
	PE_INT16_TYPE ,
	PE_INT32_TYPE ,
	PE_UINT8_TYPE ,
	PE_UINT16_TYPE ,
	PE_UINT32_TYPE ,
	PE_BIT_STRING_TYPE	/* λ������, �����������Ͳμ�BIT_STRING_DATA */
};
extern u_char g_aDTlen[];

enum	QUALITY_TYPE	/* Ʒ������ */
{
	OVERFLOW_TYPE,	/* ��� */
	ERROR_TYPE,		/* ��� */
	VALID_TYPE,		/* ��Ч */
	INVALID_TYPE,	/* ��Ч */
	OTHER_TYPE		/* ���� */
};

enum	S_COT_TYPE		/* ���ӷ�����ԭ�� */
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

enum	M_COT_TYPE		/* ���Ʒ�����ԭ�� */
{
	M_SYS_TIME_CODE		=	8,
	M_ALL_CALL_CODE		=	9,
	M_NORMAL_CMD_CODE		=	20,
	M_WAVE_CMD_CODE		=	31,
	M_GEN_WRITE_CMD_CODE		=	40,
	M_GEN_READ_CMD_CODE		=	42
};

enum	GIN_CONTINUE_TYPE	/* GIN�Ƿ����� */
{
	CONTINUE_TYPE,	/* GIN���� */
	NOT_CONTINUE_TYPE	/* GIN������ */
};

enum	KOD_OF_DATA_TYPE
{
	KOD_OF_ACTUAL_VALUE_TYPE	=	0x01,
	KOD_OF_RANGE_TYPE		=	0x03,
	KOD_OF_PRECISION_TYPE	=	0x05,
	KOD_OF_DIMENSION_TYPE	=	0x09,
	KOD_OF_DESCRIPTION_TYPE	=	0x0a
};

enum	PHASE_TYPE	/* ������� */
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

enum	FAULT_INTERFACE_ID	/* ���Ͻӿ�ENUM */
{
	FAULT_PHASE ,
	FAULT_DISTANCE,
	FAULT_MAX_ZERO_CURRENT,
	FAULT_TABLE,
	OTHER_FAULT
};

struct ACT_DATA_STRU		/* ���������ź����ݽṹ */
{
	u_char	dpi;
	u_char	rel_time[2];		/* ���ʱ�� */	
	u_char	fault_no[2]; 	/* �������*/
	u_char  ms_l;		/* ���ֽ�ʱ��	*/
	u_char	ms_h;
	u_char  minute;
	u_char  hour;	
	u_char  day;
	u_char  month;
	u_char  year_l;
};

struct	BIT_STRING_DATA	/* λ�����ݽṹ */
{
	int	num;		/* bitλ�ĸ��� */
	u_char	data[16];	/* bit���ݣ�8λռһ���ֽ� */
};

struct PROTOCOL_YC_DATA	/* ң�����ݽṹ */
{
	u_char	group;
	u_char	entry;  //��1��ʼ
	union
	{
		short      sval;
		int      s_value;	/* ����ң�� */
		float    f_value;	/* ������ң�� */
		u_char   avalue[4];
	}data;
	enum	QUALITY_TYPE	quality; /* Ʒ���������� */
};

struct PROTOCOL_YM_DATA	/* ң�����ݽṹ */
{
	u_char	group;
	u_char	entry;
	u_int	data;	
	enum	QUALITY_TYPE	quality; /*Ʒ����������*/
};	

struct PROTOCOL_YX_DATA	/* ң�����ݽṹ */
{
	u_char	group;
	u_char	entry;
	u_char	dpi;
	struct	SYS_TIME	t;	/*ʱ��*/
	enum	QUALITY_TYPE	quality; /* Ʒ���������� */
};	

struct PROTOCOL_YT_DATA	/* ������ݽṹ ��Ҫ���ڶ��Ϲ�Լ�����ݿ��·�ң������ */
{
	u_char			group;
	u_char 		entry;
	u_char			rii;
	enum	M_COT_TYPE 	cot;
	enum	CTRL_TYPE 	ctrl_type;
	enum	DATA_TYPE	data_type;
	union
	{
		int		i_value;	/*�з��������������*/
		u_int		ui_value;	/*�޷��������������*/
		float		f_value;	/*����ֵ�������*/
	}input;
};


struct PROTOCOL_RESET_DATA	/* �������ݽṹ ��Ҫ���ڶ��Ϲ�Լ�����ݿ��·����� */
{
	enum	M_COT_TYPE cot;	
	u_char	fun;
	u_char inf;
	u_char dco;
	u_char rii;
};

struct PROTOCOL_YK_DATA	/* ң�����ݽṹ ���Ϲ�Լ,���¹�Լ������ */
{
	u_char	group;
	u_char	entry;
	u_char	dpi;
	u_char rii;
	int 	cot;  /*����ԭ��*/
	enum	CTRL_TYPE 	ctrl_type;
};	

struct PROTOCOL_ACT_DATA	 /* �����ź����ݽṹ */
{
	u_char		group;
	u_char		entry;
	enum		S_COT_TYPE cot;  /*����ԭ��*/
	struct		ACT_DATA_STRU	data;
};

struct PROTOCOL_WAVE_DATA	/* �������ݽṹ */
{	
	char 	source_file_path[MDL_HTDB_FILE_NAME_LENGTH]; 
	char 	dest_file_path[MDL_HTDB_FILE_NAME_LENGTH]; 
	int		NOF;
	struct 	SYS_TIME t;
};	

struct PROTOCOL_SETTING_NO_DATA	/* ��ֵ�������ݽṹ */
{
	u_char	group;
	u_char	entry;
	u_char 	rii;
	enum	S_COT_TYPE cot;				
	u_char	data;
};	

struct PROTOCOL_SETTING_DATA	/* ��ֵ(��������Ҳ���Ը���)���ݽṹ */
{
	u_char	group;
	u_char	entry;
	enum	DATA_TYPE  type;	/*��������*/
	union
	{
		union
		{
			int	i_value;				/* �з���������ֵ */
			u_int	ui_value;				/* �޷���������ֵ */
			float	f_value;				/* ������������ֵ */
			char	str[128];				/* �ַ�����ֵ */
			struct  BIT_STRING_DATA bit_string;	/* λ����ֵ */
		}actual_value;
						/*ʵ��ֵ*/
		
		union
		{
			int	i_value[3];
			float	f_value[3];
		}range;			/*����*/

		int	precision[2];	/*����*/
		char	dimension[32];	/*����*/
		char	description[128];	/*����*/
	}data;
};	

struct PROTOCOL_FAULT_DATA		/* ������Ϣ���ݽṹ */
{
	u_char	group;
	u_char	entry;	
	
	u_short nof;

	u_char  fan_num;
	u_short fan[32];
	
	enum	FAULT_INTERFACE_ID	interface_id;
	union
	{
		enum	PHASE_TYPE	fault_phase;	/*�������*/
		enum	PHASE_TYPE	trip_phase;	/*��բ���*/
		float	fault_distance;		/*���ϲ��*/	
		float	max_zero_current;		/* ���������� */
		float	max_fault_current;		/*�����������*/
		float	max_fault_voltage;		/*���������ѹ*/
	}fault_para;
	struct	SYS_TIME	t;	/*ʱ��*/
}; 

#pragma pack(push,1)
struct  PROTOCOL_REQ_ASDU_DATA	/* ˫��֮�䴫������ */
{
	u_short	dev_addr;
	int		data_length;
	u_char		data[1];
};

struct	PROTOCOL_REQ_DATA		/* ˫��֮���໥���ͱ��� */
{	
	int	interface_id;
	union
	{		
		struct  PROTOCOL_REQ_ASDU_DATA  data;
	}req;
};
#pragma pack(pop)

struct PROTOCOL_GROUP_DESC		/*��������ݽṹ*/
{
	u_char	group;
	char	desc[32];
};

/* ������ȡö�ٱ��� */ 
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
	��̬����
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
	��Ƕ��ʽ����ϵͳ��,Ϊ�����ڴ���Ƭ,�������ȼ����в��þ�̬����ԭ��.
	���ڲ��þ�̬����,ĳЩ�������ܿ��ܲ��Ǻܺ�,����ʱ������ͳһ���ڴ�
	������
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

/*****************************���ݽṹ���岿�ֽ���*****************************/


/********************************�ӿں����Ķ���********************************/
/*���ͱ������ݵ�����*/
extern void sys_send_sio_msg
(
	u_char com_no, 
	u_char *data, 
	int len, 
	u_short src_dev_addr, /*���Ӳ�����д*/
	u_short des_dev_addr
);
 
/* ����ң�� */
extern	void sys_send_yc
(
	struct	SB_HEAD *sb_head,
	u_short	dev_addr,	
	int		num,				/*����*/
	enum	DATA_TYPE		data_type,
	enum	S_COT_TYPE		cot,
	enum	GIN_CONTINUE_TYPE	type, /*��GIN����ʱ��PROTOCOL_YC_DATA �е������Ŀ�Ž�����д��һ������*/
	struct 	PROTOCOL_YC_DATA	*data,/*�����б�*/
	u_char	watch_type,
	u_char	watch_no
);

/* ����ң�� */
extern	void sys_send_yx
(
	struct 	SB_HEAD *sb_head,
	u_short	dev_addr,	
	int		num,	/*����*/
	enum	S_COT_TYPE		cot,
	enum	GIN_CONTINUE_TYPE	type, /*��GIN����ʱ��PROTOCOL_YX_DATA �е������Ŀ�Ž�����д��һ������*/
	struct 	PROTOCOL_YX_DATA	*data,/*�����б�*/
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

/* �Ƚ�ң��״̬, ����ȫң�Ż��߱�λң�� */
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

/* ����ң�� */
extern	void sys_send_ym
(
	struct 	SB_HEAD *sb_head ,
	u_short	dev_addr ,	
	int		num,	/*����*/
	enum	S_COT_TYPE		cot,
	enum	GIN_CONTINUE_TYPE	type, /*��GIN����ʱ��PROTOCOL_YM_DATA �е������Ŀ�Ž�����д��һ������*/
	struct 	PROTOCOL_YM_DATA	*data,/*�����б�*/
	u_char	watch_type,
	u_char	watch_no
);

/*���ͱ��������ź�*/
extern	void sys_send_act
(
	struct	SB_HEAD *sb_head,
	u_short	dev_addr,
	struct 	PROTOCOL_ACT_DATA	*data,	
	int	b_event_add_ret,	/* �Ƿ������ʱ�����ź� */	
	u_char	watch_type,
	u_char	watch_no
);

/* ����ң�ط�У */
extern	void sys_send_yk
(
	struct 	SB_HEAD *sb_head,
	u_short	dev_addr,
	struct 	PROTOCOL_YK_DATA *data,
	u_char	watch_type,
	u_char	watch_no
);

/*��ֵ���ŵ�����*/
extern int sys_send_setting_no
(
	struct	SB_HEAD *sb_head,
	u_short	dev_addr,
	struct	PROTOCOL_SETTING_NO_DATA	*data, /*��ֵ������ֵ*/
	u_char	watch_type,
	u_char	watch_no
);

/*
	Function:	��ֵ����
	Parameter:
	1.	num
		����
	2.	enum	GIN_CONTINUE_TYPE	type
		��GIN����ʱ��PROTOCOL_SETTING_DATA �е������Ŀ�Ž�����д��һ������
	3.	struct 	PROTOCOL_SETTING_DATA	*data
		��ֵ����	
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

/*������������*/
extern void sys_send_analog
(
	struct	SB_HEAD *sb_head,
	u_short	dev_addr,	
	int		num,/*����*/
	u_char	rii,
	enum	S_COT_TYPE cot,
	enum	GIN_CONTINUE_TYPE	type, /*��GIN����ʱ��PROTOCOL_SETTING_DATA �е������Ŀ�Ž�����д��һ������*/
	struct 	PROTOCOL_SETTING_DATA	*data, /*������������*/	
	u_char	watch_type,
	u_char	watch_no
);

/* ������Ϣ����:��������ѡ�ࡢ���ϲ�ࡢ������������� */
extern void sys_send_fault_data
(
	struct 	SB_HEAD *sb_head,
	u_short	dev_addr,
	struct		PROTOCOL_FAULT_DATA	*data,
	enum	S_COT_TYPE cot,
	u_char		watch_type,
	u_char		watch_no	
);

/* �����ļ����� */
extern int sys_send_wave
(
	struct 	SB_HEAD *sb_head,
	u_short	dev_addr,			
	struct 	PROTOCOL_WAVE_DATA	*data 
);

/*�ظ������ݿ������*/
extern void sys_send_group_desc
(
	struct		SB_HEAD *sb_head,
	struct		EXT_HEAD *ext_head_p,
	u_short	dev_addr,	
	int		num,/*����*/
	u_char		rii,
	enum	S_COT_TYPE cot,
	struct 	PROTOCOL_GROUP_DESC	*data, /*��������*/	
	u_char		watch_type,
	u_char		watch_no
);

/*
	�򱸻���������
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

/* ʵ��ʱ���ƫ�Ƽ��㣬���Խ��мӼ����������ȵ��� */
extern void sys_adjust_time 
(
	struct SYS_TIME *time_p, 
	u_int second, 
	int sign_flag
);

/* ���Ͱ�ͷ, ���ڶ�ֵ���ţ���ֵ���ر�ע����дsource_head_p, ���ϵ��ȹ�ԼҲ�����ô���д��ͷ */
extern void sys_fill_ext_head
(
	struct EXT_HEAD *target_head_p, 
	struct EXT_HEAD *source_head_p, 
	u_short dev_addr, 
	int b_dispatch_top		/*CM_YES ���ȹ�Լ��д, CM_NO ���¹�Լ��д*/
);

/*
	���Ϲ�Լ���ô�ģ�������ݿⷢ��ң�ر���
*/
extern	int sys_dispatch_top_yk
(
	struct 	SB_HEAD *sb_head,
	u_short	dev_addr,
	struct 	PROTOCOL_YK_DATA *data,
	u_char		*p_ret,	/*���ذ�װ����ͷָ��, ���ڹ�Լģ���з�УУ��*/
	u_char		watch_type,
	u_char		watch_no
);

/* ���Ϲ�Լ�����ݿⷢ�͸������� */
extern	void sys_dispatch_top_reset
(
	struct 	SB_HEAD *sb_head,
	struct 	PROTOCOL_RESET_DATA *data,
	u_char		watch_type,
	u_char		watch_no
);


/* ���Ϲ�Լ�����ݿⷢ������������� */
extern	int sys_dispatch_top_yt
(
	struct 	SB_HEAD *sb_head,
	u_short	dev_addr ,
	struct 	PROTOCOL_YT_DATA *data,
	u_char		*p_ret,
	u_char		watch_type,
	u_char		watch_no
);

/* ���Ϲ�Լ�����ݿⷢ�͹�·����, ��Ҫ���ڶ�д��ֵ��ͨ�÷���������� */
extern	void sys_dispatch_top_pass
(
	struct 	SB_HEAD *sb_head,
	u_short	dev_addr ,
	u_char		*asdu_send_buf,	/*��дASDU����*/
	int		asdu_len,
	u_char		watch_type,
	u_char		watch_no
);

extern	void sys_dispatch_bottom_pass
(
	struct 	SB_HEAD *sb_head,
	struct EXT_HEAD *source_head_p, 
	u_short	dev_addr ,
	u_char		*asdu_send_buf,	/*��дASDU����*/
	int		asdu_len,
	u_char		watch_type,
	u_char		watch_no
);


/*�ȴ�ʵʱ���ݿ����*/
extern void sys_suspend_for_rdb(struct SB_HEAD *sb_head);

/*�ȴ���ʷ���ݿ����*/
//extern void sys_suspend_for_htdb_ready (struct SB_HEAD *sb_head);

/*�ȴ�������ͬ��ģ�����*/
//extern void sys_suspend_for_dccu_ready (struct SB_HEAD *sb_head);

/*�жϵ��Թ����Ƿ�򿪱���Լ�ĵ��Կ���*/
extern int sys_can_disp_infor
(
	u_char watch_type, 
	u_char watch_no
);


/*�жϵ�����Ϣ�Ƿ�������*/
extern int sys_can_disp_dbg_infor
(
	u_char watch_type, 
	u_char watch_no, 
	int *p_old_dbg_state
);

/*���Լ��Ϣ��ӡ�ַ�*/
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


/*���Լ��Ϣ��ӡIP��ַ*/
extern void sys_disp_ip_addr 
(
	u_char watch_type, 
	u_char watch_no, 
	char *note, 
	u_int ip_addr
);

/*���Լ��Ϣ��ӡ����*/
extern void sys_disp_data
(
	u_char watch_type, 
	u_char watch_no, 
	int data, 
	const char *note, 
	int b_is_sign
);

/*���Լ��Ϣ��ӡ�ɴ��ַ�*/
extern void sys_disp_buf
(
	u_char watch_type, 
	u_char watch_no, 
	u_char *buf, 
	int len, 
	const char *note, 
	int b_disp_asci
);

/*���Լ��Ϣ��ӡ�ɴ�����(������, ����)*/
extern void sys_disp_ini_data_type_array
(
	u_char watch_type, u_char watch_no, 
	int disp_num, u_char *disp_code, 
	enum DATA_TYPE data_type, const char *note
);

/*�ָ���̬�ļ�ָ�뵽��ȷλ��*/
extern int sys_restore_ini_fp
(
	struct SYS_STRSTREAM *strp
);

/*���װ����Ϣ*/
extern int sys_get_dev_cfg
(
	struct SYS_STRSTREAM *strp, 
	int dev_addr, 
	char *p_ret, 
	int cfg_max_len
);

/*���װ���������*/
extern int sys_get_dev_group_attr
(
	struct SYS_STRSTREAM *strp, 
	int dev_addr, 
	struct DEVICE_GROUP_ATTR_STRU *p_dev_cfg
);

/*��ȡ��̫��װ�õ�������*/
extern int sys_get_dev_protocol_infor
(
	struct DEVICE_GROUP_ATTR_STRU *p_dev_cfg,	/*װ�ÿ�*/
	u_short dev_addr, 				/*װ�õ�ַ*/
	const char *key_name, 			/*�ؼ���: ң�⣬ң�ŵ�*/
	u_char *p_ret_num, 				/*��ȡ�������*/
	u_char *p_ret_group,				/*����ÿ������*/
	u_char *p_ret_entry,				/*����ÿ����Ŀ�ĸ���*/
	u_char default_group,			/*����ȡ���ɹ�, Ĭ�����*/
	u_int max_ret_num				/*��󷵻س��ȣ���ֹԽ��*/
);

/*�����̫��װ�õ�ԭʼ���*/
extern int sys_find_original_group
(
	struct DEVICE_GROUP_ATTR_STRU *p_dev_cfg,	/*װ�ÿ�*/
	u_short dev_addr, 
	u_char map_group, 
	u_char *cpu_no, 
	u_char *original_group
);

/*��ù�Լ��Ϣ �˴�com���Ϊcommon, ���Ǵ���*/
extern int sys_get_com_cfg
(
	struct SYS_STRSTREAM *strp, 
	char *p_ret, 
	int cfg_max_len
);

/*����̬�ж�ȡ����*/
extern int sys_read_ini_int_var
(
	char *name, 
	char *ini_str, 
	int default_value
);

/*����̬�ж�ȡ������*/
extern float sys_read_ini_float_var 
(
	char *name, 
	char *ini_str, 
	float default_value
);

/*����̬�ж�ȡ�ַ���*/
extern int sys_read_ini_str_var
(
	char *name, 
	char *ini_str, 
	char *p_ret
);

/*����̬�ж�ȡװ�õ�ַ*/
extern int sys_read_ini_dev_addr
(
	char *name, 
	char *ini_str, 
	int *p_addr, 
	u_char no
);

/*����̬�ж�ȡһ������*/
extern int sys_read_ini_int_array
(
	char *name, 
	char *ini_str, 
	u_char *p_ret, 
	int  max_num, 
	int  b_read_as_hex, 
	int  b_cvt_word
);

/*����̬�ж�ȡһ���ַ���*/
extern int sys_read_ini_str_array
(
	char *name, 
	char *ini_str, 
	char *end_char, 
	char **p_ret, 
	int  max_num, 
	int b_just_get_num
);

/* ����̬�ж�ȡIP��ַ
   RETURN: CM_OK, CM_ERROR
*/
extern int sys_read_ini_ip_addr
(
	char *name, 
	char *ini_str, 
	u_int *ip_addr
);

/*����̬�ж�ȡö�ٱ���*/
extern u_char sys_read_ini_enum_var
(
	char *name, 
	char *ini_str, 
	const struct STRING_MODE *p_mode, 
	u_char str_num
);

/* �ͻ�����������˽�������
   RETURN���ɹ�socket_id; ʧ��-1
*/
extern int sys_get_tcp_connected_id
(
	int port,
	u_int ip
);

/*��ASCII��õ�ʮ����������*/
extern u_char sys_get_hex(u_char ascii_code);

/*��ASCII��õ�����������*/
extern u_char sys_get_dig_code(u_char asci_code);

/*�Ӷ��������ֵõ�ASCII��*/
extern u_char sys_get_ascii_code(u_char dig_code);

/*BCD��ʮ��������ת��*/
extern u_char sys_bcd_to_dec(u_char bcd_code);

/*ʮ����->BCD*/
extern u_char sys_dec_to_bcd(u_char dec_code);

/*�����ۼӺ�*/
u_short sys_calc_short_sum(u_char *p_code, u_short len);
u_char sys_calc_char_sum(u_char *p_code, u_short len);

/*��������*/
extern u_char sys_calc_chk_of_xor(u_char *p_code, u_short len);

/*����modbus��*/
extern u_short sys_calc_chk_of_modbus(u_char *p_code, u_short len);

/*��ʼ����Լ�ص�����*/
extern	struct	SYS_CALLBACK_DATA *init_protocol_callback
(
	u_int app_id,
	u_int group_id,
	u_int task_id,
	u_int msg_num,
	u_int stack_size,
	sem_t	*semID,
	char	*protocol_name	/*��Լ������*/
);

/*ע�ᶨʱ�ص�����*/
extern	int sys_register_period_callback
(
	struct	SYS_CALLBACK_DATA *ndp, 
	void(*callback)(void *), 
	void *callback_data, 
	struct SYS_TIME *t
);

/*ע�ᴮ�ڻص�����*/
extern	int sys_register_com_callback
(
	struct SYS_CALLBACK_DATA *ndp, 
	int com_no, 
	void (*com_callback)(void *,u_char *buf,int length), 
	void *com_callback_data
);

/*ע����¹�Լ�ص�����*/
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

/*ע����Ϲ�Լ�ص�����*/
extern int sys_register_dispatchtop_callback
(
	struct SYS_CALLBACK_DATA *ndp, 
	void (*dispatchtop_callback)(void *,u_char *buf, int length), 
	void *dispatchtop_callback_data
);

/*UDP�鲨*/
extern int sys_get_group_udp_id (u_int port, u_int group_addr);

/*UDP�㲥*/
extern int sys_get_special_udp_id_by_port (u_int port, BOOL b_do_recv);

/* �ⲿ����,��¶���û�ʹ�� 
   FUNCTION: ���ɶ���, que_size--->���д�С, 
             b_thread_safe: CM_YES(��������); CM_NO(����������)
*/

extern struct SYS_QUE *sys_create_que
(
	u_int que_size, 
	int b_thread_safe
);

/* �ⲿ����,��¶���û�ʹ�� 
   FUNCTION: ���ɶ��нڵ�, len--->���ݳ���, buffer--->��������
*/
extern struct SYS_QUE_NODE *sys_create_que_node
(
	u_int len, 
	u_char *buffer
);

/* �ⲿ����,��¶���û�ʹ�� 
   FUNCTION: �ͷŶ��нڵ�
*/
extern void sys_free_que_node
(
	struct SYS_QUE_NODE *node_p
);

/* �漰�������,��¶���û�ʹ�� 
   FUNCTION: ��ȡ���е�ʹ�����
   RETURN:   �����Ѿ�ʹ��������
*/
extern int sys_get_que_used_size
(
	struct SYS_QUE *que_p
);


/* �漰�������,��¶���û�ʹ�� 
   FUNCTION: ��ȡ���е�ʹ�����
   RETURN:   �����Ѿ�����������
*/
extern int sys_get_que_free_size
(
	struct SYS_QUE *que_p
);

/* �漰�������,��¶���û�ʹ�� 
   FUNCTION: ��������ӵ�����ͷ��
   RETURN:   CM_ERROR, CM_OK   
*/

extern int sys_push_que_front
(
	struct SYS_QUE *que_p, 
	struct SYS_QUE_NODE *node_p
);

/* �漰�������,��¶���û�ʹ�� 
   FUNCTION: ��������ӵ�����ĩ��
   RETURN:   CM_ERROR, CM_OK   
*/

extern int sys_push_que_back
(
	struct SYS_QUE *que_p, 
	struct SYS_QUE_NODE *node_p
);


/* �漰�������,��¶���û�ʹ�� 
   FUNCTION: ������PEEK, ��ɾ������
   RETURN:   CM_OK OR CM_ERROR
   indexȡ0��usedSize - 1֮��, ȡ0Ϊtail + 1,
   ȡusedSize - 1Ϊhead����   
*/
extern int sys_peek_que 
(
	struct SYS_QUE *que_p, 
	u_int index,
	struct SYS_QUE_NODE *p_ret
);


/* �漰�������,��¶���û�ʹ�� 
   FUNCTION: �Ӷ���ͷ��ȡ����
*/

extern struct SYS_QUE_NODE *sys_pop_que_front
(
	struct SYS_QUE *que_p
);


/* �漰�������,��¶���û�ʹ�� 
   FUNCTION: �Ӷ���β�Ͷ�ȡ����
*/

extern struct SYS_QUE_NODE *sys_pop_que_back
(
	struct SYS_QUE *que_p
);

/* �漰�������,��¶���û�ʹ�� 
   FUNCTION: �������
*/
extern void sys_clear_que
(
	struct SYS_QUE *que_p
);


/*
	��Ƕ��ʽ����ϵͳ��,Ϊ�����ڴ���Ƭ,�������ȼ����в��þ�̬����ԭ��.
	���ڲ��þ�̬����,ĳЩ�������ܿ��ܲ��Ǻܺ�,����ʱ������ͳһ���ڴ�
	������
*/

/* �ⲿ����,��¶���û�ʹ�� 
   FUNCTION: ���ɶ���, que_size--->���д�С, que_node_size--->����node���ݿ��С 
             b_thread_safe: CM_YES(��������); CM_NO(����������)
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

/********************************�ӿں����Ķ������********************************/
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
 
/*------------------��Լģ����ѡ����һװ�úͲ���װ�õĺ궨��-----------------*/

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
