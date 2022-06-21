#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_PORT 5000

int main()
{
	int sock = 0;
	struct sockaddr_in addr, from_adr;
	int str_len;
    socklen_t adr_sz;
	char msg[] = "hello server";
	char buf[64] = {0};
	
	sock = socket(AF_INET, SOCK_DGRAM,0);
	
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(SERVER_PORT);
	addr.sin_addr.s_addr = inet_addr("192.168.198.48");
	
	sendto(sock, msg, strlen(msg), 0, (struct sockaddr*)&addr, sizeof(addr));
	
    adr_sz = sizeof(from_adr);
    str_len = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr*)&from_adr, &adr_sz);
	printf("服务器响应：%s\n", buf);
	return 0;
}
