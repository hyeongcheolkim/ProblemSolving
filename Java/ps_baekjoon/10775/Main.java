//baekjoon ps 10755

import java.util.*;
import java.util.stream.*;

public class Main {
    static int G, P;
    static int cnt = 0;
    static int[] uf;

    static int find(int num) {
        if (num == uf[num])
            return num;
        else
            return uf[num] = find(uf[num]);
    }

    static void uni(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b)
            uf[a] = b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        G = Integer.parseInt(sc.nextLine());
        P = Integer.parseInt(sc.nextLine());
        uf = Stream.iterate(0, n -> n + 1).limit(G + 1).mapToInt(Integer::intValue).toArray();
        while (P-- > 0) {
            int g = Integer.parseInt(sc.nextLine());
            int gate = find(g);
            if (gate != 0) {
                cnt++;
                uni(g, gate - 1);
            } else
                break;
        }
        System.out.print(cnt);
        sc.close();
    }
}