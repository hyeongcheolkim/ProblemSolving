import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.event.*;


public class RadioButtonTest extends JFrame implements ActionListener {
    private JRadioButton small, medium, large;
    private JLabel text;
    private JPanel topPanel, sizePanel, resultPanel;

    public RadioButtonTest() {
        setTitle("라디오 버튼 테스트");
        setSize(300, 150);

        topPanel = new JPanel();
        topPanel.add(new JLabel("어떤 크기의 커피를 주문하시겠습니까?"));
        add(topPanel, BorderLayout.NORTH);

        sizePanel = new JPanel();
        small = new JRadioButton("Small Size");
        medium = new JRadioButton("medium Size");
        large = new JRadioButton("large Size");

        ButtonGroup size = new ButtonGroup();
        size.add(small);
        size.add(medium);
        size.add(large);

        small.addActionListener(this);
        medium.addActionListener(this);
        large.addActionListener(this);
        sizePanel.add(small);
        sizePanel.add(medium);
        sizePanel.add(large);
        add(sizePanel, BorderLayout.CENTER);
        resultPanel = new JPanel();
        text = new JLabel("크기가 선택되지 않았습니다.");
        text.setForeground(Color.RED);
        resultPanel.add(text);
        add(resultPanel, BorderLayout.SOUTH);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == small) {
            text.setText("Small 크기가 선택되었습니다.");
        }
        if (e.getSource() == medium) {
            text.setText("medium 크기가 선택되었습니다.");
        }
        if (e.getSource() == large) {
            text.setText("large 크기가 선택되었습니다.");
        }
    }
    
    public static void main(String[] args) {
        new RadioButtonTest();
    }
}
