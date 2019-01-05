#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define base 26

/**
 * 给出Ｎ个由三个字母组成的字符串
 * 给出Ｍ个查询字符串，问每个字符串在给出字符串中出现的次数
 * 
 *　三个大写字母，那么最多是26^3 = 17576
 */

int cal_str_hash(char *str, int str_len) {
    int p = 1;
    int val = 0;
    int i = 0;

    for (i = 0; i < str_len; i++) {
        val += (str[i] - 'A') * p;
        p *= base;
    }

    return val;
}

int main(int argc, char const *argv[])
{
    int hash[17580] = {0};
    char str[4] = {0};
    int N;
    int *result = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        int hash_val = cal_str_hash(str, 3);
        hash[hash_val] += 1;
        memset(str, 0, 4);
    }

    scanf("%d", &N);
    result = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        int hash_val = cal_str_hash(str, 3);
        result[i] = hash[hash_val];
        memset(str, 0, 4);
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", result[i]);
    }
    /* code */
    return 0;
}
