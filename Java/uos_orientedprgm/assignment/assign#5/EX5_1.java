import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class EX5_1 extends JFrame implements ActionListener {
    public JPanel panel;
    public JButton[] buttons;
    public String turn;

    public EX5_1() {
        setTitle("tic_tac_toe");
        setSize(600, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        panel = new JPanel();
        panel.setLayout(new GridLayout(3, 3));
        buttons = new JButton[9];
        turn = "X";
        for (int i = 0; i < 9; i++) {
            buttons[i] = new JButton("");
            buttons[i].addActionListener(this);
            panel.add(buttons[i]);
        }
        add(panel);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        for (int i = 0; i < 9; i++)
            if (e.getSource() == buttons[i] && buttons[i].getText().equals("") == true) {
                if (turn == "X") {
                    buttons[i].setText("X");
                    turn = "O";
                } else {
                    buttons[i].setText("O");
                    turn = "X";
                }
            }
    }

    public static void main(String[] args) {
        new EX5_1();
    }
}
