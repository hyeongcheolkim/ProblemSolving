import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.stream.Stream;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static class Pair implements Comparable<Pair> {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair that) {
            if (this.first != that.first)
                return this.first - that.first;
            else
                return this.second -that.second;
        }
    }

    static final int INF = Integer.MAX_VALUE / 2;
    static int n, v, e, A, B, res;
    static int[] members;
    static ArrayList<ArrayList<Pair>> graph;

    static void init() throws IOException {
        var input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        n = input[0];
        v = input[1];
        e = input[2];
        input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        A = input[0];
        B = input[1];
        members = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        graph = new ArrayList<ArrayList<Pair>>();
        for (int i = 0; i < v + 1; ++i)
            graph.add(new ArrayList<Pair>());
        for (int i = 0; i < e; ++i) {
            input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int a = input[0];
            int b = input[1];
            int l = input[2];
            graph.get(a).add(new Pair(l, b));
            graph.get(b).add(new Pair(l, a));
        }
    }

    static int[] getMinDistance(int startNode) {
        int[] dist = new int[v + 1];
        Arrays.fill(dist, INF);
        var pq = new PriorityQueue<Pair>();
        pq.add(new Pair(0, startNode));
        dist[startNode] = 0;
        while (!pq.isEmpty()) {
            int inCost = pq.peek().first;
            int nowNode = pq.poll().second;
            if (dist[nowNode] < inCost)
                continue;
            for (final var next : graph.get(nowNode)) {
                int outCost = next.first;
                int nextNode = next.second;
                int nextCost = inCost + outCost;
                if (nextCost < dist[nextNode]) {
                    dist[nextNode] = nextCost;
                    pq.add(new Pair(nextCost, nextNode));
                }
            }
        }
        return Arrays.stream(dist).map(x -> (x == INF ? -1 : x)).toArray();
    }

    public static void main(String[] args) throws IOException {
        init();
        var distFromA = getMinDistance(A);
        var distFromB = getMinDistance(B);
        for (final var member : members)
            res += distFromA[member] + distFromB[member];
        bw.write(Integer.toString(res));
        bw.flush();
    }
}