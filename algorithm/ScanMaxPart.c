#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int sum;
    int start_index;
    int end_index;
}result_t;

void ScanMaxPart(int v[], int size, result_t *t)
{
    int i, j, tmp;

    memset(t, 0, sizeof(result_t));

    for(i = 0; i < size; i++) {
        tmp = 0;
        for(j = i; j < size; j++) {
            tmp += v[j];
            if (tmp >= t->sum) {
                t->sum = tmp;
                t->start_index = i;
                t->end_index = j;
            }
        }
    }
}

int main(int argc, char**argv)
{
    int v[] = {-1, 2, 4, -1, 2, -5, -3, 1, 2, -3, -4, 5};
    result_t t = {0};

    ScanMaxPart(v, sizeof(v)/sizeof(int), &t);

    printf("Result: sum %d start %d end %d\n", t.sum, t.start_index, t.end_index);

    system("PAUSE");

    return 0;
}