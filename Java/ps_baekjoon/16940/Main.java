import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.util.stream.Stream;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int n;
    static ArrayList<ArrayList<Integer>> graph;
    static Queue<Integer> q, order;
    static boolean[] vst;

    static void init() throws IOException {
        n = Integer.parseInt(br.readLine());
        graph = new ArrayList<ArrayList<Integer>>();
        order = new LinkedList<Integer>();
        q = new LinkedList<Integer>();
        for (int i = 0; i < n + 1; ++i)
            graph.add(new ArrayList<Integer>());
        vst = new boolean[n + 1];
        for (int i = 0; i < n - 1; ++i) {
            var input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int from = input[0];
            int to = input[1];
            graph.get(from).add(to);
            graph.get(to).add(from);
        }
        var input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        for (var e : input)
            order.add(e);
    }

    static void printZeroAndExit() throws IOException {
        bw.write("0");
        bw.flush();
        System.exit(0);
    }

    public static void main(String[] args) throws IOException {
        init();
        if (order.poll() != 1)
            printZeroAndExit();
        vst[1] = true;
        q.add(1);
        while (!q.isEmpty()) {
            Set<Integer> next_nodes = new HashSet<Integer>();
            int now_node = q.poll();
            for (var next_node : graph.get(now_node)) {
                if (vst[next_node])
                    continue;
                vst[next_node] = true;
                next_nodes.add(next_node);
            }
            for (int i = 0; i < next_nodes.size(); ++i) {
                if (order.isEmpty())
                    printZeroAndExit();
                int node = order.poll();
                if (next_nodes.contains(node))
                    q.add(node);
                else
                    printZeroAndExit();
            }
        }
        bw.write("1");
        bw.flush();
    }
}