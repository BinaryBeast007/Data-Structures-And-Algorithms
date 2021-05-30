#include<iostream>
using namespace std;

const int MAXN = 100;   // Max array size
int n = 10; // Number of elements

bool deletion(int arr[], int &n, const int &pos) {
    bool flag = false;
    if(pos >= 0 && pos < MAXN) { // validating positon
        for(int i=pos; i<n-1; i++) {
            arr[i] = arr[i+1]; // shifting all elements 1 position to the lest from pos to n-1
        }
        n--; // total number of elements decreased by 1
        flag = true;
    }
    return flag; // returning true/flase based on successful/unsuccessful deletion
}

void printArray(int arr[], const int &n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[MAXN] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int pos = 4;
    
    cout << "initial array :\n";
    printArray(arr, n);
    if(deletion(arr, n, pos)) {
        cout << "deletion successful\n";
        cout << "current array :\n";
        printArray(arr, n);
    }else {
        cout << "deletion unsuccessful\n";
    }

    return 0;
}
