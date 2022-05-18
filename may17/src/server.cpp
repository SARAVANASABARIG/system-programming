//The program to create a TCP server
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include "func.cpp"
#define PORTNO 8018
#define MAX 256
int main()
{

        struct sockaddr_in servaddr,cliaddr;
        char cmsg[MAX];
        char smsg[MAX];
        bool flag,i;
        flag = true;
        pid_t client_pid;
        int sockfd,mlen,structlen,connfd;
        socklen_t servaddrlen,clen;
        structlen = sizeof(sockaddr_in);

        memset(&servaddr,0,structlen);
        memset(&cliaddr,0,structlen);
        memset(smsg,0,256);

        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = INADDR_ANY;
        servaddr.sin_port = htons(PORTNO);
        sockfd = socket(AF_INET,SOCK_STREAM,0);
        bind(sockfd,(const struct sockaddr *)&servaddr,structlen);
        listen(sockfd,6);
        connect(sockfd,(struct sockaddr *)&servaddr,structlen);

        while(flag)
        {
                connfd = accept(sockfd,(struct sockaddr *)&cliaddr,&clen);
                if(connfd < 0){
                        fputs("Error :unable to Accept connection",stderr);
                        exit(EXIT_FAILURE);
                }

                client_pid == fork();
                if(client_pid == 0){
                	mlen=read(connfd,cmsg,256);
                	write(1,"Message From Client: ",21);
                	write(1,cmsg,strlen(cmsg));
                	string s=string(cmsg);

                if(s == "Bye")

                {

                        flag = false;
                        close(connfd);
                        break;
                        exit(EXIT_SUCCESS);
                }


                write(1,"Enter your message for client: ",32);
                mlen = read(0,smsg,256);
                mlen = write(connfd,smsg,strlen(smsg));
                cout<<mlen<<"   Byte message send from server to client"<<endl;
                close(connfd);
                exit(EXIT_SUCCESS);
                }
                close(connfd);

        }
}
