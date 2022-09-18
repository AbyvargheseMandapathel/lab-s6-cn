#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>

int main(){
  char buff[100];
  int k;
  int sock_desc;
  struct sockaddr_in client;
  sock_desc = socket(AF_INET,SOCK_STREAM,0);
  if(sock_desc ==-1)
    printf("error in socket creation");
  client.sin_family=AF_INET;
  client.sin_addr.s_addr = INADDR_ANY;
  client.sin_port = 5533;
  k = connect(sock_desc,(struct sockaddr*)&client, sizeof(client));
  if(k==-1)
    printf("error in connecting");
  printf("enter message to send");
  fgets(buff,100,stdin);
  k=send(sock_desc,buff,100,0);
  printf("eror in sedning");
  return 0;
  }
}