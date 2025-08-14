#include <stdio.h>
int main()
{
    char *str = "pictcomp";
    char *ch = "p";
    long int result, occ;
    asm(
        "movq $0, %%rax;"
        "xor %%rdx, %%rdx;" // rdx = 0 (maybe unused here?)
        "xor %%rcx, %%rcx;" // rcx = 0, use rcx as a counter
        "L1:"
        "cmpb $0, (%%rdi,%%rax,1);" // check if byte at rdi+rax == 0
        "je exit;"
        "movb %1, %%bl;"              // move input byte to bl
        "cmpb %%bl, (%%rdi,%%rax,1);" // compare bl with byte at rdi+rax
        "jne skip_inc;"
        "inc %%rcx;" // increment counter rcx
        "skip_inc:"
        "inc %%rax;" // increment rax (index)
        "jmp L1;"
        "exit:"
        "movq %%rax,%0;"
        "movq %%rbx, %0;"
        : "=a"(result), "=b"(occ)
        : "D"(str));
    printf(" Sum is: %ld %ld", result, occ);
    return 0;
}