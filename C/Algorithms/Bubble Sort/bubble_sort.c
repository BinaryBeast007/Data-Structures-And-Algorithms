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
void bubbleSort(int arr[], int size) {
    int counter = 1;
    while(counter < size) {
        int swaped = 0;
        for(int i=0; i<size-counter; i++) {
            if(arr[i] > arr[i+1]) {
                swap(&arr[i], &arr[i+1]);
                swaped = 1;
            }
        }
        if(!swaped) {
            break;
        }
        counter++;
    }
}

int main() {
    int arr[10] = { 234, 34, 348, 934, 4, 12, 49, 347, 23, 2 };
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("initial array :\n");
    printArray(arr, size);
    bubbleSort(arr, size);
    printf("sorted array :\n");
    printArray(arr, size);

    return 0;
}
