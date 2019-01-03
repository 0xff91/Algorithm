#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n = 0;
    int id = 0;
    int score = 0;
    int cur_id = 0;
    int max_score = 0;
    int *scores;

    scanf("%d", &n);
    scores = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &id, &score);
        scores[id] += score;
        if (scores[id] > max_score) {
            max_score = scores[id];
            cur_id = id;
        }
    }

    printf("%d %d", cur_id, max_score);

    return 0;
}
