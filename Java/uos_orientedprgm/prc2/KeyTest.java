import javax.swing.*;
import java.awt.event.*;

class KeyFrame extends JFrame implements KeyListener {
    public KeyFrame() {
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Event Test");

        JTextField tf = new JTextField(20);
        tf.addKeyListener(this);

        add(tf);
        setVisible(true);
    }

    public void keyTyped(KeyEvent e) {
        display(e, "KeyTyped");
    }

    public void keyPressed(KeyEvent e) {
        display(e, "KeyPressed");
    }

    public void keyReleased(KeyEvent e) {
        display(e, "keyReleased");
    }

    protected void display(KeyEvent e, String s) {
        char c = e.getKeyChar();
        int keycode = e.getKeyCode();

        String modifiers = e.isAltDown() + " " + e.isControlDown() + " " + e.isShiftDown();
        System.out.println(s + " " + c + " " + keycode + " " + modifiers);
    }
}

public class KeyTest {
    public static void main(String[] args) {
        KeyFrame f = new KeyFrame();
    }
}