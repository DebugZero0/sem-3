#include <stdio.h>

#define MAX 100

// Function declarations
void display(int arr[], int n);
void deleteAtFirst(int arr[], int *n);
void deleteAtLast(int arr[], int *n);
void deleteAtPosition(int arr[], int *n, int pos);

int main() {
    int arr[MAX], n, choice, pos, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\n----- MENU -----\n");
        printf("1. Delete at First\n");
        printf("2. Delete at Last\n");
        printf("3. Delete at Any Position\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                deleteAtFirst(arr, &n);
                break;

            case 2:
                deleteAtLast(arr, &n);
                break;

            case 3:
                printf("Enter position (1 to %d): ", n);
                scanf("%d", &pos);
                if(pos < 1 || pos > n)
                    printf("Invalid position!\n");
                else
                    deleteAtPosition(arr, &n, pos);
                break;

            case 4:
                display(arr, n);
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

// Function to display array
void display(int arr[], int n) {
    int i;
    if(n == 0)
        printf("Array is empty.\n");
    else {
        printf("Array elements: ");
        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
}

// Function to delete first element
void deleteAtFirst(int arr[], int *n) {
    int i;
    if(*n == 0)
        printf("Array is empty! Nothing to delete.\n");
    else {
        printf("Deleted element: %d\n", arr[0]);
        for(i = 0; i < *n - 1; i++)
            arr[i] = arr[i + 1];
        (*n)--;
    }
}

// Function to delete last element
void deleteAtLast(int arr[], int *n) {
    if(*n == 0)
        printf("Array is empty! Nothing to delete.\n");
    else {
        printf("Deleted element: %d\n", arr[*n - 1]);
        (*n)--;
    }
}

// Function to delete element at any position
void deleteAtPosition(int arr[], int *n, int pos) {
    int i;
    if(*n == 0)
        printf("Array is empty! Nothing to delete.\n");
    else {
        printf("Deleted element: %d\n", arr[pos - 1]);
        for(i = pos - 1; i < *n - 1; i++)
            arr[i] = arr[i + 1];
        (*n)--;
    }
}
