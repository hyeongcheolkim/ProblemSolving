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

    int n, maxiDay, ret;
    List<int[]> arr = new ArrayList<>();
    PriorityQueue<int[]> pq = new PriorityQueue<>((a, b)->{
        return b[0] - a[0];
    });

    void solve(){
        n = Integer.parseInt(readLine());
        
        for(int i=0;i<n;++i){
            int[] input = Arrays.stream(readLine().split(" "))
                            .mapToInt(Integer::parseInt)
                            .toArray();
            
            maxiDay = Integer.max(maxiDay, input[1]);
            arr.add(input);
        }

        arr.sort(Comparator.comparingInt(x -> x[1]));
        for(int today = maxiDay; today > 0; --today){
            while(!arr.isEmpty() && arr.get(arr.size() - 1)[1] == today){
                pq.add(arr.get(arr.size() - 1));
                arr.remove(arr.size() - 1);
            }

            if(!pq.isEmpty()){
                ret += pq.poll()[0];
            }
        }

        System.out.print(ret);
    }
    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}