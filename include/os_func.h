
#ifndef	_OS_FUNC_H_
#define	_OS_FUNC_H_

#include "stdlib.h"
#include "stdio.h"
#ifndef _WIN32
#include "unistd.h"
#include "semaphore.h"
#include "pthread.h"
#include "sys/time.h"
//#include "sys/timerfd.h"
#include "mqueue.h"
#else
typedef int sem_t;
#endif
#include "fcntl.h"
#include "string.h"
#include "errno.h"
#include "data_types.h"

#define PTHREAD_PRIORITY    99
#define MQMSG_PRIORITY      1
#define MQ_RLIMIT_MAX_BYTES		(20 * 1024 * 1024)

enum{ENUM_FUNC01=0,WAIT_FOREVER,WAIT_NO,CM_WAIT_TIMEOUT};

typedef struct
{
	u_int iSec;
	u_int iUSec;
}ppComTime;

ppComTime ComGetTime();

int sys_thread_creat(void* (*func)(void*), void* arg, int stack_size, int priority);

int set_msgq_rlimit ();
int sys_msgq_creat(char *mqName, int mqMsgNum, int mqMsgSize);
int sys_msgq_recv(int msgId, char *msgBuf, int msgLen, unsigned int *msgPri);
int sys_msgq_send(int msgId, char *msgBuf, int msgLen, unsigned int msgPri);

int sys_sem_create(sem_t *semId, int InitVal);
int sys_sem_take(sem_t *semId, int blockType, int msecond);
int sys_sem_give(sem_t *semId);
int sys_sem_delete(sem_t *semId);

int sys_char_to_int(u_char *data);
u_int sys_char_to_uint(u_char *data);
short sys_char_to_short(u_char *data);
u_short sys_char_to_ushort(u_char *data);
int sys_my_max(int *data, int num);
int show_hexmsg(char * prompt, unsigned char buf[], int len);

int ts_close(u_int sk);
int setnonblocking(int sockfd);
#endif
