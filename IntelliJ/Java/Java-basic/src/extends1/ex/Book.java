package extends1.ex;

public class Book extends Item{
    private String author;
    private String isbn;
    private String name;
    private int price;

    public Book(String name, int price, String author, String isbn) {
        super(name, price);
        this.author = author;
        this.isbn = isbn;
    }
    @Override
    public void CPrint() {
        super.CPrint();
        System.out.println("-저자 : " + author + " isbn : " + isbn);
    }
}
