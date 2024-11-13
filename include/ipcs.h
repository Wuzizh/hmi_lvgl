/********************************************************************
	created:	2014/02/26
	created:	26:2:2014   11:07
	filename: 	Z:\prog\nr-switch-prog\inc\sync.h
	file path:	Z:\prog\nr-switch-prog\inc
	file base:	sync
	file ext:	h
	author:		zhouxf
	purpose:	Inter-Process Communication operations
*********************************************************************/
#ifndef _IPCS_H_
#define _IPCS_H_

#include <sys/types.h>
#ifndef _WIN32
#include <sys/ipc.h>
#include <sys/msg.h>
#include <semaphore.h>
#else
#include <windows.h>
#include <process.h>
#define sem_t  int
#define key_t  int
#define pthread_mutex_t CRITICAL_SECTION
#define IPC_CREAT 1
#define IPC_EXCL 1
#define SETVAL 1
#define GETVAL 1
#endif
#include <time.h>

/********************************************************************
	purpose:	define semophore operations
*********************************************************************/

#define CREAT_KEY(A,B,C,D)	(((A) << 24) | ((B) << 16) | ((C) << 8) | (D))

/*���̻����ź���*/
#define PROCESS_WAIT_FOREVER -1
#define PROCESS_SEM_TIMEOUT  10  /*��*/
#define SYNC_CALL_TIMEOUT_MS 10000 /*ms*/

/*�̻߳����ź���*/
#define PTHREAD_WAIT_FOREVER -1
#define PTHREAD_MUTEX_TIMEOUT  10  /*��*/

/*
 * pthread
 */
int sem_timewait (sem_t * sem, const struct timespec * abs_timeout);

/********************************************************************
*����:�������̻�����ź�����ԭ�������ڣ��򴴽�����ֵ��������ֱ��ʹ�ã�
      �����¸�ֵ
*����:key,�ź�����ʶ
*����:value,�ź���ֵ.
*����ֵ���ɹ����ش�����semidֵ��������-1.
********************************************************************/
extern int create_sem(key_t key, int value);

/********************************************************************
*����:�������̻�����ź�������ָ��semflgֵ����������ɹ�����valueֵ��ֵ
*����:key,�ź�����ʶ
*����:value,�ź���ֵ
*����:semflg,�ź���flag����0666|IPC_CREAT|IPC_EXCL��
*����ֵ���ɹ����ش�����semidֵ��������-1.
********************************************************************/
extern int create_sem_excl(key_t key, int value, int semflg);

/********************************************************************
*����:���ý��̻�����ź���ֵ
*����:semid,�ź���
*����:value,�ź���ֵ
*����ֵ���ɹ�����0��������-1.
********************************************************************/
extern int setvalue_sem(int semid, int value);

/********************************************************************
*����:��ȡ���̻�����ź���ֵ
*����:semid,�ź���
*����ֵ���ɹ����ض�����ֵ��������-1.
********************************************************************/
extern int getvalue_sem(int semid);

/********************************************************************
*����:ɾ�����̻�����ź���
*����:semid,�ź���
*����ֵ���ɹ�����0��������-1.
********************************************************************/
extern int destroy_sem(int semid);

/********************************************************************
*����:��ȡ���̻�����ź���
*����:semid,�ź���id
*����:timeout_s,��ʱʱ��,��λ�롣��PRCESS_WAIT_FOREVER���ʾһֱ�ȴ�.
*����ֵ���ɹ�����0��������-1.
********************************************************************/
extern int process_mutex_take(int semid, int timeout_s);

/********************************************************************
*����:�ͷŽ��̻�����ź���
*����:semid,�ź���id
*����ֵ���ɹ�����0��������-1.
********************************************************************/
extern int process_mutex_give(int semid);

/********************************************************************
*����:�����̻߳�����ź���
*����:mutex,�ź���ָ��
*����ֵ���ɹ�����0�������س�����.
********************************************************************/
int pthread_mutex_create(pthread_mutex_t *mutex);

/********************************************************************
*����:ɾ���̻߳�����ź���
*����:mutex,�ź���ָ��
*����ֵ���ɹ�����0�������س�����.
********************************************************************/
int pthread_mutex_delete(pthread_mutex_t *mutex);

/********************************************************************
*����:��ȡ�̻߳�����ź���
*����:mutex,�ź���ָ��
*����ֵ���ɹ�����0�������س�����.
********************************************************************/
int pthread_mutex_take(pthread_mutex_t *mutex);

/********************************************************************
*����:��ȡ�̻߳�����ź���
*����:mutex,�ź���ָ��
*����:timeout_s,��ʱʱ��,��λ�롣��PTHREAD_WAIT_FOREVER���ʾһֱ�ȴ�.
*����ֵ���ɹ�����0�������س�����.
********************************************************************/
int pthread_mutex_taket(pthread_mutex_t *mutex, int timeout_s);

/********************************************************************
*����:�ͷ��̻߳�����ź���
*����:mutex,�ź���ָ��
*����ֵ���ɹ�����0�������س�����.
********************************************************************/
int pthread_mutex_give(pthread_mutex_t *mutex);


/********************************************************************
	purpose:	msgq related operations
*********************************************************************/
#define MSGQ_TEST_EXIST		(IPC_EXCL)
#define MSGQ_GET_FLAG		(0666 | IPC_CREAT)
#define MSGQ_DEL_FLAG		(IPC_RMID)
#define MSGQ_SND_FLAG		(IPC_NOWAIT)
#define MSGQ_RCV_FLAG		(0)

#define MSG_CONTEX_SIZE		1024

typedef struct msgbuf_s {
	int  msg_type;
	char msg_contex [MSG_CONTEX_SIZE];
} msgbuf_t;

/*
 * return value:
 * -1: error
 *  0: success
 *  1: created
 */
int msgq_create (int key, int * msgq_id);
int create_msg_q(int *q_id);
int msgq_delete (int msgq_id);
int msgq_send (int msgq_id, char * msg, int len, int msg_type);
int msgq_recv (int msgq_id, char * msg, int len, int msg_type);
int msgrcv_timeout(int msqid, void *msgp, unsigned int msgsz, long msgtyp, int time_ms);


/********************************************************************
	purpose:	shared memory related operations
*********************************************************************/
void * create_shared_memory (key_t key, int size);

/********************************************************************
	purpose:	event mechanism 
*********************************************************************/

typedef struct events_s {
	sem_t			cnt_sem;
	sem_t			mutex_sem;
	unsigned int	event_mask;
} events_t;

int events_create (events_t * ev);
unsigned int events_timewait (events_t * ev, struct timespec * abs_timeout);
int events_post (events_t * ev, unsigned int ev_mask);

#endif /* _IPCS_H_ */

