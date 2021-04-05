// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX5_2

public class EX5_2 {
    static public void main(String args[]) {
        PlaneTest test = new PlaneTest();
        for (int i = 0; i < test.size(); i++) {
            System.out.print("제작사:"+test.getplane(i).getmanufacturer()+" ");
            System.out.print("모델:"+test.getplane(i).getmodel()+" ");
            System.out.print("최대승객:"+test.getplane(i).getpassengers()+" \n");
        }
        System.out.print("항공기 대수 = " + Plane.getPlanes()+"대");
    }
}

class PlaneTest {
    private final int SIZE = 3;
    private Plane[] planearr = new Plane[SIZE];

    public PlaneTest() {
        for (int i = 0; i < SIZE; i++)
            planearr[i] = new Plane();
        //만약 비행기를 더 추가하고 싶을경우 SIZE를 수정후, 데이터를 여기에 추가
        planearr[0].setmanufacturer("에어버스").setmodel("A380").setpassengers(500);
        planearr[1].setmanufacturer("보잉").setmodel("B777").setpassengers(400);
        planearr[2].setmanufacturer("보잉").setmodel("B747").setpassengers(500);
    }

    public Plane getplane(int index) {
        return this.planearr[index];
    }

    public int size() {
        return SIZE;
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
