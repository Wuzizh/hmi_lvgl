/********************************************************************
	created:	2013/12/27
	created:	27:12:2013   10:55
	filename: 	Z:\prog\nr-switch-prog\inc\thread.h
	file path:	Z:\prog\nr-switch-prog\inc
	file base:	thread
	file ext:	h
	author:		zhouxf
	purpose:	thread related operations
*********************************************************************/

#ifndef _TS_THREAD_H_
#define _TS_THREAD_H_
#ifndef _WIN32
#include <pthread.h>
#define CM_THREAD_ID 		pthread_t
#else
#include <WinSock2.h>
#include <windows.h>
#define CM_THREAD_ID 		unsigned
#define CM_THREAD_HANDLE 	HANDLE
#endif
CM_THREAD_ID thread_create  (char * name, int ss, int prio, void (f)(void *), void *arg);
int       thread_destroy (CM_THREAD_ID tid);
void      thread_exit    (int rc);

#endif /* _TS_THREAD_H_ */
