#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include<netinet/in.h>
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc,char *argv[])
{
    int sockfd,newsockfd,portno;
    socklen_t clilen;
    int hamming[7],parity[3],arr[4],par[3],p1,p2,p4,posn;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 3000;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
      sizeof(serv_addr)) < 0) 
      error("ERROR on binding");
  listen(sockfd,5);
  clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd, 
   (struct sockaddr *) &cli_addr, 
   &clilen);
  if (newsockfd < 0) 
      error("ERROR on accept");
  bzero(hamming,28);
  n = read(newsockfd,hamming,28);
  if (n < 0) error("ERROR reading from socket");
  parity[0]=hamming[0];
  parity[1]=hamming[1];
  parity[2]=hamming[3];
  arr[0]=hamming[2];
  arr[1]=hamming[4];
  arr[2]=hamming[5];
  arr[3]=hamming[6];
  par[0]=1;
  par[1]=arr[0]^arr[2]^arr[3];
  par[2]=arr[1]^arr[2]^arr[3];

  if(par[0]==parity[0]&&par[1]==parity[1]&&par[2]==parity[2])
    { printf("No errors in transmission\n");
int i;
for(i=0;i<7;i++)
{
   printf("%d ",hamming[i]);}
}
else 
{ 
    if(par[0]!=parity[0])
       p1=1;
    else p1=0;
    if(par[1]!=parity[1])
       p2=1;
    else p2=0;
    if(par[2]!=parity[2])
      p4=1;
    else p4=0; 
    printf("Error found at position: ");
    posn=p1+p2*2+p4*4; 
    printf("%d\n",posn); 
    hamming[posn] = (hamming[posn]==0)?1:0;   //Correct the code 
    printf("Corrected code is\n");
    for (int i = 0; i < 7; ++i)
    {
        printf("%d ", hamming[i]);
    }
}
close(newsockfd);
close(sockfd);
return 0; 
}
