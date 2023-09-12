import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] students = new int[n];
        long sum = 0;
        for(int i=0; i<n; i++) {
            String str = sc.next();
            students[i] = str.length();
        }
        // 등수가 k보다 작거나 같은 좋은친구를 카운팅할 빈도수
        int[] friends = new int[21];
        Queue<Integer> queue = new LinkedList<>();
        for(int i=0; i<n; i++) {
            int next = students[i];
            sum += friends[next];

            queue.add(next);
            friends[next]++;
            if(queue.size() > k) {
                int out = queue.poll();
                friends[out]--;
            }
        }
        System.out.println(sum);
    }
}

