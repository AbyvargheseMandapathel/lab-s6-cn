#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>

#define SERV_TCP_PORT 5535
#define MAX 60
 int i,j,temp;
char buff[4096],t;
FILE *f1;

int main(int argc , char **argv){
  int sockfd,newsockfd,clength,bd;
  struct sockaddr_in serv_addr,cli_addr;
  char t[MAX],str[MAX];
  strcpy(t,"exit");

  sockfd=socket(AF_INET,SOCK_STREAM,0);
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(SERV_TCP_PORT);
  serv_addr.sin_family = AF_INET;

  bd = bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
  if(bd <0)
    printf("error in binding");
  else 
    printf("\nbinded\n");
  printf("\nlisten\n");
  listen(sockfd,5);
  clength = sizeof(cli_addr);
  newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr,&clength);
  close(sockfd);
  read(newsockfd,&str,MAX);
  
  printf("\n client message:%s",str);
  f1=fopen(str,"r");
  while (fgets(buff,4096,f1)!=NULL){
    write(newsockfd,buff,MAX);
    printf("\n");
  }
  fclose(f1);
  printf("\nFile transfered\n");
  return 0;
}



