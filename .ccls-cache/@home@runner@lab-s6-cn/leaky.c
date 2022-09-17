#include <stdio.h>
int main () {
  int incoming,outgoing,buck_size,n,store=0; 
  printf("enter the bucket size ,outgoing size and number of inputs");
  scanf("%d %d %d",&buck_size,&outgoing, &n);

  while(n!=0){
    printf("enter the incoming packet size");
    scanf("%d",&incoming);
    printf("The incoming packet size is %d\n",incoming); 
    if(incoming<=buck_size-store){
      store+=incoming;
      printf("enter bucket buffer size %d stored out of %d\n",store,buck_size);
      }
    else {
      printf("dropeed %d no of packets",incoming -(buck_size-store) );
      printf("enter bucket buffer size %d stored out of %d\n",store,buck_size);
      store=buck_size;
    }
    store = store-outgoing;
    printf("after outgoing %d packets left out of %d buffer \n",store,buck_size);
    
  }
}

