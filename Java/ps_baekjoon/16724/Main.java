//baekjoon ps 16724

import java.util.*;
import java.util.stream.*;
import java.io.*;

class Pos {
    public int row, col;

    Pos(int row, int col) {
        this.row = row;
        this.col = col;
    }

    boolean isEqualTo(Pos obj) {
        return (this.row == obj.row) && (this.col == obj.col);
    }
}

public class Main {
    static int n, m;
    static int cnt;
    static int[] input;
    static ArrayList<String[]> map = new ArrayList<String[]>();
    static Pos[][] uf;

    static Pos find(Pos data) {
        int row = data.row;
        int col = data.col;
        if (uf[row][col].isEqualTo(data))
            return data;
        Pos nextPos = find(uf[row][col]);
        return uf[row][col] = uf[nextPos.row][nextPos.col];
    }

    static boolean uni(Pos a, Pos b) {
        a = find(a);
        b = find(b);
        if (a.isEqualTo(b))
            return false;
        else {
            uf[a.row][a.col] = b;
            return true;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        input = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        n = input[0];
        m = input[1];
        cnt = n * m;
        for (int i = 0; i < n; i++)
            map.add(Stream.of(br.readLine().split("")).limit(m).toArray(String[]::new));
        uf = new Pos[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                uf[i][j] = new Pos(i, j);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int nowRow = i;
                int nowCol = j;
                int nextRow = 0;
                int nextCol = 0;
                char direct = map.get(nowRow)[nowCol].charAt(0);
                switch (direct) {
                    case 'U':
                        nextRow = nowRow - 1;
                        nextCol = nowCol;
                        break;
                    case 'D':
                        nextRow = nowRow + 1;
                        nextCol = nowCol;
                        break;
                    case 'L':
                        nextRow = nowRow;
                        nextCol = nowCol - 1;
                        break;
                    case 'R':
                        nextRow = nowRow;
                        nextCol = nowCol + 1;
                        break;
                    default:
                        break;
                }
                if (uni(new Pos(nowRow, nowCol), new Pos(nextRow, nextCol)))
                    cnt--;
            }
        System.out.print(cnt);
    }
}