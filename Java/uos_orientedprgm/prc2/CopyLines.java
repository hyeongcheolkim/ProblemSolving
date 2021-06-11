import java.util.*;
import java.io.*;

public class CopyLines {
    public static void main(String[] args) {
        try (BufferedReader in = new BufferedReader(new FileReader("test.txt"));
                PrintWriter out = new PrintWriter(new FileWriter("output.txt"));) {
            String line;
            while ((line = in.readLine()) != null) {
                out.println(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
