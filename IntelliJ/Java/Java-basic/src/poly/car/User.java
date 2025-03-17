package poly.car;

public class User {

    Car car;

    public void setCar(Car car) {
        System.out.println("자동차를 변경합니다 : " + car);
        this.car = car;
    }

    public void drive() {
        car.startEngine();
        car.pressAccel();
        car.offEngine();
    }


}
