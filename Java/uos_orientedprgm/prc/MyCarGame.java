// import javax.swing.*;
// import java.awt.event.*;
// import java.awt.*;

// public class MyCarGame extends JFrame{
//     int img_x = 150, img_y = 150;

//     MyCarGame() {
//         setSize(600, 300);
//         JButton button = new JButton("");
//         ImageIcon icon = new ImageIcon("image.png");
//         button.setIcon(icon);
//         button.setLocation(img_x, img_y);
//         JPanel panel = new JPanel();
//         panel.add(button);
//         panel.requestFocus();
//         panel.setFocusable(true);

//         panel.addKeyListener(new KeyListener{
//             public void keyPressed(KeyEvent e){
//                 int keycode = e.getKeyCode();
//                 switch(keycode){
//                     case KeyEvent.VK_UP: img_y-=10;
//                     case KeyEvent.VK_DOWN: img_y+=10;
//                     case KeyEvent.VK_LEFT: img_x-=10;
//                     case KeyEvent.VK_RIGHT: img_x-=10;
//                 }
//                 button.setLocation(img_x,img_y);
//             }
//             public void KeyReleased(KeyEvent e){}
//             public void KeyTyped(KeyEvent e){}
//         });

//         add(panel);
//         setVisible(true)
//     }

//     public static void main(String[] args) {
//         MyCarGame g = new MyCarGame();
//     }

// }
