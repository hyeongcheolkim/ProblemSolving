import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class TestField extends JFrame{
    private JButton button;
    private JTextField text, result;

    public TestField() {
        setSize(300, 150);
        setTitle("제곱 계산하기");
        MyListener listener = new MyListener();

        JPanel panel = new JPanel();
        panel.add(new JLabel("숫자 입력: "));
        text = new JTextField(15);
        text.addActionListener(listener);
        panel.add(text);

        panel.add(new JLabel("제곱한 값: "));
        result = new JTextField(15);
        result.setEditable(false);
        panel.add(result);

        button = new JButton("OK");
        button.addActionListener(listener);
        panel.add(button);
        add(panel);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

    private class MyListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
                int value = Integer.parseInt(text.getText());
                result.setText("" + value * value);
                text.requestFocus();
        }
    }

    public static void main(String[] args) {
        new TestField();
    }
}
