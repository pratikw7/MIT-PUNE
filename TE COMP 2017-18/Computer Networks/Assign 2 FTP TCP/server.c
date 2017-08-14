//--------Ashwin Vaidya------
//-----------TE 1------------
//-----------302098----------
#include <stdio.h>
#include <sys/types.h>	//Used by next two include files
#include <sys/socket.h>	//definitions for structures needed for sockets
#include <netinet/in.h>	//contains constants and structures needed for internet domain addresses
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
	int socketdescriptor,clientdescriptor, clilen;
	struct sockaddr_in server_addr, client_addr;
	bzero(&server_addr,sizeof(server_addr));
	FILE *fp;
	char filename[100];
	socketdescriptor = socket(AF_INET, SOCK_STREAM, 0);
	if(socketdescriptor<0)
		printf("Error opening socket\n");
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(3000);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	if(bind(socketdescriptor,(struct sockaddr * ) &server_addr, sizeof(server_addr))<0) //The bind() system call binds a socket to an address
		error("Error in binding");
	listen(socketdescriptor,5);
	clilen = sizeof(client_addr);
	clientdescriptor = accept(socketdescriptor,(struct sockaddr*)&client_addr,clilen);
	char buffer[100];
	printf("Enter file name\n");
	scanf("%s",filename);
	fp=fopen(filename,"r");
	fscanf(fp, buffer,100);
	write(socketdescriptor,buffer,100);
	printf("%s\n", "fiel sent successfully");
	return 0;
}