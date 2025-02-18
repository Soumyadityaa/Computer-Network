#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#define SERVER_ADDR "10.0.24.1"
#define SERVER_PORT 15678


int main()
{
        int sd,newsd,cli_len,n;
        struct sockaddr_in cli_addr,serv_addr;
        bzero((char*)&serv_addr,sizeof(serv_addr));
        serv_addr.sin_family=AF_INET;
        serv_addr.sin_addr.s_addr=inet_addr(SERVER_ADDR);
        serv_addr.sin_port=htons(SERVER_PORT);
        sd=socket(AF_INET,SOCK_STREAM,0);

        printf("\nSuccessfullt created stream socket");
        bind(sd,(struct sockaddr*)&serv_addr,sizeof(cli_addr));
        printf("\nLocal port Bound Successfully!!");
        listen(sd,2);

        while(1)
        {
                printf("\nWaiting for any client to connect at server port%u\n",SERVER_PORT);
                newsd=accept(sd,(struct sockaddr*)&cli_addr,&cli_len);
                printf("\nReceived from Client[IP%s,TCP PORT%d]",inet_ntoa(cli_addr.sin_addr),ntohs(cli_addr.sin_port));
                close(newsd);
        }

        close(sd);
        printf("\n\n");
}

