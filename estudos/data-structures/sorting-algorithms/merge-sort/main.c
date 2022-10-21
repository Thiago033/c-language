#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int merge(int array[], int low, int mid, int high) {

    int *temp, p1, p2, size, i, j, k;
    int end1 = 0, end2 = 0;

    size = high - low + 1;

    p1 = low;
    p2 = mid + 1;

    temp = (int *) malloc(size * sizeof(int));

    if (temp != NULL) {
        for (i = 0; i < size; i++) {
            if (!end1 && !end2) {
                
                if (array[p1] < array[p2]) {
                    temp[i] = array[p1++];
                } else {
                    temp[i] = array[p2++];
                }
                
                if (p1 > mid) end1 = 1;
                if (p2 > high) end2 = 1;
            } else {
                if(!end1){
                    temp[i] = array[p1++];
                } else {
                    temp[i] = array[p2++];
                }
            }
        }

        for (j = 0, k = low; j < size; j++, k++) {
            array[k] = temp[j];
        }
    }
    
    free(temp);
}

void mergeSort(int *array, int low, int high) {

    if (low < high) {

        int mid = floor((low + high) / 2);

        mergeSort(array, low , mid);
        mergeSort(array, mid+1, high);
        
        merge(array, low, mid, high);
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

    mergeSort(array, 0, size-1);

    printArray(array, size);
   
   return(0);
}