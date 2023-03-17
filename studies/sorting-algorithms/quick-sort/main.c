#include <stdio.h>
#include <string.h>

int partition(int array[], int low, int high) {
    int left, right, pivot, aux;

    left = low;
    right = high;

    pivot = array[low];

    while (left < right) {

        while (array[left] <= pivot) {
            left++;
        }

        while (array[right] > pivot) {
            right--;
        }

        if (left < right) {
            aux = array[left];
            array[left] = array[right];
            array[right] = aux;
        }
    }

    array[low] = array[right];
    array[right] = pivot;

    return right;
}

void quickSort(int *array, int low, int high) {

    if (low < high) {
        int pivot = partition(array, low, high);

        quickSort(array, low , pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main () {

    int array[] = {64, 25, 12, 22, 11};

    int size = sizeof(array) / sizeof(array[0]);

    quickSort(array, 0, size-1);

    printArray(array, size);
   
   return(0);
}