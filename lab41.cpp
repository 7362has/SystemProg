#include <stdio.h>
int summul(unsigned char *array1, unsigned char *array2)
        {
                int sum=0;
                __asm__
                        (
                         "movl $5, %%ecx\n\t"
                         "a:\n\t"
                         "movb (%%rsi), %%al\n\t "
                         "movb (%%rdi), %%bl\n\t"
                         "mulb %%bl\n\t"
                         "addw %%ax, %%dx\n\t"
                         "xorw %%ax, %%ax\n\t"
                         "xorw %%bx, %%bx\n\t"
                         "addq $1, %%rsi\n\t"
                         "addq $1, %%rdi\n\t"
                         "loop a\n\t"
                         :"=d"(sum)
                         :"S"(array1), "D"(array2), "d"(sum)
                         :"memory"
                         );
                return sum;
        }

int main (void)
{
        unsigned char array1[5]={1,3,5,7,9};
        unsigned char array2[5]={2,4,6,8,10};
        int sum=0;
        sum=summul(array1,array2);
        printf("%d\n", sum);
        return 0;
}


