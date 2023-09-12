package part2.ch3.boj15655;

import java.util.Arrays;
import java.util.Scanner;

class Main {

    public static int[] numbers;
    public static int[] output;
    public static boolean[] check;

    public static void print(int[] arr, int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(arr[i]).append(" ");
        }
        System.out.println(sb);
    }

    public static void perm(int depth, int n, int m, int start) {
        if (depth == m) {
            print(output, m);
            return;
        }

        for (int i = start; i < n; i++) {
            if (!check[i]) {
                check[i] = true;
                output[depth] = numbers[i];
                perm(depth + 1, n, m, i + 1);
                check[i] = false;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        numbers = new int[n];
        output = new int[m];
        check = new boolean[n];
        for (int i = 0; i < n; i++) {
            numbers[i] = sc.nextInt();
        }
        Arrays.sort(numbers);
        // do something
        perm(0, n, m, 0);
    }
}
