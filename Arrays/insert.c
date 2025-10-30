#include <stdio.h>

#define MAX 100

// Function declarations
void display(int arr[], int n);
void insertAtFirst(int arr[], int *n, int element);
void insertAtLast(int arr[], int *n, int element);
void insertAtPosition(int arr[], int *n, int element, int pos);

int main() {
    int arr[MAX], n, choice, element, pos;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\n----- MENU -----\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at Any Position\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insertAtFirst(arr, &n, element);
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insertAtLast(arr, &n, element);
                break;

            case 3:
                printf("Enter position (1 to %d): ", n + 1);
                scanf("%d", &pos);
                if(pos < 1 || pos > n + 1)
                    printf("Invalid position!\n");
                else {
                    printf("Enter element to insert: ");
                    scanf("%d", &element);
                    insertAtPosition(arr, &n, element, pos);
                }
                break;

            case 4:
                display(arr, n);
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

// Function to display array elements
void display(int arr[], int n) {
    int i;
    printf("Array elements: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to insert at first position
void insertAtFirst(int arr[], int *n, int element) {
    int i;
    for(i = *n; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = element;
    (*n)++;
    printf("Inserted %d at first position.\n", element);
}

// Function to insert at last position
void insertAtLast(int arr[], int *n, int element) {
    arr[*n] = element;
    (*n)++;
    printf("Inserted %d at last position.\n", element);
}

// Function to insert at any given position
void insertAtPosition(int arr[], int *n, int element, int pos) {
    int i;
    for(i = *n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = element;
    (*n)++;
    printf("Inserted %d at position %d.\n", element, pos);
}

// NOTES: Dynamic n handling and boundary checks are minimal for simplicity.