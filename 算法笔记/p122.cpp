#include <stdio.h>
#include <stdlib.h>

typedef struct section {
    int start;
    int end; // 区间结束
} section, *sections;

int cmp(const void* p1, const void* p2)
{
    if (((sections)p1)->start < ((sections)p2)->start)
        return 1;
    else
        return -1;
}

int main(int argc, char const* argv[])
{
    /* code */
    int n;         // 区间数量
    int count = 0; // 计数
    int last;
    sections s;

    scanf("%d", &n);
 
    s = (sections)malloc(sizeof(section) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &(s + i)->start, &(s + i)->end);
    }

    qsort(s, n, sizeof(section), cmp);

    last = (s + 0)->start;
    count++;

    for (int i = 1; i < n; i++) {
        if ((s + i)->end <= last) {
            last = (s + i)->start;
            count++;
        }
    }

    printf("%d", count);

    free(s);

    return 0;
}
