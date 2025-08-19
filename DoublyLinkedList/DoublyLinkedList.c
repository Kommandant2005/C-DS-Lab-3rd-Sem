#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Node not created\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(Node* header, int value) {
    Node* newNode = createNode(value);
    Node* current = header;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;

    printf("Appended %d\n", value);
}

void deleteFromBack(Node* header) {
    if (header->next == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* current = header;
    while (current->next != NULL) {
        current = current->next;
    }

    int value = current->data;
    if (current->prev != NULL) {
        current->prev->next = NULL;
    }
    free(current);

    printf("Deleted %d from rear\n", value);
}

void insertAtPosition(Node* header, int value, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    Node* newNode = createNode(value);
    Node* current = header;
    int count = 1;

    while (current->next != NULL && count < pos) {
        current = current->next;
        count++;
    }

    if (count == pos) {
        newNode->next = current->next;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
        printf("Inserted %d at position %d\n", value, pos);
    } else {
        printf("Position out of range!\n");
        free(newNode);
    }
}

void deleteFromPosition(Node* header, int pos) {
    if (pos < 1 || header->next == NULL) {
        printf("Invalid position or list is empty!\n");
        return;
    }

    Node* current = header;
    int count = 1;

    while (current->next != NULL && count < pos) {
        current = current->next;
        count++;
    }

    if (count == pos && current->next != NULL) {
        Node* temp = current->next;
        current->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = current;
        }
        int value = temp->data;
        free(temp);
        printf("Deleted %d from position %d\n", value, pos);
    } else {
        printf("Position out of range!\n");
    }
}

void insertAfterValue(Node* header, int value, int afterValue) {
    Node* current = header->next;
    while (current != NULL && current->data != afterValue) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found!\n");
        return;
    }

    Node* newNode = createNode(value);
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;

    printf("Inserted %d after %d\n", value, afterValue);
}

void insertBeforeValue(Node* header, int value, int beforeValue) {
    Node* current = header->next;
    if (current == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (current->data == beforeValue) {
        Node* newNode = createNode(value);
        newNode->next = current;
        current->prev = newNode;
        header->next = newNode;
        printf("Inserted %d before %d\n", value, beforeValue);
        return;
    }

    while (current != NULL && current->data != beforeValue) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found!\n");
        return;
    }

    Node* newNode = createNode(value);
    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev != NULL) {
        current->prev->next = newNode;
    }
    current->prev = newNode;

    printf("Inserted %d before %d\n", value, beforeValue);
}

void traverseForward(Node* header) {
    if (header->next == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* current = header->next;
    printf("Forward traversal: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void traverseReverse(Node* header) {
    if (header->next == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* current = header;
    while (current->next != NULL) {
        current = current->next;
    }

    printf("Reverse traversal: ");
    while (current != header) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}


void freeList(Node* header) {
    Node* current = header->next;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    header->next = NULL;
}

int main() {
    Node* header = createNode(-1);
    int choice, value, pos, afterValue, beforeValue;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Append an element\n");
        printf("2. Delete from rear\n");
        printf("3. Insert at position\n");
        printf("4. Delete from position\n");
        printf("5. Insert after a value\n");
        printf("6. Insert before a value\n");
        printf("7. Traverse forward\n");
        printf("8. Traverse reverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to append: ");
                scanf("%d", &value);
                append(header, value);
                break;
            case 2:
                deleteFromBack(header);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(header, value, pos);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteFromPosition(header, pos);
                break;
            case 5:
                printf("Enter value and value to insert after: ");
                scanf("%d %d", &value, &afterValue);
                insertAfterValue(header, value, afterValue);
                break;
            case 6:
                printf("Enter value and value to insert before: ");
                scanf("%d %d", &value, &beforeValue);
                insertBeforeValue(header, value, beforeValue);
                break;
            case 7:
                traverseForward(header);
                break;
            case 8:
                traverseReverse(header);
                break;
            case 9:
                freeList(header);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
