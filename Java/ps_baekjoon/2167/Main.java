import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.stream.Stream;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int n, m, k;
    static int[][] matrix, dp;

    public static void main(String[] args) throws IOException {
        int[] input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        n = input[0];
        m = input[1];
        matrix = new int[n + 1][m + 1];
        dp = new int[n + 1][m + 1];
        for (int i = 1; i <= n; ++i) {
            input = Stream.of(("0 " + br.readLine()).split(" ")).mapToInt(Integer::parseInt).toArray();
            for (int j = 1; j <= m; ++j)
                matrix[i][j] = input[j];
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i][j];
        k = Integer.parseInt(br.readLine());
        while (k-- != 0) {
            input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int i = input[0], j = input[1], x = input[2], y = input[3];
            int sum = dp[x][y] - dp[x][j - 1] - dp[i - 1][y] + dp[i - 1][j - 1];
            bw.write(String.valueOf(sum) + '\n');
        }
        bw.flush();
    }
}