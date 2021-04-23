import java.awt.*;
import javax.swing.*;

public class MyGridLayout extends JFrame {
    public MyGridLayout() {
        setTitle("GridLayoutTest");
        setSize(300, 150);
        setLayout(new GridLayout());

        add(new JButton("Button 1"));
        add(new JButton("Button 2"));
        add(new JButton("Button 3"));
        add(new JButton("B4"));
        add(new JButton("Long Button5"));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String args[]) {
        MyGridLayout f = new MyGridLayout();
    }

}
