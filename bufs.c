#include <stdio.h>
char buf[] = "00000000000000000000000000000000\n";
int pos = 31;
int len = 2;

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
  unsigned int i=0;
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
    if(i == 0) fwrite("FizzBuzz\n", 1, 9, stdout);
    else if(lookup[i][0]) fwrite(lookup[i], 1, 5, stdout);
    else fwrite(buf+pos, 1, len, stdout);
  }
  return 0;
}
