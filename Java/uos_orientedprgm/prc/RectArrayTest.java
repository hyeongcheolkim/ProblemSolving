class Rect {
    private int w;
    private int h;

    Rect(int w, int h){
        this.w = w;
        this.h = h;
    }
    public int calcArea() {
        return w*h;
    }
}

public class RectArrayTest {
    public static void main(String[] args) throws Exception {
        Rect[] list;
        list = new Rect[5];
        for(int i=0;i<list.length;i++)
        list[i] = new Rect(i, i);
        
        for(int i=0;i<list.length;i++)
            System.out.println(i + "번째 면적" + list[i].calcArea());
    }
}
