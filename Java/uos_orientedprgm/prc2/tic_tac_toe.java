import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class tic_tac_toe extends JFrame{
    private JPanel panel;
    private JButton[] buttons;
    private String turn;

    public tic_tac_toe() {
        setTitle("tic_tac_toe");
        setSize(600, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        panel = new JPanel();
        panel.setLayout(new GridLayout(3, 3));
        JButton[] buttons = new JButton[9];
        turn = "X";
        
        ActionListener Listener = new ActionListener() {
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
        };
        for (int i = 0; i < 9; i++) {
            buttons[i] = new JButton("");
            panel.add(buttons[i]);
            buttons[i].addActionListener(Listener);
        }
        add(panel);
        setVisible(true);
    }
    public static void main(String[] args) {
        tic_tac_toe game = new tic_tac_toe();
    }
}
