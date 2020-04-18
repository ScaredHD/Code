#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 5

void show_arr(float* , int);
void cl_buffer(void);
void print_row_avg(float (*)[COLS]);
float row_avg(float (*)[COLS], int);
float arr_max(float* , int);

int main(void)
{
    float list[ROWS][COLS];

    for (int i = 0; i < ROWS; i++)
    {
        printf("Please enter five numbers divided by space \n(extra inputs will be discarded automaticly)\n");

        for (int j = 0; j < COLS; j++)
        {
            if (scanf("%f", list[i] + j))
                continue;
            else
            {
                int re_input = COLS - j;
                cl_buffer();
                switch (re_input)
                {
                case 1:
                    printf("Invalid input detected. Please re-enter %d number:\n", re_input);
                    j--;
                    break;
                default:
                    printf("Invalid input detected. Please re-enter %d numbers:\n", re_input);
                    j--;
                    break;
                }
            }
        }

        cl_buffer();
    }

    // print array entered
    putchar('{');

    for (int i = 0; i < ROWS; i++)
    {
        show_arr(list[i], COLS);

        if (i < ROWS - 1)
            printf(",\n ");
    }
    putchar('}');

    printf("\n\n");

    // row average
    print_row_avg(list);

    // average of all
    float sum = 0.0;

    for (int i = 0; i < ROWS; i++)
    {
        sum += row_avg(list, i) * 5;
    }

    printf("AVG of all: %f \n\n", sum / (ROWS * COLS));

    // max among array
    printf("MAX of all: %f \n", arr_max(*list, ROWS * COLS));

    system("pause");
    return 0;
}

void show_arr(float *arr, int len)
{
    putchar('{');

    for (int i = 0; i < len; i++)
    {
        if (i == len - 1)
            printf("%f}", *(arr + i));
        else
            printf("%f, ", *(arr + i));
    }
}

void cl_buffer(void)
{
    while (getchar() != '\n')
        continue;
}

void print_row_avg(float (*ptr)[COLS])
{
    float avg[ROWS];

    for (int i = 0; i < ROWS; i++)
    {
        float sum = 0.0;

        for (int j = 0; j < COLS; j++)
            sum += ptr[i][j];

        avg[i] = sum / COLS;
        printf("AVG of row %d is %f\n", i + 1, avg[i]);
    }
}

float row_avg(float (*ptr)[COLS], int row_index)
{
    float avg[ROWS];

    float sum = 0.0;

    for (int j = 0; j < COLS; j++)
        sum += ptr[row_index][j];

    return avg[row_index] = sum / COLS;
}

float arr_max(float* ptr, int len)
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
