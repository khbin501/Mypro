package HW1;

import java.util.Scanner;

public class OctalToDecimal {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 사용자로부터 8진수 문자열 입력 받기
        System.out.print("Enter a 3-digit octal number: ");
        String octalString = scanner.nextLine();

        // 입력 길이 확인
        if (octalString.length() > 3 || !octalString.matches("[0-7]+")) {
            System.out.println("Invalid input. Please enter a valid octal number (up to 3 digits).");
            return;
        }

        // 8진수를 10진수로 수동 변환
        int decimal = 0;
        int power = 0;

        for (int i = octalString.length() - 1; i >= 0; i--) {
            int digit = octalString.charAt(i) - '0';
            decimal += digit * Math.pow(8, power);
            power++;
        }

        // 결과 출력
        System.out.println("Decimal equivalent: " + decimal);
        scanner.close();
    }
}
