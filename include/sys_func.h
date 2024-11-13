#ifndef	_SYS_FUNC_H_
#define	_SYS_FUNC_H_

#include  "sys_extern.h"
#include "fbufcircle.h"

struct SYS_NET_ACCEPT_MSG
{
	struct SYS_NET_ACCEPT_MSG * next;
	FBufCircle    *id;
	u_short local_port;
	u_int  remote_ip;
	u_int  remote_area;
	u_char type;
	u_char judge_dccu_state;
};

extern int sys_exitpro();
extern	int	sys_reset();
extern int sys_record_boot_inf(u_char type,struct SYS_TIME * t,char *decs);
extern   int sys_del(char *file_name);

extern int sys_init_variable();
extern int sys_get_board_addr();
extern int sys_get_master_slave_state();
extern u_char sys_get_local_remote_sta();
extern	int	sys_get_hwtx_sta();
extern	int	sys_ygz_on();
extern	int	sys_ygz_off();
extern	int	sys_sgz_on();
extern	int	sys_sgz_off();

extern 	time_t 	sys_time_to_timet(struct SYS_TIME *t);
extern 	int sys_timet_to_time(time_t *source,struct SYS_TIME *target);
extern 	int sys_get_time(struct SYS_TIME *sys_t);
extern 	int sys_set_time(struct SYS_TIME *sys_t);
extern time_t sys_get_soft_timer(void);
extern 	int sys_get_tval(struct timeval *t_val);
extern 	int sys_bigger_tval(struct timeval *t_val1, struct timeval *t_val2);
extern 	struct timeval sys_add_tvalUs(struct timeval *t_val, int iUs);

extern int sys_char_to_int(u_char *data);
extern u_int sys_char_to_uint(u_char *data);
extern short sys_char_to_short(u_char *data);
extern u_short sys_char_to_ushort(u_char *data);

extern int sys_my_max(int *data, int num);
extern	 int sys_get_fileLen(char *string);
extern	int  sys_tcp_send_data(int  tcp_id,u_char *send_buf,int send_len,int con_no,u_int destiantion_ip,u_int source_ip,u_short dev_addr);
extern void     Init_printf(const char *format,...);

extern unsigned short CRC16(unsigned char c, unsigned short crc_check);

#endif
