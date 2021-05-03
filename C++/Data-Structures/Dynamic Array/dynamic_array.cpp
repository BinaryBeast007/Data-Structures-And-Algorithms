#include<iostream>
using namespace std;

template<class T> class DynamicArray {
    T *arr;
    int capacity, size;
public:
    // DynamicArray();
    DynamicArray(const int&);
    void push(const T&);
    void insert(const int&, const T&);
    void erase(const int&);
    int search(const T&);
    void resize(const int&);
    void print();
};

// template<class T> DynamicArray<T>::DynamicArray() {
//     this->size = 0;
//     this->capacity = 0;
// }
template<class T> DynamicArray<T>::DynamicArray(const int &capacity) {
    // initialize size, capacity & the array
    this->size = 0;
    this->capacity = capacity;
    arr = new T[capacity];
}
template<class T> void DynamicArray<T>::insert(const int &pos, const T &data) {
    // validating the position
    if(pos >= 0 && pos < size+1 && size+1 < capacity) {
        // shifting all elements 1 position to the right 
        // for making space for the data
        for(int i=size+1; i>pos; i--) {
            arr[i] = arr[i-1];
        }
        arr[pos] = data;    // inserting the data
        size++; // increasing the size
    }else {
        cout << "error : invalid position or capacity exceeded\n";
    }
}
template<class T> void DynamicArray<T>::push(const T &data) {
    // incase of overflow 
    if(size+1 >= capacity) {
        resize(size*2); // resize the array with twice the size
    }
    arr[size++] = data; // push the data
}
template<class T> void DynamicArray<T>::resize(const int &resize) {
    // validating resize variable
    if(resize > size) {
        // creating new temporary array
        T *temp_arr = new T[resize];
        // copying all the elements in the new temporary array
        for(int i=0; i<size; i++) {
            temp_arr[i] = arr[i];
        }
        capacity = resize;  // changing the capacity
        delete arr; // delete the old array 
        arr = temp_arr; // assign new temporary array to the old one
    }else {
        cout << "error : invalid size\n";
    }
}
template<class T> void DynamicArray<T>::erase(const int &pos) {
    // validating position
    if(pos >= 0 && pos < size) {
        // shifting all elements 1 position to the left 
        // for occupy the deleted space
        for(int i=pos; i<size; i++) {
            arr[i] = arr[i+1];
        }
        size--; // decreasing the size
    }else {
        cout << "error : invalid position\n";
    }
}
template<class T> int DynamicArray<T>::search(const T &data) {
    int index = -1;
    // linear search
    for(int i=0; i<size; i++) {
        if(arr[i] == data) {
            index = i;
            break;
        }
    }
    return index;
}
template<class T> void DynamicArray<T>::print() {
    // printing all element till size
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


int main() {
    DynamicArray<int> arr(5);
    arr.push(10);
    arr.push(20);
    arr.push(30);
    arr.push(40);
    arr.push(50);
    arr.resize(10);
    arr.push(60);
    arr.push(70);
    arr.insert(1, 999);
    arr.erase(0);

    arr.print();
    int index = arr.search(50);
    if(index != -1) {
        cout << "element found at index " << index << "\n";
    }else {
        cout << "element not found\n";
    }

    return 0;
}
