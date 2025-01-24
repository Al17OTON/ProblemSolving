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
    static ArrayList<Edge>[] edges;
    static int[] dp;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        edges = new ArrayList[N + 1];
        for(int n = 1; n <= N; n++) edges[n] = new ArrayList<>();

        StringTokenizer st;
        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            
            edges[from].add(new Edge(to, cost));
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
                Edge e = edges[edge.to].get(i);
                if(!v[e.to] && dp[e.to] > dp[edge.to] + e.cost) {
                    dp[e.to] = dp[edge.to] + e.cost;
                    pq.add(new Edge(e.to, dp[e.to]));
                }
            }
        }

        return dp[end];
    }

}