package HW2;
import java.util.Scanner;

public class GradeCounter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 각 학점(A, B, C, D, F) 카운트와 전체 카운트
        int totalCount = 0;
        int countA = 0;
        int countB = 0;
        int countC = 0;
        int countD = 0;
        int countF = 0;

        System.out.println("Enter exam scores (0~100). Enter a negative number to stop.");

        while (true) {
            System.out.print("Score: ");
            int score = scanner.nextInt();

            // 음수 입력 시 반복 종료(센티널)
            if (score < 0) {
                break;
            }

            // 점수 범위별 카운트
            if (score >= 90 && score <= 100) {
                countA++;
            } else if (score >= 80 && score <= 89) {
                countB++;
            } else if (score >= 70 && score <= 79) {
                countC++;
            } else if (score >= 60 && score <= 69) {
                countD++;
            } else if (score >= 0 && score <= 59) {
                countF++;
            } else {
                // 0~100 범위를 벗어난 입력은 무시하거나 오류 메시지를 낼 수도 있음
                System.out.println("Invalid score (must be 0~100). This score is ignored.");
                continue;
            }

            // 유효 점수일 경우에만 총 개수 증가
            totalCount++;
        }

        // 결과 출력
        System.out.println("\n=== Grade Count Result ===");
        System.out.println("Total number of grades = " + totalCount);
        System.out.println("Number of A's = " + countA);
        System.out.println("Number of B's = " + countB);
        System.out.println("Number of C's = " + countC);
        System.out.println("Number of D's = " + countD);
        System.out.println("Number of F's = " + countF);

        scanner.close();
    }
}
