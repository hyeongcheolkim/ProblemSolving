import java.awt.Graphics;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class EX6_2 extends JFrame {
    Car[] car;

    public EX6_2() {
        setTitle("CarGame");
        setSize(600, 300);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    class Car extends JPanel {
        private int x, y;

        Car(int x, int y) {
            this.x = x;
            this.y = y;
        }

        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            

        }
    }
}
