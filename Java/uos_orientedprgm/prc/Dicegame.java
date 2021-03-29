import java.util.*;

public class Dicegame {
    public static void main(String[] args) throws Exception {
        Dice dice1 = new Dice();
        Dice dice2 = new Dice();
        int repeat=0;
        dice1.setValue(0);
        dice2.setValue(0);

        do{
            dice1.roll();
            dice2.roll();
            System.out.println("주사위 1=" + dice1.getValue() + " 주사위2=" + dice2.getValue());
            repeat++;
        } while (dice1.getValue() + dice2.getValue() != 2);
        
        System.out.print("(1,1)이 나오는데 걸린 횟수 = " + repeat);
    }
}

class Dice {
    private int value;
    Random rand = new Random();

    int getValue() {
        return value;
    }

    void setValue(int num) {
        value = num;
    }

    void roll(){
        value = (rand.nextInt(5) + 1);
    }
}
