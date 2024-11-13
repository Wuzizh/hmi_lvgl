
#ifndef _RUNSTAT_H_
#define _RUNSTAT_H_

#include <stdlib.h>
#include <signal.h>

#ifdef __cplusplus
extern "C" {
#endif
	
	int FindRunning(const char *pLockFile);

	int AlreadyRunning(const char *pLockFile);

	void ProcessSIG(int iSig);
	void PrintHex(char *p, int len);


#ifdef __cplusplus
}
#endif

#endif  //_RUNSTAT_H_



