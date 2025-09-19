import java.io.*;
import java.util.*;

public class Main {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String readLine() {
        try {
            return br.readLine();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    int n, m;
    int[][] board;
    int[][] cache;

    int[] dr = {0,0,+1,-1};
    int[] dc = {+1,-1,0,0};

    int dp(int row, int col) {
        if(row == 0 && col == 0)
            return 1;
        if (!(0 <= row && row < n && 0 <= col && col < m))
            return 0;

        if (cache[row][col] != -1)
            return cache[row][col];
        
        cache[row][col] = 0;

        for(int direction=0;direction<4;++direction){
            int nr = row + dr[direction];
            int nc = col + dc[direction];

            if (!(0 <= nr && nr < n && 0 <= nc && nc < m))
                continue;
            
            if(board[nr][nc] > board[row][col])
                cache[row][col] += dp(nr, nc);
        }
        return cache[row][col];
    }

    void solve() {
        int[] input1 = Arrays.stream(readLine().split(" ")).limit(2).mapToInt(Integer::parseInt).toArray();
        n = input1[0];
        m = input1[1];

        board = new int[n][m];

        for (int i = 0; i < n; ++i) {
            int[] input2 = Arrays.stream(readLine().split(" ")).limit(m).mapToInt(Integer::parseInt).toArray();
            for (int j = 0; j < m; ++j) {
                board[i][j] = input2[j];
            }
        }

        cache = new int[n][m];
        for (var x : cache){
            Arrays.fill(x, -1);
        }
        
        System.out.print(String.valueOf(dp(n - 1, m - 1)));
    }

    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}