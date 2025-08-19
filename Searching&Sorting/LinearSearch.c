#include<stdio.h>

int linearSearch(int arr[],int key,int num){
    for(int i=0;i<num;i++){
        if(key==arr[i]){
            return i;
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
    int res = linearSearch(arr,key,num);
    if(res!=-1){
        printf("The number is at position %d",res+1);
    }
    else{
        printf("The number is not present");
    }
    return 0;
}
