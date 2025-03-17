package poly.animal;

public class AnimalMain {
    public static void main(String[] args) {
        Animal cat = new Cat();
        Animal dog = new Dog();
        Animal cow = new Cow();
        Chicken chicken = new Chicken();
        bird bird = new bird();

        Sound(cat);
        Sound(dog);
        Sound(cow);
        Sound(chicken);
        Sound(bird);

        FlyTest(chicken);
        FlyTest(bird);
    }

     static void Sound(Animal animal) {
         System.out.println("시작");
        animal.sound();
         System.out.println("종료");
    }

    static void FlyTest(Fly fly) {
        System.out.println("날기 시작");
        fly.fly();
        System.out.println("날기 종료");
    }

}


