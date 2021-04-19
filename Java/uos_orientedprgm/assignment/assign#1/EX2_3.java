// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX2_3

import java.util.*;

public class EX2_3 {
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);

        int money;
        int price;
        System.out.print("받은 금액을 입력하시오:");
        money = sc.nextInt();
        System.out.print("상품의 가격을 입력하시오:");
        price = sc.nextInt();

        System.out.println("받은돈:" + money);
        System.out.println("상품가격:" + price);
        System.out.println("부가세:" + (int) (price * 0.1)); //교수님 언급에 따라 부가세 소수점이하는 버림
        System.out.println("잔돈:" + (money - price)); //잔돈이 음수일경우 그만큼 손님에게 더 받아야 함

        sc.close();
    }
}
