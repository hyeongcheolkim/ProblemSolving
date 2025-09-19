import java.io.*;
import java.util.*;

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
    char[] arr1;
    char[] arr2;

    int[][] dp;

    int fnc(int len1, int len2){
        if(dp[len1][len2] != -1)
            return dp[len1][len2];
        dp[len1][len2] = 0;

        if(len1 == 0 || len2 == 0)
            return dp[len1][len2] = 0;
        
        if(arr1[len1 - 1] == arr2[len2 - 1])
            return dp[len1][len2] = fnc(len1-1, len2-1)+ 1;
        else
            return dp[len1][len2] = Integer.max(fnc(len1, len2-1), fnc(len1-1, len2));
        
    }

    void solve(){
        a = readLine();
        b = readLine();

        arr1 = a.toCharArray();
        arr2 = b.toCharArray();

        dp = new int[arr1.length + 1][arr2.length + 1];
        for(var x : dp)
            Arrays.fill(x, -1);

        System.out.println(fnc(arr1.length, arr2.length));

    }
    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}