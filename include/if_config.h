/********************************************************************
	created:	2016/06/22
	created:	22:6:2016   11:25
	filename: 	D:\rd\src_code\RTU_PJT\HSDC_TEST\inc\base_functions.h
	file path:	D:\rd\src_code\RTU_PJT\HSDC_TEST\inc
	file base:	base_functions
	file ext:	h
	author:		
	purpose:	net interface config
*********************************************************************/
#ifndef _IF_CONFIG_H_
#define _IF_CONFIG_H_

#include <stdio.h>
#include <time.h>

#include "data_types.h"

#define DEF_IF_IPx(IF)		(0xc6780014 + (IF << 16))
#define DEF_IF_MASKx(IF)	0xffff0000
#define DEF_DST_NETx(IF)	(0xc6780000 + (IF << 16))
#define DEF_GW_MASKx(IF)	0xffff0000
#define DEF_GWx(IF)			(0xc6780001 + (IF << 16))

extern char * if_name [];

int regen_mac_addr ();
int set_if_ip_addr (char * et, u_int ip_no, u_int ip_addr, u_int net_mask);
int set_if_gateway (u_int dst_net, u_int dst_mask, u_int gateway);
int get_mac_addr (char * eth, mac_addr_t mac_addr);
int set_mac_addr (char * eth, mac_addr_t mac_addr);

#endif /* _IF_CONFIG_H_ */
