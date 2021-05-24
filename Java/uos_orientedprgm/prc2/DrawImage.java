import javax.swing.*;
import java.awt.*;

public class DrawImage extends JFrame {
    Image img;
    int pos_x = 150, pos_y = 50;

    public DrawImage() {
        ImageIcon icon = new ImageIcon("dog.png");
        img = icon.getImage();
        setSize(500, 200);
        add(new MyPanel(), BorderLayout.CENTER);
        setVisible(true);
        JPanel panel = new JPanel();
        Button b1 = new Button("왼쪽이동");
        Button b2 = new Button("오른쪽이동");

        b1.addActionListener(e -> {
            pos_x -= 10;
            repaint();
        });
        b2.addActionListener(e -> {
            pos_x += 10;
            repaint();
        });
        panel.add(b1);
        panel.add(b2);
        add(panel, BorderLayout.SOUTH);
    }

    class MyPanel extends JPanel{
        public void paintComponent(Graphics g){
            super.paintComponent(g);
            g.drawImage(img, pos_x, pos_y, this);
        }
    }

    public static void main(String[] args){
        new DrawImage();
    }
}