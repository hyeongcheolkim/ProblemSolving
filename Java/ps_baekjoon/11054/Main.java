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

    int n;
    int[] arr;
    int[] dp1, dp2;

    void solve(){
        n = Integer.parseInt(readLine());
        arr = Arrays.stream(readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        dp1 = new int[arr.length];
        dp2 = new int[arr.length];
        Arrays.fill(dp1, 1);
        Arrays.fill(dp2, 1);

        for(int i=0;i<dp1.length;++i){
            for(int j=0;j<i;++j){
                if(arr[j] < arr[i])
                    dp1[i] = Integer.max(dp1[i] , dp1[j] + 1);
            }
        }
        for(int i=dp1.length - 1;i>=0;--i){
            for(int j=dp1.length - 1;j>i;--j){
                if(arr[j] < arr[i])
                    dp2[i] = Integer.max(dp2[i], dp2[j] + 1);
            }
        }

        int maxi = 1;
        for(int i=0;i<arr.length;++i)
            maxi = Integer.max(maxi, dp1[i] + dp2[i] - 1);
        System.out.print(maxi);

    }
    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}