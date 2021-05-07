// import javax.swing.*;
// import java.awt.event.*;
// import java.awt.*;
// import java.util.*;

// public class SimpleGame extends JFrame {
//     int n1, n2, n3;
//     JButton button1, button2, button3;

//     public SimpleGame() {
//         setTitle("Simple Game Machine");
//         setSize(300, 150);
//         JPanel panel = new JPanel();
//         button1 = new JButton("" + n1);
//         panel.add(button1);
//         button2 = new JButton("" + n2);
//         panel.add(button2);
//         button3 = new JButton("" + n3);
//         panel.add(button3);
//         panel.requestFocus();
//         panel.setFocusable(true);

//         panel.addKeyListener(new KeyListener() {
//             public void KeyPressed(KeyEvent e) {
//                 int keycode = e.getKeyCode();
//                 if (keycode == KeyEvent.VK_ENTER) {
//                     n1 = (int) (Math.random() * 10);
//                     n2 = (int) (Math.random() * 10);
//                     n3 = (int) (Math.random() * 10);
//                     button1.setText("" + n1);
//                     button2.setText("" + n2);
//                     button3.setText("" + n3);
//                 }
//             }

//             public void KeyReleased(KeyEvent e) {
//             }

//             public void keyTyped(Keyevent e) {
//             }
//         });
//         add(panel);
//         setVisible(true);
//     }

//     public static void main(String[] args) {
//         SimpleGame g = new SimpleGame();
//     }
// }