#include<stdio.h>

int binarySearch(int arr[],int key,int num){
    int high = num-1;
    int low = 0;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
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
    printf("Enter number to search");
    int key;
    scanf("%d",&key);
    int res = binarySearch(arr,key,num);
    if(res!=-1){
        printf("The number is at position %d",res+1);
    }
    else{
        printf("The number is not present");
    }
    return 0;
}
