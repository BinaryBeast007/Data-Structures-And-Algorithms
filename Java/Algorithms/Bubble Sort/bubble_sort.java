public class bubble_sort {
    public static void print_array(int arr[], int size) {
        for(int i=0; i<size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void bubbleSort(int arr[], int size) {
        int counter = 1;
        while(counter < size) {
            boolean swaped = false;
            for(int i=0; i<size-counter; i++) {
                if(arr[i] > arr[i+1]) {
                    int temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                    swaped = true;
                }
            }
            if(!swaped) {
                break;
            }
        }
    }
    public static void main(String[] args) {
        int[] arr = new int[] { 121, 43, 11, 34, 5, 34, 65, 567, 23, 238 };
        int size = arr.length;
        System.out.println("initial array :");
        print_array(arr, size);
        System.out.println("sorted array :");
        bubbleSort(arr, size);
        print_array(arr, size);
    }
} 
