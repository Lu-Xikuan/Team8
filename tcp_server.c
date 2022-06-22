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
	struct sockaddr_in stLocalAddr = { 0 }; //���ص�ַ��Ϣ�ṹͼ�������о�������Ը�ֵ
	struct sockaddr_in stRemoteAddr = { 0 }; //�Է���ַ��Ϣ
	socklen_t socklen = 0;

	sockfd = socket(AF_INET, SOCK_STREAM, 0); //����socket
	if (0 > sockfd)
	{
		printf("����socketʧ�ܣ�\n");
		return 0;
	}

	stLocalAddr.sin_family = AF_INET;  /*�����Ա�ʾ���ձ�����������������*/
	stLocalAddr.sin_port = htons(PORT); /*�˿ں�*/
	stLocalAddr.sin_addr.s_addr = htonl(INADDR_ANY); /*IP���������ݱ�ʾ����IP*/

	//�󶨵�ַ�ṹ���socket
	if (0 > bind(sockfd, (void*)&stLocalAddr, sizeof(stLocalAddr)))
	{
		printf("��ʧ�ܣ�\n");
		return 0;
	}

	//�������� ���ڶ�����������������
	if (0 > listen(sockfd, BACKLOG))
	{
		printf("����ʧ�ܣ�\n");
		return 0;
	}

	printf("sockfd: %d\n", sockfd);
	//����������֪�����յ���Ϣ�������ֱ���socket��������յ��ĵ�ַ��Ϣ�Լ���С 
	new_fd = accept(sockfd, (void*)&stRemoteAddr, &socklen);
	if (0 > new_fd)
	{
		printf("����ʧ�ܣ�\n");
		return 0;
	}
	else {
		printf("���ճɹ���\n");
		//�������ݣ������ֱ������Ӿ�������ݣ���С��������Ϣ����Ϊ0���ɣ� 
		send(new_fd, msg, sizeof(msg), 0);
	}

	printf("new_fd: %d\n", new_fd);
	recvlen = recv(new_fd, buf, sizeof(buf), 0);
	if (0 >= recvlen)    //�Զ˹ر����� ����0
	{
		printf("����ʧ�ܻ��߶Զ˹ر����ӣ�\n");
	}
	else {
		printf("buf: %s\n", buf);
	}

	close(new_fd);
	close(sockfd);

	return 0;
}