/****************************************************************
 * FileName :sys_define.h
 * Description:
 *
 * Modify Log:
 * 
 
 ****************************************************************/
#ifndef	_SYS_DEFINE_H_
#define	_SYS_DEFINE_H_
 
#include 	"stdio.h"
#include 	"stdlib.h"
#include 	"string.h"
#ifndef _WIN32
#include 	"unistd.h"
#include    <sys/time.h>
#endif
#include	"fcntl.h"
#include	"stdarg.h"
#include 	"sys/types.h"

#include	"board_cfg.h"
#include    "data_types.h"

//��������Ϣ��ӡ���˿�,������
//#ifndef     _CONSOLE_DEBUG_PRINTF_
//#define     _CONSOLE_DEBUG_PRINTF_
//#endif

#define   	_SYS_MY_PRINTF_
#ifdef 		_SYS_MY_PRINTF_
//#define		printf	my_printf
#endif

#define FOREVER     while(1)

#ifndef MSB
#define MSB(x) (((x)>>8) & 0xff)
#endif
#ifndef LSB
#define LSB(x) ((x) & 0xff)
#endif
#ifndef MSW
#define MSW(x) (((x)>>16) & 0xffff)
#endif
#ifndef LSW
#define LSW(x) ((x) & 0xffff)
#endif

#define HTONL(X)	(X)
#define HTONS(X)	(X)
#define NTOHL(X)	(X)
#define NTOHS(X)	(X)

#define	 CM_OK					0
#define	 CM_ERROR				-1

#define	 CM_FALSE				0
#define	 CM_TRUE				1

#define	 CM_NO					0
#define	 CM_YES				    1

#define	CM_EOS       			'\0'  

#define	 BOOL				u_char

#define  MAX_DEBUG_LEN	500

#define	 SYS_SOFT_BUS_ID			0x68686868
#define	 SYS_COM_NUM				(UART_NUM + EX_UART_NUM)
#define	 SYS_CON_NUM				200
#define	 SYS_BOARD_NUM				4
#define	 SYS_PROT_NUM   			700
#define	 SYS_DEV_NUM				1000
#define  SYS_MAX_CHAR_LENGTH  			40
#define  SYS_TICKS              		60	
#define  sys_get_ticks(x)           ((x*SYS_TICKS)/1000)
#define	 SYS_SRAM_ADDR				0x51000000
#define  SYS_RAM_DOC_SPACE			10485760/*16384000*/
#define	 SYS_NEW103NET_MAX_MSG_LENGTH	1100
#define  SYS_9798_YX_NUM			4
#define	 SYS_PRINTF_MSG_NUM			200

#define  SYS_DAT_TYPE	 			0x100
#define  SYS_CMD_TYPE	 			0x200	 		/*�շ�ת������·���п���*/
#define  SYS_STA_TYPE	 			0x200	 		/*��·״̬*/
#define	 SYS_RX_EN	 			0x0200  	/*��ʼ����*/
#define	 SYS_TX_EN	 			0x0201  	/*��ʼ����*/
#define	 SYS_SYNEN	 			0x0202  	/*ͬ��*/
#define  SYS_INS_IDLE	 			0x0203  	/*�������*/
#define  SYS_WAIT_ALLS	 			0x0204  	/*���͵ȴ�*/
#define	 SYS_REC_IDLE	 			0x0210  	/*���ܿ���*/
#define	 SYS_REC_OE 	 			0x0211  	/*overrun err */
#define	 SYS_REC_PE 	 			0x0212   	/*У���*/
#define	 SYS_REC_FE 	 			0x0213   	/*֡��ʽ��*/
#define	 SYS_REC_BI 	 			0x0214   	/*break interrupt*/
#define  SYS_NET_CON_NUM 			16				/*�������������*/
#define  SYS_MAX_PER_LIN  			1000			/*ÿ���ı�����ֽ���*/
enum	 {SYS_COM_PROTOCOL,SYS_NET_PROTOCOL};
enum   {SYS_RECDATA,SYS_REQDATA};
enum	 task_type{SYS_PERIOD,SYS_ONCE_RELATIVE,SYS_ONCE_ABSOLUTE,SYS_MINUTE_PERIOD};
enum	 {SYS_NOUSE_TYPE,SYS_MSGQ_TYPE,SYS_PIPE_TYPE,MSGPOLLING_TYPE,SYS_MSGQ_BRF_TYPE,SYS_PIPE_BRF_TYPE};
/*enum	 msg_type{SYS_NOUSE_TYPE,SYS_MSGQ_TYPE,SYS_PIPE_TYPE,MSGPOLLING_TYPE,SYS_MSGQ_BRF_TYPE,SYS_PIPE_BRF_TYPE};*/
enum	 {SYS_AUTO_TASK,SYS_NOT_AUTO_TASK};
enum   board_type{SYS_CKMEM1024_BOARD,SYS_CKCPU_BOARD,SYS_CKMEM256_BOARD};
enum   {SYS_DOUBLE,SYS_SINGLE};
enum   {SYS_MASTER,SYS_SLAVE};
enum	 {SYS_INACTIVE,SYS_ACTIVE};
enum   {SYS_NET_ACCEPT_MSG=100};
enum	 YX_STATE{OFF,ON};
enum 	{CHECK_NONE, CHECK_ODD, CHECK_EVEN, CHECK_MARK, CHECK_SPACE};

struct	SYS_STRSTREAM
{
	FILE *	fp;
	int	line;
	int	pos;
	int	eof;
	int	fpos;
	char	buf[SYS_MAX_PER_LIN];
};
#pragma pack(push,1)
struct	SYS_TIME
{
	u_short msecond;  /*����ż��ַ��ʼ*/
	u_char	second;
	u_char	minute;
	u_char	hour;
	u_char	day;
	u_char	month;
	u_short year;
	u_char  unuse; /*��֤Ϊż��*/
};
#pragma pack(pop)
 
struct  SYS_COM_INIT
{
	int		comId;	//���ڴ򿪺��id
	u_char	com_no;
	u_short	protocol_type;	/* ��Э��ȷ */
	char	protocol_name[40];
	u_char	line_mode;	/* 485 232 422 modem�첽 modemͬ��(�Ƿ�ͬ��)*/
	u_char	data;		/* 8 */
	u_char	parity; 	/* n,o,e */
	u_char	stop;		/* 1,2 */
	char	syn[16];
	int	bps;		/* ������*/
	u_char	addr_num;
	u_short	dev_addr[256];
	u_char	list_num;			/*���ñ���*/
	u_char  list_lib_no[10];	/*���ñ���*/
	u_char	list_type[10];
	u_char	list_description[10][20];
};

struct  SYS_CON_INIT
{
	u_char	con_no;
	u_short	protocol_type;	/* ��Э��ȷ */
	char	protocol_name[40];
	u_char	dev_num;
	u_short	dev_addr[256];
	u_char	list_num;			/*���ñ���*/
	u_char  list_lib_no[10];	/*���ñ���*/
	u_char	list_type[10];
	u_char	list_description[10][20];
};

struct   SYS_CONFIG_DATA
{
	int	con_num;  //��������
	int	com_num;  //��������
	int	dev_num;	
	u_int  	con_use_flag[SYS_CON_NUM];
	u_int  	com_use_flag[SYS_COM_NUM];
    int	f_pos_com[SYS_COM_NUM];
    int	f_line_com[SYS_COM_NUM];
    int	f_pos_con[SYS_CON_NUM];
    int	f_line_con[SYS_CON_NUM];
};
struct	SYS_INDEX_ELEMENT		/*������Ԫ��*/
{
	u_int		index;	/*��Ԫ�ض�Ӧ����Ϣ�����ţ���ַ��FUN��INF��*/	
	u_int 		_index;
	int		_no;
	u_int		user_id;
	u_short 	fun_inf;
	u_char 		bord_addr;
};
struct	SYS_INDEX_LIST			/*������*/
{
	u_int	list_no;
	u_int	item_num;
	struct 	SYS_INDEX_ELEMENT item[1];
};
struct	SYS_INDEX_LIST_MAP_NO
{
	u_char board_addr;
	u_char port_type;
	u_char port_no;
	u_char list_no;
	u_char list_map_no;
};
struct	SYS_CONSOLE_INDEX_LIST_DATA
{
	u_char	console_list_num;
	struct	SYS_INDEX_LIST_MAP_NO	index_map_no_inf[256];
};

struct	SYS_SYSTEM_INF
{
	u_char sb_gateway_net1;
	u_char sb_gateway_net2;
	u_char dccu_precept;
	u_char run_precept;
	u_char settime_disable;
	u_char wave_need_flag;
};

struct	PRINT_CHAIN_BUF
{
	struct	  PRINT_CHAIN_BUF * next;
	int	  length;
	int	  start;
	u_char	  data[2];
};


struct SYS_GD_JHQX_STRUCT
{
	u_short xline[8][289];
	u_short xaddr[8][289];
	u_char line_flag;
	u_char call_line;
	u_char active_xflag;
	u_short line_num;
	u_short line_ptr;
	u_char x_qos[8];
	u_char xtime[8][7];
	u_char xline_no;
};



#define SYS_RLL_MAX 5
#define SYS_RLL_MASTER 0xff
#define SYS_RLL_SLAVE 0x00
#define SYS_RLL_NULL 0xaa

struct SYS_RLL_STRUCT
{
	u_char use_fig;
	u_char log_fig[2];
	u_char com_no[2];
	u_char line_sta[2];
	u_short link_addr[2];
	u_short switch_count[2];
	u_short protocol_no;
	u_char *COSBuf,*SOEBuf;
	u_short COSHeadPtr,COSRearPtr;
	u_short SOEHeadPtr,SOERearPtr;
};

#define		MDL_HTDB_MAX_FAN_NUM				8
#define		MDL_HTDB_FILE_NAME_LENGTH			80
struct	FILE_NAME
{	
	char  	name[MDL_HTDB_FILE_NAME_LENGTH];
};
struct  FAN_DATA
{
	struct		SYS_TIME	time;
	u_short		fan;
};

#pragma pack(push,1)
struct WAVE_REPORT
{
	struct FILE_NAME  disk;  	/*����Ҫ��д,����ʷ���ݿ���д*/
	int		hdr_len;	/*hdr�ļ��ĳ���,��ʷ���ݿ���д*/
	int		cfg_len;	/*cfg�ļ��ĳ���,��ʷ���ݿ���д*/
	int		dat_len;	/*dat�ļ��ĳ���,��ʷ���ݿ���д*/
	u_short		dev_addr;
	u_short		nof;
	struct		SYS_TIME	time;		/*�����е�һ���������ʱ��*/
	struct		SYS_TIME	fault_time;	/*added by wwl:2005-11-18 15:10*/		
	int   		fan_num;
	struct  	FAN_DATA	fandata[MDL_HTDB_MAX_FAN_NUM];
	u_int source_file_flag;/*��Ϊ0xeb90eb90Ϊ��Ч,������Ч*/
	u_char source_file_name[MDL_HTDB_FILE_NAME_LENGTH];
};
#pragma pack(pop)
#endif

