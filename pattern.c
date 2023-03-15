#include <stdio.h>
#define LIMIT 1000000000000000

int main(){
  unsigned int i=0, j=0;
  char* lookup[] = {
    "FizzBuzz\n",
    "",
    "",
    "Fizz\n",
    "",
    "Buzz\n",
    "Fizz\n",
    "",
    "",
    "Fizz\n",
    "Buzz\n",
    "",
    "Fizz\n",
    "",
    ""
  };
  while(i < LIMIT){
    i++;
    j = i%15;
    if(lookup[j][0]) printf("%s", lookup[j]);
    else printf("%d\n",  i);
  }
  return 0;
}
