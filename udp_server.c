#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MYPORT 5000
int main()
{
	int sock = 0;
	char msg[] = "hello server";
	char buf[64] = {0};
	struct sockaddr_in my_addr, clnt_adr;
	socklen_t clnt_adr_sz;	
	
	
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock == -1)
	{
		printf("socket failed!\n");
		return -1;
	}
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(MYPORT);
	my_addr.sin_addr.s_addr = INADDR_ANY;
	
	if (-1 == bind( sock, (struct sockaddr *) &my_addr, sizeof(struct sockaddr)))
	{
		printf("bind failed!\n");
		return -1;
	}
	
	recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
	sendto(sock, msg, strlen(msg), 0, (struct sockaddr*)&clnt_adr, clnt_adr_sz);
	return 0;
}