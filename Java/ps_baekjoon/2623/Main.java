//baekjoon ps 2623

import java.util.*;
import java.util.stream.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] input;
        input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int n = input[0];
        int m = input[1];
        ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>() {
            {
                for (int i = 0; i < n + 1; i++)
                    add(new ArrayList<Integer>());
            }
        };
        int[] degree = new int[n + 1];
        ArrayList<Integer> res = new ArrayList<Integer>();
        Queue<Integer> Q = new LinkedList<>();
        while (m-- != 0) {
            input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int num = input[0];
            int[] arr = IntStream.of(input).skip(1).limit(num).toArray();
            for (int i = 0; i < arr.length - 1; i++)
                for (int j = i + 1; j < arr.length; j++) {
                    graph.get(arr[i]).add(arr[j]);
                    degree[arr[j]]++;
                }
        }
        for (int i = 1; i <= n; i++)
            if (degree[i] == 0)
                Q.add(i);
        while (!Q.isEmpty()) {
            int now = Q.poll();
            res.add(now);
            for (int i = 0; i < graph.get(now).size(); i++) {
                int next = graph.get(now).get(i);
                degree[next]--;
                if (degree[next] == 0)
                    Q.add(next);
            }
        }
        if(res.size()==n)
            res.stream().forEach(System.out::println);
        else
            System.out.print(0);
    }
}