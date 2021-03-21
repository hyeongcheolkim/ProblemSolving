import java.util.*;

public class TIC_TAC_TOE {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        // set value. 3X3 Board. pos(x,y).
        char[][] board = new char[3][3];
        int x, y;
        int repeat = 0;
        char winner = 'D';

        // set board empty.
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';

        while (true) {
            // show present board.
            for (int i = 0; i < 3; i++) {
                System.out.println("  " + board[i][0] + "|  " + board[i][1] + "|  " + board[i][2]);
                if (i != 2)
                    System.out.println("---|---|---");
            }

            // input pos(x,y)
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

            // put 'X' if it's empty place
            board[x][y] = 'X';
            repeat++;

            // Check Win condition for user.
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
                    if (board[r][c] != 'X')
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

            // if win or draw. break while loop.
            if (winner == 'U')
                break;
            if (repeat == 9)
                break;

            // computer put 'O'
            outter: for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (board[i][j] == ' ') {
                        board[i][j] = 'O';
                        repeat++;
                        break outter;
                    }

            // Check Win condition for computer.
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
                    if (board[r][c] != 'O')
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

            // if win or draw. break while loop.
            if (winner == 'C')
                break;
            if (repeat == 9)
                break;
        }

        // gameover. print final board.
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
