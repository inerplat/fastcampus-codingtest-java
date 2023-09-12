import java.util.Scanner;

class Main {
    static int n;
    static int[][] board;
    static int[] paper = new int[3];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        board = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = sc.nextInt();
            }
        }
        cut(0, 0, n);
        for(int i = 0; i < 3; i++) {
            System.out.println(paper[i]);
        }
    }

    static boolean isSame(int r, int c, int length) {
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < length; j++) {
                if(board[r][c] != board[r + i][c + j]) return false;
            }
        }
        return true;
    }

    static void cut(int r, int c, int length) {
        if(isSame(r, c, length)) {
            int color = board[r][c] + 1;
            paper[color]++;
            return;
        }

        int next = length / 3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cut(r + next*i, c + next*j, next);
            }
        }
    }
}