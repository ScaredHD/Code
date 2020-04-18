#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int isprime(int);

int main(void)
{
    long long i, div;
    printf("Enter an integer: ");
    scanf("%lld", &i);

    printf("divisors: ");

    for (div = 1; (div * div) <= i; div++)
        if (i % div == 0)
        {
            if (isprime(div))
                printf("%lld(prime) ", div);
            else
                printf("%lld ", div);

            if (isprime(i / div))
                printf("%lld(prime) ", i / div);
            else
                printf("%lld ", i / div);
        }
    
    





    system("pause");
    return 0;
}

int isprime(int i)
{
    for (int div = 2; (div * div) <= i; div++)
    {
        if (i % div == 0)
            return false;
    }

    return true;
}

