#include <stdio.h>
int main(void)
{
    long number;
    printf("Number: ");
    scanf("%ld", &number);
    long n=number;
    int sum1=0;
    int sum2=0;
    while (n>0)
    {
        int digit=n%10;
        sum1=sum1+digit;
        n=n/10;
        if (n>0)
        {
            int digit2=n%10;
            digit2=digit2*2;
            if (digit2>9)
            {
                sum2=sum2+(digit2/10)+(digit2%10);
            }
            else
            {
                sum2=sum2+digit2;
            }
            n=n/10;
        }
    }
    int total=sum1+sum2;
        if (total%10==0)
        {
            printf("VALID\n");
        }
        else
        {
            printf("INVALID\n");
        }
}
