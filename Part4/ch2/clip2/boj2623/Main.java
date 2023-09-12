package part4.ch2.boj2623;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<Integer>[] list = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            list[i] = new ArrayList<>();
        }
        Queue<Integer> q = new LinkedList<>();
        int[] indegree = new int[n + 1];
        int[] check = new int[n + 1];

        for (int i = 0; i < m; i++) {
            int cnt = sc.nextInt();
            int front = sc.nextInt();

            for (int j = 2; j <= cnt; j++) {
                int back = sc.nextInt();
                list[front].add(back);
                indegree[back]++;
                front = back;
            }
        }

        List<Integer> answer = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) q.offer(i);
        }
        while (!q.isEmpty()) {
            int now = q.poll();
            check[now] = 1;
            answer.add(now);
            if (answer.size() > n) {
                System.out.println(0);
                return;
            }
            for (int next : list[now]) {
                if (check[next] == 1) continue;
                indegree[next]--;
                if (indegree[next] == 0) q.offer(next);
            }
        }
        for(int i = 1; i <= n; i++) {
            if(check[i] == 0) {
                System.out.println(0);
                return;
            }
        }
        for (Integer ans : answer) {
            System.out.println(ans);
        }
    }
}
