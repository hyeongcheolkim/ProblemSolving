// University of Seoul. Dept of Computer Science.
// 2018430021 김형철
// EX5_1

public class EX5_2 {
    static public void main(String args[]) {
   
        System.out.print("항공기 대수 = " + Plane.getPlanes());
    }
}

class PlaneTest {
    public Plane p1 = new Plane();
    public Plane p2 = new Plane();
    public Plane p3 = new Plane();
}

class Plane {
    private String manufacturer;
    private String model;
    private int limit;
    static int planes = 0;

    public Plane() {
        this.manufacturer = "default manufacturer";
        this.model = "default model";
        this.limit = 0;
        planes++;
    }

    public Plane(String manufacturer, String model, int limit) {
        this.manufacturer = manufacturer;
        this.model = model;
        this.limit = limit;
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

    public int getlimit() {
        return this.limit;
    }

    Plane setmanufacturer(String manufacturer) {
        this.manufacturer = manufacturer;
        return this;
    }

    Plane setmodel(String model) {
        this.model = model;
        return this;
    }

    Plane setlimit(int limit) {
        this.limit = limit;
        return this;
    }
}
