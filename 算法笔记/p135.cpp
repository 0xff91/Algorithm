/**
 * 快速幂
 */

#include <stdio.h>

typedef long long LL;

LL binaryPow(LL a, LL b, LL m)
{
    if (b == 0)
    {
        return 1;
    }
    else if (b % 2 == 0)
    {
        return binaryPow(a, b / 2, m) * binaryPow(a, b / 2, m);
    }
    else
    {
        return a * binaryPow(a, b - 1, m);
    }
}

int main()
{
    int a, b, m;

    scanf("%d%d%d", &a, &b, &m);
    printf("%ld", binaryPow(a, b, m));
}