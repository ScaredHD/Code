#include <stdio.h>
#include <stdlib.h>

int power(int, int);
int digits(int);
int digit_val(int, int);

int main(void)
{

    int i;

    printf("Enter a number: ");
    scanf("%d", &i);

    printf("Inverse: ");
    for (int count = 1; count <= digits(i); count++)
        printf("%d", digit_val(i, count));
    printf("\n");


    system("pause");
    return 0;
}


int power(int i, int j)
{
    if (j == 1)
        return i;
    else
        return i * power(i, j - 1);
}

int digits(int N)
{
    int count = 0;
    for (int i = 1; N / i > 0; i *= 10)
        count++;

    return count;
}

int digit_val(int N, int digit)
{
    int number[digits(N)];
    int value[digits(N)];

    number[0] = N % 10;
    value[0] = number[0];

    for (int i = 1; i < digits(N); i++)
    {
        N = N - value[i - 1];
        number[i] = (N % power(10, i + 1)) / power(10, i);

        value[i] = power(10, i) * number[i];
    }

    return number[digit - 1];
}
