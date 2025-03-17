package access.ex;

public class item {
    private String name;
    private int count;
    private int price;

    public item(String name, int price, int count) {
        this.name = name;
        this.price = price;
        this.count = count;
    }

    public static String getName(item item){
        return item.name;
    }

    public static int getSum(item item){
        return item.count * item.price;
    }
}
