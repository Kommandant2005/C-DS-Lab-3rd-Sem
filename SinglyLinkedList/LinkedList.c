#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
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

// Function to append a node to the list
Node* append(Node* head, Node* tail, int value) {
    Node* newNode = createNode(value);
    if (tail == NULL) {  // If the list is empty
        head = newNode;  // Both head and tail point to the new node
        tail = newNode;
    } else {
        tail->next = newNode;  // Link the current tail to the new node
        newNode->prev = tail;  // Set the previous pointer of the new node to the old tail
        tail = newNode;        // Update tail to the new node
    }
    return head;  // Return the updated head (even if it doesn't change)
}

// Function to delete a node from the back of the list
Node* deleteFromBack(Node* head, Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return head;
    }
    Node* temp = tail;
    int value = temp->data;
    if (head == tail) {  // If there's only one node in the list
        head = NULL;  // Set head to NULL
        tail = NULL;  // Set tail to NULL
    } else {
        tail = tail->prev;  // Move tail to the previous node
        tail->next = NULL;   // Set new tail's next pointer to NULL
    }
    free(temp);
    printf("Deleted %d from rear\n", value);
    return head;  // Return the updated head
}

// Function to insert a node at a specific position
Node* insertAtPosition(Node* head, Node* tail, int value, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return head;
    }

    Node* newNode = createNode(value);

    if (pos == 1) {  // Insert at the beginning
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == NULL) {  // If the list is empty, set tail to new node
            tail = newNode;
        }
        return head;
    }

    Node* current = head;
    int count = 1;

    while (current != NULL && count < pos - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    } else {
        tail = newNode;  // If inserting at the end, update tail
    }
    current->next = newNode;
    newNode->prev = current;

    return head;
}

// Function to delete a node from a specific position
Node* deleteFromPosition(Node* head, Node* tail, int pos) {
    if (pos < 1 || head == NULL) {
        printf("Invalid position or list is empty!\n");
        return head;
    }

    Node* temp;
    if (pos == 1) {  // Delete the first node
        temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;  // If the list becomes empty, set tail to NULL
        }
    } else {
        Node* current = head;
        int count = 1;

        while (current != NULL && count < pos) {
            current = current->next;
            count++;
        }

        if (current == NULL) {
            printf("Position out of range!\n");
            return head;
        }

        temp = current;
        if (current->prev != NULL) {
            current->prev->next = current->next;
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;  // If deleting the last node, update the tail
        }
    }

    int value = temp->data;
    free(temp);
    printf("Deleted %d from position %d\n", value, pos);
    return head;
}

// Function to insert a node after a specific value
Node* insertAfterValue(Node* head, Node* tail, int value, int afterValue) {
    Node* current = head;
    while (current != NULL && current->data != afterValue) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found!\n");
        return head;
    }

    Node* newNode = createNode(value);
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    } else {
        tail = newNode;  // If inserting at the end, update tail
    }
    current->next = newNode;
    newNode->prev = current;

    return head;
}

// Function to insert a node before a specific value
Node* insertBeforeValue(Node* head, Node* tail, int value, int beforeValue) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    if (head->data == beforeValue) {
        Node* newNode = createNode(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }

    Node* current = head;
    while (current != NULL && current->data != beforeValue) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found!\n");
        return head;
    }

    Node* newNode = createNode(value);
    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev != NULL) {
        current->prev->next = newNode;
    }
    current->prev = newNode;

    return head;
}

// Function to traverse the list forward
void traverseForward(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* current = head;
    printf("Forward traversal: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to traverse the list in reverse
void traverseReverse(Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* current = tail;
    printf("Reverse traversal: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Function to free the list
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
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
                head = append(head, tail, value);
                break;
            case 2:
                head = deleteFromBack(head, tail);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                head = insertAtPosition(head, tail, value, pos);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                head = deleteFromPosition(head, tail, pos);
                break;
            case 5:
                printf("Enter value and value to insert after: ");
                scanf("%d %d", &value, &afterValue);
                head = insertAfterValue(head, tail, value, afterValue);
                break;
            case 6:
                printf("Enter value and value to insert before: ");
                scanf("%d %d", &value, &beforeValue);
                head = insertBeforeValue(head, tail, value, beforeValue);
                break;
            case 7:
                traverseForward(head);
                break;
            case 8:
                traverseReverse(tail);
                break;
            case 9:
                freeList(head);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
