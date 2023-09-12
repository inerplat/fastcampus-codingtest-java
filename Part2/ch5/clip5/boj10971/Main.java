import java.util.Scanner;

class Main {
    static int n;
    static int[][] w;
    static boolean[] visited;
    static int answer = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        w = new int[n][n];
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                w[i][j] = sc.nextInt();
            }
        }
        travel(0, 0, 0, 0);
        System.out.println(answer);
    }

    static void travel(int start, int node, int sum, int cnt) {
        // base case
        if (cnt == n && start == node) {
            answer = Math.min(sum, answer);
            return;
        }
        // recursive case
        for (int i = 0; i < n; i++) {
            if(!visited[i] && w[node][i] != 0){
                visited[i] = true;
                travel(start, i, sum + w[node][i], cnt + 1);
                visited[i] = false;
            }
        }
    }
}
