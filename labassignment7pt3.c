#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int value;
    int swapcounter;
} swapcount;

void printSwapCount(swapcount arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i].value, arr[i].swapcounter);
    }
}

void bubbleSort(swapcount arr[], int n) {
    int i, j, totalSwaps = 0;
    swapcount temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].value > arr[j + 1].value) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                arr[j].swapcounter++;
                arr[j + 1].swapcounter++;
                totalSwaps++;
            }
        }
    }

    printf("Bubble Sort\nTotal swaps: %d\n", totalSwaps);
    printSwapCount(arr, n);
}

void selectionSort(swapcount arr[], int n) {
    int i, j, min_idx, totalSwaps = 0;
    swapcount temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].value < arr[min_idx].value)
                min_idx = j;
        }
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            arr[i].swapcounter++;
            arr[min_idx].swapcounter++;
            totalSwaps++;
        }
    }

    printf("Selection Sort\nTotal swaps: %d\n", totalSwaps);
    printSwapCount(arr, n);
}

int main() {
    swapcount array1[9] = {{97, 0}, {16, 0}, {45, 0}, {63, 0}, {13, 0}, {22, 0}, {7, 0}, {58, 0}, {72, 0}};
    swapcount array2[9] = {{90, 0}, {80, 0}, {70, 0}, {60, 0}, {50, 0}, {40, 0}, {30, 0}, {20, 0}, {10, 0}};
    swapcount array1_copy[9], array2_copy[9];

    // Copy the original arrays
    memcpy(array1_copy, array1, sizeof(array1));
    memcpy(array2_copy, array2, sizeof(array2));

      printf("\nArray 1: ");
    bubbleSort(array1, 9);
       printf("\nArray 2: ");
    bubbleSort(array2, 9);

    printf("\nArray 1: ");
    selectionSort(array1_copy, 9);
       printf("\nArray 2: ");
    selectionSort(array2_copy, 9);

    return 0;
}