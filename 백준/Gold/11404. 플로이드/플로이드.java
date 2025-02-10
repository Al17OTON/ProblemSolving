import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class Bus implements Comparable<Bus> {
        int idx, cost;
        public Bus(int idx, int cost) {
            this.idx = idx;
            this.cost = cost;
        }
        public int compareTo(Bus o) {
            return this.cost - o.cost;
        }
    }

    static int N, M;
    static ArrayList<Integer>[] adj;
    static int[][] cost;
    static int[][] result;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        adj = new ArrayList[N + 1];
        cost = new int[N + 1][N + 1];
        result = new int[N + 1][N + 1];
        for(int n = 1; n <= N; n++) {
            adj[n] = new ArrayList<>();
            Arrays.fill(result[n], Integer.MAX_VALUE);
        }

        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            if(cost[from][to] == 0) {
                adj[from].add(to);
                cost[from][to] = c;
            } else {
                cost[from][to] = Math.min(cost[from][to], c);
            }
        }
        for(int i = 1; i <= N; i++) {
            bfs(i);
            for(int j = 1; j <= N; j++) {
                sb.append(result[i][j] == Integer.MAX_VALUE ? 0 : result[i][j]).append(" ");
            }
            sb.append("\n");
        }

        System.out.println(sb);
    }

    static void bfs(int idx) {
        PriorityQueue<Bus> pq = new PriorityQueue<>();
        pq.offer(new Bus(idx, 0));
        result[idx][idx] = 0;

        while(!pq.isEmpty()) {
            Bus b = pq.poll();

            if(b.cost > result[idx][b.idx]) continue;

            for(int i = 0; i < adj[b.idx].size(); i++) {
                int next = adj[b.idx].get(i);
                if(result[idx][next] <= b.cost + cost[b.idx][next]) continue;
                result[idx][next] = b.cost + cost[b.idx][next];
                pq.offer(new Bus(next, result[idx][next]));
            }

        }
    }
}