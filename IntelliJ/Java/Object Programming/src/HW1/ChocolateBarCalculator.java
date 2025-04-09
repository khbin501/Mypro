package HW1;

import java.util.Scanner;

public class ChocolateBarCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 사용자 입력 받기
        System.out.print("Enter your weight (in pounds): ");
        double weight = scanner.nextDouble();

        System.out.print("Enter your height (in inches): ");
        double height = scanner.nextDouble();

        System.out.print("Enter your age (in years): ");
        int age = scanner.nextInt();

        // BMR 계산
        double bmrWoman = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
        double bmrMan = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);

        // 초콜릿 바 1개 = 230 칼로리
        int barsForWoman = (int) (bmrWoman / 230);
        int barsForMan = (int) (bmrMan / 230);

        // 출력
        System.out.println("\nTo maintain your weight:");
        System.out.println("A woman needs approximately " + barsForWoman + " chocolate bars per day.");
        System.out.println("A man needs approximately " + barsForMan + " chocolate bars per day.");

        scanner.close();
    }
}
