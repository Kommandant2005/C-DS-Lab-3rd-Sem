#include<stdio.h>

void bubbleSort(int arr[],int num){
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
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
    bubbleSort(arr,num);
    for(int i=0;i<num;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
