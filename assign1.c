#include<stdio.h>

int main(){
char a,b;

char a=10,b=20,result;

asm volatile(
"movq %1,%%al;"
"addq %2,%%al;"
"movq %%al,%0;" 
: "=r"(result)
: "r"(a), "r"(b)
:"%al"
);

printf("The sum is %d",result);
return 0;

}
