#include<stdio.h>

void printArray(int arr[], int size) {
    int i;
    for(i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertionSort(int arr[], int size) {
    int i;
    for(i=1; i<size; i++) {
        int current = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > current) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

int main() {
    int arr[10] = { 234, 34, 348, 934, 4, 12, 49, 34798, 23, 2 };
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("initial array :\n");
    printArray(arr, size);
    insertionSort(arr, size);
    printf("sorted array :\n");
    printArray(arr, size);

    return 0;
}
