#include <stdio.h>
#define LIMIT 1000000000000000

int main(){
  unsigned int i = 0;
  while(i < LIMIT){
    i++;
    if(i%3 == 0) printf("Fizz");
    if(i%5 == 0) printf("Buzz");
    if(i%3 > 0 && i%5 > 0) printf("%d",  i);
    printf("\n");
  }
  return 0;
}
