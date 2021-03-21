// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX2_4

import java.util.*;

public class EX2_4
{
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("정수(음수제외)를 입력하시오:");
        int num;
        num = sc.nextInt();
        
        String str = "";
        
        while (num!=0)
        {
            str = num % 2 + str;
            num /= 2;
        }
        System.out.print(str);
        
        sc.close();
    }
}
