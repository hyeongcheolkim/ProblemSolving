import java.util.Random;

public class EX3_7 {
    public static void main(String[] args) {
        Random rand = new Random();
        String[] pattern = new String[] { "Clubs", "Diamonds", "Hearts", "Spades" };
        String[] num = new String[] { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

        //Math.Random사용시 5번 시행 모두 같은 결과가 나오므로 Random 클래스 사용.
        for (int i = 0; i < 5; i++)
            System.out.println(pattern[rand.nextInt(pattern.length)] + "의 " + num[rand.nextInt(num.length)]);
    }

}
