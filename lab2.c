#include <stdio.h>
int main()
{
int i,min,max;
int m[10]={7,1,4,5,8,13,2,98,3,56};
//min
min=m[0];
max=m[0];
        for (i=0;i<10;i++)
        {
                if(m[i]<min)
                min=m[i];
                if(m[i]>max)
                max=m[i];
        }
printf("max=%d\n", max);
printf("min=%d\n", min);

}
