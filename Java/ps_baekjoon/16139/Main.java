import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static String str;
    static int q;
    static ArrayList<HashMap<Character, Integer>> dp;

    public static void main(String[] args) throws IOException {
        str = br.readLine();
        q = Integer.parseInt(br.readLine());
        dp = Stream.generate(HashMap<Character, Integer>::new)
                .limit(str.length() + 1)
                .collect(Collectors.toCollection(ArrayList<HashMap<Character, Integer>>::new));
        for (int i = 0; i < str.length(); ++i)
            dp.get(i + 1).put(str.charAt(i), 1);
        for (int i = 1; i <= str.length(); ++i)
            for (char c = 'a'; c <= 'z'; ++c)
                dp.get(i).put(c, dp.get(i).getOrDefault(c, 0) + dp.get(i - 1).getOrDefault(c, 0));
        while (q-- != 0) {
            var sb = new StringTokenizer(br.readLine());
            var c = sb.nextToken().charAt(0);
            var from = Integer.parseInt(sb.nextToken()) + 1;
            var to = Integer.parseInt(sb.nextToken()) + 1;
            bw.write(String.valueOf(dp.get(to).getOrDefault(c, 0) - dp.get(from - 1).getOrDefault(c, 0)) + '\n');
        }
        bw.flush();
    }
}