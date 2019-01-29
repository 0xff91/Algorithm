#include <stdio.h>

int main() {
    int *d = (int *)0x12;
    d++;
    printf("%d", d);
}