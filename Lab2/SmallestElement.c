 #include<stdio.h>
#include<stdlib.h>
int smallestElement(int* arr,int n){
    int* ptr = arr;
    int min = *ptr;
    for(int i=0;i<n;i++){
        if(min>*(ptr+i)){
            min = *(ptr+i);
        }
    }
    return min;
}

int main(){
    int n;
    int *arr;
    printf("Enter the size of array");
    scanf("%d",&n);
    arr = (int* )malloc(n*sizeof(int));
    if(arr == NULL){
        printf("Array not formed");
        return 1;
    }
    printf("Enter the array");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    int min = smallestElement(arr,n);
    printf("The smallest element in the array is %d",min);
    free(arr);
    return 0;
}
