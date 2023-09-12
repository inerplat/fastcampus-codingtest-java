package part2.ch5.boj1759;

import java.util.Arrays;
import java.util.Scanner;

class Main {
    static int l, c;
    static char[] input;
    static char[] password;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        l = sc.nextInt();
        c = sc.nextInt();

        input = new char[c];
        password = new char[l];
        for (int i = 0; i < c; i++) {
            input[i] = sc.next().charAt(0);
        }
        Arrays.sort(input);
        generate(0, 0, 0);
    }

    static void generate(int length, int index, int vowelCnt) {
        // base case
        if(length == l) {
            if (vowelCnt >= 1 && l - vowelCnt >= 2) {
                System.out.println(password);
            }
            return;
        }

        // recursive case
        if(index < c) {
            // password에 input[index] 사용하는 경우
            password[length] = input[index];
            int v = isVowel(input[index]) ? 1 : 0;
            generate(length + 1, index + 1, vowelCnt + v);

            // password에 input[index] 사용하지 않는 경우
            password[length] = 0;
            generate(length, index + 1, vowelCnt);
        }
    }

    static boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}