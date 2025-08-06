import java.io.*;
import java.util.*;

public class Main {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String readLine() {
        try {
            return br.readLine();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    void solve() {
        String str = readLine().strip();
        int k = Integer.parseInt(readLine());

        Map<Character, List<Integer>> cnt = new HashMap<>();
        for (int i = 0; i < str.length(); ++i) {
            char c = str.charAt(i);

            cnt.computeIfAbsent(c, (key) -> new ArrayList<>()).add(i);
        }
        int mini = Integer.MAX_VALUE;
        int maxi = -1;

        for (List<Integer> s : cnt.values()) {
            if (s.size() < k)
                continue;
            for (int i = 0; i <= s.size() - k; ++i) {
                int lt = i;
                int rt = i + k - 1;

                int diff = s.get(rt) - s.get(lt) + 1;

                mini = Integer.min(mini, diff);
                maxi = Integer.max(maxi, diff);
            }
        }
        if (mini == Integer.MAX_VALUE && maxi == -1)
            System.out.println(-1);
        else
            System.out.println(String.format("%d %d", mini, maxi));
    }

    void __solve() {
        int t = Integer.parseInt(readLine());
        while(t-- != 0)
            solve();
    }

    public static void main(String[] args) throws IOException {
        new Main().__solve();
    }
}