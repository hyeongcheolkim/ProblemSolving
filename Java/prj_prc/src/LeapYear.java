import java.util.*;

public class LeapYear 
{
    public static void main(String[] args)
    {   
        Scanner sc = new Scanner(System.in);
        int year;
        boolean isLeapYear;

        System.out.print("년을 입력하세요");
        year = sc.nextInt();

        isLeapYear = (year%4==0) && (year%100!=0);

        System.out.println(year + "=" + isLeapYear);
        sc.close();
    }
}
