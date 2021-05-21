import java.util.*;
import java.util.Queue;

class Pair {
    int first;
    int second;
    String check;

    Pair(int first, int second, String check) {
        this.first = first;
        this.second = second;
        this.check = check;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = Integer.parseInt(sc.nextLine());
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(n, 0, n + ""));
        while (!q.isEmpty()) {
            int num = q.peek().first;
            int cnt = q.peek().second;
            String trace = q.peek().check;
            if (num == 1)
                break;
            q.remove();
            if (num % 3 == 0)
                q.add(new Pair(num / 3, cnt + 1, trace + " " + num / 3));
            if (num % 2 == 0)
                q.add(new Pair(num / 2, cnt + 1, trace + " " + num / 2));
            q.add(new Pair(num - 1, cnt + 1, trace + " " + (num - 1)));
        }
        System.out.println(q.peek().second);
        System.out.print(q.peek().check);
        sc.close();
    }
}