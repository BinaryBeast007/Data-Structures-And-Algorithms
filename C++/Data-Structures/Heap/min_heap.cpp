#include<bits/stdc++.h>
using namespace std;

class MinHeap {
    int* arr, capacity, heap_size;
public:
    MinHeap(int);
    int linearSearch(int);
    void print();
    int height();
    int size();
    int parent(int);
    int left(int);
    int right(int);
    void insert(int);
    int extractMin();
    void minHeapify(int);
    void decreaseKey(int, int);
    void deleteKey(int);
};
MinHeap::MinHeap(int capacity) {
    this->capacity = capacity;
    heap_size = 0;
    arr = new int[capacity];
}
int MinHeap::linearSearch(int data) {
    int index = -1;
    for(int i=0; i<heap_size; i++) {
        if(arr[i] == data) {
            index = i;
            break;
        }
    }
    return index;
}
void MinHeap::print() {
    for(int i=0; i<heap_size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int MinHeap::height() {
    return ceil(log2(heap_size + 1)) - 1; 
}
int MinHeap::size() {
    return heap_size;
}
int MinHeap::parent(int index) {
    return (index-1)/2;
}
int MinHeap::left(int index) {
    return (2*index + 1);
}
int MinHeap::right(int index) {
    return (2*index + 2);
}
void MinHeap::insert(int data) {
    if(heap_size == capacity) {
        cout << "error : heap overflow\n";
        return;
    }
    // insert data at the end
    arr[heap_size++] = data;
    int index = heap_size - 1;
    // Fix the min heap property if it is violated
    while(index!=0 && arr[parent(index)] > arr[index]) {
        swap(arr[index], arr[parent(index)]);
        index = parent(index);
    }
}
int MinHeap::extractMin() {
    if(heap_size <= 0) {
        return INT_MAX;
    }
    if(heap_size == 1) {
        heap_size--;
        return arr[0];
    }
    // Store the minimum value, and remove it from heap
    int root = arr[0];
    arr[0] = arr[heap_size-1];
    heap_size--;
    minHeapify(0);

    return root;
}
void MinHeap::minHeapify(int index) {
    int l = left(index);
    int r = right(index);
    int smallest = index;

    if(l < heap_size && arr[l] < arr[index]) {
        smallest = l;
    }
    if(r < heap_size && arr[r] < arr[smallest]) {
        smallest = r;
    }
    if(smallest != index) {
        swap(arr[index], arr[smallest]);
        minHeapify(smallest);
    }
}
void MinHeap::decreaseKey(int index, int data) {
    if(index > heap_size) {
        cout << "error : invalid index\n";
    }
    arr[index] = data;
    // Fix the min heap property if it is violated
    while(index!=0 && arr[parent(index)] > arr[index]) {
        swap(arr[index], arr[parent(index)]);
        index = parent(index);
    }
}
void MinHeap::deleteKey(int index) {
    decreaseKey(index, INT_MIN);
    extractMin();
}

int main() {
    MinHeap mh(10);
    mh.insert(19);
    mh.insert(56);
    mh.insert(4);
    mh.insert(45);
    mh.insert(9);
    mh.insert(12);
    cout << "min heap : "; mh.print();
    cout << "height : " << mh.height() << "\n";
    mh.extractMin();
    cout << "min heap : "; mh.print();
    mh.deleteKey(1);
    cout << "min heap : "; mh.print();
    cout << "min heap : "; mh.print();
    mh.decreaseKey(2, 100);
    cout << "min heap : "; mh.print();
    cout << "heap size : " << mh.size() << '\n';
    if(mh.linearSearch(45) != -1) {
        cout << "data found\n";
    }else {
        cout << "data not found\n";
    }

    return 0;
}
