package poly.car;

public class carMain {
    public static void main(String[] args) {

        User user = new User();
        K3Car k3 = new K3Car();
        model3 m3 = new model3();

        user.setCar(k3);
        user.drive();

        user.setCar(m3);
        user.drive();
    }
}
