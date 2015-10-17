#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int maxSum(int a[], int n)
{
    int sum = 0;
// Change this to "int sum = a[0]" when all is negtive
// you can also leave it as it is as well, it simply returns 0.
    int b = 0;

    for (int i = 0; i < n; i++) {
        if (b < 0)
            b = a[i];
        else
            b += a[i];
        if (sum < b)
            sum = b;
    }
    return sum;
}

int main()
{
    clock_t start, end;
    start = clock();
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, -4};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf(" The max sum is %d", maxSum(arr, size));
    getchar();
    end = clock();
    printf("%lf\n",(end-start)/(double)(CLOCKS_PER_SEC));
    return 0;
}
