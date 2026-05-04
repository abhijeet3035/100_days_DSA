// Day 5: Arrange Arrival Logs
// Sort arrival times in ascending order using bubble sort
#include <stdio.h>

void sortLogs(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[100], n;

    printf("Enter the number of arrival logs: ");
    scanf("%d", &n);

    printf("Enter %d arrival times:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sortLogs(arr, n);

    printf("Arranged arrival logs:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
