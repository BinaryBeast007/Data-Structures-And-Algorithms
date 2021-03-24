public class insertion_sort {
    public static void print_array(int arr[], int size) {
        for(int i=0; i<size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void insertionSort(int arr[], int size) {
        for(int i=1; i<size; i++) {
            int value = arr[i];
            int hole = i;
            while(hole>0 && arr[hole-1] > value) {
                arr[hole] = arr[hole-1];
                hole--;
            }
            arr[hole] = value;
        }
    }
    public static void main(String[] args) {
        int[] arr = new int[] { 121, 43, 11, 34, 5, 34, 65, 567, 23, 238 };
        int size = arr.length;
        System.out.println("initial array :");
        print_array(arr, size);
        System.out.println("sorted array :");
        insertionSort(arr, size);
        print_array(arr, size);
    }
}
