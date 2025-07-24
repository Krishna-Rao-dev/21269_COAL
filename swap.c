#include<stdio.h>

int main(){
int a=10,b=20;
asm volatile("xchg %0, %1":"=r"(a),"=r"(b):"0"(a),"1"(b) );
printf("a= %d, b=%d 😎️",a,b);

return 0;

}                                                               
