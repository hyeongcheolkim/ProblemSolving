//baekjoon ps 1450

import java.util.*;
import java.io.*;
import java.util.stream.*;

public class Main {
    static int n, c;
    static int cnt = 0;
    static int[] arr;

    static void dfs(int lt, int rt, int sum, ArrayList<Integer> al) {
        if (sum > c)
            return;
        if (lt > rt) {
            al.add(sum);
            return;
        }
        dfs(lt + 1, rt, sum, al);
        dfs(lt + 1, rt, sum + arr[lt], al);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        n = input[0];
        c = input[1];
        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();
        arr = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        dfs(0, n / 2 - 1, 0, left);
        dfs(n / 2, n - 1, 0, right);
        left.sort(Comparator.naturalOrder());
        right.sort(Comparator.naturalOrder());
        int ptrRight = right.size() - 1;
        for (int ptrLeft = 0; ptrLeft < left.size(); ptrLeft++) {
            while (ptrRight >= 0 && left.get(ptrLeft) + right.get(ptrRight) > c)
                ptrRight--;
            cnt += ptrRight + 1;
        }
        System.out.print(cnt);
    }
}