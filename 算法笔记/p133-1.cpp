#include <stdio.h>
#include <math.h>

/**
 * 装水问题
 *
 * 直接用公式不好算，那么可以穷举，但是h是一个无理数，
 * 所以穷举不可能穷尽，使用二分法，尽可能逼近
 */
const double PI = acos(-1); // π
const double eps = 1e-5;    // 精度

// 计算面积s1
double f(double R, double h)
{
    double s1 = acos((R - h) / R) * R * R - sqrt(R * R - (R - h) * (R - h)) * (R - h);

    return s1;
}

int main(int argc, char const *argv[])
{
    /* code */
    double R;
    double r;

    double h;

    scanf("%lf%lf", &R, &r);

    double s1 = PI * R * R * r / 2;

    // h是从0 到 R的
    double low = 0;
    double height = R;
    double mid;

    while (height - low > eps)
    {
        mid = (low + height) / 2;
        // if (f(R, mid) - s1 < eps)
        //     break;
        if (f(R, mid) > s1)
        {
            height = mid;
        }
        else if (f(R, mid) < s1)
        {
            low = mid;
        }
        else
            break;
    }

    printf("%.4lf", mid);

    return 0;
}
