package Construct;

public class BookMain {
    public static void main(String[] args) {
            Book book1 = new Book("", "", 0);
            Book book2 = new Book("Hello Java", "Seo", 0);
            Book book3 = new Book("JPA 프로그래밍", "Kim", 700);

            book1.DisplayBook();

            book2.DisplayBook();

            book3.DisplayBook();

    }
}
