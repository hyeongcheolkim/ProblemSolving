import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class ComboBoxTest extends JFrame implements ActionListener {
    JLabel label;

    public ComboBoxTest() {
        setTitle("콤보박스");
        setSize(400, 200);

        String[] animals = { "dog", "cat", "bird" };
        JComboBox animallist = new JComboBox(animals);
        animallist.setSelectedIndex(0);
        animallist.addActionListener(this);

        label = new JLabel();
        changePicture(animals[animallist.getSelectedIndex()]);
        add(animallist, BorderLayout.NORTH);
        add(label, BorderLayout.CENTER);
        label.setHorizontalAlignment(JLabel.CENTER);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

    public void actionPerformed(ActionEvent e) {
        JComboBox cb = (JComboBox) e.getSource();
        String name = (String) cb.getSelectedItem();
        changePicture(name);
    }

    public void changePicture(String name) {
        ImageIcon icon = new ImageIcon("./"+name+".png");
        label.setIcon(icon);
        if (icon != null) {
            label.setText(null);
        } else {
            label.setText("이미지가 발견되지 않았습니다.");
        }
    }

    public static void main(String[] args) {
        new ComboBoxTest();
    }
}