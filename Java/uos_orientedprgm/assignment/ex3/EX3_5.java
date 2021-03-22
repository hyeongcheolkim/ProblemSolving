// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX3_5

import java.util.Scanner;

public class EX3_5 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            if (i == 0)
                arr[i] = 0;
            else if (i == 1)
                arr[i] = 1;
            else
                arr[i] = arr[i - 1] + arr[i - 2];
        }
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        sc.close();
    }
}
