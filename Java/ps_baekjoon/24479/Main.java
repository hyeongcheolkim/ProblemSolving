import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, m, r, ord;
    static StringTokenizer input;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static boolean[] vst;
    static int[] order;

    static void init() throws IOException {
        input = new StringTokenizer(br.readLine());
        n = Integer.parseInt(input.nextToken());
        m = Integer.parseInt(input.nextToken());
        r = Integer.parseInt(input.nextToken());
        graph = Stream.generate(ArrayList<Integer>::new)
                .limit(n + 1)
                .collect(Collectors.toCollection(ArrayList<ArrayList<Integer>>::new));
        vst = new boolean[n + 1];
        order = new int[n + 1];
        while (m-- != 0) {
            input = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(input.nextToken());
            int to = Integer.parseInt(input.nextToken());
            graph.get(from).add(to);
            graph.get(to).add(from);
        }
    }

    static void dfs(int now_node) {
        for (var next_node : graph.get(now_node)) {
            if (vst[next_node])
                continue;
            vst[next_node] = true;
            order[next_node] = ++ord;
            dfs(next_node);
        }
    }

    public static void main(String[] args) throws IOException {
        init();
        for (var arr : graph)
            arr.sort(Integer::compare);
        vst[r] = true;
        order[r] = ++ord;
        dfs(r);
        for (int i = 1; i <= n; ++i)
            bw.write(String.valueOf(order[i]) + '\n');
        bw.flush();
    }
}