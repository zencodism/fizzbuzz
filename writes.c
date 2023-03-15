#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define LIMIT 1000000000000000


char* itoa(int val, int base){
	
	static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
	
}

int main(){
  unsigned int i = 0;
  while(i < LIMIT){
    i++;
    if(i%3 == 0) fwrite("Fizz", 1, 4, stdout);
    if(i%5 == 0) fwrite("Buzz", 1, 4, stdout);
    if(i%3 > 0 && i%5 > 0){
      printf("%d", i);
    }
    fwrite("\n", 1, 1, stdout);
  }
  return 0;
}
