import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class CalculatorFrame extends JFrame {
    private JPanel panel;
    private String[] labels = { "Backspace", "", "", "CE", "C", "7", "8", "9", "/", "sqrt", "4", "5", "6", "x", "%",
            "1", "2", "3", "-", "1/x", "0", "+/-", ".", "+", "=", };

    public CalculatorFrame() {
        setTitle("Calculator");
        setSize(600, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        panel = new JPanel();
        panel.setBackground(Color.yellow);
        panel.setLayout(new GridLayout(0, 5, 3, 3));

        JButton[] buttons = new JButton[25];
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) {
                buttons[i * 5 + j] = new JButton(labels[i * 5 + j]);
                panel.add(buttons[i * 5 + j]);
            }

        add(panel);
        setVisible(true);
    }

    public static void main(String[] args) {
        CalculatorFrame f = new CalculatorFrame();
    }
}
