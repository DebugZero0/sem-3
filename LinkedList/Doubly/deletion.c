#include <stdio.h>
#include <stdlib.h>

// Define Node using typedef
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function declarations
Node* deleteAtBeginning(Node* head);
Node* deleteAtEnd(Node* head);
Node* deleteAtPosition(Node* head, int pos);
void display(Node* head);

int main() {
    Node* head = NULL;
    Node* temp;
    int choice, value, pos;

    // Create an initial list (optional)
    // You can insert manually before deleting if needed.

    do {
        printf("\n----- MENU -----\n");
        printf("1. Delete from Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Delete from Any Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                head = deleteAtBeginning(head);
                break;

            case 2:
                head = deleteAtEnd(head);
                break;

            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                head = deleteAtPosition(head, pos);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 5);

    return 0;
}

// Function to delete first node
Node* deleteAtBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return head;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
    return head;
}

// Function to delete last node
Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return head;
    }

    Node* temp = head;

    // Traverse to last node
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev == NULL) {
        // Only one node in list
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return NULL;
    }

    temp->prev->next = NULL;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
    return head;
}

// Function to delete node at any position (1-based index)
Node* deleteAtPosition(Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return head;
    }

    if (pos <= 1)
        return deleteAtBeginning(head);

    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    // If last node
    if (temp->next == NULL)
        return deleteAtEnd(head);

    // In-between node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
    return head;
}

// Function to display list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
