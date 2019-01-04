#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    printf("p1 is %d, p2 is %d\n", *(int *)p1, *(int *)p2);
    if (*(int *)p1 > *(int *)p2) {
        return 1;
    } else return -1;
}

int main(int argc, char* argv[])
{

    int** a;
    int *b;
    int i;
    a = (int **)malloc(5 * sizeof(int*));
    b = (int *)malloc(5 * sizeof(int));

    for (i = 0; i < 5; i++) {
        a[i] = (int*)malloc(sizeof(int));
        scanf("%d", a[i]);
        b[i] = *a[i];
    }

    qsort(a, 5, sizeof(int*), cmp);
    printf("\n");
    qsort(b, 5, sizeof(int), cmp);

    for (i = 0; i < 5; i++) {
        printf("%d ", *(a[i]));
    }
    printf("\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}
