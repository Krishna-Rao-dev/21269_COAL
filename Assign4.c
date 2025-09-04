#include <stdio.h>

int main() {
    int num;
    printf("Enter the number of elements : ");
    scanf("%d",&num);
    int pc = 0, nc = 0;
    int arr[num];
    for(int i=0;i<num;i++){
        printf("Enter element no.%d : ",i+1);
        scanf("%d",&arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    asm volatile (
        "movl %3, %%ecx;"     
        "movq %2, %%rdi;"      
        "movl $0, %%ebx;"      
        "movl $0, %%edx;"      

        "Repeat:;"
        "cmpl $0, (%%rdi);" 
        "jl ncount;"           
        "incl %%ebx;"          
        "jmp next_num;"

        "ncount:;"
        "incl %%edx;"

        "next_num:;"
        "addq $4, %%rdi;"     
        "loop Repeat;"         

        "movl %%ebx, %0;"    
        "movl %%edx, %1;"     
        : "=r"(pc), "=r"(nc)
        : "r"(arr), "r"(n)
        : "%ecx", "%ebx", "%edx", "%rdi"
    );

    printf("Positive Count : %d\n", pc);
    printf("Negative Count : %d\n", nc);

    return 0;
}