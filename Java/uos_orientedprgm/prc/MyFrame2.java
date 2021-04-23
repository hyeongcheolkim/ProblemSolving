import java.awt.*;
import javax.swing.*;

public class MyFrame2 extends JFrame{
    public MyFrame2() {
        setTitle("BoarderLayoutTest");
        setSize(300, 150);
        setLayout(new BorderLayout());

        JButton b1 = new JButton("NORTH");
        JButton b2 = new JButton("SOUTH");
        JButton b3 = new JButton("EAST");
        JButton b4 = new JButton("WEST");
        JButton b5 = new JButton("CENTER");

        add(b1, BorderLayout.NORTH);
        add(b2, BorderLayout.SOUTH);
        add(b3, BorderLayout.EAST);
        add(b4, BorderLayout.WEST);
        add(b5, BorderLayout.CENTER);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String args[]) {
        MyFrame2 f = new MyFrame2();
    }
}
