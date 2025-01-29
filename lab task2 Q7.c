#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return ((int)b - (int)a); 
}

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    printf("The %d-th largest element is: %d\n", k, arr[k-1]);
    
    return 0;
}