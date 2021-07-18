//baekjoon ps 1766

import java.io.*;
import java.util.*;
import java.util.stream.*;

public class Main {
    static int n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder res = new StringBuilder();
        int[] input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        n = input[0];
        m = input[1];
        ArrayList<ArrayList<Integer>> map = new ArrayList<ArrayList<Integer>>() {
            {
                for (int i = 0; i < n + 1; i++)
                    add(new ArrayList<Integer>());
            }
        };
        int[] degree = new int[n + 1];
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        while (m-- > 0) {
            int from, to;
            int[] edge = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            from = edge[0];
            to = edge[1];
            map.get(from).add(to);
            degree[to]++;
        }
        for (int i = 1; i <= n; i++)
            if (degree[i] == 0)
                pq.add(i);
        while (!pq.isEmpty()) {
            int now = pq.poll();
            res.append(now + " ");
            for (int i = 0; i < map.get(now).size(); i++) {
                int next = map.get(now).get(i);
                if (--degree[next] == 0)
                    pq.add(next);
            }
        }
        System.out.print(res);
    }
}