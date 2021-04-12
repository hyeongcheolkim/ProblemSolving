interface Printable{

    void print();
}

interface Drawable {
    void draw();
}

class Shape1 {
    int x, y;

    public void move(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void draw() {
        System.out.println("Shape Draw");
    }
}


public class MultiInterface extends Shape1 implements Printable, Drawable {
    public void print() {
        System.out.println("프린터로 원을 출력합니다.");
    }

    public void draw() {
        System.out.println("화면에 원을 그립니다.");
    }
    public static void main(String[] args) throws Exception {
        MultiInterface obj = new MultiInterface();
        obj.print();
        obj.draw();

        Printable p = obj;
        p.print();
        

        Drawable d = obj;
        d.draw();
    }
}
