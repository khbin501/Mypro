package access.ex;
public class ShoppingCart {
    private item[] items = new item[10];
    private int count = 0;

    public void addItem(item item ) {
        if (count < 10) {
            items[count] = item;
            count++;
        }
        else System.out.println("장바구니가 가득 찼습니다.");
    }

    public void displayItems(){
        System.out.println("장바구니 상품 출력");
        for (int i = 0; i < count; i++) {
            System.out.println("제품명 : "+ item.getName(items[i]));
            System.out.println("총 가격 : "+ item.getSum(items[i]));
        }

    }

    }

