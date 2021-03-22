// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX3_6

import java.util.*;

public class EX3_6 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        // 3X3게임판을 설정한다. x와 y는 보드판의 좌표 변수다.
        char[][] board = new char[3][3];
        int x, y;
        int repeat = 0;
        char winner = 'D';

        // 게임판을 빈칸으로 초기세팅한다.
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';

        while (true) {
            // 현재 게임판 상태를 보임.
            for (int i = 0; i < 3; i++) {
                System.out.println("  " + board[i][0] + "|  " + board[i][1] + "|  " + board[i][2]);
                if (i != 2)
                    System.out.println("---|---|---");
            }

            // x,y좌표를 입력받는다. 조건에 맞지 않을경우 다시 입력받음.
            while (true) {
                System.out.print("다음 수의 좌표를 입력하시오: ");
                x = sc.nextInt();
                y = sc.nextInt();
                if (!(0 <= x && x < 3 && 0 <= y && y < 3)) {
                    System.out.println("좌표의 범위는 Row:0~2 Column:0~2 입니다. 다시입력하세요.");
                    continue;
                }
                if (board[x][y] != ' ') {
                    System.out.println("이미 표시된 위치입니다. 다시입력하세요.");
                    continue;
                }
                break;
            }

            // 입력받은 좌표위치에 User가 X를 놓는다.
            board[x][y] = 'X';
            repeat++;

            // 유저 승리조건을 체크한다.
            for (int r = 0; r < 3; r++) {
                boolean flag = true;
                for (int c = 0; c < 3; c++)
                    if (board[r][c] != 'X')
                        flag = false;
                if (flag)
                    winner = 'U';
            }
            for (int r = 0; r < 3; r++) {
                boolean flag = true;
                for (int c = 0; c < 3; c++)
                    if (board[c][r] != 'X')
                        flag = false;
                if (flag)
                    winner = 'U';
            }
            boolean flag_U0 = true;
            for (int i = 0; i < 3; i++)
                if (board[i][i] != 'X')
                    flag_U0 = false;
            if (flag_U0)
                winner = 'U';
            boolean flag_U1 = true;
            for (int i = 0; i < 3; i++)
                if (board[2 - i][i] != 'X')
                    flag_U1 = false;
            if (flag_U1)
                winner = 'U';

            // 유저가 승리하거나 비겼을경우 반복문 break.
            if (winner == 'U')
                break;
            if (repeat == 9)
                break;

            // 컴퓨터가 O를 놓는다. 무조건 (0,0)부터 (2,2)까지 순서대로. 빈칸에 놓게 설정. 
            outter: for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (board[i][j] == ' ') {
                        board[i][j] = 'O';
                        repeat++;
                        break outter;
                    }

            // 컴퓨터 승리조건 체크.
            for (int r = 0; r < 3; r++) {
                boolean flag = true;
                for (int c = 0; c < 3; c++)
                    if (board[r][c] != 'O')
                        flag = false;
                if (flag)
                    winner = 'C';
            }
            for (int r = 0; r < 3; r++) {
                boolean flag = true;
                for (int c = 0; c < 3; c++)
                    if (board[c][r] != 'O')
                        flag = false;
                if (flag)
                    winner = 'C';
            }
            boolean flag_C0 = true;
            for (int i = 0; i < 3; i++)
                if (board[i][i] != 'O')
                    flag_C0 = false;
            if (flag_C0)
                winner = 'C';
            boolean flag_C1 = true;
            for (int i = 0; i < 3; i++)
                if (board[2 - i][i] != 'O')
                    flag_C1 = false;
            if (flag_C1)
                winner = 'C';

            // 컴퓨터가 이기거나 비길경우 break.
            if (winner == 'C')
                break;
            if (repeat == 9)
                break;
        }

        //게임 종료. 종료후 게임판을 보여주고. winner변수에 따라 승자를 표시. 비겼을경우 draw.
        for (int i = 0; i < 3; i++) {
            System.out.println("  " + board[i][0] + "|  " + board[i][1] + "|  " + board[i][2]);
            if (i != 2)
                System.out.println("---|---|---");
        }
        if (winner == 'U')
            System.out.print("Game Over!!! User Win!!");
        else if (winner == 'C')
            System.out.print("Game Over!!! Computer Win!!");
        else if (winner == 'D')
            System.out.print("DRAW!!!");
        sc.close();
    }
}
