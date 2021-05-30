import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class EX5_3 extends JFrame implements ActionListener {
    private JPanel HelloPanel, TypePanel, ToppingPanel, SizePanel, ActionPanel;
    private JTextField cost;
    private JRadioButton combo, potato, bulgogi, pimang, cheese, peperoni, bacon, small, medium, large;
    private int cost1, cost2, cost3;

    public EX5_3() {
        setTitle("피자 주문");
        setSize(500, 250);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        cost1 = cost2 = cost3 = 0;

        TypePanel = new JPanel();
        ToppingPanel = new JPanel();
        SizePanel = new JPanel();
        HelloPanel = new JPanel();
        ActionPanel = new JPanel();

        TypePanel.setBorder(BorderFactory.createTitledBorder("종류"));
        ToppingPanel.setBorder(BorderFactory.createTitledBorder("추가토핑"));
        SizePanel.setBorder(BorderFactory.createTitledBorder("크기"));

        TypePanel.setLayout(new GridLayout(3, 1));
        ToppingPanel.setLayout(new GridLayout(4, 1));
        SizePanel.setLayout(new GridLayout(3, 1));

        HelloPanel.add(new JLabel("자바 피자에 오신것을 환영합니다."));

        combo = new JRadioButton("콤보 (10000원)", false);
        potato = new JRadioButton("포테이토 (11000원)", false);
        bulgogi = new JRadioButton("불고기 (12000원)", false);
        pimang = new JRadioButton("피망 (1000원)", false);
        cheese = new JRadioButton("치즈 (2000원)", false);
        peperoni = new JRadioButton("페페로니 (3000원)", false);
        bacon = new JRadioButton("베이컨 (4000원)", false);
        small = new JRadioButton("Small (5000원)", false);
        medium = new JRadioButton("Medium (6000원)", false);
        large = new JRadioButton("Large (7000원)", false);

        combo.addActionListener(this);
        potato.addActionListener(this);
        bulgogi.addActionListener(this);
        pimang.addActionListener(this);
        cheese.addActionListener(this);
        peperoni.addActionListener(this);
        bacon.addActionListener(this);
        small.addActionListener(this);
        medium.addActionListener(this);
        large.addActionListener(this);

        ButtonGroup Type, Topping, Size;
        Type = new ButtonGroup();
        Topping = new ButtonGroup();
        Size = new ButtonGroup();
        Type.add(combo);
        Type.add(potato);
        Type.add(bulgogi);
        Topping.add(pimang);
        Topping.add(cheese);
        Topping.add(peperoni);
        Topping.add(bacon);
        Size.add(small);
        Size.add(medium);
        Size.add(large);
        TypePanel.add(combo);
        TypePanel.add(potato);
        TypePanel.add(bulgogi);
        ToppingPanel.add(pimang);
        ToppingPanel.add(cheese);
        ToppingPanel.add(peperoni);
        ToppingPanel.add(bacon);
        SizePanel.add(small);
        SizePanel.add(medium);
        SizePanel.add(large);

        JButton order, cancel;
        order = new JButton("주문");
        cancel = new JButton("취소");
        cost = new JTextField(25);
        ActionPanel.add(order);
        ActionPanel.add(cancel);
        ActionPanel.add(cost);
        order.addActionListener(e -> {
            int temp = cost1 + cost2 + cost3;
            cost.setText(temp + "원 입니다 조금만 기다려주세요!");
        });
        cancel.addActionListener(e -> {
            // cost1 = cost2 = cost3 = 0;
            cost.setText("주문이 취소되었습니다");
        });

        add(HelloPanel, BorderLayout.NORTH);
        add(TypePanel, BorderLayout.WEST);
        add(ToppingPanel, BorderLayout.CENTER);
        add(SizePanel, BorderLayout.EAST);
        add(ActionPanel, BorderLayout.SOUTH);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == combo) {
            cost1 = 10000;
        }
        if (e.getSource() == potato) {
            cost1 = 11000;
        }
        if (e.getSource() == bulgogi) {
            cost1 = 12000;
        }
        if (e.getSource() == pimang) {
            cost2 = 1000;
        }
        if (e.getSource() == cheese) {
            cost2 = 2000;
        }
        if (e.getSource() == peperoni) {
            cost2 = 3000;
        }
        if (e.getSource() == bacon) {
            cost2 = 4000;
        }
        if (e.getSource() == small) {
            cost3 = 5000;
        }
        if (e.getSource() == medium) {
            cost3 = 6000;
        }
        if (e.getSource() == large) {
            cost3 = 7000;
        }
    }

    public static void main(String[] args) {
        new EX5_3();
    }
}
