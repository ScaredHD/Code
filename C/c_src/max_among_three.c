#include <stdio.h>
#include <stdlib.h>

int max_3(int, int, int);

int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    printf("%d", max_3(a, b, c));


    system("pause");
    return 0;
}


int max_3(int a,int b, int c)
{
    int weight_a = 0, weight_b = 0, weight_c = 0;

    if (a > b)
        weight_a++;
    else
        weight_b++;

    if (b > c)
        weight_b++;
    else
        weight_c++;
    
    if (a > c)
        weight_a++;
    else
        weight_c++;
    
    if (weight_a == 2)
        return a;
    else if (weight_b == 2)
        return b;
    else 
        return c;
}