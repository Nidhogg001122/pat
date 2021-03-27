import java.util.Scanner;

public class Main {
    public static void main (String [] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int row = 0, i = 0, j = 0;
        char letter = scanner.next().charAt(0);
        if (num % 2 == 0) row = num / 2;
        else row = num / 2 + 1;
        for (i = 0; i < num; i++) System.out.print(letter);
        System.out.print("\n");
        for (i = 0; i < row - 2; i++) {
            for (j = 1; j <= num; j++) {
                if (j == 1) System.out.print(letter);
                else if (j == num) System.out.print(letter + "\n");
                else System.out.print(" ");
            }
        }
        for (i = 0; i < num; i++) System.out.print(letter);
    }
}