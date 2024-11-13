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
#ifndef _FB_CIRCLE_H_
#define _FB_CIRCLE_H_
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#ifdef __cplusplus
extern C{
#endif

typedef struct {
	int iDataLen;
	char *aDataBuf;
}FBufElement;
typedef struct {
	int iReadPtr;
	int iWritePtr;
	short iElementCnt;
	FBufElement *aDataElm;
}FBufCircle;

void FBInitCircleWR(FBufCircle* pCircle);
int FBInitCircle(FBufCircle *pCircle, int iElementCnt);
int FBReadElement(FBufCircle *pCircle, char *pElement, int iDataLen);
int FBAppendElement(FBufCircle *pCircle, char *pElement,int iDataLen);
void FBReleaseCircle(FBufCircle *pCircle);

#ifdef __cplusplus
}
#endif

#endif /* _FB_CIRCLE_H_ */
