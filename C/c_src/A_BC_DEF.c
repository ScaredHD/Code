#include <float.h>
#include <inttypes.h>   // provide extra integer types e.g. int32_t
#include <limits.h>     // limits of int_t
#include <stdbool.h>    //_Bool --> bool, true, false
#include <stdio.h>
#include <string.h>     // provide strlen()



int main(void)
{
    int row, row_num, i, j;
    j = 0;

    for (row = 0, row_num = 1; row < 6; row++, row_num++)
    {
        for (i = 0; i < row_num; i++, j++)
            printf("%c", 'A' + j);

        printf("\n");
    }

    system("pause");
    return 0;
}
