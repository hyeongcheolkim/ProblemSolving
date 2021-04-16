public class ExceptionText {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 6, 7, 9 };

     
        try {
            for (int i = 0; i <= arr.length; i++)
                System.out.print(arr[i]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("예외");
        } finally {
            System.out.println("최종");
        }

    }

}
