#include <stdio.h>

int nums[10];

int main(int argc, char const *argv[])
{
    bool flag = false; // 用于标志0是否已经用过

    int i = 0;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", nums + i);
    }

    for (i = 1; i < 10; i++)
    {
        if (nums[i] > 0)
        {
            printf("%d", i);
            nums[i]--;
            break;
        }
    }

    for (int j = 0; j < nums[0]; j++)
        printf("0");

    for (; i < 10; i++)
    {
        for (int j = 0; j < nums[i]; j++)
            printf("%d", i);
    }

    return 0;
}
