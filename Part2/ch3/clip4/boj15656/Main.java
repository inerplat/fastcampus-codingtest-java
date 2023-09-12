package part2.ch3.boj15656;

import java.util.Arrays;
import java.util.Scanner;

class Main {
    public static int[] numbers;
    public static int[] output;
    public static boolean[] check;
    public static StringBuilder sb = new StringBuilder();

    public static void print(int[] arr, int n) {
        for (int i = 0; i < n; i++) {
            sb.append(arr[i]).append(" ");
        }
        sb.append("\n");
    }

    public static void perm(int depth, int n, int m) {
        if (depth == m) {
            print(output, m);
            return;
        }

        for (int i = 0; i < n; i++) {
            output[depth] = numbers[i];
            perm( depth + 1, n, m);
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
        perm(0, n, m);
        System.out.println(sb);
    }
}
