#include<stdio.h>

void printArray(int arr[], int size) {
    int i;
    for(i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(int arr[], int size) {
    int i;
    for(i=0; i<size-1; i++) {
        int minIdx = i, j = i+1;
        for(j=i+1; j<size; j++) {
            if(arr[minIdx] > arr[j]) {
                minIdx = j;
            }
        }
        swap(&arr[i], &arr[minIdx]);
    }
}

int main() {
    int arr[10] = { 234, 34, 348, 934, 4, 12, 49, 347, 23, 2 };
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("initial array :\n");
    printArray(arr, size);
    selectionSort(arr, size);
    printf("sorted array :\n");
    printArray(arr, size);

    return 0;
}
