#include<iostream>
using namespace std;

const int MAXN = 100;   // Max array size
int n = 10; // Number of elements

bool insert(int arr[], int &n, const int &pos, const int &data) {
    bool flag = false;
    if(pos >= 0 && pos < MAXN && n+1 < MAXN) { // validating positon
        for(int i=n; i>pos; i--) {
            arr[i] = arr[i-1]; // shifting all elements 1 position to the right from pos to n-1
        }
        arr[pos] = data; // inserting data
        n++; // total number of elements increased by 1
        flag = true;
    }
    return flag; // returning true/flase based on successful/unsuccessful insertion
}

void printArray(int arr[], const int &n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[MAXN] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int pos = 5, data = 99;
    
    cout << "initial array :\n";
    printArray(arr, n);
    if(insert(arr, n, pos, data)) {
        cout << "insertion successful\n";
        cout << "current array :\n";
        printArray(arr, n);
    }else {
        cout << "insertion unsuccessful\n";
    }

    return 0;
}
