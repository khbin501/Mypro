package poly.car;

public class model3 implements Car {
    @Override
    public void startEngine() {
        System.out.println("모델3 앤진켜기");
    }

    @Override
    public void offEngine() {
        System.out.println("모델3 엔진 끄기");
    }

    @Override
    public void pressAccel() {
        System.out.println("모델3 엑셀 밟기");
    }
}
