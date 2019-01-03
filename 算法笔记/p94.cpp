#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    int a, b, d;
    int result[64];
    int num = 0;

    scanf("%d%d%d", &a, &b, &d);

    a += b;

    do
    {
        result[num++] = a % d;
        a /= d;
    } while(a != 0);

    for (int j = num - 1; j >= 0; j--)
    {
        printf("%d", result[j]);
    }

    return 0;
}
