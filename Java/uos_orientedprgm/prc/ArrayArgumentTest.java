import java.util.Arrays;

// import java.util.*;

public class ArrayArgumentTest {

    public static void addArray(double[] list, int len) {
        for (int i=0;i<list.length;i++)
            list[i]++;
        len++;
    }
    public static void main(String[] args) throws Exception {
        double[] a = { 1.1, 2.2, 3.3, 4.4, 5.5 };

        System.out.println(Arrays.toString(a) + " " + a.length);
        addArray(a, a.length);
        System.out.println(Arrays.toString(a)+" "+a.length);
    }
}
