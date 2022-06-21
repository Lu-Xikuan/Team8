#include<stdio.h>

int main()
{
	int sockfd = 0;
	char buf[64] = { 0 };
	char msg[] = "hello client";

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	//bind(int sockfd, const struct sockaddr* addr, socklen_t addlen);

	//listen(sockfd, 10);

	connfd = accept(sockfd, const struct sockaddr* addr, socklen_t addrlen);

	//recv(connfd, buf, sizeof(buf), 0);

	send(connfd, msg, strlen(msg), 0);

	close(sockfd);
	close(connfd);

	return 0;
}