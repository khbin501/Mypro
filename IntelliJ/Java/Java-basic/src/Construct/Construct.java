package Construct;

public class Construct {
    String name;
    int age;
    int grade;

    Construct(String name, int age, int grade){
        System.out.println("생성자 호출 이름 : " + name + " 나이 : " + age + " 학년 : " + grade);
        this.name = name;
        this.age = age;
        this.grade = grade;
    }
}
