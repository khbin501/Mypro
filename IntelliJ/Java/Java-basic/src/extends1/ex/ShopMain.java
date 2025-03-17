package extends1.ex;

public class ShopMain {
    public static void main(String[] args) {
        Book book = new Book("java", 1000, "han", "12345");
        Album album = new Album("album1", 15000, "seo");
        Movie movie = new Movie("movie", 10000, "director", "actor1");

        book.CPrint();
        album.CPrint();
        movie.CPrint();

        int sum = book.getPrice() + album.getPrice() + movie.getPrice();
        System.out.println("sum = " + sum);
    }
}
