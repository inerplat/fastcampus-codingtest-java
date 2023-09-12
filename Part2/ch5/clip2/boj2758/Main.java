package part2.ch5.boj2758;

import java.util.Scanner;

public class Main {

    public static long[][] mem;

    public static long solve(int i, int last) {
        if(last <= 0) return 0;
        if(i == 1) return last;
        if(mem[i][last] == -1) {
            mem[i][last] = solve(i - 1, last / 2) + solve(i, last - 1);
        }
        return mem[i][last];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int tc = 0; tc < t; tc++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            mem = new long[n + 1][m + 1];

            for (int i = 0; i < n + 1; i++) {
                for (int j = 0; j < m + 1; j++) {
                    mem[i][j] = -1;
                }
            }


            System.out.println(solve(n, m));
        }
    }
}
