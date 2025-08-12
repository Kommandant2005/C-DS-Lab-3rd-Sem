#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Node not created\n");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void display(Node* head){
    if(head==NULL){
        printf("LinkedList is empty\n");
        return;
    }
    Node* curr = head;
    while(curr){
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}

Node* deleteNode(Node* head, int data) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return NULL;
    }
    Node* curr = head;
    Node* prev = NULL;
    while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Element not found in the linked list.\n");
        return head;
    }
    if (prev == NULL) {
        head = curr->next;
    }
    else {
        prev->next = curr->next;
    }
    free(curr);
    printf("Element deleted successfully.\n");
    return head;
}

void insertBefore(Node* head, int data, int beforeData) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((head)->data == beforeData) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != beforeData) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Element %d not found in the list\n", beforeData);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfter(Node* head, int data, int afterData) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL && temp->data != afterData) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list\n", afterData);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertSorted(Node* head, int info){
    Node* newNode = createNode(info);
    if(head==NULL){
        printf("List is Empty");
        return;
    }
    Node* temp = head;
    while(temp->next && temp->next->data <= newNode->data){
        temp = temp->next;
    }
    newNode->next= temp->next;
    temp->next = newNode;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void sortLL(Node* head) {
    if (head == NULL) {
        return;
    }
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;
    swapped = 1;
    while (swapped) {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap the data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

void deleteAlternate(Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
        temp = temp->next;
    }
}

int main() {
    Node* head = createNode(10);
    Node* temp1 = createNode(40);
    head->next=temp1;
    Node* temp2 = createNode(30);
    temp1->next=temp2;
    Node* temp3 = createNode(20);
    temp2->next=temp3;


    int choice, data, beforeData, afterData;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element before another specified element\n");
        printf("2. Insert an element after another specified element\n");
        printf("3. Delete a specified element\n");
        printf("4. Display the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert an element into a sorted list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element before which to insert: ");
                scanf("%d", &beforeData);
                insertBefore(head, data, beforeData);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element after which to insert: ");
                scanf("%d", &afterData);
                insertAfter(head, data, afterData);
                break;
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                deleteNode(head, data);
                break;
            case 4:
                display(head);
                break;
            case 5:
                Node* newHead = reverse(head);
                head=newHead;
                break;
            case 6:
                sortLL(head);
                break;
            case 7:
                deleteAlternate(head);
                break;
            case 8:
                printf("Enter the element to insert into the sorted list: ");
                scanf("%d", &data);
                insertSorted(head, data);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
