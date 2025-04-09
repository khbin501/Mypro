package HW2;
import java.util.Scanner;

public class DecryptMessage {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 암호화된 문자열 입력
        System.out.print("Enter the sentence to decode: ");
        String encrypted = scanner.nextLine();

        // 키 입력 (1~100 범위)
        System.out.print("Enter the key to decode: ");
        int key = scanner.nextInt();

        // 복호화 결과를 담을 StringBuilder
        StringBuilder decrypted = new StringBuilder();

        // 각 문자를 순회하면서 디코딩
        for (int i = 0; i < encrypted.length(); i++) {
            char encChar = encrypted.charAt(i);
            int asciiVal = (int) encChar;

            // printable ASCII: 32~126 (총 95개)
            // 디코딩 = (암호화된 값 - key) 가 32 미만이면 95만큼 더해줌
            int decodedVal = asciiVal - key;

            // 범위보다 작아지면 95씩 더해서 32 이상으로 만든다
            while (decodedVal < 32) {
                decodedVal += 95;
            }

            // 복호화된 ASCII 코드를 문자로 변환
            decrypted.append((char) decodedVal);
        }

        // 결과 출력
        System.out.println("Decrypted message: " + decrypted.toString());

        scanner.close();
    }
}
