using namespace std;
template<typename StackType> 
class Stack {
    int top, stackSize;
    StackType *arr;
public:
    Stack() {
        top = -1;
        stackSize = 100;
        arr = new StackType[stackSize];
    }
    Stack(int size) {
        if(size < 1) {
            cout << "invalid size\n";
            return;
        }else {
            top = -1;
            stackSize = size;
            arr = new StackType[stackSize];
        }
    }
    ~Stack() {
        delete[] arr;
    }
    void push(StackType x) {
        if(isFull()) {
            resize(stackSize*2);
        }
        arr[++top] = x;
    }
    StackType pop() {
        if(isEmpty()) {
            cout << "stack underflow\n";
            return 0;
        }else {
            return arr[top--];
        }
    }
    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return (top == stackSize-1);
    }
    StackType peek() {
        if(isEmpty()) {
            cout << "stack is empty\n";
            return 0;
        }else {
            return arr[top];
        }
    }
    int size() {
        return (top+1);
    }
    int capacity() {
        return (stackSize);
    }
    void resize(int size) {
        if(size <= this->size()) {
            cout << "can't resize\n";
            return;
        }else {
            StackType *tempStack = new StackType[size];
            for(int i=0; i<this->size(); i++) {
                tempStack[i] = arr[i];
            }
            stackSize = size;
            delete[] arr;
            arr = tempStack;
        }
    }
    void display() {
        for(int i=top; i>=0; i--){
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
};
