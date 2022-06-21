#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

#define SERVER_PORT 5000
int main()
{
	int sock = 0;
	struct sockaddr_in addr;
	char msg[] = "hello server";
	
	sock = socket(AF_INET, SOCK_DGRAM,0);
	
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.ain_port = htons(SERVER_PORT);
	addr.sin_addr.s_addr = inet_addr();
	
	sendto(sock, msg, strlen(msg), 0, &addr, addr_len);
	
	return 0;