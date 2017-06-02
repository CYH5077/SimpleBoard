#include "./system.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <pthread.h>
#include <signal.h>

#define PORT 36555
#define RUN_SERVER 4

static int system_show(reInfo re, int flag, char* address)
{
	get_resource_info(&re);
	system("clear");

	font_color(32);
	print_line('=',LINE); printf("%s", VERSION); print_line('=',LINE);
	if(flag == RUN_SERVER){
		printf("\n");
		printf("Connect : %s", address);
	}
	font_color_reset();
	printf("\n\n");
		
	printResource(re);
	fflush(stdout);

	return 0;
}


static void * comunication_thread(void * arg)
{
	int sock = *((int*)arg);
	reInfo re;
	memset(&re, 0x00, sizeof(reInfo));
	while(1){
		get_resource_info(&re);
		if(send(sock, &re, sizeof(re), 0) <= 0){
			break;
		}
	}
	return (void*)0;
}
static int server_start()
{
	int sock, client_sock; //Socket
	struct sockaddr_in serv_addr, client_addr;
	socklen_t client_addr_size;
	pthread_t pt;

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1) return -1;

	memset(&serv_addr, 0x00, sizeof(serv_addr));
	memset(&client_addr, 0x00, sizeof(client_addr));
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if(bind(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1){
		close(sock);
		return -1;
	}
	if(listen(sock, 5) == -1){
		close(sock);
		return -1;
	}
	signal(SIGPIPE, SIG_IGN);
	while(1)
	{
		client_sock = accept(sock, (struct sockaddr*)&client_addr, &client_addr_size);
		if(client_sock == -1) continue;

		pthread_create(&pt, NULL, comunication_thread, (void*)&client_sock);
		pthread_join(pt, NULL);
		close(client_sock);
	}
	return 0;
}
static int client_start(char * address)
{
	int sock; //소켓 디스크립터.
	struct sockaddr_in addr; //상대의 정보를 저장할 구조체.
	reInfo re;

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1) return -1;
	
	memset(&addr, 0x00, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(address);

	printf("Loding.....\n");
	if(connect(sock, (struct sockaddr*)&addr,sizeof(addr)) == -1)return -1;

	while(1){
		if(recv(sock, &re, sizeof(re), 0) == -1){
			close(sock); 
			return -1;
		}		

		system_show(re, RUN_SERVER, address);
	}
	return 0;
}

static int this_system()
{
	reInfo re;
	memset(&re, 0x00, sizeof(re));
	printf("Loding.....\n");
	while(1)
	{
		get_resource_info(&re);
		system_show(re, 0, 0);
	}
	return 0;
}



int main(int argc, char *argv[])
{
	if(argc >= 2)
	{
		if(strcmp(argv[1], "-c") == 0){
			if(client_start(argv[2]) == -1){
				perror("server_start() failed");
				return -1;
			}

		}
		else if(strcmp(argv[1], "-s") == 0){
			if(server_start() == -1){
				perror("client_start() failed");
				return -1;
			}
		}
	}
	else
	{
		return this_system();
	}
	return 0;
}
