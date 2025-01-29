1)#include <stdio.h>

void traverse_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    traverse_array(arr, n);
    return 0;
}

2)#include <stdio.h>

void delete_at_beginning(int arr[], int *n) {
    for (int i = 0; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void delete_at_end(int *n) {
    (*n)--;
}

void delete_at_index(int arr[], int *n, int index) {
    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    delete_at_beginning(arr, &n); // Delete first element
    printf("After deleting at beginning: ");
    traverse_array(arr, n);

    delete_at_end(&n); // Delete last element
    printf("After deleting at end: ");
    traverse_array(arr, n);

    delete_at_index(arr, &n, 1); // Delete at index 1
    printf("After deleting at index 1: ");
    traverse_array(arr, n);

    return 0;
}

3)#include <stdio.h>

void insert_at_beginning(int arr[], int *n, int value, int capacity) {
    if (*n == capacity) return; // Check for overflow
    for (int i = *n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    (*n)++;
}

void insert_at_end(int arr[], int *n, int value, int capacity) {
    if (*n == capacity) return; // Check for overflow
    arr[*n] = value;
    (*n)++;
}

void insert_at_index(int arr[], int *n, int value, int index, int capacity) {
    if (*n == capacity) return; // Check for overflow
    for (int i = *n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    (*n)++;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5};
    int n = 5;

    insert_at_beginning(arr, &n, 10, 10); // Insert at beginning
    printf("After inserting at beginning: ");
    traverse_array(arr, n);

    insert_at_end(arr, &n, 20, 10); // Insert at end
    printf("After inserting at end: ");
    traverse_array(arr, n);

    insert_at_index(arr, &n, 15, 3, 10); // Insert at index 3
    printf("After inserting at index 3: ");
    traverse_array(arr, n);

    return 0;
}

4)#include <stdio.h>

void reverse_array(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverse_array(arr, n);
    printf("Reversed array: ");
    traverse_array(arr, n);

    return 0;
}

5)#include <stdio.h>

void left_shift(int arr[], int n) {
    int first = arr[0];
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = first;
}

void right_shift(int arr[], int n) {
    int last = arr[n - 1];
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    left_shift(arr, n); // Left shift
    printf("After left shift: ");
    traverse_array(arr, n);

    right_shift(arr, n); // Right shift
    printf("After right shift: ");
    traverse_array(arr, n);

    return 0;
}

6)#include <stdio.h>

void sort_indices(int arr[], int n, int is_odd) {
    for (int i = (is_odd ? 1 : 0); i < n; i += 2) {
        for (int j = i + 2; j < n; j += 2) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort_indices(arr, n, 1); // Sort odd indices
    printf("After sorting odd indices: ");
    traverse_array(arr, n);

    sort_indices(arr, n, 0); // Sort even indices
    printf("After sorting even indices: ");
    traverse_array(arr, n);

    return 0;
}
