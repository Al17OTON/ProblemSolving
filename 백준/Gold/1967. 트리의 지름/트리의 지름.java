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
    static ArrayList<Integer>[] adjCost;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        adjList = new ArrayList[N + 1];
        adjCost = new ArrayList[N + 1];
        for(int n = 1; n <= N; n++) {
            adjList[n] = new ArrayList<>();
            adjCost[n] = new ArrayList<>();
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
        
        int max = 0;
        for(int i = 0; i < adjList[node].size(); i++) {
            Node child = adjList[node].get(i);
            int cost = child.cost + dfs(child.to);
            adjCost[node].add(cost);
            max = Math.max(max, cost);
        }

        for(int i = 0; i < adjCost[node].size(); i++) {
            for(int j = i + 1; j < adjCost[node].size(); j++) {
                MAX = Math.max(MAX, adjCost[node].get(i) + adjCost[node].get(j));
            }
        }
        MAX = Math.max(MAX, max);

        return max;
    }
}