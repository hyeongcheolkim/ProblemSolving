// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX2_2

import java.util.*;

public class EX2_2
{
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);

        double mile;
        System.out.print("마일을 입력하시오: ");
        mile = sc.nextDouble();
        
        System.out.print(mile + "마일은 " + mile * 1.609 + "킬로미터입니다.");

        sc.close();
    }
}
