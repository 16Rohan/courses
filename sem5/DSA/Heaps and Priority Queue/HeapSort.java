import java.util.*;

public class HeapSort {
    static void heapify(int a[], int n, int i) {
        int li = 2 * i + 1, ri = 2 * i + 2, mi = i;
        if (li < n && a[li] > a[mi])
            mi = li;
        if (ri < n && a[ri] > a[mi])
            mi = ri;
        if (i != mi) {
            int t = a[i];
            a[i] = a[mi];
            a[mi] = t;
            heapify(a, n, mi);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(a, n, i);
        }
        for (int i = n - 1; i >= 0; i--) {
            int t = a[0];
            a[0] = a[i];
            a[i] = t;
            heapify(a, i, 0);
        }
        for (int x : a)
            System.out.print(x + " ");
    }
}
