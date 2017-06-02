#include "./info.h"
#include <sys/sysinfo.h>

struct sysinfo memInfo;

//전체 메모리 크기를 구하는 함수.
static double physical_total_mem()
{
	double total_mem;
	
	total_mem = memInfo.totalram;
	total_mem *= memInfo.mem_unit;

	return total_mem;
}
//전체 사용중인 메모리를 구하는 함수.
static double physical_using_mem()
{
	double using_mem;
	
	using_mem = memInfo.totalram - memInfo.freeram;
	using_mem *= memInfo.mem_unit;

	return using_mem;
}

//전체 가상 메모리 크기를 구하는 함수
static double virtual_total_mem()
{
	double total_vir;
	
	total_vir = memInfo.totalram;
	total_vir += memInfo.totalswap;
	total_vir *= memInfo.mem_unit;

	return total_vir;
}
//전체 사용중인 가상 메모리 크기를 구하는 함수
static double virtual_using_mem()
{
	double using_vir;

	using_vir = memInfo.totalram - memInfo.freeram;
	using_vir += memInfo.totalswap - memInfo.freeswap;
	using_vir *= memInfo.mem_unit;

	return using_vir;
}

void * get_mem_info(void * arg)
{
	reInfo * re = (reInfo*)arg;

	sysinfo(&memInfo);
	re->total_mem = physical_total_mem();
	re->using_mem = physical_using_mem();
	re->total_vir_mem = virtual_total_mem();
	re->using_vir_mem = virtual_using_mem();
	return (void*)0;
}
