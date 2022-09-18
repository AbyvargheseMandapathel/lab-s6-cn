#include<stdio.h>
#include<stdlib.h>

int ack() {
  int k;
  k=rand();
  if(k%2==0)
    return 1;
  else 
    return 0;
}

void main(){
  int n,i,test;
  printf("enter n\n");
  scanf("%d",&n);
  
for (i=0;i<=n;i++)
  x:test=ack();
  if(test==1){
    printf("success\n");
  }
  else {
    printf("failed\n");
  goto x;
  }
}
}