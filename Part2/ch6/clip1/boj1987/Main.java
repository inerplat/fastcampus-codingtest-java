import java.util.Scanner;

class Main {
    public static int[][] board;
    public static boolean[] check = new boolean[26];
    public static int r, c;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        c = sc.nextInt();
        board = new int[r][c];
        visited = new int[r][c];
        for (int i = 0; i < r; i++) {
            String line = sc.next();
            for (int j = 0; j < c; j++) {
                board[i][j] = line.charAt(j) - 'A';
            }
        }
        visited[0][0] = 1 << (board[0][0]);
        check[board[0][0]] = true;
        System.out.println(solve(0, 0));
    }

    // dr[0] dc[0] : 상
    // dr[1] dc[1] : 우
    // dr[2] dc[2] : 하
    // dr[3] dc[3] : 좌
    static int[] dr = {-1, 0, 1, 0};
    static int[] dc = {0, 1, 0, -1};

    // visited[row][col] -> (row, col) 도달했을때 사용한 알파벳
    public static int[][] visited;

    public static int solve(int row, int col) {
        int result = 0;
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i], nc = col + dc[i];
            if (isOutOfBound(nr, nc, r, c)) continue;
            int next = board[nr][nc];
            if (check[next]) continue;
            int route = 1 << next;
            if (visited[nr][nc] == (visited[row][col] | route)) continue;

            visited[nr][nc] = visited[row][col] | route;
            check[next] = true;
            int nextResult = solve(nr, nc);
            result = Math.max(result, nextResult);
            check[next] = false;
        }
        return result + 1;
    }

    static boolean isOutOfBound(int row, int col, int boundR, int boundC) {
        return row < 0 || col < 0 || row >= boundR || col >= boundC;
    }
}