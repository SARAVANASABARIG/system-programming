// function to create a TCP socket
#include<iostream>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#define PORTNO 8018
using namespace std;
 
int errHandling(int flag, const char errmsg[])
{
       if(flag < 0)
       {
               perror(errmsg);
               exit(EXIT_FAILURE);
       }
       return 0;
}

int create_tcp_socket(string ip_addr, int port_num)
{
 
         struct sockaddr_in servaddr;
         int sockfd;
         int slen;
         int ret;
 
 
         slen = sizeof(servaddr);
 
         servaddr.sin_family = AF_INET;
         servaddr.sin_port = htons(PORTNO);
         servaddr.sin_addr.s_addr = INADDR_ANY;

         sockfd = socket(AF_INET, SOCK_STREAM, 0);
         errHandling(sockfd, "Error: Unable to  create TCP socket");
 
         ret = bind(sockfd, (struct sockaddr *) &servaddr, slen);
         errHandling(ret, "Error: Unable to  bind TCP socket");
         ret = listen(sockfd, 5);
         errHandling(ret, "Error: Unable to  listen on TCP socket");

         return sockfd;
 
}
