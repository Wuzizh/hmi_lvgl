// ============================================================================
//	2012-2026, All Rights Reserved					
//								      	
// �ļ��� �� ffcircle.h			    	      	
// ��Ʒ���������װ					      	
// ���ߣ�������
// ���ڣ�							      	
// �ļ�����:  ���ζ��У�ע��"ֻ���������߳�֮�乲�����ݡ�		      	
//
// �޸���־:	(��ѡ)						
//  Date     Who   Rev			Comments			
// ============================================================================/
#ifndef _FF_CIRCLE_H_
#define _FF_CIRCLE_H_
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#ifdef __cplusplus
extern C{
#endif

typedef struct {
	int iReadPtr;
	int iWritePtr;
	int iAllSize;
	short iElementSize;
	short iElementCnt;
	char *pDataBuf;
}FFCircle;

int FCInitCircle(FFCircle *pCircle, int iElemenSize, int iElementCnt);
int FCReadElement(FFCircle *pCircle, void *pElement);
int FCAppendElement(FFCircle *pCircle,void *pElement);
void FCReleaseCircle(FFCircle *pCircle);

#ifdef __cplusplus
}
#endif

#endif /* _FF_CIRCLE_H_ */
