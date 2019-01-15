#include <stdio.h>

/**
 * 二分法计算根号2
 */
const double eps = 1e-5;

int main(int argc, char const *argv[])
{
    /* code */
    double low = 1;
    double hight = 2;
    double mid = (low + hight) / 2;

    while ((hight - low) > eps)
    {
        mid = (low + hight) / 2;
        if (mid * mid > 2)
        {
            hight = mid;
        }
        else if (mid * mid < 2)
        {
            low = mid;
        }
        else
        {
            break;
        }
    }

    printf("%lf", mid);

    return 0;
}
