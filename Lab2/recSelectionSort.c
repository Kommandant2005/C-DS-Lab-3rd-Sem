#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void recSelectionSort(int *arr, int start, int n) {
    if (start >= n - 1) {
        return;
    }

    int min_index = start;
    for (int j = start + 1; j < n; j++) {
        if (arr[j] < arr[min_index]) {
            min_index = j;
        }
    }

    swap(&arr[start], &arr[min_index]);
    recSelectionSort(arr, start + 1, n);
}
int main() {
    int n;
    int *arr;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Array not formed\n");
        return 1;
    }
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    recSelectionSort(arr,0,n);
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
