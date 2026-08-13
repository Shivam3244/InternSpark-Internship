#include <stdio.h>
#include <stdlib.h>

int binarySearch(const int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main(void) {
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int *arr = malloc((size_t)n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter value to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if (result != -1)
        printf("%d found at index %d.\n", target, result);
    else
        printf("%d not found.\n", target);

    free(arr);
    return 0;
}
