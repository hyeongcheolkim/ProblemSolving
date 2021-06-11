import java.util.*;
import java.io.*;

public class ObjectStream {
    public static void main(String[] args) throws IOException {
        ObjectInputStream in = null;
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("object.dat"));) {
            Date dd = new Date();
            System.out.println(dd);
            out.writeObject(dd);

            out.flush();
            Thread.sleep(2000);
            in = new ObjectInputStream(new FileInputStream("object.dat"));
            Date d = (Date) in.readObject();
            System.out.println(new Date());
            System.out.println(d);
        } catch (ClassNotFoundException e) {
        } catch (InterruptedException e) {
        } finally {
            if (in != null)
                in.close();
        }
    }
}
