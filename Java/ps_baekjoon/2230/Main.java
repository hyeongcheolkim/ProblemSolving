import java.util.*;
import java.util.stream.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    private int n, m;
    private List<Integer> arr = new ArrayList<>();
    private int ret = Integer.MAX_VALUE / 2;

    private String readLine() {
        try {
            return br.readLine();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private void solve() {

        var input = Arrays.stream(readLine().split(" "))
                .limit(2)
                .mapToInt(Integer::parseInt)
                .toArray();
        n = input[0];
        m = input[1];

        for (int i = 0; i < n; ++i)
            arr.add(Integer.parseInt(readLine()));

        arr.sort(Comparator.naturalOrder());

        int lt = 0;
        int rt = 0;

        while (lt < arr.size() && rt < arr.size()) {
            int diff = arr.get(rt) - arr.get(lt);

            if (diff >= m) {
                ret = Integer.min(ret, diff);
                ++lt;
            } else {
                ++rt;
            }
        }
        System.out.print(ret);
    }

    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}