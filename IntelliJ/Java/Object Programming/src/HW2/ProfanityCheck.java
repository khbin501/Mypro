package HW2;
import java.util.Scanner;

public class ProfanityCheck {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Please enter a line to be checked for profanity:");
        String inputLine = scanner.nextLine();

        // 대소문자 구별 없이 비교하기 위해 입력받은 문자열을 모두 소문자로 변환
        String lowerInput = inputLine.toLowerCase();

        // 포함 여부 검사
        boolean containsCat = lowerInput.contains("cat");
        boolean containsDog = lowerInput.contains("dog");
        boolean containsLlama = lowerInput.contains("llama");

        // 검사 결과 출력
        System.out.println("Your input line:");
        System.out.println(inputLine);

        if (containsCat) {
            System.out.println("contains cat");
        } else {
            System.out.println("does not contain cat");
        }

        if (containsDog) {
            System.out.println("contains dog");
        } else {
            System.out.println("does not contain dog");
        }

        if (containsLlama) {
            System.out.println("contains llama");
        } else {
            System.out.println("does not contain llama");
        }

        // 하나라도 포함되어 있으면 'profane'으로 처리
        if (containsCat || containsDog || containsLlama) {
            System.out.println("This line would be considered profane.");
        } else {
            System.out.println("This line would not be considered profane.");
        }

        scanner.close();
    }
}
