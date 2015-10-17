#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int maxSubArraySum(int a[], int size, int *begin, int *end)
{
    int max_sum = 0, max_end = 0;
    int i, index = 0;

    for (i = 0; i < size; i++) {
        max_end = max_end + a[i];
        if (max_end <= 0) {
            max_end = 0;
            index = i + 1;
        } else if (max_sum < max_end) {
            max_sum = max_end;
            *begin = index;
            *end = i;
        }
    }
    return max_sum;
}

int main()
{
    clock_t init, fin;
    init = clock();
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, -4};
    int start = 0, end = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    printf(" The max sum is %d", maxSubArraySum(arr, size, &start, &end));
    printf(" The begin and end are %d & %d", start, end);
    getchar();
    fin = clock();
    printf("%lf\n",(init-fin)/(double)(CLOCKS_PER_SEC));
    return 0;
}
