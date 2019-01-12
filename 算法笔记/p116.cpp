/**
 * n皇后问题
 * 
 * 解法：
 * 只看行组合，然后判断对角线是否在一行
 * 判断方法，示例：
 * 坐标：
 *   5   1
 *   4   2
 *   3   3
 *   2   4
 *   1   5
 * 坐标：
 *   2   1
 *   3   2
 *   4   3
 *   5   4
 * 
 * 按照行坐标从小到大，不需要回退
 * 行列同时+1，行+1，列-1
 * 
 * 从8开始结果就不对了，然后从12开始严重超时以及内存超出限制
 */

#include <stdio.h>

const int maxn = 11;

int n, p[maxn];
char hash_table[maxn] = {0};
int count = 0;

void genarate(int index)
{
    // 边界
    if (index == n + 1)
    {
        // 已经获得一个行排列，判断该排列是否在符合条件
        for (int i = 1; i <= n; i++)
        {
            // 行列同时增加
            int r = i;
            int c = p[r];
            r++;
            c++;
            for (; r <= n, c <= n; r++, c++)
            {
                if (p[r] == c)
                    return; // 斜方向有
            }

            // 行+1，列-1
            r = i;
            c = p[r];
            r++;
            c--;
            for (; r <= n, c >= 1; r++, c--)
            {
                if (p[r] == c)
                    return; // 斜方向有
            }
        }

        count++;

        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%d", p[i]);
        // }
        // printf("\n%d\n", count);
    }

    for (int i = 1; i <= n; i++)
    {
        // 第一位开始输出
        if (!hash_table[i])
        {
            // 如果该位没有被使用，那么可以使用该位
            p[index] = i;
            hash_table[i] = 1;
            genarate(index + 1);
            hash_table[i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    scanf("%d", &n);
    genarate(1);
    printf("%d\n", count);
    return 0;
}
