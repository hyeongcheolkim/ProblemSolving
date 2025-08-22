import java.io.*;
import java.util.*;

public class Main {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String readLine(){
        try {
            return br.readLine();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    int n;
    long ret;
    Stack<int[]> s = new Stack<>();

    void solve(){
        n = Integer.parseInt(readLine());

        for(int idx=0;idx<n;++idx){
            int h = Integer.parseInt(readLine());

            while(!s.isEmpty() && s.peek()[1] <= h){    
                ret += idx - s.pop()[0] - 1;
            }
            s.add(new int[]{idx, h});
        }

        int lastIdx = s.peek()[0];
        while(!s.isEmpty()){
            ret += lastIdx - s.pop()[0];
        }

        System.out.print(ret);
    }
    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}