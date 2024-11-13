/****************************************************************
 * Description:�������ݴ���ӿ�
 *
 * Modify Log:
 ****************************************************************/

#ifndef	_SYS_SIO_H_
#define	_SYS_SIO_H_

#define UART_DEV_FMT(X)	"/dev/uart"#X

#ifndef _WIN32
#define PARITY_NONE		0
#define PARITY_ODD		1
#define PARITY_EVEN		2
#endif

/* ioctl commands */
#define SERIAL_SET		0x6503

#ifdef _MT6816
typedef struct _srlled_info {
	int  fd;									// �ļ�������
	int	 translen;
	pthread_mutex_t mutex;						// �߳���
	unsigned char led_tx[10];
	unsigned char led_rx[10];
	unsigned char trsans_buf[256];				// ���仺����
}__attribute__((packed))  srlled_info;
#endif

typedef struct serial_setting_s {
	unsigned int baud;    /* ֧�ֲ����� 1200 2400 4800 9600 19200 38400 57600 115200*/
	unsigned int parity;  /* 0: ��У��, 1: ��У��, 2: żУ�� */
} serial_setting_t;

extern int sys_com_init(int com_no);
extern int sys_put_sio_msg(int com_no,u_char *buf,int len);
extern int init_uart(unsigned int uart_id, struct	SYS_COM_INIT* init);

int serialread(int comId, char* buf, int iBufLen, int timer);

#ifdef _FORLINX_PLF
extern int sys_open_wdt(char* name);
extern void sys_close_wdt(int fd);
extern int sys_start_wdt(int fd, int sec);
extern int sys_keepalive_wdt(int fd);
#endif

#ifdef _FORLINX_PLF
extern int sys_wdt_fd;
#endif

#ifdef _WIN32
extern HANDLE hCom;//���,���ڳ�ʼ������
#endif

#endif
