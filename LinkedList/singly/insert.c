#include <stdio.h>
#include <stdlib.h>

// Define node using typedef
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function declarations
void display(Node *head);
void insertAtFirst(Node **head, int data);
void insertAtLast(Node **head, int data);
void insertAtPosition(Node **head, int data, int pos);

int main() {
    Node *head = NULL;
    int choice, data, pos;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at Any Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtFirst(&head, data);
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtLast(&head, data);
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtPosition(&head, data, pos);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting program...\n"); 
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

// Function to insert node at first
void insertAtFirst(Node **head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at first position.\n", data);
}

// Function to insert node at last
void insertAtLast(Node **head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d at last position.\n", data);
}

// Function to insert node at any position
void insertAtPosition(Node **head, int data, int pos) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Inserted %d at position %d.\n", data, pos);
        return;
    }

    Node *temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", data, pos);
}
