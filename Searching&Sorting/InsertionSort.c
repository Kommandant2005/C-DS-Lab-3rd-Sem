#include<stdio.h>

void insertionSort(int arr[], int num) {
    for (int i = 1; i < num; i++) {
        int res = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > res) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = res;
    }
}
int main(){
    int num;
    printf("Enter the size of the array");
    scanf("%d",&num);
    int arr[num];
    printf("Enter the numbers");
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,num);
    for(int i=0;i<num;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}


