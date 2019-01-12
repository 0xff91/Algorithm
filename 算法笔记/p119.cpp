#include <stdio.h>
#include <stdlib.h>

typedef struct commodity
{
    double inventory;   // 库存
    double total_price; // 总售价
    double price;       // 单价
} commodity, *commoditys;

int cmp(const void *s1, const void *s2)
{
    if (((commodity *)s1)->price >= ((commodity *)s2)->price)
        return -1;
    else
        return 1;
}

int main(int argc, char const *argv[])
{
    int n;              // 商品种类数量
    double need;        // 市场需求
    double total = 0.0; // 总售价
    commoditys coms;

    scanf("%d%lf", &n, &need);
    coms = (commoditys)malloc(sizeof(commodity) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &(coms + i)->inventory); // 输入库存
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &(coms + i)->total_price); // 输入总价
    }

    for (int i = 0; i < n; i++)
    {
        (coms + i)->price = (coms + i)->total_price / (coms + i)->inventory; // 计算单价
    }

    /* 按照单价排序 */
    qsort(coms, n, sizeof(commodity), cmp);

    for (int i = 0; i < n; i++)
    {
        if ((coms + i)->inventory < need)
        {
            need -= (coms + i)->inventory;
            total += (coms + i)->total_price;
        }
        else
        {
            total += (coms + i)->price * need;
            break;
        }
    }

    printf("%.2lf", total);

    free(coms);

    return 0;
}
