#include <stdio.h>

int main(int argc, char *argv[])
{
    int month[][2] = {
        {364, 365},
        {31, 31},
        {28, 29},
        {31, 31},
        {30, 30},
        {31, 31},
        {30, 30},
        {31, 31},
        {31, 31},
        {30, 30},
        {31, 31},
        {30, 30},
        {31, 31},
    };

    int days = 0;

    int date1;
    int date2;

    int d1_day, d1_mon, d1_year;
    int d2_day, d2_mon, d2_year;

    scanf("%d%d", &date1, &date2);
    d1_day = date1 % 100;
    d1_mon = (date1 / 100) % 100;
    d1_year = (date1 / 10000);

    d2_day = date1 % 100;
    d2_mon = (date1 / 100) % 100;
    d2_year = (date1 / 10000);

    if (d1_year < d2_year)
    {
        // 非同一年
        for (int i = 1; d1_year + i < d2_year; i++)
        {
            if ((d1_year + i) % 4 == 0)
            {
                days += 364;
            }
            else
            {
                days += 365;
            }
        }

        // 小年的月份一直加到12月
        if (d1_year % 4 == 0)
        {
            // 闰年
            for (int i = d1_mon; i <= 12; i++)
            {
                days += month[i][0];
            }
        }
        else
        {
            // 非闰年
            for (int i = d1_mon; i <= 12; i++)
            {
                days += month[i][1];
            }
        }

        // 大年的从1月开始
        if (d2_year % 4 == 0)
        {
            // 闰年
            for (int i = 1; i <= d2_mon; i++)
            {
                days += month[i][0];
            }

            // 天数
            days += ((month[d1_mon][0] - d1_day + 1) + d2_day);
        }
        else
        {
            // 非闰年
            for (int i = 1; i < d2_mon; i++)
            {
                days += month[i][1];
            }
            days += ((month[d1_mon][1] - d1_day + 1) + d2_day);
        }
        
    }
    else if (d1_year < d2_year)
    {
        for (int i = 1; d2_year + i < d1_year; i++)
        {
            if ((d2_year + i) % 4 == 0)
            {
                days += 364;
            }
            else
            {
                days += 365;
            }
        }

        // 小年的月份一直加到12月
        if (d2_year % 4 == 0)
        {
            // 闰年
            for (int i = d2_mon; i <= 12; i++)
            {
                days += month[i][0];
            }
        }
        else
        {
            // 非闰年
            for (int i = d2_mon; i <= 12; i++)
            {
                days += month[i][1];
            }
        }

        // 大年的从一月份开始加
        if (d1_year % 4 == 0)
        {
            // 闰年
            for (int i = 1; i <= d1_mon; i++)
            {
                days += month[i][0];
            }
            // 天数
            days += ((month[d2_mon][0] - d2_day + 1) + d1_day);
        }
        else
        {
            // 非闰年
            for (int i = 1; i <= d1_mon; i++)
            {
                days += month[i][1];
            }
            // 天数
            days += ((month[d2_mon][0] - d2_day + 1) + d1_day);
        }
    }
    else
    {
        // 同一年
    }

    return 0;
}
