#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    srand((unsigned int)time(0));
    int num = rand() % 100 + 1;
    int input;

    printf("Guess the number (1 to 100): ");
    while (1)
    {
        while (scanf("%d", &input) != 1)
        {
            printf("Wrong input, try again:\n");

            while (getchar() != '\n')
                continue;
        }

        if (input == num)
        {
            printf("YES, you're right!\n");
            break;
        }
        else if (input > num)
        {
            printf("Too big, try again:\n");
            continue;
        }
        else
        {
            printf("Too small, try again:\n");
            continue;
        }
            
    break; 
    }

    printf("Done.\n");


    system("pause");
    return 0;
}

