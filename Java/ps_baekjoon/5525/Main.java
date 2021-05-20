import java.util.*;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n, m;
        int res = 0;
        n = Integer.parseInt(sc.nextLine());
        m = Integer.parseInt(sc.nextLine());
        String input = sc.nextLine();
        char pre = 'O';
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            char c = input.charAt(i);
            if (c == 'I') {
                if (pre == 'I') {
                    pre = 'I';
                    cnt = 1;
                } else {
                    pre = 'I';
                    cnt++;
                    if (cnt >= 2 * n + 1)
                        res++;
                }
            } else {
                if (pre == 'I') {
                    pre = 'O';
                    cnt++;
                } else {
                    pre = 'O';
                    cnt = 0;
                }
            }
        }
        System.out.print(res);
        sc.close();
    }
}