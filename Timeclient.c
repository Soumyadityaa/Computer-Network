#include<sys/types.h>

#include<sys/socket.h>

#include<netinet/in.h>

#include<arpa/inet.h>

#include<netdb.h>

#include<unistd.h>

#include<string.h>

#include<stdio.h>

#include<stdlib.h>

#define SERVER_ADDR "192.168.92.129"

#define SERVER_PORT 15555

#define CLIENT_ADDR "192.168.92.129"

#define CLIENT_PORT 15555

#define MAX_MSG 100

int main()

{ 

int sd,newsd,clilen,n;

struct sockaddr_in cliaddr,servaddr ;

short line[MAX_MSG];

bzero((char*) &servaddr, sizeof(servaddr));

servaddr.sin_family = AF_INET;

servaddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

servaddr.sin_port = htons(SERVER_PORT);

bzero((char*) &cliaddr, sizeof(cliaddr));

cliaddr.sin_family = AF_INET;

cliaddr.sin_port = htons(CLIENT_PORT);

sd=socket(AF_INET, SOCK_STREAM, 0);

printf("\nSuccessfully created stream socket");

bind(sd, (struct sockaddr*)&cliaddr, sizeof(cliaddr));

printf("\n local port bound successfully. . . . \n");

connect(sd, (struct sockaddr*)&servaddr, sizeof(servaddr));

printf("\nConnected Successfully!");

memset(line,0x0,1);

n=recv(sd,line,sizeof(line)+1,0);

line[n]='\n';

printf("\n recieved from host : %u",line[0]); 

close(sd);

printf("\n\n");

return 0;
}
