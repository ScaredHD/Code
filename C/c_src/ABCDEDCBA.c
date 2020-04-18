#include <float.h>
#include <inttypes.h>   // provide extra integer types e.g. int32_t
#include <limits.h>     // limits of int_t
#include <stdbool.h>    //_Bool --> bool, true, false
#include <stdio.h>
#include <string.h>     // provide strlen()

int main(void)
{
    char ch, j;

    printf("Enter a letter (capital):");
    scanf("%c", &ch);

    int i = 0;


    /* 控制行循环 */

    for (int row = 0; row < ch - 'A' + 1; row++, i++)
    {
        /* 输出前部分空格, 第一次输出数量为 n_sp = 用户输入字母 ch 减去 'A'. 
            下一次循环 i++, 输出空格数减少 1 */

        for (int n_sp = ch - 'A'; n_sp > i; n_sp--)
            printf(" ");


        /* 输出升序字母, A 到主字母 (本行ASCII码最大字母) 
            
            e.g.    ABCDE | DCBA  
            分割线前为升序, 分割线后为降序 */

        char pr = 'A' + row; //定义主字母为本行 ASCII 码最大的字母

        for (j = 'A'; j <= pr; j++)
            printf("%c", j);


        /* 输出降序字母 */

        for (j -= 2; j >= 'A'; j--) // 此处 j - 2 是由于上一个循环退出前, j++, 使其 ASCII 码等于 主字母 + 1
            printf("%c", j);


        /* 输出后半部分空格, 数量与前半部分相同, 故代码一致 */

        for (int n_sp = ch - 'A'; n_sp > i; n_sp--)
            printf(" ");


        printf("\n");   // 一行结束, 换行
    }

    system("pause");
    return 0;
}
