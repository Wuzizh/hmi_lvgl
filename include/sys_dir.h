
#ifndef	_SYS_DIR_H_
#define	_SYS_DIR_H_

#include "board_cfg.h"

#define SYS_HOME_PATH           "./"//"/home/comm" //"tffs1:/"

#define SYS_PROG_PATH           SYS_HOME_PATH"/run" //"tffs1:/bin"
#define SYS_CCU_PATH            SYS_HOME_PATH"/ccu" //"tffs1:/ccu"
#define SYS_SET_PATH            SYS_HOME_PATH"/set" //"tffs1:/set"
#define SYS_OTHER_PATH          SYS_HOME_PATH"/other" //"c1:/other"
#define SYS_COMTRADE_PATH		SYS_HOME_PATH"/comtrade" //"c1:/other"
#define SYS_CCU_BAK_PATH        SYS_HOME_PATH"/ccubak/" //"c1:/other"

#define SYS_SCC_MULTIPC_PATH	SYS_HOME_PATH"/multipc.txt"

#define SYS_COMTRADE_TEMP_PATH  SYS_HOME_PATH"/temp" //"c1:/other"

#define SYS_PROG_FILE_NAME      "ccumain" //"vxWorks"
#define SYS_CCU_FILE_NAME       "config.ini"		//"RCS9798.ini"
#define SYS_IP_FILE_NAME        "ipaddr.ini"
#define SYS_RESET_FILE_NAME     "reset.cmd"
#define SYS_DEVSTAT_FILE_NAME   "DevState.dat"
#define SYS_STATMODE_FILE_NAME  "devstamode.txt"
#define SYS_INI_FILE_NAME        ".ini"
#define SYS_CFG_FILE_NAME        ".cfg"
#define SYS_CID_FILE_NAME        ".cid"

#define SYS_PROG_INI_PATH       SYS_HOME_PATH"/bin/ccumain"
#define SYS_CCU_INI_PATH        SYS_HOME_PATH"/ccu/config.ini"  //"tffs1:/ccu/RCS9798.ini"
#define SYS_PCTCP_INI_PATH      SYS_HOME_PATH"/set/ipaddr.ini"  //"tffs1:/set/ipaddr.ini"
#define SYS_PCTCP_INI_BAK       SYS_HOME_PATH"/set/ipaddr.bak"  //"tffs1:/set/ipaddr.bak"
#define SYS_ADDR_INI_PATH       SYS_HOME_PATH"/set/ftaddr.ini"  //"tffs1:/set/ftaddr.ini"
#define SYS_ADDR_INI_BAK        SYS_HOME_PATH"/set/ftaddr.bak"  //"tffs1:/set/ftaddr.bak"
#define SYS_SET_INI_PATH        SYS_HOME_PATH"/set/set.ini"     //"tffs1:/set/set.ini"
#define SYS_ARP_INI_PATH        SYS_HOME_PATH"/set/arps.ini"    //"tffs1:/set/arps.ini"
#define SYS_RESET_INI_PATH      SYS_HOME_PATH"/bin/reset.ini"   //"tffs1:/bin/reset.cmd"

//#define SYS_PROG_INI_PATH_1     "c1:/system/ccu/vxworks"
//#define SYS_CCU_INI_PATH_1      "/home/rcs9798.ini" //"c1:/system/ccu/RCS9798.ini"
//#define SYS_PCTCP_INI_PATH_1    "/home/ipaddr.ini"  //"c1:/system/set/ipaddr.ini"
//#define SYS_PCTCP_INI_BAK_1     "/home/ipaddr.bak"  //"c1:/system/set/ipaddr.bak"
//#define SYS_ADDR_INI_PATH_1     "/home/ftaddr.ini"  //"c1:/system/set/ftaddr.ini"
//#define SYS_ADDR_INI_BAK_1      "/home/ftaddr.bak"  //"c1:/system/set/ftaddr.bak"
//#define SYS_SET_INI_PATH_1      "/home/set.ini"     //"c1:/system/set/set.ini"

#endif
