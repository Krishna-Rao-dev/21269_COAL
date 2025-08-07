#include <stdio.h>

int main()
{
    // int a1, b1, quotient, remainder;
    // scanf("%u %u", &a1, &b1);
    // asm volatile(
    //     "movl %2, %%eax;"
    //     "cltd;"
    //     "idivl %3;"
    //     "movl %%eax, %0;"
    //     "movl %%edx, %1;"
    //     : "=r"(quotient), "=r"(remainder)
    //     : "r"(a1), "r"(b1)
    //     : "%eax", "%edx");
    // printf("Quotient = %ld, Remainder = %ld, quotient, remainder);
    // return 0;

    int x,y,quo,rem;
    asm volatile(
        "movl %1, %%eax;"
        "cdq;"
        "divl %2;"
        "xorl %%edx, %%edx;"
        :"=a"(quo),"=d"(rem)
        :"r"(x),"a"(y)
        :"%eax","%edx"
    );
    printf("quotient = %d, remainder = %d", quo,rem);
    return 0;
} 



