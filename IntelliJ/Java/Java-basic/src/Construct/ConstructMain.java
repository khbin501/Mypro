package Construct;

public class ConstructMain {
    public static void main(String[] args) {
        Construct student1 = new Construct("student1", 19, 3);

        Construct student2 = new Construct("student2", 18, 2);

        Construct[] students = {student1, student2};

        for (Construct student : students) {
            System.out.println("이름 : " + student.name + " 나이 : " + student.age + " 학년 : " + student.grade  );
        }

    }
}
