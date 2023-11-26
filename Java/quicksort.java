import java.util.Scanner;

public class QuickSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the size of the array
        System.out.println("Enter the size of the array: ");
        int size = scanner.nextInt();

        // Input the array elements
        int[] array = new int[size];
        System.out.println("Enter the array elements:");
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }

        // Perform quicksort
        quickSort(array, 0, size - 1);

        // Display the sorted array
        System.out.println("Sorted Array:");
        for (int value : array) {
            System.out.print(value + " ");
        }
    }

    // Quicksort algorithm
    private static void quickSort(int[] array, int low, int high) {
        if (low < high) {
            // Find the partition index such that elements smaller than pivot are on the left,
            // and elements greater than pivot are on the right.
            int partitionIndex = partition(array, low, high);

            // Recursively sort the subarrays
            quickSort(array, low, partitionIndex - 1);
            quickSort(array, partitionIndex + 1, high);
        }
    }

    // Helper method to partition the array
    private static int partition(int[] array, int low, int high) {
        // Choose the rightmost element as the pivot
        int pivot = array[high];

        // Index of the smaller element
        int i = low - 1;

        // Traverse through the array and rearrange elements
        for (int j = low; j < high; j++) {
            if (array[j] <= pivot) {
                i++;

                // Swap array[i] and array[j]
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        // Swap array[i+1] and array[high] (pivot)
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        // Return the partition index
        return i + 1;
    }
}
