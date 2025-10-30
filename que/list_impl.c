#include <stdio.h>
#include <stdlib.h>

// Define Node using typedef
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function declarations
void enqueue(Node** front, Node** rear, int value);
void dequeue(Node** front, Node** rear);
void peek(Node* front);
void display(Node* front);

int main() {
    Node* front = NULL;
    Node* rear = NULL;
    int choice, value;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Peek (Front Element)\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;

            case 2:
                dequeue(&front, &rear);
                break;

            case 3:
                peek(front);
                break;

            case 4:
                display(front);
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

// Function to insert element at rear
void enqueue(Node** front, Node** rear, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }

    printf("%d inserted into queue.\n", value);
}

// Function to delete element from front
void dequeue(Node** front, Node** rear) {
    if (*front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    Node* temp = *front;
    printf("Deleted element: %d\n", temp->data);
    *front = (*front)->next;

    // If queue becomes empty, update rear also
    if (*front == NULL)
        *rear = NULL;

    free(temp);
}

// Function to view front element
void peek(Node* front) {
    if (front == NULL) {
        printf("Queue is empty! Nothing to peek.\n");
        return;
    }
    printf("Front element: %d\n", front->data);
}

// Function to display all elements
void display(Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
