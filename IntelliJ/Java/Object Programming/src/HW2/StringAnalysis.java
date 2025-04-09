package HW2;
import java.util.Scanner;

public class StringAnalysis {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter a line of text:");
        String input = scanner.nextLine();

        // 각종 카운트 변수
        int vowelCount = 0;        // 모음 개수
        int consonantCount = 0;    // 자음 개수
        int uppercaseCount = 0;    // 대문자 개수
        int lowercaseCount = 0;    // 소문자 개수
        int alphabetCount = 0;     // 알파벳 개수
        int digitCount = 0;        // 숫자 개수

        // 문자열의 각 문자에 대해 분석
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);

            // 알파벳인 경우
            if (Character.isLetter(c)) {
                alphabetCount++;

                // 대문자/소문자 판별
                if (Character.isUpperCase(c)) {
                    uppercaseCount++;
                } else {
                    lowercaseCount++;
                }

                // 모음/자음 판별
                // 비교 편의를 위해 소문자로 변환
                char lowerC = Character.toLowerCase(c);
                if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i'
                        || lowerC == 'o' || lowerC == 'u') {
                    vowelCount++;
                } else {
                    consonantCount++;
                }
            }
            // 숫자인 경우
            else if (Character.isDigit(c)) {
                digitCount++;
            }
        }

        // 결과 출력
        System.out.println("Number of vowels: " + vowelCount);
        System.out.println("Number of consonants: " + consonantCount);
        System.out.println("Number of uppercase letters: " + uppercaseCount);
        System.out.println("Number of lowercase letters: " + lowercaseCount);
        System.out.println("Number of alphabets: " + alphabetCount);
        System.out.println("Number of digits: " + digitCount);

        scanner.close();
    }
}
