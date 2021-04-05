// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX4_1

import java.util.*;

public class EX4_1 {
    public static void main(String[] args) {
        Dice dice1 = new Dice();
        Dice dice2 = new Dice();
        int repeat = 0;

        do {
            dice1.roll();
            dice2.roll();
            System.out.println("주사위1=" + dice1.getValue() + " 주사위2=" + dice2.getValue());
            repeat++;
        } while (dice1.getValue() + dice2.getValue() != 2);

        System.out.print("(1,1)이 나오는데 걸린 횟수 = " + repeat);
    }
}

class Dice {
    private int value;
    Random rand = new Random();

    public Dice() {
        value = 0;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int num) {
        value = num;
    }

    public void roll() {
        value = (rand.nextInt(5) + 1);
    }

}