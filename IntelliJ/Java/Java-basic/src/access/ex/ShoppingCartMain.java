package access.ex;

public class ShoppingCartMain {
    public static void main(String[] args) {
        ShoppingCart cart = new ShoppingCart();

        item m1 = new item("김치",2000,3);
        item m2 = new item("과자", 500, 2);

        cart.addItem(m1);
        cart.addItem(m2);

        cart.displayItems();
    }
}
