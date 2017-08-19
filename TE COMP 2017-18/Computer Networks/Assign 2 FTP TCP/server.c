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
	FILE *f;
	char filename[100];
	socketdescriptor = socket(AF_INET, SOCK_STREAM, 0);
	if(socketdescriptor<0)
		printf("Error opening socket\n");
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(3001);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	if(bind(socketdescriptor,(struct sockaddr * ) &server_addr, sizeof(struct sockaddr))<0) //The bind() system call binds a socket to an address
		error("Error in binding");
	listen(socketdescriptor,5);
	clilen = sizeof(struct sockaddr_in);
	clientdescriptor = accept(socketdescriptor,(struct sockaddr*)&client_addr,&clilen);
	char buffer[100];
	printf("Enter name of recieved file\n");
	scanf("%s",filename);
	f=fopen(filename,"w");
	while(recv(clientdescriptor,buffer,100,0))
	{	
		//buffer[i]='\0';
		printf("%s",buffer);
		fprintf(f, "%s",buffer);
	}
	printf("File recieved successfully\n");
	close(f);
	return 0;
}
