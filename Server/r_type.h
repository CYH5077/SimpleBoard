#ifndef __RESOURCE_TYPE_HEADER__
#define __RESOURCE_TYPE_HEADER__

//자원 정보를 저장할 구조체
typedef struct resource_info{
	double total_mem; 
	double using_mem;
	double total_vir_mem;
	double using_vir_mem;

	int cpu;
	char cpu_model[50];
	char cpu_core_count[3];
	char cpu_vendor[20];

	int netSec_recv; //초당 받은 데이터.
	int netSec_send; //초당 전송한 데이터
	int netSec_total; //초당 전송,받은 데이터
	int netSec_max_send; //초당 최고치를 기록한 전송 바이트.
	int netSec_max_recv; //초당 최고치를 기록한 수신 바이트
	int netSec_max_total; //초당 전송,받은 데이터의 최대 크기.

	int netSock_recv; //초당 전송한 패킷
	int netSock_send; //초당 수신한 패킷
	int netSock_total; //초당 전송 및 수신 패킷 
	int netSock_max_send; //초당 최고치를 기록한 전송패킷 수
	int netSock_max_recv; //초당 최고치를 기록한 수신패킷 수
	int netSock_max_total; //초당 전송, 받은 데이터의 최대 개수.
}reInfo;
#endif
