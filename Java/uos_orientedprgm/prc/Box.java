import java.util.*;

public class Box
{
    public static void main(String[] args)
    {
        double w, h, area, perimeter;

        Scanner input = new Scanner(System.in);

        System.out.print("사각형의 가로를입력하시오:");
        w = input.nextDouble();
        System.out.print("사각형의 세로를입력하시오:");
        h = input.nextDouble();
        area = w * h;
        perimeter = 2.0 * (w + h);

        System.out.println("사각형의 넓이는" + area);
        System.out.println("사각형의 둘레는" + perimeter);
        input.close();
    }    
}
