public class Stack {
    private final int MAX_SIZE = 100;
    private int top;
    private int[] arr = new int[MAX_SIZE];

    public Stack() {
        top = -1;
    }
    public boolean isEmpty() {
        return (top == -1);
    }
    public boolean isFull() {
        return (top == MAX_SIZE-1);
    }
    public void push(int x) {
        if(isFull()) {
            System.out.println("stack overflow");
        }else {
            arr[++top] = x;
        }
    }
    public int pop() {
        if(isEmpty()) {
            System.out.println("stack underflow");
            return 0;
        }else {
            return arr[top--];
        }
    }
    public int size() {
        return (top+1);
    }
    public int peek() {
        if(isEmpty()) {
            System.out.println("stack is empty");
            return 0;
        }else {
            return arr[top];
        }
    }
    public void display() {
        for(int i=top; i>=0; i--) {
            System.out.println(arr[i]);
        }
    }
    public static void main(String[] args) {
        Stack st = new Stack();
        st.push(10);
        st.push(20);
        st.push(30);
        st.push(40);
        st.pop();
        st.display();
        System.out.println("total elements : " + st.size());
        System.out.println("top element : " + st.peek());
        System.out.println("is empty : " + st.isEmpty());
        System.out.println("is full : " + st.isFull());
    }
}
