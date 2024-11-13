 /****************************************************************
 * Description:	��Լģ�������
 * Modify Log:
 ****************************************************************/

#ifndef _SYS_PROTOCOL_COMMON_H_
#define _SYS_PROTOCOL_COMMON_H_ 

#define MAX_SIO_RECV_BUF_LEN	512
#define MAX_SIO_SEND_BUF_LEN	512

#define MAX_NET_RECV_BUF_LEN	4096
#define MAX_NET_SEND_BUF_LEN	512


#endif

/* ���ڹ������� */
#ifdef	_COM_PROTOCOL_DEF_	
	u_char		com_no ;
	u_char		com_state ;

	/*���ڱ���ͷ������ر���*/
	u_char		sio_recv_buf[MAX_SIO_RECV_BUF_LEN];
	u_char		sio_syn_head_recv_flag;
	int		sio_has_recv_bytes;
	int		sio_should_recv_bytes;

	int		sio_send_flag ;
	int		sio_send_len ;	
	u_char		sio_send_buf[MAX_SIO_SEND_BUF_LEN] ;	/*���ڴ����ط�����*/
#endif

/* ���繫������ */
#ifdef _NET_PROTOCOL_DEF_
	SEM_ID		lock_id ;

	u_char		con_no ;
	u_char		con_state ;
	
	u_char		net_recv_buf[MAX_NET_RECV_BUF_LEN] ;
	u_char		net_syn_head_recv_flag ;
	int		net_has_recv_bytes ;
	int		net_should_recv_bytes ;
	
	int		net_send_len ;
	u_char		net_send_buf[MAX_NET_SEND_BUF_LEN] ;
#endif

	
	u_char		protocol_type;
	u_char		board_addr;	
	u_int		app_id;
	u_int		group_id;
	u_int		task_id;
	struct		SB_HEAD	sb_head;

