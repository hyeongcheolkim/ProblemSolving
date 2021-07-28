//baekjoon ps 14003

import java.util.*;
import java.util.stream.*;
import java.io.*;

public class Main {
    static int INF = Integer.MAX_VALUE;

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = Stream.of(br.readLine().split(" ")).limit(n).mapToInt(Integer::parseInt).toArray();
        ArrayList<Integer> lis = new ArrayList<>();
        ArrayList<Integer> res = new ArrayList<>();
        ArrayList<Pair> trace = new ArrayList<>();
        lis.add(-INF);
        for (int i = 0; i < n; i++) {
            int data = arr[i];
            if (lis.get(lis.size() - 1) < data) {
                trace.add(new Pair(lis.size(), data));
                lis.add(data);
            } else {
                int idx = Collections.binarySearch(lis, data);
                idx = idx < 0 ? idx * (-1) - 1 : idx;
                lis.set(idx, data);
                trace.add(new Pair(idx, data));
            }
        }
        for (int i = trace.size() - 1, j = lis.size() - 1; i >= 0; i--)
            if (trace.get(i).first == j) {
                res.add(trace.get(i).second);
                j--;
            }
        Collections.reverse(res);
        System.out.println(res.size());
        res.stream().forEach((e) -> System.out.print(e + " "));
    }
}