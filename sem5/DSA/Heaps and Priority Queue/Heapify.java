import java.util.*;

public class Heapify {
    static void heapify(int[] arr, int n, int i) {
        // Heapifying index will be compared with its left child idx and right child idx
        // We select the max heap idx or min heap idx and swap it with the current idx.
        int li = 2 * i + 1;
        int ri = 2 * i + 2;
        int mi = i;

        if (li < n && arr[li] > arr[mi]) {
            mi = li;
        }
        if (ri < n && arr[ri] > arr[mi]) {
            mi = ri;
        }
        if (i != mi) {
            int t = arr[i];
            arr[i] = arr[mi];
            arr[mi] = t;
            heapify(arr, n, mi);
        }
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = sc.nextInt();
            int[] arr = new int[n];

            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            for (int i = n / 2 - 1; i >= 0; i--) {
                heapify(arr, n, i);
            }

            for (int i = 0; i < n; i++) {
                System.out.print(arr[i] + " ");
            }
        }
    }
}
