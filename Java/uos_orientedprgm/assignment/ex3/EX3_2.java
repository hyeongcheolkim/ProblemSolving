public class EX3_2 {
    public static void main(String[] args) throws Exception {

        boolean[] arr = new boolean[100+1];
        for (int i = 2; i <= 100; i++)
            arr[i] = true;

        for (int i = 2; i*i < 100; i++)
            for (int j = i + i; j <= 100; j += i)
                arr[j] = false;

        for (int i = 2; i <= 100; i++)
            if(arr[i])
                System.out.print(i+" ");
    }
}
