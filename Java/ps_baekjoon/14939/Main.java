//baekjoon ps 14939

import java.io.*;
import java.util.function.*;
import java.util.stream.*;

public class Main {
    static final int SIZE = 10;
    static final int INF = Integer.MAX_VALUE;
    static char[][] Map = new char[SIZE + 2][SIZE + 2];
    static int res = INF;

    static int fnc(boolean[] check) {
        int cnt = 0;
        char[][] temp = Stream.of(Map).map(char[]::clone).toArray(char[][]::new);
        BiConsumer<Integer, Integer> OnOffBulb = (row, col) -> {
            final int[] dr = { 0, 0, 0, +1, -1 };
            final int[] dc = { 0, +1, -1, 0, 0 };
            for (int i = 0; i < dr.length; i++) {
                if (temp[row + dr[i]][col + dc[i]] == '#')
                    temp[row + dr[i]][col + dc[i]] = 'O';
                else
                    temp[row + dr[i]][col + dc[i]] = '#';
            }
        };
        for (int col = 1; col <= SIZE; col++)
            if (check[col]) {
                OnOffBulb.accept(1, col);
                cnt++;
            }
        for (int row = 2; row <= SIZE; row++)
            for (int col = 1; col <= SIZE; col++)
                if (temp[row - 1][col] == 'O') {
                    OnOffBulb.accept(row, col);
                    cnt++;
                }
        for (int col = 1; col <= SIZE; col++)
            if (temp[SIZE][col] != '#')
                cnt = INF;
        return cnt;
    }

    static void dfs(int cursor, boolean[] check) {
        if (cursor == 11) {
            int cnt = fnc(check);
            res = Integer.min(res, cnt);
            return;
        }
        dfs(cursor + 1, check.clone());
        check[cursor] = true;
        dfs(cursor + 1, check.clone());
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int row = 1; row <= SIZE; row++) {
            String[] input = br.readLine().split("");
            for (int col = 1; col <= SIZE; col++)
                Map[row][col] = input[col - 1].charAt(0);
        }
        boolean[] check = new boolean[SIZE + 1];
        for (int i = 0; i < check.length; i++)
            check[i] = false;
        dfs(1, check.clone());
        if (res == INF)
            System.out.print(-1);
        else
            System.out.print(res);
    }
}