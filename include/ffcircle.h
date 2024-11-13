// ============================================================================
//	2012-2026, All Rights Reserved					
//								      	
// 文件名 ： ffcircle.h			    	      	
// 产品：公共类封装					      	
// 作者：唐庆林
// 日期：							      	
// 文件描述:  环形队列，注意"只限在两个线程之间共享数据。		      	
//
// 修改日志:	(可选)						
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
