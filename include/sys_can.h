/****************************************************************
 * Description:CAN���ݴ���ӿ�
 *
 * Modify Log:
 ****************************************************************/

#ifndef	_SYS_CAN_H_
#define	_SYS_CAN_H_

#include <stdint.h>


// can_no��0��ʼ��0��ʾCAN0��1��ʾCAN1��......
extern int sys_can_open(int can_no, int baudrate);

extern int sys_can_write(int can_fd, uint32_t can_id, const void *buf, int len);

// buf���Ȳ���С��8
extern int sys_can_read(int can_fd, uint32_t *can_id, void* buf);

#endif
