
#ifndef	_SYS_STREAM_H_
#define	_SYS_STREAM_H_

#include  "sys_define.h"

extern	struct	SYS_STRSTREAM *sys_openstream(char * path,char * mode);
extern	void	sys_strclose(struct SYS_STRSTREAM * strp);
extern	void	sys_strprintf(struct SYS_STRSTREAM * strp,const char *format,...);
extern	int	sys_strseeknext(struct SYS_STRSTREAM *strp);
extern	int	sys_strftell(struct SYS_STRSTREAM * strp,int * line_p);
extern	void	sys_strfseek(struct SYS_STRSTREAM * strp,int fpos,int line);
extern	int	sys_checkLBrkt(struct SYS_STRSTREAM * strp);
extern	int	sys_checkRBrkt(struct SYS_STRSTREAM * strp);
extern	int	sys_strfind(struct SYS_STRSTREAM * strp,char *buf,char *string);
extern	int	sys_strcpy(struct SYS_STRSTREAM * strp,char *buf,char *s_buf);
extern	void	sys_strscanf(struct SYS_STRSTREAM * strp,char *s_buf);
extern	int	sys_range_scanf(struct SYS_STRSTREAM * strp,int *min,int *max,int *step);
extern	int	sys_precision_scanf(struct SYS_STRSTREAM * strp,int *m,int *n);

#endif
