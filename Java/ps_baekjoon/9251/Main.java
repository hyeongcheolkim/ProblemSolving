import java.io.*;

public class Main {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String readLine(){
        try{
            return br.readLine();
        }catch(Exception e){
            throw new RuntimeException(e);
        }
    }

    String a;
    String b;

    int[][] dp;

    void solve(){
        a = readLine();
        b = readLine();

        char[] arr1 = a.toCharArray();
        char[] arr2 = b.toCharArray();

        dp = new int[a.length() + 1][b.length() + 1];

        for(int i=1;i<=arr1.length;++i){
            for(int j=1;j<=arr2.length;++j){
                if(arr1[i-1] == arr2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = Integer.max(dp[i-1][j], dp[i][j-1]);
            }
        }
        System.out.print(dp[arr1.length][arr2.length]);
    }
    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}