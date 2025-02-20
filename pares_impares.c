#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100000

int compare_asc(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int compare_desc(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}
int main() {
    int n, i;
    int even_count = 0, odd_count = 0;
    int even[MAX_NUMBERS], odd[MAX_NUMBERS];

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        int numbers;
        scanf("%d", &numbers);
        if (numbers % 2 == 0) {
            even[even_count++] = numbers;
        } else {
            odd[odd_count++] = numbers;
        }
    }

    qsort(even, even_count, sizeof(int), compare_asc);
    qsort(odd, odd_count, sizeof(int), compare_desc);
    for (i = 0; i < even_count; i++) {
        printf("%d\n", even[i]);
    }
    for (i = 0; i < odd_count; i++) {
        printf("%d\n", odd[i]);
    }

    return 0;
}

