package part2.ch6.boj2661;

import java.util.Scanner;

public class Main {
    public static int n;

    public static boolean solve(int endIndex) {
        if (endIndex == n) {
            for (int i = 0; i < n; i++) {
                System.out.print(numbers[i]);
            }
            return true;
        } else {
            for (int i = 1; i <= 3; i++) {
                numbers[endIndex] = i;
                if (!isBad(endIndex)) {
                    if (solve(endIndex + 1)) return true;
                }
            }
        }
        return false;
    }

    public static int[] numbers = new int[80];

    public static boolean isBad(int endIndex) {
        for (int i = 1; i <= (endIndex + 1) / 2; i++) {
            boolean isSame = true;
            for (int j = 0; j < i; j++) {
                if (numbers[endIndex - j] != numbers[endIndex - i - j]) {
                    isSame = false;
                    break;
                }
            }
            if (isSame) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        solve(0);
    }
}
