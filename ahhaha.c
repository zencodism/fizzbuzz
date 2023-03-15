#include <stdio.h>
#include <string.h>

#define THRESH 64000
#define PING THRESH-40

char buf[] = "00000000000000000000000000000000\n";
int pos = 31;
int len = 2;
char out_buf[THRESH];
unsigned int out_pos = 0;

void inc_buf(int z){
  if(buf[z] == '9'){
    if(z <= pos){
      len = 34 - z;
      pos = z-1;
    }
    buf[z] = '0';
    inc_buf(z-1);
  }
  else{
    buf[z] = buf[z] + 1;
  }
}

int main(){
  unsigned long i=0;
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
  while(1){
    inc_buf(31);
    i++;
    i%=15;
    if(i == 0){memcpy(out_buf+out_pos, "FizzBuzz\n", 9); out_pos += 9;}
    else if(lookup[i][0]) {memcpy(out_buf+out_pos, lookup[i], 5); out_pos += 5;}
    else {memcpy(out_buf+out_pos, buf+pos, len); out_pos += len;}

    if(out_pos > PING){
      fwrite(out_buf, 1, out_pos, stdout);
      out_pos = 0;
    }
  }
  return 0;
}
