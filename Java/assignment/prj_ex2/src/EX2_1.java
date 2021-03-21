// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX2_1

import java.util.*;

public class EX2_1
{
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        
        int orange;
        System.out.print("오렌지의 개수를 입력하시오:");
        orange = sc.nextInt();
        
        System.out.print(orange / 10 + "박스가 필요하고 " + orange % 10 + "개가 남습니다.");
        
        sc.close();
    }
}