#include <stdio.h>
#include <string.h>

/**
 * 单词倒序
 * 输入 hello world
 * 输出 world hello
 * 
 * 解法
 *     整体倒序存储，然后每个单词在倒序
 */

/**
 * 翻转函数
 */
void reverse(char *str, int len)
{
    int i = 0;
    int j = len - 1;
    char tmp;

    while (i < j)
    {
        tmp = str[i];
        str[i++] = str[j];
        str[j--] = tmp;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int i = 0;
    char tmp;
    char str[128];

    // 读入一行
    do
    {
        scanf("%c", str + i);
    } while (str[i++] != '\n');
    str[i - 1] = ' ';           // 统一在最后加一个空格
    str[i] = '\0';

    // 整体翻转
    reverse(str, i - 1);

    printf("%s\n", str);


    // 每个单词翻转
    int count = 0;
    int j = 0;

    for (j = 0; j < i; j++)
    {
        if (str[j] != ' ')
            count++;
        else
        {
            reverse(str + j - count, count);
            count = 0;
        }
    }

    // 删除开头的空格
    j = 0;
    while (str[j++] == ' ');
    printf("%s", str + j - 1);


    return 0;
}
