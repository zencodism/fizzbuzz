#include <stdio.h>
#define LIMIT 1000000000000000

int main(){
  unsigned int i, j, k;
  i = j = k = 0;
  while(i < LIMIT){
    i++;
    if(i - j >= 3){
       printf("Fizz");
       j++;
    }
    if(i - k >= 5){
      printf("Buzz");
      k++;
    }
    if(i - j < 3 && i - k < 5) printf("%d",  i);
    printf("\n");
  }
  return 0;
}
