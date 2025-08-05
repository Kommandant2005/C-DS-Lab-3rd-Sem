#include<stdio.h>
#include<string.h>

void deleteSubstring(char str[], char result[]) {
    int i = 0, j = 0, k = 0, match, found = 0;
    char substr[100];
    printf("Enter Substring to be deleted");
    scanf(" %[^\n]", substr);
    while (str[i] != '\0') {
        j = 0;
        match = i;
        while (str[match] == substr[j] && substr[j] != '\0') {
            match++;
            j++;
        }
        if (substr[j] == '\0' && !found) {
            i = match;
            found = 1;
        } else {
            result[k++] = str[i++];
        }
    }
    result[k] = '\0';
}

void insertSubstring(char str[],char result[]) {
    int i = 0, j = 0, k = 0;
    int pos;
    char substr[100];
    printf("Enter Sub String\n");
    scanf(" %[^\n]", substr);
    printf("Enter Position To Insert Substring\n");
    scanf(" %d", &pos);
    while (i < pos && str[i] != '\0') {
        result[k++] = str[i++];
    }
    while (substr[j] != '\0') {
        result[k++] = substr[j++];
    }
    while (str[i] != '\0') {
        result[k++] = str[i++];
    }
    result[k] = '\0';
}

int stringCompare(char str1[]) {
    int i = 0;
    char str2[100];
    printf("Enter Second String\n");
    scanf(" %[^\n]", str2);
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }

    return str1[i] - str2[i];
}

void stringConcat(char str1[],char result[]) {
    int i = 0, j = 0;
    char str2[100];
    printf("Enter Second String\n");
    scanf(" %[^\n]", str2);
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }

    result[i] = '\0';
}

int findLength(char str[]){
    int count=0;
    for(int i = 0;str[i]!='\0';i++){
        count++;
    }
    return count;
}

int main(){
    char str[100];
    printf("Enter your string\n");
    scanf(" %[^\n]", str);
    printf("\n1. String Length\n");
    printf("2. String Concatenation\n");
    printf("3. String Comparison\n");
    printf("4. Substring Insertion\n");
    printf("5. Substring Deletion\n");
    int choice;
    printf("Enter choice");
    scanf("%d",&choice);
    if(choice == 1){
        int length = findLength(str);
        printf("The string is of length %d/n",length);
    }
    else if(choice==2){
        char result[200];
        stringConcat(str,result);
        printf("The concatenated strings is %s\n",result);
    }
    else if(choice==3){
        int result;
        result = stringCompare(str);
        if(result<0){
            printf("The first string is smaller ascii wise");
        }
        else if(result>0){
            printf("The second string is smaller ascii wise");
        }
        else{
            printf("Both strings are same");
        }
    }
    else if(choice==4){
        char result[200];
        insertSubstring(str,result);
        printf("The resultant string is \n%s\n",result);
    }
    else if(choice==5){
        char result[200];
        deleteSubstring(str,result);
        printf("The resultant string is \n%s\n",result);
    }
    else{
        printf("Invalid Choice");
    }
}
