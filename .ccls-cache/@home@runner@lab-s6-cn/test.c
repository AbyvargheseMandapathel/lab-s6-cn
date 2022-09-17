//code to implement leaky

#include<stdio.h>
int main () {
  int incoming,outgoing,buck_size,n,store=0;
  printf("enter the incoming,bck_size and n");
  scanf("%d %d %d",&incoming,&buck_size,&n);
  while(n!=0){
    printf("Enter the incoming packets");
    scanf("%d",&incoming);
    if (incoming<=buck_size-store){
      printf("bucket size buffer %d out of %d",store, buck_size);
    store+=incoming;
      }
    else {
      printf("dropped %d no of packets ",incoming-(buck_size-store));
      printf("bucket size buffer %d out of %d",store, buck_size);
      store = buck_size;
    }
    store=store-outgoing;
    printf("after ongoing %d packets in %d buffer ",store ,buck_size);
n--;
  }
}