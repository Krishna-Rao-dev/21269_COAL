
#include <stdio.h>
//% ->	Operand placeholder	Refers to C variable (like %0, %1)
//%% ->	Real register	Refers to hardware register (like %%eax, %%ebx)
// %0 -> the output, %1/2 as variables

// asm volatile(
//             "movb %1, %%al;"
//             "addb %2, %%al;"
//             "movb %%al, %0;"
//             : "=r"(result)
//             : "r"(a), "r"(b)
//             : "%al");

int main()
{
    int a, b, quotient, remainder;
    scanf("%d %d", &a, &b);
    // asm volatile(
    //     "movb %1, %%al;"
    //     "mulb %2;"
    //     "movb %%al, %0;"
    //     : "=r"(result)
    //     : "r"(a), "r"(b)
    //     : "%al");

    asm volatile(
        "movl %2, %%eax;"
        "cltd;"
        "idivl %3;"
        "movl %%eax, %0;"
        "movl %%edx, %1;"
        : "=r"(quotient), "=r"(remainder)
        : "r"(a), "r"(b)
        : "%eax", "%edx");
    printf("Quotient = %d, Remainder = %d", quotient, remainder);
    return 0;
}