import javax.swing.*;
import java.awt.event.*;

public class MouseTest extends JFrame {
    int img_x = 150;
    int img_y = 150;

    public MouseTest(){
        setSize(600,300);
        JButton button = new JButton("");
        ImageIcon icon = new ImageIcon("img.png");
        button.setIcon(icon);
        JPanel panel = new JPanel();
        panel.add(button);
        panel.requestFocus();
        panel.setFocusable(true);

        panel.addMouseListener(new MouseListener() {
            public void mousePressed(MouseEvent e) {
                img_x = e.getX();
                img_y = e.getY();
                button.setLocation(img_x, img_y);
            }
            public void mouseReleased(MouseEvent e){}
            public void mouseEntered(MouseEvent e){}
            public void mouseExited(MouseEvent e){}
            public void mouseClicked(MouseEvent e){}
        });
        add(panel);
        setVisible(true);
    }

    public static void main(String[] args) {
        MouseTest t = new MouseTest();
    }
}
