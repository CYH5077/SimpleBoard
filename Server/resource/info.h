#ifndef __INFO_HEADER__
#define __INFO_HEADER__
#include "../r_type.h"
#include "../system.h"

void * get_mem_info(void * arg);

void * get_cpu_info(void * arg);
int get_cpu_name(reInfo * re);

void * get_net_info(void * arg);

#endif
