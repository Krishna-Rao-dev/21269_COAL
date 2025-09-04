#include <stdio.h>

int main() {
    char str[100];
    char target;
    long int len, count;

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    printf("Enter a character to count: ");
    scanf(" %c", &target);

    asm (
        "xor %%rax, %%rax;"        
        "xor %%rcx, %%rcx;"         
        "xor %%rdx, %%rdx;"       

    "l1: cmpb $0, (%2, %%rax, 1);"  
        "je l3;"                  

        "movb (%2, %%rax, 1), %%bl;" 
        "cmpb %%bl, %3;"             
        "jne l2;"                  
        "inc %%rcx;"             

    "l2: inc %%rax;"                
        "jmp l1;"                  

    "l3: movq %%rax, %%rdx;"         
        "movq %%rcx, %0;"            
        "movq %%rdx, %1;"          

        : "=r"(count), "=r"(len)   
        : "r"(str), "r"(target)     
        : "%rax", "%rcx", "%rdx", "%r8" 
    );

    printf("Length of string is %ld\n", len);
    printf("Character '%c' occurs %ld times.\n", target, count);

    return 0;
}

}