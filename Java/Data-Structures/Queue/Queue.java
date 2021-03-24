public class Queue {
    private int front, rear, arr[], maxSize = 100;
    Queue() {
        front = rear = -1;
        arr = new int[maxSize];
    }
    public boolean isEmpty() {
        return (front == -1 && rear == -1);
    }
    public boolean isFull() {
        return (rear == maxSize);
    }
    public void enqueue(int x) {
        if(isFull()) {
            System.out.println("queue overflow");
            return;
        }else if(isEmpty()) {
            front = rear = 0;
        }else {
            ++rear;
        }
        arr[rear] = x;
    }
    public int dequeue() {
        if(isEmpty()) {
            System.out.println("queue underflow");
            return -1;
        }else if(front == rear) {
            int x = arr[front];
            front = rear = -1;
            return x;
        }else {
            return arr[front++];
        }
    }
    public int size() {
        return (rear-front+1);
    }
    public int Front() {
        return arr[front];
    }
    public void display() {
        for(int i=front; i<=rear; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Queue q = new Queue();
        q.enqueue(10);
        q.enqueue(20);
        q.dequeue();
        q.enqueue(50);
        q.enqueue(100);
        System.out.println("Size : " + q.size());
        System.out.println("Front element : " + q.Front());
        System.out.println("Display queue : ");
        q.display();
    }
}
