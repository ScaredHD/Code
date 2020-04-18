/*  字符, 行, 单词计数

注:
非特殊行末尾为 '\n'
特殊行末尾为 '|', 末尾前一字符不为 '\n'

示例: 
Yesterday, I    (非特殊行)
went home.      (非特殊行)
|

Yesterday, I    (非特殊行)
went home.|     (特殊行)

*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>      // isxxx() function



int main(void)
{
    char ch, c;
    int char_count = 0, ln_count = 0, word_count = 0;

    c = '\0';   // 为 c 随意赋一个初值, 进入循环后被 ch 值覆盖

    while ( (ch = getchar()) != '|' )
    {
        /* 字符计数 */
        if (ch != ' ' && ch != '\n' && ch != '\t')
            char_count++;


        /* 非特殊行计数 */
        if (ch == '\n')
            ln_count++;


        /* 词计数 */
        if ((isalnum(c) && ispunct(ch)) || (isalnum(c) && ch == ' ') || (isalnum(c) && ch == '\n'))
            word_count++;
        

        c = ch;     // 使 c, ch 一前一后的读取模式继续推进
    }

    /*  特殊行检验:
        当 ch 读取 '|' 后, 跳出循环, 此时 ch 为 '|', c 为 
        '|' 前一个字符, 若 c 不是换行符, 则该行为特殊行, 补
        充计入行数中 */
    if (c != '\n')
        ln_count++;


    /* 末尾特殊词检验:
        同上, 若出现如下无标点末尾词 word|, 因 ch 在读取到 '|' 后就
        已经退出循环, 循环内的 if 词计数无法判断到该词. 故手动将其
        补充计入词数中 */
    if (isalnum(c))
        word_count++;



    printf("\ncharacters: %d \t lines: %d \t words: %d \n", char_count, ln_count, word_count);

    system("pause");
    return 0;
}