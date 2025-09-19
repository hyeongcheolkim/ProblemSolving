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

    void solve(){
        int n = Integer.parseInt(readLine());
        List<int[]> arr = new ArrayList<>();
        int res = 1;

        for(int i=0;i<n;++i){
            int[] input = Arrays.stream(readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

            arr.add(input);
        }
        arr.sort(Comparator.comparingInt(x -> x[0]));
        int[] dp = new int[arr.size()];
        Arrays.fill(dp, 1);

        for(int i=0;i<arr.size();++i){
            for(int j=0;j<i;++j){
                if(arr.get(j)[1] < arr.get(i)[1])
                    dp[i] = Integer.max(dp[i], dp[j] + 1);
                    res = Integer.max(res, dp[i]);
            }
        }
        for(var x : arr){
            System.out.println(Arrays.toString(x));
        }
        System.out.println(Arrays.toString(dp));
        System.out.print(n - res);
    }
    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}