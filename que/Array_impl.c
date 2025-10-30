#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function declarations
void enqueue(int queue[], int *front, int *rear, int element);
void dequeue(int queue[], int *front, int *rear);
void display(int queue[], int front, int rear);
void peek(int queue[], int front, int rear);

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int choice, element;

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
                printf("Enter element to insert: ");
                scanf("%d", &element);
                enqueue(queue, &front, &rear, element);
                break;

            case 2:
                dequeue(queue, &front, &rear);
                break;

            case 3:
                peek(queue, front, rear);
                break;

            case 4:
                display(queue, front, rear);
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

// Function to insert element (Enqueue)
void enqueue(int queue[], int *front, int *rear, int element) {
    if (*rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }
    if (*front == -1)
        *front = 0;
    *rear = *rear + 1;
    queue[*rear] = element;
    printf("%d inserted into queue.\n", element);
}

// Function to delete element (Dequeue)
void dequeue(int queue[], int *front, int *rear) {
    if (*front == -1 || *front > *rear) {
        printf("Queue Underflow! No element to delete.\n");
        *front = *rear = -1;
        return;
    }
    printf("Deleted element: %d\n", queue[*front]);
    *front = *front + 1;
}

// Function to see front element without deleting
void peek(int queue[], int front, int rear) {
    if (front == -1 || front > rear) {
        printf("Queue is empty! Nothing to peek.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

// Function to display queue elements
void display(int queue[], int front, int rear) {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
