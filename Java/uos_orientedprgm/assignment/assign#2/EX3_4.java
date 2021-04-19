// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX3_4

import java.util.*;

public class EX3_4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("연산을 입력하세요: ");
        char opt = sc.next().charAt(0);
        System.out.print("숫자 2개를 입력하세요: ");
        double a = sc.nextDouble();
        double b = sc.nextDouble();

        //스위치문을 이용한 계산기 연산.
        switch (opt) {
        case '+':
            System.out.printf("%.1f + %.1f = %.1f", a, b, a + b);
            break;
        case '-':
            System.out.printf("%.1f - %.1f = %.1f", a, b, a - b);
            break;
        case '*':
            System.out.printf("%.1f * %.1f = %.1f", a, b, a * b);
            break;
        case '/':
            if (b == 0) {
                System.out.print("inf"); //b=0일때 inf값이 나오도록 예외처리.
                break;
            }
            System.out.printf("%.1f / %.1f = %.1f", a, b, a / b);
            break;
        default:
            System.out.printf("정의되지 않은 연산자입니다. (+)(-)(*)(/)연산만 가능합니다.)");
        }

        sc.close();
    }

}
