#include<stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define PORT 23	
#define BACKLOG 5

int main()
{
	int sockfd = 0, recvlen = 0, new_fd = 0;
	char buf[64] = { 0 };
	char msg[] = "Hello Client";
	struct sockaddr_in stLocalAddr = { 0 }; //本地地址信息结构图，下面有具体的属性赋值
	struct sockaddr_in stRemoteAddr = { 0 }; //对方地址信息
	socklen_t socklen = 0;

	iSocketFD = socket(AF_INET, SOCK_STREAM, 0); //建立socket
	if (0 > iSocketFD)
	{
		printf("创建socket失败！\n");
		return 0;
	}

	stLocalAddr.sin_family = AF_INET;  /*该属性表示接收本机或其他机器传输*/
	stLocalAddr.sin_port = htons(PORT); /*端口号*/
	stLocalAddr.sin_addr.s_addr = htonl(INADDR_ANY); /*IP，括号内容表示本机IP*/

	//绑定地址结构体和socket
	if (0 > bind(iSocketFD, (void*)&stLocalAddr, sizeof(stLocalAddr)))
	{
		printf("绑定失败！\n");
		return 0;
	}

	//开启监听 ，第二个参数是最大监听数
	if (0 > listen(iSocketFD, BACKLOG))
	{
		printf("监听失败！\n");
		return 0;
	}

	printf("iSocketFD: %d\n", iSocketFD);
	//在这里阻塞知道接收到消息，参数分别是socket句柄，接收到的地址信息以及大小 
	new_fd = accept(iSocketFD, (void*)&stRemoteAddr, &socklen);
	if (0 > new_fd)
	{
		printf("接收失败！\n");
		return 0;
	}
	else {
		printf("接收成功！\n");
		//发送内容，参数分别是连接句柄，内容，大小，其他信息（设为0即可） 
		send(new_fd, msg, sizeof(msg), 0);
	}

	printf("new_fd: %d\n", new_fd);
	iRecvLen = recv(new_fd, buf, sizeof(buf), 0);
	if (0 >= iRecvLen)    //对端关闭连接 返回0
	{
		printf("接收失败或者对端关闭连接！\n");
	}
	else {
		printf("buf: %s\n", buf);
	}

	close(new_fd);
	close(iSocketFD);

	return 0;

