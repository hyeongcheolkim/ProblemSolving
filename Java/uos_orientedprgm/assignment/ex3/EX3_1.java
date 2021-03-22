// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX3_1

public class EX3_1 {
    public static void main(String[] args) throws Exception {
        final int n = 5; // n은 홀수.
        int star;
        boolean flag = true;

        //blank*2+star = 5 항등식 이용
        //n부터 시작하여 1까지 star += -2. 그후 flag를 false로 바꾸어 n까지 star += 2.
        for (star = n; star <= n; star+=(flag?-2:2)){
            for (int blank = 0; blank < (n - star) / 2; blank++)
                System.out.print(" ");
            for (int i = 0; i < star; i++)
                System.out.print("*");
            System.out.print('\n');
            if(star==1)
                flag=false;
        }


    }
}
