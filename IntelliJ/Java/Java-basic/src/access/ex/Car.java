package access.ex;

public class Car {
    private String name;
     private static int count;

    public Car (String name) {
        this.name = name;
        count++;
    }

    public static void showTotalCar(){
        System.out.println("count = " + count);
    }
}
