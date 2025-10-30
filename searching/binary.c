#include <stdio.h>

// Function declaration
int binarySearch(int arr[], int n, int key);

int main() {
    int arr[100], n, key, pos, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in ascending order:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    pos = binarySearch(arr, n, key);

    if (pos == -1)
        printf("Element not found!\n");
    else
        printf("Element %d found at position %d.\n", key, pos + 1);

    return 0;
}

// Binary Search Function
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // not found
}
