package Project1;

public class Pencil {
    public String color;
    public int length;
    public float diameter;
    public int price;

    public void setColor(String color) {
        this.color = color;
    }
    public void setLength(int length) {
        this.length = length;
    }
    public void setDiameter(float diameter) {
        this.diameter = diameter;
    }
    public void setPrice(int price) {
        this.price = price;
    }
    public void printAll(){
        System.out.println("Color: " + color);
        System.out.println("Length: " + length);
        System.out.println("Diameter: " + diameter);
        System.out.println("Price: " + price);
        System.out.println();
    }
}
