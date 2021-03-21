import java.util.*;

public class updowngame
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int repeat = 0;
        int guess=0;
        final int answer = (int)(Math.random()*100);

        do
        {   
            guess = sc.nextInt();
            repeat++;
            if(guess<answer)
                System.out.println("up");
            else if (guess>answer)
                System.out.println("down");
            else if (guess==answer)
                System.out.println("correct ");
        } while (guess != answer);

        System.out.print("시도횟수: " + repeat);
        sc.close();
    }   
}
