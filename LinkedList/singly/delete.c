#include <stdio.h>
#include <stdlib.h>

// Define Node using typedef
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function declarations
void display(Node *head);
void insertAtLast(Node **head, int data);
void deleteAtFirst(Node **head);
void deleteAtLast(Node **head);
void deleteAtPosition(Node **head, int pos);

int main() {
    Node *head = NULL;
    int choice, data, pos;

    // Pre-fill some nodes for testing
    int n;
    printf("Enter number of initial nodes: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtLast(&head, data);
    }

    do {
        printf("\n----- MENU -----\n");
        printf("1. Delete at First\n");
        printf("2. Delete at Last\n");
        printf("3. Delete at Any Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                deleteAtFirst(&head);
                break;

            case 2:
                deleteAtLast(&head);
                break;

            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
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

// Function to display linked list
void display(Node *head) {
    Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert node at last (for setup)
void insertAtLast(Node **head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to delete first node
void deleteAtFirst(Node **head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Function to delete last node
void deleteAtLast(Node **head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    if ((*head)->next == NULL) { // Only one node
        printf("Deleted element: %d\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    Node *temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;

    printf("Deleted element: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Function to delete node at any position
void deleteAtPosition(Node **head, int pos) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    if (pos == 1) {
        deleteAtFirst(head);
        return;
    }

    Node *temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }

    Node *delNode = temp->next;
    temp->next = delNode->next;
    printf("Deleted element: %d\n", delNode->data);
    free(delNode);
}
