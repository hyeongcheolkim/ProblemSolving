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
    PriorityQueue<int[]> gpq = new PriorityQueue<>((a,b) ->{
        if(a[0] == b[0])
            return b[1] - a[1];
        return b[0] - a[0];
    });
    PriorityQueue<int[]> lpq = new PriorityQueue<>((a,b) ->{
        if(a[0] == b[0])
            return a[1] - b[1];
        return a[0] - b[0];
    });

    static 

    Set<int[]> s = new HashSet<>();
    Map<Integer, Integer> difficulty = new HashMap<>();

    StringBuilder sb = new StringBuilder();


    void solve(){
        int n = Integer.parseInt(readLine());

        while(n-- != 0){
            int[] inputs = Arrays.stream(readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int p = inputs[0];
            int l = inputs[1];

            gpq.add(new int[]{l, p});
            lpq.add(new int[]{l, p});

            difficulty.put(p, l);
        }

        int m = Integer.parseInt(readLine());

        while(m-- != 0){
            String[] inputs = readLine().split(" ");
            String operator = inputs[0];

            if("add".equals(operator)){
                int p = Integer.parseInt(inputs[1]);
                int l = Integer.parseInt(inputs[2]);

                gpq.add(new int[]{l, p});
                lpq.add(new int[]{l, p});

                difficulty.put(p, l);
            }
            if("recommend".equals(operator)){
                int x = Integer.parseInt(inputs[1]);

                if(x == 1){
                    while(s.contains(gpq.peek())){
                        gpq.poll();
                    }
                    int[] peek = gpq.peek();
                    sb.append(peek[1]).append('\n');
                }
                if(x == -1){
                    while(s.contains(lpq.peek())){
                        lpq.poll();
                    }
                    int[] peek = lpq.peek();
                    sb.append(peek[1]).append('\n');
                }
            }
            if("solved".equals(operator)){
                int p = Integer.parseInt(inputs[1]);
                int l = difficulty.get(p);
                s.add(new int[]{l, p});
            }
        }
        System.out.print(sb.toString());
    }
    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}