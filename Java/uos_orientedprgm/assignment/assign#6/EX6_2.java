import java.awt.Graphics;
import javax.swing.*;
import java.awt.*;

public class EX6_2 extends JFrame {

    Car[] car;
    final int TIME = 500;

    public EX6_2() {
        setTitle("CarGame");
        setSize(1200, 600);
        setResizable(false);
        setVisible(true);
        setLayout(new GridLayout(3, 1));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        car = new Car[3];
        for (int i = 0; i < car.length; i++) {
            car[i] = new Car(0);
            add(car[i]);
        }
        for (int i = 0; i < TIME; i++)
            for (Car obj : car) {
                obj.move(2);
                try {
                    Thread.sleep(1);
                } catch (InterruptedException e) {
                    System.out.println("Thread sleep err");
                    System.out.print(e.getStackTrace());
                }
            }
    }

    class Car extends JPanel {
        private int x;

        Car(int x) {
            this.x = x;
        }

        public void move(int dx) {
            this.x += dx;
            repaint();
        }

        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.setColor(Color.RED);
            g.fillRect(90 + x, 80, 40, 30);
            g.fillOval(80 + x, 120, 20, 20);
            g.fillOval(120 + x, 120, 20, 20);
            g.setColor(Color.ORANGE);
            g.fillRect(70 + x, 100, 80, 25);
        }
    }

    public static void main(String[] args) {
        new EX6_2();
    }

}
