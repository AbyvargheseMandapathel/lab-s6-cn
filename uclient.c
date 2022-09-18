#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

void main (int argc ,char **argv){
  if(argc !=2){
    printf("error ");
    exit(0);
  }
  int port = atoi(argv[1]);
  int sockfd;
  struct sockaddr_in serveraddr;
  char buffer[1024];
  socklen_t addr_size;

  sockfd=socket(AF_INET,SOCK_DGRAM,0);
  memset(&serveraddr,'\0',sizeof(serveraddr));

  serveraddr.sin_family=AF_INET;
  serveraddr.sin_port = htons(port);
  serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  strcpy(buffer,"hello udp done!!");
  sendto(sockfd,buffer,1024,0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));

  printf("data sent:%s",buffer);
  
}