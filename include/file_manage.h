/********************************************************************
	created:	2017/01/10
	created:	10:1:2017   10:26
	filename: 	D:\rd\src_code\F28M35_PRJ\dtu\dtu_arm\inc\file_manage.h
	file path:	D:\rd\src_code\F28M35_PRJ\dtu\dtu_arm\inc
	file base:	file_manage
	file ext:	h
	author:		
	purpose:	file manage interface
*********************************************************************/
#ifndef _FILE_MANAGE_H_
#define _FILE_MANAGE_H_

#include <data_types.h>
#ifndef _WIN32
#include <semaphore.h>
#endif
#include <stdio.h>

#if 1
#define FWRITE(BUF, SIZE, N, FP) fwrite (BUF, 1, SIZE * N, FP)
#define FREAD(BUF, SIZE, N, FP) fread (BUF, 1, SIZE * N, FP)
#else
#define FWRITE(BUF, SIZE, N, FP) fwrite (BUF, SIZE, N, FP)
#define FREAD(BUF, SIZE, N, FP) fread (BUF, SIZE, N, FP)
#endif

FILE * sys_fopen (const char * path, const char * mode);
int sys_fclose (FILE * stream);
int sys_mkdir (const char * path, int mode);

int write_cfg_header (char fbuf [], char * header);
int write_cfg_tailer (char fbuf []);
int write_cfg_comment (char fbuf [], char * comment, int header_tailer /* 1, 2 */);
int write_item_u32 (char fbuf [], char * item_name, u_int val);
int write_item_u32_hex (char fbuf [], char * item_name, u_int val);
int write_item_hex_seq (char fbuf [], char * item_name, unsigned char val [], u_int size);
int write_item_f32 (char fbuf [], char * item_name, float val);
int get_key_val_str (char fbuf [], char * key, char * val_buf, int buf_len);
int get_key_pos (char fbuf [], char * key);
int read_item_u32 (char fbuf [], char * key, u_int * val);
int read_item_u32_hex (char fbuf [], char * key, u_int * val);
int read_item_hex_seq (char fbuf [], char * key, unsigned char val [], u_int * size);
int read_item_f32 (char fbuf [], char * key, float * val);
int get_file (FILE * fp, char fbuf []);
void scan_dir (char * dir, int depth);
int get_file_len (FILE * fp, char * file_name);
int recover_file_from_bak (const char * path, const char * path_bak);

#endif /* _FILE_MANAGE_H_ */

