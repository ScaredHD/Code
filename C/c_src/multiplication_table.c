/* 9 * 9 乘法表 */
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    short x, y;

/* 将表划分为网格, 根据各个方格“坐标”满足的条件作出相应处理 
    y   0   1   2 ... 9
  x
  0
  1
  2
*/

    for (x = 0; x < 11; x++)
    {
        for (y = 0; y < 11; y++)
        {
            // 左上角 *
            if (x == 0 && y == 0)
                printf("*");

            // 第一行
            if ( x == 0 && y > 1)
                printf("%4d", y - 1);

            // 第一列
            if ( x > 1 && y == 0)
                printf("%d", x - 1);

            // 乘法表中间部分 , 打印两数乘积
            if ( x > 1 && y > 1)
                printf("%4d", (x - 1) * (y - 1));

            // 第二行, 水平分界线 ----
            if ( x == 1 && y != 1)
                printf("----");

            // 第二列, 竖直分界线     |
            if ( x != 1 && y == 1)
                printf("   |");

            // 水平和竖直分界线相交的位置, 用 - 代替
            if ( x== 1 && y == 1)
                printf("-");

            // 行末换行
            if ( y == 10)
                printf("\n");
        }
    }

    system("pause");
    return 0;
}
