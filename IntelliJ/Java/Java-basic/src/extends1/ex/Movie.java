package extends1.ex;

public class Movie extends Item{
    String director;
    String actor;

    public Movie(String name, int price, String director, String actor) {
        super(name, price);
        this.actor = actor;
        this.director = director;
    }

    @Override
    public void CPrint() {
        super.CPrint();
        System.out.println("감독 : " + director + " 배우 : " + actor);
    }
}
