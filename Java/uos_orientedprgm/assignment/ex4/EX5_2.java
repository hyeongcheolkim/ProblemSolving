// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX5_2

public class EX5_2 {
    static public void main(String args[]) {
        PlaneTest test = new PlaneTest(3);
        test.print();
        System.out.print("항공기 대수 = " + Plane.getPlanes() + "대");
    }
}

class PlaneTest {
    private int SIZE; // SIZE=비행기 갯수
    private Plane[] planearr;

    public PlaneTest(int SIZE) {
        this.SIZE = SIZE;
        planearr = new Plane[SIZE];
        for (int i = 0; i < SIZE; i++)
            planearr[i] = new Plane();
        // 3대의 정보를 미리 받았으므로, SIZE>=3이어야함. 4대째부터는 default 정보를 갖는다
        planearr[0].setmanufacturer("에어버스").setmodel("A380").setpassengers(500);
        planearr[1].setmanufacturer("보잉").setmodel("B777").setpassengers(400);
        planearr[2].setmanufacturer("보잉").setmodel("B747").setpassengers(500);
    }
    //PlaneTest에서 만든 비행기 리스트 출력
    public void print() {
        for (int i = 0; i < SIZE; i++) {
            System.out.print("제작사:" + planearr[i].getmanufacturer() + " ");
            System.out.print("모델:" + planearr[i].getmodel() + " ");
            System.out.print("최대승객:" + planearr[i].getpassengers() + " \n");
        }
    }
}

class Plane {
    private String manufacturer;
    private String model;
    private int passengers;
    static int planes = 0;

    public Plane() {
        this.manufacturer = "default manufacturer";
        this.model = "default model";
        this.passengers = 0;
        planes++;
    }

    public Plane(String manufacturer, String model, int passengers) {
        this.manufacturer = manufacturer;
        this.model = model;
        this.passengers = passengers;
        planes++;
    }

    static int getPlanes() {
        return planes;
    }

    public String getmanufacturer() {
        return this.manufacturer;
    }

    public String getmodel() {
        return this.model;
    }

    public int getpassengers() {
        return this.passengers;
    }

    public Plane setmanufacturer(String manufacturer) {
        this.manufacturer = manufacturer;
        return this;
    }

    public Plane setmodel(String model) {
        this.model = model;
        return this;
    }

    public Plane setpassengers(int passengers) {
        this.passengers = passengers;
        return this;
    }
}
