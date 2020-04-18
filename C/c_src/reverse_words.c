/* 
给定一个字符串，将字符串中的单词反序输出(单词字母顺序不变)
例: 输入 "see you later!!" 输出 "!!later you see" 
*/
#include <ctype.h>    // isxxx() 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define SIZE 100

int main(void)
{
    char org_str[SIZE];

    printf("Enter a string: \n");
    fgets(org_str, SIZE, stdin);

    int len = strlen(org_str);

    // 初始化指向字符串的指针
    char* p = org_str;


    // 从字符串尾部向头部依次检验
    for (int i = len; i >= 0; i--)
    {
        if (isalpha(p[i]) && !isalpha(p[i - 1]))    // 一个字符为字母, 前一个字符不是字母, 如: ,a 或 [空格]a
        {
            int j = i;

            while (isalpha(p[j]))   // 从此处开始, 打印整个单词
            {
                putchar(p[j]);
                j++;
            }
        }

        if (!isalpha(p[i]))     // 非字母字符, 原样输出
            putchar(p[i]);
    }


    system("pause");
    return 0;
}
