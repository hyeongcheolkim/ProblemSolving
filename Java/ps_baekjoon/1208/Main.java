//baekjoon ps 1208

import java.util.*;
import java.io.*;
import java.util.stream.*;

public class Main {
    static int n, s;
    static long cnt = 0;
    static HashMap<Integer, Integer> map = new HashMap<>();
    static int[] input;
    static int[] arr1, arr2;

    static void dfs1(int idx, int sum) {
        if (idx == arr1.length) {
            map.putIfAbsent(sum, 0);
            map.compute(sum, (key, value) -> ++value);
            return;
        }
        dfs1(idx + 1, sum);
        dfs1(idx + 1, sum + arr1[idx]);
    }

    static void dfs2(int idx, int sum) {
        if (idx == arr2.length) {
            cnt += map.getOrDefault(s - sum, 0);
            return;
        }
        dfs2(idx + 1, sum);
        dfs2(idx + 1, sum + arr2[idx]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        n = input[0];
        s = input[1];
        input = Stream.of(br.readLine().split(" ")).limit(n).mapToInt(Integer::parseInt).toArray();
        arr1 = IntStream.of(input).limit(n / 2).toArray();
        arr2 = IntStream.of(input).skip(n / 2).toArray();
        dfs1(0, 0);
        dfs2(0, 0);
        if(s==0)
            cnt--;
        System.out.print(cnt);
    }
}