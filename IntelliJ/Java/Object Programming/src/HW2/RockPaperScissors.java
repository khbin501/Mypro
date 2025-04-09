package HW2;
import java.util.Scanner;

public class RockPaperScissors {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Player 1, choose Paper, Rock, or Scissors (P, R, S):");
        String player1Choice = scanner.nextLine().trim().toUpperCase();

        System.out.println("Player 2, choose Paper, Rock, or Scissors (P, R, S):");
        String player2Choice = scanner.nextLine().trim().toUpperCase();

        // 같은 선택인 경우 (비기는 경우)
        if (player1Choice.equals(player2Choice)) {
            System.out.println("Nobody wins!");
            // 굳이 이유(“종이 바위 덮음” 등)를 표시하지 않아도 되지만, 필요하다면 추가 가능
        }
        // 플레이어1이 이기는 경우
        else if ( (player1Choice.equals("R") && player2Choice.equals("S")) ||
                (player1Choice.equals("P") && player2Choice.equals("R")) ||
                (player1Choice.equals("S") && player2Choice.equals("P")) ) {

            System.out.print("Player 1 wins! ");
            // 승리 사유 출력
            if (player1Choice.equals("R") && player2Choice.equals("S")) {
                System.out.println("Rock breaks scissors.");
            } else if (player1Choice.equals("P") && player2Choice.equals("R")) {
                System.out.println("Paper covers rock.");
            } else { // (player1Choice.equals("S") && player2Choice.equals("P"))
                System.out.println("Scissors cuts paper.");
            }
        }
        // 그 밖의 경우는 플레이어2가 이기는 경우
        else {
            System.out.print("Player 2 wins! ");
            // 승리 사유 출력
            if (player2Choice.equals("R") && player1Choice.equals("S")) {
                System.out.println("Rock breaks scissors.");
            } else if (player2Choice.equals("P") && player1Choice.equals("R")) {
                System.out.println("Paper covers rock.");
            } else { // (player2Choice.equals("S") && player1Choice.equals("P"))
                System.out.println("Scissors cuts paper.");
            }
        }

        scanner.close();
    }
}
