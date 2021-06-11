import java.awt.Graphics;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class EX6_1 extends JFrame {

    int number1, number2;
    Dice[] dice;

    public EX6_1() {
        setTitle("DiceGame");
        setSize(600, 300);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(1, 2));
        number1 = number2 = 6;
        dice = new Dice[2];
        dice[0] = new Dice(100, 100, Color.WHITE, number1);
        dice[1] = new Dice(100, 100, Color.WHITE, number2);
        add(dice[0]);
        add(dice[1]);
    }

    class Dice extends JPanel {
        private int x, y;
        private Color color;
        private int number;

        public Dice(int x, int y, Color color, int num) {
            this.x = x;
            this.y = y;
            this.color = color;
            this.number = num;
            setSize(300, 300);
            Random random = new Random();
            this.addMouseListener(new MouseAdapter() {
                public void mouseClicked(MouseEvent e) {
                    for (int i = 0; i < dice.length; i++) {
                        dice[i].number = random.nextInt(6) + 1;
                        dice[i].paint();
                    }
                }
            });
            repaint();
        }

        public void paint() {
            repaint();
        }

        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.drawRect(x, y, 50, 50);
            g.setColor(color);
            g.fillRect(x, y, 50, 50);
            switch (number) {
                case 1:
                    g.drawRect(x + 20, y + 20, 5, 5);
                    g.setColor(Color.BLACK);
                    g.fillRect(x + 20, y + 20, 5, 5);
                    break;
                case 2:
                    g.drawRect(x + 10, y + 20, 5, 5);
                    g.drawRect(x + 40, y + 20, 5, 5);
                    g.setColor(Color.BLACK);
                    g.fillRect(x + 10, y + 20, 5, 5);
                    g.fillRect(x + 40, y + 20, 5, 5);
                    break;
                case 3:
                    g.drawRect(x + 10, y + 10, 5, 5);
                    g.drawRect(x + 20, y + 20, 5, 5);
                    g.drawRect(x + 30, y + 30, 5, 5);
                    g.setColor(Color.BLACK);
                    g.fillRect(x + 10, y + 10, 5, 5);
                    g.fillRect(x + 20, y + 20, 5, 5);
                    g.fillRect(x + 30, y + 30, 5, 5);
                    break;
                case 4:
                    g.drawRect(x + 10, y + 10, 5, 5);
                    g.drawRect(x + 10, y + 10, 5, 5);
                    g.drawRect(x + 40, y + 30, 5, 5);
                    g.drawRect(x + 40, y + 30, 5, 5);
                    g.setColor(Color.BLACK);
                    g.fillRect(x + 10, y + 10, 5, 5);
                    g.fillRect(x + 10, y + 10, 5, 5);
                    g.fillRect(x + 40, y + 30, 5, 5);
                    g.fillRect(x + 40, y + 30, 5, 5);
                    break;
                case 5:
                    g.drawRect(x + 10, y + 10, 5, 5);
                    g.drawRect(x + 10, y + 10, 5, 5);
                    g.drawRect(x + 30, y + 20, 5, 5);
                    g.drawRect(x + 40, y + 30, 5, 5);
                    g.drawRect(x + 40, y + 30, 5, 5);
                    g.setColor(Color.BLACK);
                    g.fillRect(x + 10, y + 10, 5, 5);
                    g.fillRect(x + 10, y + 10, 5, 5);
                    g.fillRect(x + 30, y + 20, 5, 5);
                    g.fillRect(x + 40, y + 30, 5, 5);
                    g.fillRect(x + 40, y + 30, 5, 5);
                    break;
                case 6:
                    g.drawRect(x + 10, y + 10, 5, 5);
                    g.drawRect(x + 10, y + 20, 5, 5);
                    g.drawRect(x + 10, y + 30, 5, 5);
                    g.drawRect(x + 30, y + 10, 5, 5);
                    g.drawRect(x + 30, y + 20, 5, 5);
                    g.drawRect(x + 30, y + 30, 5, 5);
                    g.setColor(Color.BLACK);
                    g.fillRect(x + 10, y + 10, 5, 5);
                    g.fillRect(x + 10, y + 20, 5, 5);
                    g.fillRect(x + 10, y + 30, 5, 5);
                    g.fillRect(x + 30, y + 10, 5, 5);
                    g.fillRect(x + 30, y + 20, 5, 5);
                    g.fillRect(x + 30, y + 30, 5, 5);
                    break;
                default:
                    break;
            }
        }
    }

    public static void main(String[] args) {
        new EX6_1();
    }
}
