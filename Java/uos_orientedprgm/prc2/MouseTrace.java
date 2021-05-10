import javax.swing.*;
import java.awt.event.*;

public class MouseTrace extends JFrame implements MouseListener, MouseMotionListener {
    public MouseTrace() {
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("MouseTrace");

        JPanel panel = new JPanel();
        panel.addMouseListener(this);
        panel.addMouseMotionListener(this);
        add(panel);
        setVisible(true);
    }

    public void mousePressed(MouseEvent e) {
        display("Mouse Pressed (# of clicks: " + e.getClickCount() + ")", e);
    }

    public void mouseReleased(MouseEvent e) {
        display("Mouse Released (# of clicks: " + e.getClickCount() + ")", e);
    }

    public void mouseEntered(MouseEvent e) {
        display("Mouse Entered", e);
    }

    public void mouseExited(MouseEvent e) {
        display("Mouse Exited", e);
    }

    public void mouseClicked(MouseEvent e) {
        display("Mouse Clicked (# of clicks: " + e.getClickCount() + ")", e);
    }

    public void mouseDragged(MouseEvent e) {
        display("Mouse Dragged", e);
    }

    public void mouseMoved(MouseEvent e) {
        display("Mouse Moved", e);
    }

    protected void display(String s, MouseEvent e) {
        System.out.println(s + "X-" + e.getX() + " Y-" + e.getY());
    }
    
    public static void main(String[] args) {
        MouseTrace f = new MouseTrace();
    }
}
