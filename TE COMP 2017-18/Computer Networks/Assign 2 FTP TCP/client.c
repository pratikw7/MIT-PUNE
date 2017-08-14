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
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=INADDR_ANY;
	servaddr.sin_port = htons(3000);
	listenfd = socket(AF_INET,SOCK_STREAM,0);
    if (connect(socketfd,(struct sockaddr *)&servaddr,sizeof(servaddr)) < 0) 
        printf("ERROR connecting");
    FILE *f;
    //listen(listenfd,5);
    //connfd = accept(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    read(socketfd,buffer,100);
    printf("Enter name of recieved file\n");
    scanf("%s",filename);
    f=fopen(filename,"r");
    fprintf(f, "%s", buffer);
    printf("File recieved successfully\n");
	return 0;
}