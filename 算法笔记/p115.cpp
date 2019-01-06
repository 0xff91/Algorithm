/**
 * 输出全排列
 * 
 */

#include <stdio.h>

const int maxn = 11;

int n, p[maxn];
char hash_table[maxn] = {0};

void genarate(int index)
{
    // 边界
    if (index == n+1)
    {
        for (int i = 1; i <= n; i++)
        {
            // 输出
            printf("%d", p[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        // 第一位开始输出
        if (!hash_table[i]) 
        {
            // 如果该位没有被使用，那么可以使用该位
            p[index] = i;
            hash_table[i] = 1;
            genarate(index+1);
            hash_table[i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    n = 3;
    genarate(1);
    return 0;
}
