// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX2_5

import java.util.*;

public class EX2_5
{
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);

        int x = 4080;
        int y = x << 8;
        int z = x >> 8;
        int a = x & 0xf0ff;
        int b = x ^ 0xf0ff;

        //print formatted. to hexa.
        System.out.printf("x = 0x%x\n" , x);
        System.out.printf("y = 0x%x\n" , y);
        System.out.printf("z = 0x%x\n" , z);
        System.out.printf("a = 0x%x\n" , a);
        System.out.printf("b = 0x%x\n" , b);

        sc.close();
    }
}
