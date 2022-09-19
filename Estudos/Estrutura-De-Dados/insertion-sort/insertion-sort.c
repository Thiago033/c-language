// C program for insertion sort
#include <math.h>
#include <stdio.h>

// A utility function to print an array of size n
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}  

// Function to sort an array using insertion sort
void insertionSort(int arr[], int n) {
    int i, j, temp;

    for (i = 1; i < n; i++) {

        j = i - 1;
        temp = arr[i];

        while ((j>=0) && (temp < arr[j])) {
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = temp;
    }
}
  
int main()
{
    int arr[] = { 6, 5, 4, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    insertionSort(arr, n);
    printArray(arr, n);
  
    return 0;
}