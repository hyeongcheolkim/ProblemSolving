import java.io.*;
import java.util.*;

public class Main {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String readLine() {
        try {
            return br.readLine();
        } catch (Exception e) {
            return null;
        }
    }

    int n, m, cnt;
    char[][] board;
    int sr, sc;
    int[] dr = { 0, 0, +1, -1 };
    int[] dc = { +1, -1, 0, 0 };
    boolean[][] vst;

    void solve() {
        int[] input = Arrays.stream(readLine().split(" "))
                .mapToInt(Integer::parseInt)
                .toArray();
        n = input[0];
        m = input[1];

        board = new char[n][m];
        vst = new boolean[n][m];

        for (int i = 0; i < n; ++i) {
            String line = readLine();
            for (int j = 0; j < m; ++j) {
                board[i][j] = line.charAt(j);
                if (board[i][j] == 'I') {
                    sr = i;
                    sc = j;
                }
            }
        }

        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[] { sr, sc });
        vst[sr][sc] = true;

        while (!q.isEmpty()) {
            int[] poll = q.poll();
            int r = poll[0];
            int c = poll[1];

            for (int direction = 0; direction < 4; ++direction) {
                int nr = r + dr[direction];
                int nc = c + dc[direction];

                if (!(0 <= nr && nr < n && 0 <= nc && nc < m))
                    continue;
                if (vst[nr][nc])
                    continue;
                if(board[nr][nc] == 'X')
                    continue;

                if(board[nr][nc] == 'P')
                    ++cnt;

                vst[nr][nc] = true;
                q.add(new int[] { nr, nc });
            }
        }
        if(cnt == 0)
            System.out.print("TT");
        else
            System.out.print(cnt);
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}