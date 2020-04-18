#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int isprime(int);

int main(void)
{

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
