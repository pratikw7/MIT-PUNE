//Ashwin Vaidya
//302098
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int hamming[7],arr[4],parity[3];


    portno = 3000;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname("192.168.0.4");
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    printf("Please enter 4 numbers: ");
    int i;
    bzero(hamming,28);
    for(i=0;i<4;i++)
    scanf("%d",&arr[i]);
    parity[0]=arr[0]^arr[1]^arr[3];
    parity[1]=arr[0]^arr[2]^arr[3];
    parity[2]=arr[1]^arr[2]^arr[3];
    hamming[0]=parity[0];
    hamming[1]=parity[1];
    hamming[2]=arr[0];
    hamming[3]=parity[2];
    hamming[4]=arr[1];
    hamming[5]=arr[2];
    hamming[6]=arr[3];
 
    printf("Code generated is: ");
    for (int i = 0; i < 7; ++i)
    {
    	printf("%d ", hamming[i]);
    }
    int senddata[7];
    bzero(senddata,28);
    printf("\nEnter the code\n");
    for (int i = 0; i < 7; ++i)
    {
    	scanf("%d",&senddata[i]);
    }
    n = write(sockfd,senddata,28);
    if (n < 0) 
         error("ERROR writing to socket");
    close(sockfd);
    return 0;
}
