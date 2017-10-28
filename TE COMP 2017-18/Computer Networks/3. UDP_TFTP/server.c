//----------Ashwin Vaidya------------
//-------------TE-1------------------
//------------302098-----------------
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
	int sock, addr_len;
	struct sockaddr_in server_addr, client_addr;
	char recv_data[100];
	if((sock = socket(AF_INET, SOCK_DGRAM,0)) ==-1)
	{
		printf("Error creating socket\n");
	}
	else
	{
		printf("socket created\n");
	}
	server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(3000);
    server_addr.sin_addr.s_addr = INADDR_ANY;
	if(bind(sock,(struct sockaddr *)&server_addr,sizeof(struct sockaddr))==-1)
	{
		printf("Error binding socket\n");
	}
	else
	{
		printf("Binded\n");
	}
	addr_len = sizeof(struct sockaddr);
	int bufferlength = recvfrom(sock,recv_data,100,0,(struct sockaddr*)&client_addr, &addr_len);
	recv_data[bufferlength]='\0';
	FILE *fp;
	fp = fopen(recv_data,"r");
	if(fp==NULL)
	{
		printf("File not found\n");
		close(sock);
	}
	else
	{
		while(fgets(recv_data,sizeof(recv_data),fp))
		{
			printf("%s",recv_data );
			sendto(sock,recv_data,sizeof(recv_data),0,(struct sockaddr*)&client_addr,sizeof(struct sockaddr));
		}
		sendto(sock,"EOF",sizeof("EOF"),0,(struct sockaddr*)&client_addr,sizeof(struct sockaddr));
		close(sock);
	}
	return 0;
}