import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static String pw;
    static int dp[];
    static int MOD = 1000000;

    static public int solve(int idx) {
        if (idx == 0)
            return 1;
        if (dp[idx] != -1)
            return dp[idx];
        int pre_val = pw.charAt(idx - 1) - '0';
        int now_val = pw.charAt(idx) - '0';
        dp[idx] = 0;
        if (now_val != 0)
            dp[idx] = (dp[idx] + solve(idx - 1)) % MOD;
        if (10 <= pre_val * 10 + now_val && pre_val * 10 + now_val <= 26)
            dp[idx] = (dp[idx] + solve(idx - 2)) % MOD;
        return dp[idx];
    }

    public static void main(String[] args) throws IOException {
        pw = br.readLine().strip();
        pw = "0" + pw;
        dp = new int[pw.length()];
        Arrays.fill(dp, -1);
        int ret = solve(pw.length() - 1);
        bw.write(Integer.toString(ret));
        bw.flush();
    }
}