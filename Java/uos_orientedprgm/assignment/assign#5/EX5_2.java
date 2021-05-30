import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class EX5_2 extends JFrame implements ActionListener {
    private JPanel res, oper;
    private JTextField formula;
    private String num1, num2, operator;
    private double result;

    public EX5_2() {
        setTitle("Calculator");
        setSize(700, 450);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        num1 = num2 = operator = "";

        res = new JPanel();
        formula = new JTextField(30);
        formula.setEditable(false);
        res.add(formula);

        oper = new JPanel();
        oper.setLayout(new GridLayout(5, 4, 2, 2));

        JButton b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, bp, bm, bd, bmp, beq, bc;
        b0 = new JButton("0");
        b1 = new JButton("1");
        b2 = new JButton("2");
        b3 = new JButton("3");
        b4 = new JButton("4");
        b5 = new JButton("5");
        b6 = new JButton("6");
        b7 = new JButton("7");
        b8 = new JButton("8");
        b9 = new JButton("9");
        bp = new JButton("+");
        bm = new JButton("-");
        bd = new JButton("/");
        bmp = new JButton("*");
        beq = new JButton("=");
        bc = new JButton("C");

        b0.addActionListener(this);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        b6.addActionListener(this);
        b7.addActionListener(this);
        b8.addActionListener(this);
        b9.addActionListener(this);
        bp.addActionListener(this);
        bm.addActionListener(this);
        bd.addActionListener(this);
        bmp.addActionListener(this);
        beq.addActionListener(this);
        bc.addActionListener(this);

        oper.add(bc);
        oper.add(new JLabel(""));
        oper.add(new JLabel(""));
        oper.add(new JLabel(""));
        oper.add(b7);
        oper.add(b8);
        oper.add(b9);
        oper.add(bd);
        oper.add(b4);
        oper.add(b5);
        oper.add(b6);
        oper.add(bmp);
        oper.add(b1);
        oper.add(b2);
        oper.add(b3);
        oper.add(bm);
        oper.add(b0);
        oper.add(new JLabel(""));
        oper.add(bp);
        oper.add(beq);

        add(res, BorderLayout.NORTH);
        add(oper, BorderLayout.CENTER);
        setVisible(true);
    }

    public double divide(double a, double b) throws ZeroDivideException {
        if (b == 0)
            throw new ZeroDivideException();
        else
            return a / b;
    }

    public void actionPerformed(ActionEvent e) {
        String input = e.getActionCommand();
        char c = input.charAt(0);

        if ('0' <= c && c <= '9') {
            if (operator.equals(""))
                num1 += c;
            else
                num2 += c;
            formula.setText(num1 + operator + num2);
        } else if (c == 'C') {
            num1 = operator = num2 = "";
            formula.setText(num1 + operator + num2);
        } else if (c == '=') {
            if (operator.equals("+"))
                result = (Double.parseDouble(num1) + Double.parseDouble(num2));
            else if (operator.equals("-"))
                result = (Double.parseDouble(num1) - Double.parseDouble(num2));
            else if (operator.equals("/"))
                try {
                    result = divide(Double.parseDouble(num1), Double.parseDouble(num2));
                } catch (ZeroDivideException err) {
                    num1 = num2 = operator = input = "";
                    result = 0.0;
                    num1 = err.getMessage() + " 0.0으로 초기화 됩니다. -> ";
                }
            else
                result = (Double.parseDouble(num1) * Double.parseDouble(num2));
            formula.setText(num1 + operator + num2 + "=" + result);
            num1 = Double.toString(result);
            operator = num2 = "";
        } else {
            if (operator.equals("") || num2.equals(""))
                operator = input;
            else {
                if (operator.equals("+"))
                    result = (Double.parseDouble(num1) + Double.parseDouble(num2));
                else if (operator.equals("-"))
                    result = (Double.parseDouble(num1) - Double.parseDouble(num2));
                else if (operator.equals("/"))
                    try {
                        result = divide(Double.parseDouble(num1), Double.parseDouble(num2));
                    } catch (ZeroDivideException err) {
                        num1 = num2 = operator = input = "";
                        result = 0.0;
                        num1 = err.getMessage() + " 0.0으로 초기화 됩니다. -> ";
                    }
                else
                    result = (Double.parseDouble(num1) * Double.parseDouble(num2));

                num1 = Double.toString(result);
                operator = input;
                num2 = "";
            }
            formula.setText(num1 + operator + num2);
        }
    }

    public static void main(String[] args) {
        new EX5_2();
    }
}

class ZeroDivideException extends Exception {
    public ZeroDivideException() {
        super("0으로 나눌수 없습니다");
    }
}