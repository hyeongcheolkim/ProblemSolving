public class EX6_4 {
    public static void main(String[] args) {
        Bus bus = new Bus(10);
        Customer A = new Customer(bus, "Thread-A", 5);
        Customer B = new Customer(bus, "Thread-B", 2);
        Customer C = new Customer(bus, "Thread-C", 4);
        new Thread(A).start();
        new Thread(B).start();
        new Thread(C).start();
    }
}

class Bus {
    private int reservable;

    public Bus(int num) {
        reservable = num;
    }

    public synchronized void reserve(String name, int num) {
        System.out.println(name + "가 들어왔음.");
        System.out.printf("가능한 좌석수 : %d 요청좌석수 : %d\n", reservable, num);
        if (num > reservable) {
            System.out.println("좌석 예약이 불가능합니다.");
        } else {
            System.out.println(num + "좌석이 예약되었음.");
            reservable -= num;
        }
        System.out.println(name + "가 나갑니다.");
        System.out.println("==================================");
    }

    public int getReservable() {
        return reservable;
    }
}

class Customer extends Thread {
    Bus bus;
    String name;
    int num;

    public Customer(Bus bus, String name, int num) {
        this.bus = bus;
        this.name = name;
        this.num = num;
    }

    public void run() {
        bus.reserve(name, num);
    }
}
