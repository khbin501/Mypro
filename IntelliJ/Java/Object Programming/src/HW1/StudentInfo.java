package HW1;

import java.util.Scanner;

public class StudentInfo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 사용자 입력 받기
        System.out.print("Enter your name: ");
        String name = scanner.nextLine();

        System.out.print("Enter your roll number: ");
        int rollNumber = scanner.nextInt();
        scanner.nextLine();  // 개행 문자 소비

        System.out.print("Enter your address: ");
        String address = scanner.nextLine();

        System.out.print("Enter your course: ");
        String course = scanner.nextLine();

        // 결과 출력
        System.out.println();
        System.out.println(name + " has roll no. " + rollNumber + ",");
        System.out.println("his address is " + address + " and the course he studies is " + course + ".");

        scanner.close();
    }
}
