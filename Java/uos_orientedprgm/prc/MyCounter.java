import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class MyCounter extends JFrame {
    private JButton button;
    private JLabel label;
    int counter = 0;

    public MyCounter() {
        setSize(400, 150);
        setTitle("이벤트 예제");
        setLayout(new FlowLayout());
        button = new JButton("증가");
        label = new JLabel("현재의 카운터값: " + counter);

        // class MyListener implements ActionListener {
        //     public void actionPerformed(ActionEvent e) {
        //         counter++;
        //         label.setText("현재의 카운터값: " + counter);
        //     }
        // }
        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                counter++;
                label.setText("현재의 카운터값: " + counter);
            } 
        });

        add(label);
        add(button);
        setVisible(true);
    }

    public static void main(String[] args) {
        MyCounter f = new MyCounter();
    }

}
