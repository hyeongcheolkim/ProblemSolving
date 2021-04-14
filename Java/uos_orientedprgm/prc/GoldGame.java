import java.util.*;

public class GoldGame {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        Gold gold = new Gold();
        Monster monster = new Monster();
        Main main = new Main();

        System.out.println("몬스터를 피해 골드를 획득하세요! 당신의 캐릭터는 @모양입니다.");
        while (true) {
            Map.print();
            System.out.println("h:좌 j:상 k:하 l:우");
            char input = sc.nextLine().charAt(0);
            // 몬스터의 move를 후순위로 배치함으로서, 사망판정시 M가 @를 가리게 한다.
            main.move(input);
            monster.move('\0'); // 몬스터는 자동으로 움직이므로 함수인수 없음.

            // Rule:동시에 몬스터와 주인공이 골드를 가질경우, 주인공이 몬스터에 죽는걸로 판정
            if (main.compare(monster)) {
                System.out.println("몬스터를 만나 사망하였습니다...");
                Map.print();
                break;
            }
            if (gold.compare(monster)) {
                System.out.println("몬스터가 골드를 획득하였습니다...");
                Map.print();
                break;
            }
            if (gold.compare(main)) {
                System.out.println("골드를 획득하였습니다!!");
                Map.print();
                break;
            }
        }
        sc.close();
    }
}

class Map {
    static final int rowsize = 10; // 게임판의 row사이즈
    static final int columnsize = 19; // 게임판의 column사이즈
    static private char[][] map = new char[rowsize][columnsize];
    static {
        for (int i = 0; i < rowsize; i++)
            for (int j = 0; j < columnsize; j++)
                map[i][j] = ' ';
        for (int i = 0; i < rowsize; i++) {
            map[i][0] = '#';
            map[i][columnsize - 1] = '#';
        }
        for (int j = 0; j < columnsize; j++) {
            map[0][j] = '#';
            map[rowsize - 1][j] = '#';
        }
    }

    static void check(int row, int column, char character) {
        map[row][column] = character;
    }

    static void print() {
        for (int i = 0; i < rowsize; i++) {
            for (int j = 0; j < columnsize; j++)
                System.out.print(map[i][j]);
            System.out.print('\n');
        }
    }

    static char get(int row, int column) {
        return map[row][column];
    }
}

abstract class Sprite {
    int row, column;

    abstract void move(char c);

    boolean compare(Sprite obj) {
        if (this.row == obj.row && this.column == obj.column)
            return true;
        else
            return false;
    }
}

class Main extends Sprite {
    public Main() {
        row = 8;
        column = 17;
        Map.check(row, column, '@');
    }

    void move(char c) {
        if (Map.get(row, column) == '@') // 주인공이 있던곳에 다른 물체가 오지 않았으면
            Map.check(row, column, ' '); // 주인공이 있던던곳을 지운다
        boolean outofmap = false;
        switch (c) {
        case 'h':
            if (--column == 0) {
                column++;
                outofmap = true;
            }
            break;
        case 'j':
            if (--row == 0) {
                row++;
                outofmap = true;
            }
            break;
        case 'k':
            if (++row == Map.rowsize - 1) {
                row--;
                outofmap = true;
            }
            break;
        case 'l':
            if (++column == Map.columnsize - 1) {
                column--;
                outofmap = true;
            }
            break;
        default:
            System.out.println("유효하지 않은 입력입니다.");
            break;
        }
        if (outofmap)
            System.out.println("벽에 부딪혔습니다!!");
        Map.check(row, column, '@');
    }

}

class Gold extends Sprite {
    public Gold() {
        row = 3;
        column = 6;
        Map.check(row, column, 'G');
    }

    void move(char c) {
    }
}

class Monster extends Sprite {
    public Monster() {
        row = column = 7;
        Map.check(row, column, 'M');
    }

    void move(char c) {
        Random rand = new Random();
        if (Map.get(row, column) == 'M') // 몬스터가 있던곳에 다른 물체가 오지 않았다면
            Map.check(row, column, ' '); // 몬스터가 있던곳을 지운다
        if (rand.nextBoolean()) {
            row += (rand.nextBoolean()) ? 1 : -1;
            if (row == 0)
                row += 2;
            if (row == Map.rowsize - 1)
                row -= 2;
        } else {
            column += (rand.nextBoolean()) ? 1 : -1;
            if (column == 0)
                column += 2;
            if (column == Map.columnsize - 1)
                column -= 2;
        }
        Map.check(row, column, 'M');
    }
}
