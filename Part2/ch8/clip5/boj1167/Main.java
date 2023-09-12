import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int v;
    static List<Node>[] tree;
    static int[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        v = sc.nextInt();
        List<Node>[] tree = new ArrayList[v+1];
        int[] visited = new int[v+1];
        for(int i = 1; i <= v; i++) {
            tree[i] = new ArrayList<>();
        }

        for (int i = 0; i < v; i++) {
            int node = sc.nextInt();
            while (true) {
                int next = sc.nextInt();
                if (next == -1) break;
                int dist = sc.nextInt();
                tree[node].add(new Node(next, dist));
                tree[next].add(new Node(node, dist));
            }
        }
        // 1차 탐색: 임의의 노드에서 가장 먼 노드를 찾는다.
        maxDepth = 0;
        visited[1] = 1;
        findMaxDepthLeaf(1, 0);

        // 2차 탐색: 가장 먼 노드에서 다시 가장 먼 노드를 찾는다.
        for(int i = 1; i <= v; i++) visited[i] = 0;
        maxDepth = 0;
        visited[maxDepthLeaf] = 1;
        findMaxDepthLeaf(maxDepthLeaf, 0);
        System.out.println(maxDepth);
    }

    static int maxDepth = 0;
    static int maxDepthLeaf = 1;
    public static void findMaxDepthLeaf(int node, int depth) {
        if (depth > maxDepth) {
            maxDepth = depth;
            maxDepthLeaf = node;
        }
        for (Node next : tree[node]) {
            if(visited[next.node] == 1) continue;
            visited[next.node] = 1;
            findMaxDepthLeaf(next.node, depth + next.dist);
        }
    }
}

class Node {
    int node;
    int dist;

    public Node(int node, int dist) {
        this.node = node;
        this.dist = dist;
    }
}