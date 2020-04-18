#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float add(void);
float sub(void);
float times(void);
float divide(void);
void clr(void);
char get_choice(void);

int main(void)
{
    while (1)
    {
        printf("Choices: \n"
                "a) add \t\t b) subtract \n"
                "c) multiply \t d) divide \n"
                "q) quit \n"
                "\t YOUR CHOICE: ");

        char choice = get_choice();
        putchar('\n');

        switch (choice)
        {
            case 'A':
            case 'a':
                printf("RESULT: %f \n\n", add());
                break;

            case 'B':
            case 'b':
                printf("RESULT: %f \n\n", sub());
                break;

            case 'C':
            case 'c':
                printf("RESULT: %f \n\n", times());
                break; 

            case 'D':
            case 'd':
                printf("RESULT: %f \n\n", divide());
                break;
            
            case 'Q':
            case 'q':
                break;

            default:
                printf("Input not valid. Please try again.\n\n"
                        "------------------ \n");
                continue;
        }

        if (choice == 'q' || choice == 'Q')
            break;

        printf("------------------ \n");

    }

    printf("Done.\n");


    system("pause");
    return 0;
}

float add(void)
{
    float i, j;

    printf("Enter first number: ");
    while (scanf("%f", &i) != 1)
    {
        printf("Wrong input. Please try again: ");
        clr();
    }
    
    clr();

    printf("Enter second number: ");
    while (scanf("%f", &j) != 1)
    {
        printf("Wrong input. Please try again: ");
        clr();
    }

    clr();

    return i + j;
}

float sub(void)
{
    float i, j;

    printf("Enter first number: ");
    while (scanf("%f", &i) != 1)
    {
        printf("Wrong input. Please try again: ");
        clr();
    }
        
    clr();

    printf("Enter second number: ");
    while (scanf("%f", &j) != 1)
    {
        printf("Wrong input. Please try again: ");
        clr();
    }

    clr();

    return i - j;
}

float times(void)
{
    float i, j;

    printf("Enter first number: ");
    while (scanf("%f", &i) != 1)
    {
        printf("Wrong input. Please try again: ");
        clr();
    }

    clr();

    printf("Enter second number: ");
    while (scanf("%f", &j) != 1)
    {
        printf("Wrong input. Please try again: ");
        clr();
    }

    clr();

    return i * j;
}


float divide(void)
{
    float i, j;

    printf("Enter first number: ");
    while (scanf("%f", &i) != 1)
    {
        printf("Wrong input. Please try again: ");
        clr();
    }
    
    clr();

    printf("Enter second number: ");

    // validation
    // in-valid situation: j is not a float or j equals 0
    while (1)
    {
        if (scanf("%f", &j) != 1)
        {
            printf("Wrong input. Please try again: ");
            clr();
        }    
        else if ( j == 0.0)
        {
            printf("0 is not accepted here. Please try again: ");
            clr();
        }
        else
            break;
    }

    clr();

    return i / j;
}


// clear buffer line
void clr(void)
{
    while (getchar() != '\n')
        continue;
}

// get first character of a line, ignoring preceding blanks
char get_choice(void)
{
    char ch, c;
    ch = getchar();

    while ( ch == ' ' || ch == '\n')
        ch = getchar();

    // clear buffer
    while ( (c = getchar()) != '\n')
        continue;

    return ch;
}