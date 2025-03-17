package Project1;

public class PencilMain {
    public static void main(String[] args) {
        Pencil pencil1 = new Pencil();

        Pencil pencil2 = new Pencil();

        pencil1.setColor("white");
        pencil1.setDiameter(5);
        pencil1.setLength(3);
        pencil1.setPrice(10000);

        pencil2.setColor("black");
        pencil2.setDiameter(10);
        pencil2.setLength(2);
        pencil2.setPrice(20000);

        pencil1.printAll();

        pencil2.printAll();
    }

}
