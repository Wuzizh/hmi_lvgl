/*
 * data types defines
 * zhouxf, 2017.6.23
 */

#ifndef _DATA_TYPES_H_
#define _DATA_TYPES_H_

#ifndef _WIN32
typedef  unsigned char u_char;
typedef  unsigned short u_short;
typedef  unsigned int u_int;
#else
#include <WinSock2.h>
#define sleep(a)  Sleep(a*1000)
#define usleep(a)  Sleep(a/1000)
#define ioctl(a,b,c)   1
#endif


typedef struct {
	unsigned int seconds;
	unsigned int msec;
} time_type;

typedef unsigned char mac_addr_t [6];


#ifndef MSB
#define MSB(X) (((X) >> 8) & 0xff)
#endif /* MSB */

#ifndef LSB
#define LSB(X) ((X) & 0xff)
#endif /* LSB */

#ifndef MSW
#define MSW(X) (((X) >> 16) & 0xffff)
#endif /* MSW */

#ifndef LSW
#define LSW(X) ((X) & 0xffff)
#endif /* LSW */

#endif /* _DATA_TYPES_H_ */

