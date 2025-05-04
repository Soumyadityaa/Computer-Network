#include<sys/types.h>

#include<sys/socket.h>

#include<netinet/in.h>

#include<arpa/inet.h>

#include<netdb.h>

#include<unistd.h>

#include<string.h>

#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#define SERVER_ADDR "192.168.92.129"

#define SERVER_PORT 15555

#define MAX_MSG 100

int main()

{ 

int sd, newsd, clilen, n;

int pts;

char line[MAX_MSG];

time_t t;

struct sockaddr_in cli_addr, serv_addr;

bzero((char*) &serv_addr, sizeof(serv_addr));

serv_addr.sin_family = AF_INET;

serv_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

serv_addr.sin_port = htons(SERVER_PORT);

sd=socket(AF_INET, SOCK_STREAM, 0);

printf("\nSuccessfully created stream socket");

bind(sd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

printf("\nLocal port bound successfully!");

listen(sd,5);

while(1)

{ 

printf("\nWaiting for any client to connect at server port %u \n", SERVER_PORT);

newsd= accept(sd,(struct sockaddr*)&cli_addr, &clilen);

t = time(NULL);

pts=time(&t);

line[0]=pts;

printf("%d \n",pts);

send(newsd,line,strlen(line)+1,0);
printf("\n closing. . . .");

}
close(newsd);

return 0;

}
