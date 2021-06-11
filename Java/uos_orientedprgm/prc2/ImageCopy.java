import java.util.*;
import java.io.*;

public class ImageCopy {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        System.out.print("원본 파일 이름을 입력하시오. :");
        String inputFileName = scan.next();
        System.out.print("복사 파일 이름을 입력하시오. :");
        String outputFileName = scan.next();
        try (InputStream is = new FileInputStream(inputFileName);
                OutputStream os = new FileOutputStream(outputFileName);) {
            int c;
            while ((c = is.read()) != -1) {
                os.write(c);
            }
        }
        System.out.println(inputFileName + "을" + outputFileName + "로 복사하였습니다.");
        scan.close();
    }
}