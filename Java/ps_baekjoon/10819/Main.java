//baekjoon ps 10819

import java.util.*;
import java.util.stream.*;
import java.io.*;

public class Main {
    static int n;
    static int[] arr;
    static int res = Integer.MIN_VALUE;
    static ArrayDeque<Integer> dq = new ArrayDeque<>();
    static boolean[] check;

    static void dfs(int level) {
        if (level == n) {
            int sum = 0;
            int[] temp = dq.stream().mapToInt(Integer::intValue).toArray();
            for (int i = 0; i < temp.length - 1; i++)
                sum += Math.abs(temp[i] - temp[i + 1]);
            res = Integer.max(res, sum);
            return;
        }
        for (int i = 0; i < arr.length; i++)
            if (!check[i]) {
                check[i] = true;
                dq.addLast(arr[i]);
                dfs(level + 1);
                check[i] = false;
                dq.removeLast();
            }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = Stream.of(br.readLine().split(" ")).limit(n).mapToInt(Integer::parseInt).toArray();
        check = new boolean[n];
        dfs(0);
        System.out.print(res);
    }
}