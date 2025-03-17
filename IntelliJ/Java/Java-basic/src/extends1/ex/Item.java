package extends1.ex;

public class Item {

    private String name;
    private int price;

    public Item(String name, int price) {
        this.name = name;
        this.price = price;
    }

    public void CPrint() {
        System.out.println("이름 : "+ this.name + " 가격 : "+ this.price);
    }

    public int getPrice() {
        return price;
    }

}
