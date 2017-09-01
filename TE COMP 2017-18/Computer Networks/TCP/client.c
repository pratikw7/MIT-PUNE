//----------Ashwin Vaidya------------
//-------------TE-1------------------
//------------302098-----------------

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>  //inet_addr
#include <string.h>
int main(int argc, char const *argv[])
{
  char message[100],choice;
  int sock_desc;
  struct sockaddr_in server;
  sock_desc = socket(AF_INET, SOCK_STREAM,0);
  if (sock_desc ==-1)
  {
    printf("Error creating socket\n");
  }

  //Prepare sockaddr_in structure
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_port = htons(3000);

  if(connect(sock_desc,(struct socketaddr *)&server, sizeof(server))<0)
  {
    printf("connect error\n");
  }
  else
    printf("connected\n");

  do{
    bzero(message,sizeof(message));
    printf("1. Chat\n");
    printf("2. File transfer\n");
    printf("3. Calculator\n");
    scanf(" %c",&choice);
    message[0] = choice;
    send(sock_desc,message,strlen(message),0);
    switch(choice)
    {
      case '1':
      {
        printf("Starting Chat service\n");
        while(1)
        {
          printf("Enter text\n");
          scanf(" %s",&message);
          printf("[ME]: %s\n",message );
          send(sock_desc,message,strlen(message),0);
          printf("Waiting for server to send text\n");
          int bufflen = recv(sock_desc,message,10,0);
          message[bufflen]='\0';
          printf("[Other]: %s\n",message );
          printf("Enter y to continue chatting\n");
          scanf(" %s",&message);
          send(sock_desc,message,strlen(message),0);
          if(message[0]!='y')
            break;
        }
      }
      break;
      case '2':
      {
        FILE *fp;
        char filename[20];
        printf("Enter name you want to save as\n");
        scanf("%s",&filename);
        fp=fopen(filename,"wb");
        printf("Enter remote file name\n");
        scanf("%s",&filename);
        printf("Entered filename is: %s\n",filename);
        send(sock_desc,filename,strlen(filename),0);
        while(1)
        { 
          int i = recv(sock_desc,message,100,0);
          message[i]='\0';
          if(strcmp(message,"EOF")==0)
            break;
          printf("%s\n", message);
          fprintf(fp, "%s",message);
        }
        fclose(fp);
        printf("\nFile recieved successfully\n");
      }
      break;
      case '3':
      {
       printf("Enter operation\n");
       printf("1. Addition\n");
       printf("2. Subtraction\n");
       printf("3. Multiplication\n");
       printf("4. Division\n");
       scanf(" %c",&choice);
       message[0] = choice;
       send(sock_desc,message,strlen(message),0);
       printf("Enter first number\n");
       scanf(" %s",&message);
       send(sock_desc,message,strlen(message),0);
       printf("Enter second number\n");
       scanf(" %s",&message);
       send(sock_desc,message,strlen(message),0);
       printf("Answer is: \n");
       int i=recv(sock_desc,message,100,0);
       message[i]='\0';
       printf("%s\n", message);

      }
      break;
    }
    printf("Enter y to continue: \n");
    scanf(" %c",&choice);
    message[0] = choice;
    send(sock_desc,message,strlen(message),0);
  }while(choice=='y');
  //TODO close all sockets
  return 0;
}