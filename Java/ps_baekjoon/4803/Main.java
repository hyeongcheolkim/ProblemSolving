//baekjoon ps 4803

import java.util.*;
import java.io.*;
import java.util.stream.*;

public class Main {

    static int[] uf;

    static int find(int num) {
        if (uf[num] == num)
            return num;
        return uf[num] = find(uf[num]);
    }

    static boolean uni(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            uf[a] = b;
            return true;
        } else
            return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder res = new StringBuilder();
        for (int testCase = 1;; testCase++) {
            int[] input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int n = input[0];
            int m = input[1];
            if (n == 0 && m == 0)
                break;
            uf = Stream.iterate(0, x -> x + 1).limit(n + 1).mapToInt(Integer::intValue).toArray();
            ArrayList<Integer> notTree = new ArrayList<>();
            while (m-- > 0) {
                input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
                int from = input[0];
                int to = input[1];
                if (!uni(from, to))
                    notTree.add(from);
            }
            HashSet<Integer> set = new HashSet<>();
            for (int i = 1; i <= n; i++)
                set.add(find(i));
            for (final Integer e : notTree) {
                set.remove(find(e));
            }
            int cnt = set.size();
            switch (cnt) {
                case 0:
                    res.append("Case " + testCase + ": " + "No trees." + "\n");
                    break;
                case 1:
                    res.append("Case " + testCase + ": " + "There is one tree." + "\n");
                    break;
                default:
                    res.append("Case " + testCase + ": " + "A forest of " + cnt + " trees." + "\n");
                    break;
            }
        }
        System.out.print(res);
    }
}