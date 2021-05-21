import java.awt.Graphics;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.font.*;
import javax.swing.*;

public class MyFrame extends JFrame {
    int x, y;

    public MyFrame() {
        setTitle("Basic Painting");
        setSize(600, 200);
        add(new MyPanel());
        setVisible(true);
    }

    class MyPanel extends JPanel {
        public MyPanel() {
            addMouseListener(new MouseAdapter() {
                public void mousePressed(MouseEvent e) {
                    x = e.getX();
                    y = e.getY();
                    repaint();
                }
            });
        }

        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.setColor(Color.ORANGE);
            g.fillRect(x, y, 100, 100);
        }

    }

    public static void main(String[] args) {
        new MyFrame();
    }
}
