import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main {
    static List<Integer>[] tree;
    static boolean[] check;
    static int[] sum;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), r = sc.nextInt(), q = sc.nextInt();
        check = new boolean[n + 1];
        sum = new int[n + 1];
        tree = new ArrayList[n + 1];
        for (int i = 0; i < tree.length; i++) {
            tree[i] = new ArrayList<>();
        }
        for(int i=0; i<n-1; i++) {
            int u = sc.nextInt(), v = sc.nextInt();
            tree[u].add(v);
            tree[v].add(u);
        }
        sum[r] = getSum(r);
        for (int i = 0; i < q; i++) {
            int u = sc.nextInt();
            System.out.println(sum[u]);
        }
    }

    public static int getSum(int node) {
        if (sum[node] != 0) return sum[node];
        check[node] = true;
        int result = 1; // 자기 자신
        for (int child : tree[node]) {
            if (!check[child]) {
                result += getSum(child);
            }
        }
        return sum[node] = result;
    }
}