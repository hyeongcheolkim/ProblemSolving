import java.util.*;

public class CtoF 
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        double f;
        double c;

        f = sc.nextDouble();
        c = 5.0 / 9.0 * (f - 32.0);
        System.out.print(c);
        
        sc.close();
    }
}
