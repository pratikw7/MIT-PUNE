//--------Ashwin Vaidya------
//-----------TE 1------------
//-----------302098----------
#include <stdio.h>
#include <arpa/inet.h>
int main(int argc, char const *argv[])
{
	int socketfd, listenfd,connfd;
	char filename[100],buffer[100];
	struct sockaddr_in servaddr,clientaddr;
	//bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=INADDR_ANY;
	servaddr.sin_port = htons(3001);
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	if (connect(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr)) < 0) 
		printf("ERROR connecting");
	FILE *fp;

	printf("Enter existing file name\n");
	scanf("%s",filename);
	fp=fopen(filename,"r");
	while(fread(buffer,100,sizeof(char),fp))
	{
		//char buffer[100]={0};
	   	printf("%s",buffer);
		send(listenfd,buffer,100,0);
		/*if(i<100)
			break;*/
	}
	//send(listenfd,"\0",1,0);
	printf("%s\n", "file sent successfully");
	close(fp);
	return 0;
}
