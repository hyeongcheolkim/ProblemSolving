import java.awt.Graphics;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.font.*;
import javax.swing.*;

public class BounceBall extends JFrame implements ActionListener{
    int x, y;
    private int xSpeed = 3, ySpeed = 3;
    private static final int WIDTH = 600;
    private static final int HEIGHT = 200;
    private static final int PERIOD = 10;

    class MyPanel extends JPanel {
        public void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.setColor(Color.ORANGE);
            g.fillOval(x, y, 40, 40);
        }
    }

    public void update() {
        x += xSpeed;
        y += ySpeed;
        if (x > WIDTH - 60 || x < 0) {
            xSpeed = -xSpeed;
        }
        if (y > HEIGHT - 80 || y < 0) {
            ySpeed = -ySpeed;
        }
    }

    public BounceBall() {
        setSize(WIDTH, HEIGHT);
        setTitle("Bounce Ball");
        setVisible(true);

        add(new MyPanel());
        Timer timer = new Timer(PERIOD, this);
        timer.start();
    }

    @Override
    public void actionPerformed(ActionEvent evt) {
        update();
        repaint();
    }

    public static void main(String[] args) {
        new BounceBall();
    }
}
