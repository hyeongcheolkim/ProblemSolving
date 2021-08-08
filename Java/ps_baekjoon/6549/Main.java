//baekjoon ps 6549

import java.util.*;
import java.util.stream.*;
import java.io.*;
import static java.lang.Math.*;

public class Main {

    static int[] input;

    static long recursion(int lt, int rt) {
        if(lt==rt)
            return input[lt];
        int mid = (lt + rt) / 2;
        long ret = max(recursion(lt, mid), recursion(mid + 1, rt));
        int low = mid;
        int high = mid + 1;
        long height = min(input[low], input[high]);
        ret = max(ret, height * 2);
        while (lt < low || high < rt) {
            if (high < rt && (low == lt || input[low - 1] < input[high + 1])) {
                high++;
                height = min(height, input[high]);
            } else {
                low--;
                height = min(height, input[low]);
            }
            ret = max(ret, height * (high - low + 1));
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        while (true) {
            input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int n = input[0];
            if (n == 0)
                break;
            bw.write(recursion(1, n) + "\n");
        }
        bw.flush();
        bw.close();
    }
}