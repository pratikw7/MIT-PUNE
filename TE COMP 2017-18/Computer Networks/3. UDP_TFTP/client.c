//----------Ashwin Vaidya------------
//-------------TE-1------------------
//------------302098-----------------
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
	int socket_fd,addr_len;
	char buffer[100];
	struct sockaddr_in server_addr,client_addr;
	if ((socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
		printf("Error creating socket\n");
	}
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(3000);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	printf("Enter the new file name\n");
	scanf("%s",buffer);
	FILE *fp;
	fp=fopen(buffer,"w");
	printf("Enter the existing file name\n");
	scanf("%s",buffer);
	sendto(socket_fd, buffer, sizeof(buffer), 0,
              (struct sockaddr *)&server_addr, sizeof(struct sockaddr));
	while(1)
	{
		int bufflen = recvfrom(socket_fd,buffer,100,0,(struct sockaddr*)&server_addr,&addr_len);
		buffer[bufflen]='\0';
		if(strcmp(buffer,"EOF")==0)
		{
			fclose(fp);
			break;
		}
		fprintf(fp,"%s", buffer);
		printf("%s", buffer);
	}
	close(socket_fd);
	return 0;
}