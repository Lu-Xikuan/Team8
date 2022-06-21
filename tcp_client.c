#include<stdio.h>

int main()
{
	int sockfd = 0;
	int ret = 0;
	char msg[] = "hello server";
	char buf[64] = { 0 };

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	//res = connect(sockfd, (struct sockaddr*)&saddr, sizeof(saddr));

	send(connfd, msg, strlen(msg), 0);

	//recv(connfd, buf, sizeof(buf), 0);

	close(sockfd);

	return 0;
}