//baekjoon ps 2658

import java.util.*;
import java.util.stream.*;
import java.io.*;

class Pair implements Comparable<Pair> {
    int first, second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public int compareTo(Pair obj) {
        return this.first - obj.first;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Pair[] lines = new Pair[n];
        ArrayList<Pair> trace = new ArrayList<Pair>();
        ArrayList<Integer> arr, res;
        res = new ArrayList<>();
        arr = new ArrayList<>();
        arr.add(0);
        for (int i = 0; i < n; i++) {
            int[] input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            lines[i] = new Pair(input[0], input[1]);
        }
        Arrays.sort(lines);
        for (int i = 0; i < n; i++) {
            int idx = lines[i].first;
            int data = lines[i].second;
            if (arr.get(arr.size() - 1) < data) {
                trace.add(new Pair(arr.size(), idx));
                arr.add(data);
            } else {
                int ptr = Collections.binarySearch(arr, data);
                if (ptr < 0)
                    ptr = -ptr - 1;
                arr.set(ptr, data);
                trace.add(new Pair(ptr, idx));
            } 
        }
        for (int i = trace.size() - 1, j = arr.size() - 1; i >= 0; i--) {
            if (trace.get(i).first == j)
                j--;
            else
                res.add(trace.get(i).second);
        }
        Collections.sort(res);
        System.out.println(n - (arr.size() - 1));
        res.stream().forEach(System.out::println);
    }
}
