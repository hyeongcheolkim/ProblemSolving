// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX5_1

import java.util.Scanner;

public class EX5_1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        final int SIZE = 10;
        int[] seat = new int[SIZE];
        int cnt = 0;
        System.out.println("===============================");
        System.out.println("-1을 입력하면 예약을 종료합니다");
        while (true) {
            System.out.println("===============================");
            System.out.print("좌석번호| ");
            for (int i = 0; i < SIZE; i++) {
                System.out.print(i + " ");
            }
            System.out.println("\n===============================");
            System.out.print("예약여부| ");
            for (int i = 0; i < SIZE; i++) {
                System.out.print(seat[i] + " ");
            }
            System.out.println("\n===============================");
            if (cnt == 10) {
                System.out.println(">좌석이 꽉찼습니다. 예약이 불가능합니다<");
                break;
            }
            int num;
            System.out.print("몇번째 좌석을 예약하시겠습니까? : ");
            num = sc.nextInt();
            if (num == -1)
            {
                System.out.print("예약을 종료합니다.");
                break;
            }
            if (!(0 <= num && num <= 9)) {
                System.out.println(">0과 9사이의 좌석을 골라주십시오<");
                continue;
            }
            if (seat[num] == 1) {
                System.out.println(">이미 예약된 자리입니다. 다른자리를 골라주세요<");
                continue;
            }
            seat[num] = 1;
            System.out.println(">"+num + "자리로 예약 완료되었습니다<");
            cnt++;
        }
        sc.close();
    }
}
