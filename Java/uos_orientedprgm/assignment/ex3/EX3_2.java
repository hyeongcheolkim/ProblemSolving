public class EX3_2 {
    public static void main(String[] args) throws Exception {
        int n = 100 + 1;
        boolean[] arr = new boolean[n];
        for (int i = 2; i < n; i++)
            arr[i] = true;

        for (int i = 2; i*i < n; i++)
            for (int j = i + i; j <= n; j += i)
                arr[j] = false;

        for (int i = 2; i < n; i++)
            if(arr[i])
                System.out.print(i+" ");
    }
}
