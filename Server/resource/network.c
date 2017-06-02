#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "./info.h"
#include <string.h>

#define NET_BYTE_SEND "/sys/class/net/enp2s0/statistics/tx_bytes"
#define NET_BYTE_RECV "/sys/class/net/enp2s0/statistics/rx_bytes"
#define NET_SOCK_SEND "/sys/class/net/enp2s0/statistics/tx_packets"
#define NET_SOCK_RECV "/sys/class/net/enp2s0/statistics/rx_packets"

static int get_file(char * file, int * result)
{
	FILE *fp;
	fp = fopen(file, "r");
	if(fp == NULL) return -1;
	fscanf(fp, "%d", result);
	fclose(fp);
	return 0;
}

static int get_byte(reInfo * re)
{
	int send_bandwidth, send_bandwidth2;
	int recv_bandwidth, recv_bandwidth2;
	int send_sock, send_sock2;
	int recv_sock, recv_sock2;
	//바이트 계산.
	if(get_file(NET_BYTE_SEND, &send_bandwidth) == -1) return -1;
	if(get_file(NET_BYTE_RECV, &recv_bandwidth) == -1) return -1;
	//패킷 개수 계산
	if(get_file(NET_SOCK_SEND, &send_sock) == -1) return -1;
	if(get_file(NET_SOCK_RECV, &recv_sock) == -1) return -1;

	sleep(1);

	//바이트 계산.
	if(get_file(NET_BYTE_SEND, &send_bandwidth2) == -1) return -1;
	if(get_file(NET_BYTE_RECV, &recv_bandwidth2) == -1) return -1;
	//패킷 개수 계산.
	if(get_file(NET_SOCK_SEND, &send_sock2) == -1) return -1;
	if(get_file(NET_SOCK_RECV, &recv_sock2) == -1) return -1;

	//초당 전송 및 수신 계산.
	re->netSec_send = send_bandwidth2 - send_bandwidth;
	re->netSec_recv = recv_bandwidth2 - recv_bandwidth;
	re->netSock_send = send_sock2 - send_sock;
	re->netSock_recv = recv_sock2 - recv_sock;
	
	//최대값인지 비교.
	re->netSec_max_send = (re->netSec_max_send < re->netSec_send) ? re->netSec_send : re->netSec_max_send;
	re->netSec_max_recv = (re->netSec_max_recv < re->netSec_recv) ? re->netSec_recv : re->netSec_max_recv;

	re->netSock_max_send = (re->netSock_max_send < re->netSock_send) ? re->netSock_send : re->netSock_max_send;
	re->netSock_max_recv = (re->netSock_max_recv < re->netSock_recv) ? re->netSock_recv : re->netSock_max_recv;
	
	//수신, 송신 계산.
	re->netSec_total = re->netSec_send + re->netSec_recv;
	re->netSock_total = re->netSock_send + re->netSock_recv;
	
	re->netSec_max_total = (re->netSec_max_total < re->netSec_total) ? re->netSec_total : re->netSec_max_total;
	re->netSock_max_total = (re->netSock_max_total < re->netSock_total) ? re->netSock_total : re->netSock_max_total;
	return 0;
}


void * get_net_info(void* arg)
{
	reInfo *re = (reInfo*)arg;
	if(get_byte(re) == -1) return (void*)-1;
	return (void*)0;
}
