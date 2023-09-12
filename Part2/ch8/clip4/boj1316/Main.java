package part2.ch8.boj1316;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            boolean[] check = new boolean[26];
            boolean isGroupWord = true;
            char[] str = sc.next().toCharArray();
            for (int j = 0; j < str.length - 1; j++) {
                char now = str[j];
                char next = str[j + 1];
                if(now == next) continue;

                if (check[now - 'a']) {
                    isGroupWord = false;
                    break;
                }
                check[now - 'a'] = true;
            }
            if (check[str[str.length - 1] - 'a']) isGroupWord = false;
            if (isGroupWord) cnt++;

        }
        System.out.println(cnt);
    }
}
