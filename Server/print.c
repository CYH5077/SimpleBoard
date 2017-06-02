#include "./system.h"
#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define BYTE_GIGA 1024

static void print_label(char * title, int line){
	print_line('-', line); printf("%s", title);
}


static void printProgress(char * label, double now, double max)
{
	int loop;
	double percent;
	int ca;

	percent = (now*100)/max;
	ca = (int)(percent/5);
	
	printf("%s [", label);
	for(loop = 0; loop <ca; loop++)printf("=");
	printf("%*c %.0lf%%", 22-ca, ']', percent);	
}

void printResource(reInfo re)
{
	/////////메모리 정보 출력.
	print_label("Memory\n",LINE*2);
	font_color(31); printf("총 메모리 : %.0lf KByte\t\t\t", re.total_mem/BYTE_GIGA); font_color_reset();
	font_color(34); printf("총 가상메모리 : %.0lf KByte\n", re.total_vir_mem/BYTE_GIGA); font_color_reset();
	
	font_color(31); printf("사용중인 메모리 : %.0lf KByte\t\t\t", re.using_mem/BYTE_GIGA); font_color_reset();
	font_color(34); printf("사용중인 가상 메모리 : %.0lf KByte\n", re.using_vir_mem/BYTE_GIGA); font_color_reset();
	
	font_color(31); printProgress("사용량",re.using_mem, re.total_mem); font_color_reset();
	printf("\t\t");
	font_color(34); printProgress("사용량", re.using_vir_mem, re.total_vir_mem); font_color_reset();
	printf("\n");

	/////////Network 정보 출력
	print_label("Network\n", LINE*2);
	font_color(36); 
	printf("바이트 수신 : %4d Bytes/s\t\t\t", re.netSec_recv);
	printf("초당 소켓 수신 : %4d (1/s)\n", re.netSock_recv);
		
	printf("바이트 송신 : %4d Bytes/s\t\t\t", re.netSec_send);
	printf("초당 소켓 송신 : %4d (1/s)\n\n", re.netSock_send);


	printf("초당 총 바이트 : %4d Bytes/s\t\t\t", re.netSec_total);
	printf("초당 총 패킷 : %4d (1/s)\n\n", re.netSock_total);

	printf("수신 최고 기록 : %4.1f KBytes/s\t\t\t", re.netSec_max_recv/1024.0);
	printf("수신 패킷 최고 기록 : %4d (1/s)\n", re.netSock_max_recv);
	
	printf("송신 최고 기록 : %4.1f KBytes/s\t\t\t", re.netSec_max_send/1024.0);
	printf("송신 패킷 최고 기록 : %4d (1/s)\n", re.netSock_max_recv);
	
	printf("바이트 최대 기록 : %4d KBytes/s\t\t", re.netSec_max_total/1024);
	printf("패킷 최대 기록 : %4d (1/s)\n", re.netSock_max_total);
	font_color_reset();
	
	//////////cpu 정보 출력.
	print_label("CPU\n", LINE*2);
	font_color(35); 
	printf("CPU Vendor :\t%s", re.cpu_vendor);
	printf("CPU Model :\t%s", re.cpu_model);
	printf("CPU Core count :%s", re.cpu_core_count);
	printProgress("CPU 사용량", (double)re.cpu, 100.0); 
	font_color_reset(); 
	printf("\n\n");
}
void get_resource_info(reInfo * re)
{
	pthread_t pt[3];
	int loop;

	pthread_create(&pt[0], NULL , get_mem_info, (void*)re);
	pthread_create(&pt[1], NULL , get_cpu_info, (void*)re);
	pthread_create(&pt[2], NULL , get_net_info, (void*)re);

	for(loop = 0; loop < 3; loop++)
		pthread_join(pt[loop], NULL);
	return ;
}

void font_color(int color){
	printf("%c[1;%dm", 27, color);
}
void font_color_reset(){
	printf("%c[0m", 27);
}
void print_line(char print_char, int line){
	int i;
	for(i = 0; i < line; i++) printf("%c", print_char);
}
