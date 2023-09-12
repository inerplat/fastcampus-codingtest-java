import java.util.Scanner;

public class Main {
    public static int n;
    public static int d;
    public static boolean[] usedNumber;
    public static int[] number;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        d = sc.nextInt();

        usedNumber = new boolean[d];
        number = new int[d];
        int result = findPermutation(0);
        System.out.println(result);
    }

    public static int findPermutation(int depth) {
        if (depth == d) {
            // 3. 진법변환
            int result = 0;
            for (int i = 0; i < depth; i++) {
                result *= d;
                result += number[i];
            }
            return result;
        }

        // 2. 앞자리가 0이면 무시하도록
        int start = 0;
        if (depth == 0) start = 1;
        for (int i = start; i < d; i++) {
            // 1. 중복되는 수가 생성되지 않도록
            if (!usedNumber[i]) {
                usedNumber[i] = true;
                number[depth] = i;
                int num = findPermutation(depth + 1);
                if (num > n) return num;

                usedNumber[i] = false;
            }
        }
        return -1;
    }
}
