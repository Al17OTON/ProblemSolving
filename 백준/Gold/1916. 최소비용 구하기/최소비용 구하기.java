import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class Edge implements Comparable<Edge> {
        int to, cost;

        public Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge o) {
            return this.cost - o.cost;
        }
        
    }
    static int N, M, start, end;
    static ArrayList<Integer>[] edges;
    static int[] dp;
    static int[][] adj;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        edges = new ArrayList[N + 1];
        adj = new int[N + 1][N + 1];
        for(int n = 1; n <= N; n++) {
            edges[n] = new ArrayList<>();
            Arrays.fill(adj[n], -1);
        }

        StringTokenizer st;
        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            
            if(adj[from][to] == -1) {
                edges[from].add(to);
                adj[from][to] = cost;
            } else if(adj[from][to] > cost) {
                adj[from][to] = cost;
            }
        }
        st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());

        System.out.println(Dijkstra());
    }

    static int Dijkstra() {
        dp = new int[N + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        boolean[] v = new boolean[N + 1];
        pq.add(new Edge(start, 0));
        dp[start] = 0;

        while(!pq.isEmpty()) {
            Edge edge = pq.poll();

            if(v[edge.to]) continue;

            v[edge.to] = true;
            for(int i = 0; i < edges[edge.to].size(); i++) {
                int next = edges[edge.to].get(i);
                if(!v[next] && dp[next] > dp[edge.to] + adj[edge.to][next]) {
                    dp[next] = dp[edge.to] + adj[edge.to][next];
                    pq.add(new Edge(next, dp[next]));
                }
            }
        }

        return dp[end];
    }

}