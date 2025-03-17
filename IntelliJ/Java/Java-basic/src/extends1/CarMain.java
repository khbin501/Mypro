package extends1;

public class CarMain {
    public static void main(String[] args) {
        ElectricCar electricCar = new ElectricCar();
        electricCar.charge();
        electricCar.move();
        electricCar.openCar();

        gasCar gascar = new gasCar();
        gascar.fillIn();
        gascar.move();
        gascar.openCar();

        HydrogenCar hydrogenCar = new HydrogenCar();
        hydrogenCar.FillHydrogen();
        hydrogenCar.move();
        hydrogenCar.openCar();
    }

}
