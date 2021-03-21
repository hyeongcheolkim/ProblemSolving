import java.util.*;

public class Arraytest {
    public static void main(String[] args)
    {
        int[][] arr=
        {
            {10,20,30},
            {40,50},
            {60,70,80}
        };

        for(int i=0;i<arr.length;i++)
        {
            System.out.println(arr[i]);
            System.out.println(Arrays.toString(arr[i]));
        }
        String str = Arrays.toString(arr[0]);
        str += "hi";
        System.out.print(str);
    }
}
