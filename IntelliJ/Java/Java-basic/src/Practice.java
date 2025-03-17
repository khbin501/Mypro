import java.util.Scanner;

public class Practice {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("입력할 주문의 개수를 입력하세요 : ");
        int count = input.nextInt();

        ProductOrder[] orders = new ProductOrder[count];

        for (int i=0; i<count; i++){
            System.out.println((i+1) + " 번째 주문 정보를 입력하세요.");
            System.out.print("상품명 : ");
            String name = input.next();

            System.out.print("가격 : ");
            int price = input.nextInt();


            System.out.print("수량 : ");
            int quantity = input.nextInt();

            orders[i] = createProduct(name, price, quantity);
        }

        printProduct(orders);

        int totalSum = total(orders);
        System.out.println("총 가격 :  = " + totalSum);

    }

    public static ProductOrder createProduct(String name, int price, int quantity){
        ProductOrder product = new ProductOrder();
        product.productName = name;
        product.price = price;
        product.quantitiy = quantity;
        return product;

    }

    public static void printProduct(ProductOrder[] orders){
        for ( ProductOrder order : orders ) {
            System.out.println("이름 : " + order.productName + "  가격 : " + order.price + " 수량 : " + order.quantitiy );
            
        }
    }

    public static int total(ProductOrder[] orders){
        int sum=0;
        for (ProductOrder order : orders) {
            sum += order.price * order.quantitiy;
        }
        return sum;
    }


}
