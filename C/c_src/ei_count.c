/* 输入文本中 ei 的出现次数 */
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    char ch, pre_ch;
    int count = 0;

    // for(为 pre_ch 随意赋初值; 读取字符至 # 退出; 使 pre_ch, ch 一前一后的读取模式继续推进)
    for (pre_ch = '\0'; (ch = getchar()) != '#'; pre_ch = ch)
        if ( pre_ch == 'e' && ch == 'i')
            count++;


    switch (count)
    {
        case 0:
            printf("There's no 'ei' in the text.\n");
            break;
        case 1:
            printf("There's 1 'ei' in the text.\n");
            break;
        default:
            printf("There're %d 'ei's in the text.\n", count);
    }
    

    system("pause");
    return 0;
}