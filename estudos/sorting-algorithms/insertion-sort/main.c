#include <math.h>
#include <stdio.h>

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertionSort(int array[], int size) {
    int i, j, key;

    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
    
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j+1] = key;
    }
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };

    int n = sizeof(arr) / sizeof(arr[0]);
 
    insertionSort(arr, n);

    printArray(arr, n);
 
    return 0;
}