package part2.ch5.boj1182;

import java.util.Scanner;

public class Main {

    public static int[] numbers;
    public static int s;
    public static int answer = 0;

    public static void solve(int index, int sum) {
        if(index == numbers.length) return;
        if(sum + numbers[index] == s) answer++;

        solve(index + 1 , sum);
        solve(index + 1, sum + numbers[index]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        s = sc.nextInt();
        numbers = new int[n];

        for(int i = 0; i < n; i++) {
            numbers[i] = sc.nextInt();
        }
        solve(0, 0);
        System.out.println(answer);
    }
}
