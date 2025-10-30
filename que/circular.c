#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // you can change size

// Function declarations
void enqueue(int queue[], int *front, int *rear, int value);
void dequeue(int queue[], int *front, int *rear);
void peek(int queue[], int front, int rear);
void display(int queue[], int front, int rear);

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
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
                enqueue(queue, &front, &rear, value);
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

// Function to insert element in circular queue
void enqueue(int queue[], int *front, int *rear, int value) {
    // Condition for queue full
    if ((*front == 0 && *rear == MAX - 1) || (*rear + 1) % MAX == *front) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    // First element insertion
    if (*front == -1) {
        *front = *rear = 0;
        queue[*rear] = value;
    }
    else {
        *rear = (*rear + 1) % MAX;
        queue[*rear] = value;
    }

    printf("%d inserted into queue.\n", value);
}

// Function to delete element
void dequeue(int queue[], int *front, int *rear) {
    if (*front == -1) {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }

    printf("Deleted element: %d\n", queue[*front]);

    // If queue has only one element
    if (*front == *rear) {
        *front = *rear = -1;
    } else {
        *front = (*front + 1) % MAX;
    }
}

// Function to see front element
void peek(int queue[], int front, int rear) {
    if (front == -1) {
        printf("Queue is empty! Nothing to peek.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

// Function to display queue
void display(int queue[], int front, int rear) {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
