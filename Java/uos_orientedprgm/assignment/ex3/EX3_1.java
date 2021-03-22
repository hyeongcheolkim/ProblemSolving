// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX3_1

public class EX3_1 {
    public static void main(String[] args) throws Exception {
        int n = 5;// 홀수만 가능.
        for(int i=n;i>=1;i-=2)
        {
            for(int j=0;j<(n-i);j++)
                System.out.print(" ");
            for(int j=0;j<i;i++)
                System.out.print("*");
            System.out.print('\n');
        }
        
    }
}
