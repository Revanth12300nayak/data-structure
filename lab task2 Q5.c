#include <stdio.h>
void insertionSort(int arr[], int n) {
    int insertionCount = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i]; 
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            insertionCount++; 
        }

        arr[j + 1] = key; 
    }
    printf("Number of insertions: %d\n", insertionCount);
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
    insertionSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}