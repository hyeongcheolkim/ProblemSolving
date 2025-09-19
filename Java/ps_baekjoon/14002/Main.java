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

    int n, answer = 1;
    int[] arr;
    int[] dp;
    int[] trace;
    int root = 0;
    void solve(){
        n = Integer.parseInt(readLine());
        arr = Arrays.stream(readLine().split(" "))
                .limit(n)
                .mapToInt(Integer::parseInt)
                .toArray();
        
        dp = new int[n];
        trace = new int[n];
        Arrays.fill(dp, 1);
        Arrays.fill(trace, -1);
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(arr[i] > arr[j] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    trace[i] = j;
                    
                    if(answer < dp[i]){
                        answer = dp[i];
                        root = i;
                    }
                }
            }
        }
        System.out.println(answer);
        Deque<Integer> tmp = new ArrayDeque<>();
        tmp.addFirst(arr[root]);
        while(trace[root] != -1){
            root = trace[root];
            tmp.addFirst(arr[root]);
        }

        for(var x : tmp){
            System.out.print(x + " ");
        }

    }
    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}