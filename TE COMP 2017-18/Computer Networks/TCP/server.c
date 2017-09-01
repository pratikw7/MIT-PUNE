//----------Ashwin Vaidya------------
//-------------TE-1------------------
//------------302098-----------------
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char message[100],choice;
	int sock_desc,c,new_socket;
	struct sockaddr_in server, client;
	//Create socket
	sock_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_desc == -1)
	{
		printf("could not create scoket\n");
	}

	//Prepare sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(3000);

	//Bind
	if(bind(sock_desc,(struct sockaddr *)&server,sizeof(server))<0)
	{
		printf("Bind failed\n");
	}
	else
		printf("Binded\n");

	//Listen
	listen(sock_desc,3);
	printf("Waiting for connection...\n");
	c = sizeof(struct sockaddr_in);
	new_socket = accept(sock_desc,(struct sockaddr *)&client,(socklen_t*)&c);
	if (new_socket<0)
	{
		printf("accept failed\n");
	}
	printf("Connection accepted\n");
	do
	{
		int bytes =	recv(new_socket,message,20,0);
		if(bytes>0)
		{
			choice = message[0];
			printf("Choice entered: %c\n",choice);
			switch(choice)
			{
				case '1':
				{
					printf("Starting Chat service.\n");
					while(1)
					{
						printf("Waiting for client to send text\n");
						int bufflen = recv(new_socket,message,20,0);
						message[bufflen]='\0';
						printf("[Other]: %s\n",message );
						printf("Enter text\n");
						scanf(" %s",&message);
						printf("[ME]: %s\n",message );
						send(new_socket,message,strlen(message),0);
						recv(new_socket,message,20,0);
						if(message[0]!='y')
							break;
					}
				}
				break;
				case '2':
				{
					int bufflen = recv(new_socket,message,100,0);
					message[bufflen]='\0';
					FILE *fp;
					fp = fopen(message,"rb");
					if(fp ==NULL)
						printf("Error file not found\n");
					else
					{
						while(fgets(message,100,fp))
							{
								printf("%s",message);
								send(new_socket,message,100,0);
							}
							send(new_socket,"EOF",strlen("EOF"),0);
							fclose(fp);
						printf("%s\n", "file sent successfully");
					}
				}
				break;
				case '3':
				{
					recv(new_socket,message,20,0);
					choice = message[0];
					int bufflen = recv(new_socket,message,20,0);
					message[bufflen]='\0';
					int num1 = atoi(message);
					bufflen = recv(new_socket,message,20,0);
					message[bufflen]='\0';
					int num2 = atoi(message);
					float result;
					printf("Option entered: %c\n", choice);
					if(choice=='1')
					{
						result = num1+num2;
						strcpy(message,"");
						sprintf(message,"%f",result);
					}
					else if(choice=='2')
					{
						result = num1-num2;
						strcpy(message,"");
						sprintf(message,"%f",result);
					}
					else if(choice=='3')
					{
						result = num1*num2;
						strcpy(message,"");
						sprintf(message,"%f",result);
					}
					else if(choice=='4')
					{
						result = num1/num2;
						strcpy(message,"");
						sprintf(message,"%f",result);
					}
					else
						strcpy(message,"Invalid input");
					printf("num1 %d\n",num1 );
					printf("num2 %d\n",num2 );
					printf("result %s\n",message );
					send(new_socket,message,100,0);
				}
				break;

			}
		}
		if(recv(new_socket,message,10,0)>0)
			choice = message[0];
	}while(choice=='y');
	  //TODO close all sockets
	return 0;
}