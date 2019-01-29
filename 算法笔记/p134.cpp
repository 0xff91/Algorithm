/**
 * 木棒问题
 *
 * 从最大的开始进行尝试，大的不行那么二分减少
 *
 */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p1, const void *p2)
{
    //return *(int*)p2 - *(int*)p1;
    // 大号排在前面
    //(int)(*p2)
    if ((*((int *)p1)) >= (*((int *)p2)))
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int N;     // N段木棒
    int *lens; // N段木棒各自长度
    int K;     // 要分成几段
    int k = 0; // 当前可以分成的段数
    int l;     // 表示当前分段大小

    scanf("%d", &N);
    lens = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", lens + i);
    }

    scanf("%d", &K);

    // 降序排列
    qsort(lens, N, sizeof(int), cmp);

    l = lens[0];

    while (k < K && l >= 1)
    {
        k = 0;
        for (int i = 0; i < N; i++)
        {
            k += (*(lens + i)) / l;
        }
        printf("l=%d, k=%d\n", l, k);
        l /= 2;
    }

    printf("%d, %d", k, l * 2);

    free(lens);
    return 0;
}