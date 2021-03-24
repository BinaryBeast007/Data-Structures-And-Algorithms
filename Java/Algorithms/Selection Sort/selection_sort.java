public class selection_sort {
    public static void print_array(int arr[], int size) {
        for(int i=0; i<size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void selectionSort(int arr[], int size) {
        for(int i=0; i<size-1; i++) {
            int minIdx = i;
            for(int j=i+1; j<size; j++) {
                if(arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }
    }
    public static void main(String[] args) {
        int[] arr = new int[] { 121, 43, 11, 34, 5, 34, 65, 567, 23, 238 };
        int size = arr.length;
        System.out.println("initial array :");
        print_array(arr, size);
        System.out.println("sorted array :");
        selectionSort(arr, size);
        print_array(arr, size);
    }
}
