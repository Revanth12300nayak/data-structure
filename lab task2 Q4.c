#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int swapCount = 0; // Variable to store the number of swaps
    for (int i = 0; i < n - 1; i++) {
        // Each pass through the array
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapCount++; // Increment the swap counter
            }
        }
    }
    // Print the number of swaps
    printf("Number of swaps: %d\n", swapCount);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}