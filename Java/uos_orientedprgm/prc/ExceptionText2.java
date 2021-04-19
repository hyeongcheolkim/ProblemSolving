import java.io.*;


public class ExceptionText2 {
    public static void main(String[] args) throws IOException {
        FileReader fr = new FileReader("test.txt");
        char[] a = new char[50];
        fr.read(a);
        for (char c : a)
            System.out.print(c);
        try {
            method1();
        } catch (MyException e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
            System.out.println("예외 테스트");
        }
        fr.close();

    }

    public static void method1() throws MyException {
        throw new MyException();
    }
}

class MyException extends Exception {
    public MyException() {
        super("사용자 정의 예외");
    }

}
