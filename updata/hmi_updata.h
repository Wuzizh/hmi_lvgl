#ifndef _HMI_UPDATA_H_
#define _HMI_UPDATA_H_
#include "../include/rdb_dispatch.h"
#include "../include/rdb_init.h"
#include "../include/rdb_define.h"
#include "sys_func.h"
#include "sys_protocol_interface.h"
#include <stdint.h>
#include "fbufcircle.h"
//#include "ipcs.h"
//#include "rdb_init.h"

#ifndef DATA_TYPES
#define DATA_TYPES
typedef signed char     int8;
typedef unsigned char   Uint8;
typedef signed short	int16;
typedef unsigned short  Uint16;
typedef int			    int32;
typedef unsigned int	Uint32;
typedef float			float32;
typedef long long       int64;
typedef unsigned long long Uint64;



typedef struct hmi_updata_struct;
#endif

#define MAX_ITEM_NUM 4096

#define MAX_FD103       10
#define	MAX_BUF_LEN		4096
#define MAX_FD103_BUF_LEN       (16*1024)
#define MAXCLIENT                  8
#define MAX_TCP_RESEND_TIMES       5				// TCP报文重发次数
#define COMM_PORT_NUM              4                // 通讯口个数
#define MAXCONSOLE                 4
#define COMM_CONNECT_MAX          (COMM_PORT_NUM-1+MAXCONSOLE)
#define LIST_BUF_FRAME_NUM_MAX  2048
#define MAX_RS485     3
#define RS485_MODBUS               1				// old is RS485_LFP


#define ACTIVE_NOW		1
#define ACTIVE_LATER	0

#define MODBUS_FIFO_DATA_LENGTH        256
#define MODBUS_FIFO_LENGTH             (MODBUS_FIFO_DATA_LENGTH+5)

#define MODBUS_FIFO_START_FLAG         0xEB
#define MODBUS_FIFO_END_FLAG           0x90

#define SOCK_BUFFER_MAX_LENGTH     256

//modbus错误码
#define MODBUS_NO_EXCEPTION  0x00 
#define MODBUS_EXCEPTION_01  0x01 //非法的功能码
#define MODBUS_EXCEPTION_02  0x02 //非法地址
#define MODBUS_EXCEPTION_03  0x03 //非法数据
#define MODBUS_EXCEPTION_04  0x04 //装置异常
#define MODBUS_EXCEPTION_05  0x05 //未知异常

#define MODBUS_YX_START_ADDR     0x0000
#define MODBUS_YK_START_ADDR     0x1000
#define MODBUS_YC_START_ADDR     0x0000
#define MODBUS_YT_START_ADDR     0x3000


#ifndef NAME_STRING_LEN
#define NAME_STRING_LEN 50			// 字符串的最大长度
#endif

#define MSB(x)  (((x) >> 8) & 0xff)   /* most signif byte of 2-byte integer */
#define LSB(x)  ((x) & 0xff)          /* least signif byte of 2-byte integer*/
#define MSW(x) (((x) >> 16) & 0xffff) /* most signif word of 2-word integer */
#define LSW(x) ((x) & 0xffff)         /* least signif byte of 2-word integer*/

/* swap the MSW with the LSW of a 32 bit integer */
#define WORDSWAP(x) (MSW(x) | (LSW(x) << 16))
#define BYTESWAP(x) (MSB(x) | (LSB(x) << 8))

#define LLSB(x) ((x) & 0xff)        /* 32bit word byte/word swap macros */
#define LNLSB(x) (((x) >> 8) & 0xff)
#define LNMSB(x) (((x) >> 16) & 0xff)
#define LMSB(x)  (((x) >> 24) & 0xff)
#define LONGSWAP(x) ((LLSB(x) << 24) | \
             (LNLSB(x) << 16)| \
             (LNMSB(x) << 8) | \
             (LMSB(x)))

#define TIMER_MS                500

typedef union
{
    float fdata;
    unsigned long ldata;
}HMI_FloatLongType;

typedef struct
{
    char str_list_value[3][NAME_STRING_LEN];
}HMI_LIST_ITEM;

struct HMI_LBNODE
{
    struct HMI_LBNODE* prev;
    struct HMI_LBNODE* next;
    unsigned int   key;
    int    size;
    unsigned char   data[1];
};

enum HMI_LBTYPE { REPLACE, APPEND };

struct HMI_LBC
{
    struct HMI_LBNODE* head;
    struct HMI_LBNODE* end;
    int           buf_num;
    int           max_buf;
    enum   HMI_LBTYPE type;
};

struct HMI_MODBUS_TCPMSG
{
    Uint8 tid[2];                          // 传输标志
    Uint8 pid[2];                          // 协议标志
    Uint8 length[2];                       // 数据长度
    Uint8 uid;                             // 单元标志
    unsigned char data[256];
};

typedef struct
{
    //Uint8 slave_addr;
    Uint8 fun_code;
    Uint8 start_addr_h;
    Uint8 start_addr_l;
    Uint8 no_point_h;
    Uint8 no_point_l;
    //Uint8 crc_l;
    //Uint8 crc_h;
} HMI_MODBUS_MSG;

typedef struct
{
    unsigned char  active;
    Uint8  addr;
    int port;
    struct HMI_CONSOLE* console;
    Uint8  enable_hmip;
    Uint32 client_addr;

    Uint16 selforbroad_frame;
    Uint16 received_frame;
    Uint16 crc_error_frame;
    Uint16 exception_frame;
    Uint16 noresponse_frame;
    Uint8 listen_only_mode;
    Uint8 exception;

    // 应用层发送数据
    Uint8 app_data[400];
    Uint8 app_length;

    struct HMI_LBC* l1_list_buf;
    pthread_mutex_t l1_mutex;
    pthread_mutex_t msg_send_mutex;
} HMI_APPMODBUS;

struct HMI_UART
{
    HMI_APPMODBUS* app_modbus;
    int     com_fd;              // 打开通讯串口返回的文件描述符,读入
    int     wr_fd;               // 打开通讯串口返回的文件描述符,写出
    int     timeout;
    Uint8   com_addr;
    int     com_id;
    Uint32  baudrate;
    Uint32  last_baudrate;
    Uint32  delay_time;         // 485口读写转换延时时间，单位us
    Uint32  protocol;
    Uint32  last_protocol;
    Uint16  recv_data;          //通讯口通讯状态

    // 串口链路层
    Uint8  send_buf[400];
    int    send_length;

    // 时间判断相关
    struct timeval  check_time;
    int             wait_recvall_flag;
};

struct HMI_CONSOLE
{
    HMI_APPMODBUS* app_modbus;
    struct  HMI_CLIENT* client[4];
    Uint32  addr;                          // 该节点的源IP地址
    Uint16  tcp_timeout;                   // 该节点tcp端口超时没有接收到数据的时间计数器

    char    used;
    Uint16  tid;                           // 传输标志
    Uint16  pid;                           // 协议标志
    Uint16  length;                        // 数据长度
    Uint8   uid;                           // 单元标志
};

typedef struct
{
    int		active;
    int		fd;
    int     start;
    int		rd_cursor;
    char	buf[MAX_BUF_LEN];
    void	(*read)(void*);
    void* arg;
    time_t	last_active_time;
}HMI_FD;

struct HMI_CLIENT
{
    HMI_FD* fdp;
    struct  HMI_CONSOLE* console;
    struct  in_addr client_addr;
    int     fd;
    Uint8   iscon;
};

typedef struct
{
    int     active;
    int     fd;
    int     rd_cursor;
    char    buf[MAX_FD103_BUF_LEN];
    void    (*read)(void*);
    void* arg;
    time_t  last_active_time;
}HMI_FD103;

typedef struct
{
    char desc[64];//遥信or遥测or遥调or遥控or定值
    char updata_unit[64];//单位
    char name[64];//名称
    float coe;//单位系数
    u_short iDevAddr;
    u_char iStatus;  //0=没有，=1 正在选择，=2 选择成功 ，=3 正在执行, =5 正在撤消
    u_char  iGroup;    //设备中的组号
    u_char  iItemNo;   //设备中的条目号
    u_char  iValType;
    u_char  iYb;       //是否样板
    u_char	iFirstTrigFlg;		//第一次读取遥调值
    u_int   iActCnt;
    union 	UINT_FLOAT   uVal; //遥测值，遥信状态，遥控状态等
    float  fOldVal;//保持上一次的遥调值
    float fCeo;   //遥测系数,
    float fOffset;//遥测零漂，遥控超时计数，遥调超时计数
    u_int modbus_addr;
}HMI_MU_INDEX_ELEMENT;

union _HMI_MODBUS_RX_FIFO
{
    Uint8 buf[MODBUS_FIFO_LENGTH];
    struct
    {
        Uint8 start_flag;
        Uint8 data_length_low;
        Uint8 data_length_high;
        Uint8 port;              // 指明是给哪个后台端口的
        Uint8 app_buf[MODBUS_FIFO_DATA_LENGTH];
        Uint8 reserved_end_flag;       // 预留给app_buf满载时的end_flag
    }data;
};

typedef union _HMI_MODBUS_RX_FIFO HMI_MODBUS_RX_FIFO;

typedef struct
{
    struct SB_HEAD sh;
    u_int	app_id;                          //任务模块标示
    u_int	group_id;                        //组标示
    u_int	task_id;                          // 
    FBufCircle msg_cc;                         //任务消息表示
    u_char	net_no;                          //使用物理网口号
    u_char	board_no;                        //所属板卡地址号

    struct  HMI_CLIENT  tcp_client[MAXCLIENT];
    HMI_FD103  fdt_app;
    HMI_FD103   fdt_103[MAX_FD103];
    int max_fd_103;
    fd_set read_set_103;
    fd_set read_set_save_103;

    int modbus_fifo_fd;
    HMI_MODBUS_RX_FIFO app_rx_fifo;
    HMI_APPMODBUS modbus[COMM_CONNECT_MAX];
    struct  HMI_CONSOLE tcp_console[MAXCONSOLE];

    int modbus_tcplistensock;
    int modbus_tcp_port_number;
    uint32_t  modbus_float_byteorder;

    u_int     hUdpsk;
    struct sockaddr_in  tUdpAddr;
    char udpbuf[512];
    u_int     hSendUdpsk;

    Uint16 selforbroad_frame;
    Uint8 exception;
    // 应用层发送数据
    Uint8 app_data[400];
    Uint8 app_length;
    Uint8 language_type;
    Uint32 keep_alive_interval;

    u_short iYcNums;
    u_short iYxNums;
    u_short iYmNums;
    u_short iYkNums;
    u_short iYtNums;
    HMI_MU_INDEX_ELEMENT* paYcList;
    HMI_MU_INDEX_ELEMENT* paYxList;
    HMI_MU_INDEX_ELEMENT* paYmList;
    HMI_MU_INDEX_ELEMENT* paYkList;
    HMI_MU_INDEX_ELEMENT* paYtList;

    struct HMI_UART uart[MAX_RS485];
    void* modbus_rtu_readUartData_fun;

    char msg_buf[MAX_MSG_LEN];
    u_short msg_len;
} HMI_MODBUS_UP_STRUCT;
typedef struct {
    //char* buf;  // 动态数组，用于储存中文字符
    int num_Yc;
    int num_Yx;
    int num_Yxx;
    int num_Yt;
    int num_Yk;
    int num_Ycc;
    int num_Yx_S;
    float* buf_Yc;
    float* buf_Ycc;
    float* buf_Yx;
    float* buf_Yxx;
    float* buf_Yt;
    float* buf_Yk;
    float* buf_Yx_S;
    char* desc_Yc;
    char* desc_Ycc;
    char* desc_Yx;
    char* desc_Yxx;
    char* desc_Yt;
    char* desc_Yk;
    char* desc_Yx_S;
    char* unit_Yc;
    char* unit_Ycc;
    char* unit_Yx;
    char* unit_Yxx;
    char* unit_Yt;
    char* unit_Yk;
    char* unit_Yx_S;
    float* coe_Yc;
    float* coe_Ycc;
    float* coe_Yx;
    float* coe_Yxx;
    float* coe_Yk;
    float* coe_Yt;
    float* coe_Yx_S;
    char* name_Yc;
    char* name_Ycc;
    char* name_Yx;
    char* name_Yxx;
    char* name_Yk;
    char* name_Yt;
    char* name_Yx_S;
}hmi_updata_struct;
hmi_updata_struct* get_hmi_data(); 
#endif