import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main {
    static int[] check = new int[101];
    static char[] input;
    static int n = 0;
    static List<Integer> answer = new ArrayList<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        input = sc.next().toCharArray();
        n = input.length > 9 ? 9 + (input.length - 9) / 2 : input.length;
        solve(0);
    }

    static void solve(int index) {
        // base case
        if(index >= input.length) {
            for(Integer num : answer) {
                System.out.print(num + " ");
            }
            System.exit(0);
        }

        // recursive case
        int target1 = atoi(input, index, 1);
        if(target1 <= n && check[target1] == 0) {
            check[target1] = index + 1;
            answer.add(target1);
            solve(index + 1);
            answer.remove(answer.size() - 1);
            check[target1] = 0;
        }
        if(index + 1 >= input.length) return;
        int target2 = atoi(input, index, 2);
        if(target2 <= n && check[target2] == 0) {
            check[target2] = index + 1;
            answer.add(target2);
            solve(index + 2);
            answer.remove(answer.size() - 1);
            check[target2] = 0;
        }
    }

    static int atoi(char[] input, int start, int length) {
        int result = 0;
        for(int i = start; i < start + length; i++) {
            result *= 10;
            result += input[i] - '0';
        }
        return result;
    }
}