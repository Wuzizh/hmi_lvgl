/****************************************************************
 * Description:CAN数据处理接口
 *
 * Modify Log:
 ****************************************************************/

#ifndef	_SYS_CAN_H_
#define	_SYS_CAN_H_

#include <stdint.h>


// can_no从0开始，0表示CAN0，1表示CAN1，......
extern int sys_can_open(int can_no, int baudrate);

extern int sys_can_write(int can_fd, uint32_t can_id, const void *buf, int len);

// buf长度不能小于8
extern int sys_can_read(int can_fd, uint32_t *can_id, void* buf);

#endif
