class NotFoundException extends Exception {
    public NotFoundException() {
        super("사용자 정의 예외");
    }
}

public class ExceptionPrc {
    public static int searchArray(int[] arr, int key) throws NotFoundException {
        for (int i = 0; i < arr.length; i++)
            if (key == arr[i])
                return i;
        throw new NotFoundException();
    }
    public static void main(String[] args) {
        int[] arr = { 3, 1, 5, 9, 6 };
        try {
            System.out.println(searchArray(arr, 8));
        } catch (NotFoundException e) {
            System.out.print("찾는 key가 배열안에 없습니다");
        }
    }
}
