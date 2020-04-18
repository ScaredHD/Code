#include <stdio.h>
#include <stdlib.h>

int arr_max(int*, int);

int main(void)
{
    



    system("pause");
    return 0;

}


int arr_max(int* ptr, int len)
{
    int weight[len];

    for (int i = 0; i < len; i++)
        weight[i] = 0;


    for (int i = 0; i < len; i++)
    {
        int j;
        for (j = i + 1; j < len; j++)
        {
            if (ptr[i] > ptr[j])
                weight[i]++;
            else
                weight[j]++;
        }
    }

    for (int i = 0; i < len; i++)
        if (weight[i] == len - 1)
            return ptr[i];

    return 0;
}

