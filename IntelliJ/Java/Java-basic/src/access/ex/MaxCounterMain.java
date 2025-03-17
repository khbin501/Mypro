package access.ex;

public class MaxCounterMain {
    public static void main(String[] args) {
        MaxCounter counter =new MaxCounter(3);
        counter.increment();
        counter.increment();
        counter.increment();
        counter.increment();

        counter.getCount();
    }
}
