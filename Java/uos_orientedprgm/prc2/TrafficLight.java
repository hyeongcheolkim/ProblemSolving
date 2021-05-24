import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class MyPanel extends JPanel implements ActionListener {
    int light_number = 0;
    boolean flag = false;

    public MyPanel() {
        setLayout(new BorderLayout());
        JButton b = new JButton("신호 변경");
        b.addActionListener(this);
        add(b, BorderLayout.SOUTH);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.BLACK);
        g.drawOval(100, 10, 100, 100);
        g.drawOval(200, 10, 100, 100);
        g.drawOval(300, 10, 100, 100);
        switch (light_number) {
            case 0:
                g.setColor(Color.RED);
                g.fillOval(100, 10, 100, 100);
                break;
            case 1:
                g.setColor(Color.ORANGE);
                g.fillOval(200, 10, 100, 100);
                break;
            case 2:
                g.setColor(Color.GREEN);
                g.fillOval(300, 10, 100, 100);
                break;
            default:
                break;
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (++light_number >= 3)
            light_number = 0;
        repaint();
    }
}

public class TrafficLight extends JFrame {
    public TrafficLight() {
        add(new MyPanel());
        setSize(600, 200);
        setTitle("신호등");
        setVisible(true);
    }
    public static void main(String[] args) {
        new TrafficLight();
    }

}
