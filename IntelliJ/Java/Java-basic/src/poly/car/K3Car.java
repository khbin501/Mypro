package poly.car;

public class K3Car implements Car{
    @Override
    public void startEngine() {
        System.out.println("k3앤진 켜기");
    }

    @Override
    public void offEngine() {
        System.out.println("k3앤진 끄기");
    }

    @Override
    public void pressAccel() {
        System.out.println("k3엔진 액셀 밟기");
    }
}
