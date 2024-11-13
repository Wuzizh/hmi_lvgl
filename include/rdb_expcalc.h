
#ifndef	_RDB_EXPCALC_H_
#define	_RDB_EXPCALC_H_

#include "../../include/sys_extern.h"
//#include "../../include/sys_asdu.h"
#include "../../include/rdb_itf.h"
//#include "../../include/softbus.h"
#include "../../include/sys_func.h"
#include "../../include/os_func.h"
#include "../../include/sys_stream.h"

#include "rdb_extern.h"

/* DEFINE */
#define  EXP_HANDLE_NUM     28
#define  EXP_SET_HANDLE_NUM 6

/* DATA STRUCTURES */
union MYDATA
{
    float fmea;
    int lmea;
    u_char spi;
	u_char dpi;
    u_int yp;
    u_int ym;
};

struct  iteml 
{
	union {
		struct  ELEMENT *dp;
		union MYDATA mdd;
	};
	int operate;
};
struct  EXPRESSION
{
    struct  EXPRESSION *next;
    int dp_no;
    struct  ELEMENT *dp;
    int item_num;
    struct  iteml *myitem[1];
};
typedef struct  
{
	union   MYDATA  stack[10];
	u_char  stack_ycqds[10];
	short   sp;
	short   g_first_flag;
}RDB_EXPCALC_Data;

struct  RDB_EXPCALC_STR
{
    struct  EXPRESSION *exp_head;
    void    (* handle[EXP_HANDLE_NUM])(struct iteml *dp, RDB_EXPCALC_Data *pExpData);
    void    (* saveresult[EXP_SET_HANDLE_NUM])(struct ELEMENT *dp, RDB_EXPCALC_Data *pExpData);
};

struct  RDB_EXPCALC_STR     *Rdb_expcalc_p;

extern  void  createExpLists(struct SYS_STRSTREAM *strp);
extern  void  expcalc_calc_hook(void *dp, struct SYS_TIME *t);
extern  void  expcalc_calc(void *dp);

static  void  initExpcalcVar(void);
static  struct EXPRESSION *createExpList(struct SYS_STRSTREAM *strp);
static  void  setyc(struct ELEMENT *dp, RDB_EXPCALC_Data *pExpData);
static  void  setyx(struct ELEMENT *dp, RDB_EXPCALC_Data *pExpData);
static  void  setym(struct ELEMENT *dp, RDB_EXPCALC_Data *pExpData);
static  void  setyk(struct ELEMENT *dp, RDB_EXPCALC_Data *pExpData);
static  void  setyt(struct ELEMENT *dp, RDB_EXPCALC_Data *pExpData);
static  void  setyp(struct ELEMENT *dp, RDB_EXPCALC_Data *pExpData);
static  void  notused(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  getyc(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  getyx(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  getyp(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  immyc(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  not(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  and(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  or(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  xor(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  add(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  sub(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  mul(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  divv(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  getbx(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData); //ªÒ»°bitŒª
static  void  greatx(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  equalx(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  lowx(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  greatex(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  lowex(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  yxtoyp(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  YPtoYXnstep(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  YPtoYC(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);
static  void  YPtoYXbcd(struct iteml *pOpr, RDB_EXPCALC_Data *pExpData);


#endif
