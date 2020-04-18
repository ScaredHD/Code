/* 
e.g. add two arrays and assign the result to the third one
*/

#include <stdio.h>
#include <stdlib.h>

void mat_add(int, int, int (*)[*], int (*)[*], int (*)[*]);
void show_arr(int, int (*)[*], int);
int arr_max(int* , int);
int int_width(int);

int main(void)
{
    int mat1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int mat2[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};

    int mat3[3][3];

    mat_add(3, 3, mat1, mat2, mat3);

    int max = arr_max(*mat3, 9);

    show_arr(3, mat3, max);

    system("pause");
    return 0;
}

void mat_add(int row, int col, int (*mat1)[3], int (*mat2)[3], int (*mat3)[3])
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat3[i][j] = mat1[i][j] + mat2[i][j];
}

void show_arr(int row, int (*ptr)[3], int max)
{
    printf("[\n");
    for (int i = 0; i < row; i++)
    {
        printf("  [");

        for (int j = 0; j < 3; j++)
        {
            if (j != 2)
                printf("%-*d,", int_width(max), ptr[i][j]);
            else
                printf("%-*d", int_width(max), ptr[i][j]);
        }

        if (i != row - 1)
            printf("],\n");
        else
            printf("]\n");
    }
    printf("]\n");
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

int int_width(int N)
{
    int count = 0;
    for (int i = 1; N / i > 0; i *= 10)
        count++;

    return count;
}