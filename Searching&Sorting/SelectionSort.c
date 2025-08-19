#include<stdio.h>

void selectionSort(int arr[],int num){
    for(int i=0;i<num;i++){
        int min = i;
        for(int j = i+1;j<num;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp =arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
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
    selectionSort(arr,num);
    for(int i=0;i<num;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

