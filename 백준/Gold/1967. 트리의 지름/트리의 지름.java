import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static class Node {
        int to, cost;
        public Node(int to, int cost) {this.to = to; this.cost = cost;}
    }
    static int N, MAX = Integer.MIN_VALUE;
    static ArrayList<Node>[] adjList;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        adjList = new ArrayList[N + 1];
        for(int n = 1; n <= N; n++) {
            adjList[n] = new ArrayList<>();
        }

        StringTokenizer st;
        for(int n = 0; n < N - 1; n++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            adjList[from].add(new Node(to, cost));
        }

        dfs(1);

        System.out.println(MAX);

    }

    static int dfs(int node) {
        // 각 노드의 자식들 중 가장 긴 두 개만 기억하기
        int max = 0, max_sec = 0;
        for(int i = 0; i < adjList[node].size(); i++) {
            Node child = adjList[node].get(i);
            int cost = child.cost + dfs(child.to);

            if(max < cost) {
                max_sec = max;
                max = cost;
            } else if(max_sec < cost) {
                max_sec = cost;
            }
        }

        MAX = Math.max(MAX, max + max_sec);

        return max;
    }
}