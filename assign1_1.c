#include <stdio.h>

int main()
{
    int choice;

    printf("Select operation: 1. unsigned short  2. signed short  3. unsigned long  4. signed long 5. char\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        unsigned short a, b, result;
        scanf("%hu %hu", &a, &b);
        asm volatile(
            "movw %1, %%ax;"
            "addw %2, %%ax;"
            "movw %%ax, %0;"
            : "=r"(result)
            : "r"(a), "r"(b)
            : "%ax");
        printf("%hu\n", result);
        break;
    }

    case 2:
    {
        short a, b, result;
        scanf("%d %d", &a, &b);
        asm volatile(
            "movw %1, %%ax;"
            "addw %2, %%ax;"
            "movw %%ax, %0;"
            : "=r"(result)
            : "r"(a), "r"(b)
            : "%ax");
        printf("%hd\n", result);
        break;
    }

    case 3:
    {
        unsigned long a, b, result;
        scanf("%lu %lu", &a, &b);
        asm volatile(
            "movq %1, %%rax;"
            "addq %2, %%rax;"
            "movq %%rax, %0;"
            : "=r"(result)
            : "r"(a), "r"(b)
            : "%rax");
        printf("%lu\n", result);
        break;
    }

    case 4:
    {
        long a, b, result;
        scanf("%ld %ld", &a, &b);
        asm volatile(
            "movq %1, %%rax;"
            "addq %2, %%rax;"
            "movq %%rax, %0;"
            : "=r"(result)
            : "r"(a), "r"(b)
            : "%rax");
        printf("%ld\n", result);
        break;
    }

    case 6:
    {
        char a, b, result;
        scanf(" %c %c", &a, &b);
        asm volatile(
            "movb %1, %%al;"
            "addb %2, %%al;"
            "movb %%al, %0;"
            : "=r"(result)
            : "r"(a), "r"(b)
            : "%al");
        printf("%d\n", result);
        break;
    }

    default:
        printf("Invalid choice\n");
    }

    return 0;
}
