import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static class Truck implements Comparable<Truck> {
        int idx, cost;

        public Truck(int idx, int cost) {
            this.idx = idx;
            this.cost = cost;
        }
        public int compareTo(Truck o) {
            return this.cost - o.cost;
        }

    }

    static int N, M;
    // static int[][] adjCost;
    static ArrayList<int[]>[] adj;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        // adjCost = new int[N + 1][N + 1];
        adj = new ArrayList[N + 1];
        for(int n = 1; n <= N; n++) {
            // Arrays.fill(adjCost[n], Integer.MAX_VALUE);
            adj[n] = new ArrayList<int[]>();
        }

        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            // if(adjCost[a][b] == Integer.MAX_VALUE) {
            //     adj[a].add(b);
            //     adj[b].add(a);
            // }

            // adjCost[a][b] = Math.min(c, adjCost[a][b]);
            // adjCost[b][a] = adjCost[a][b];
            adj[a].add(new int[] {b, c});
            adj[b].add(new int[] {a, c});
        }

        for(int n = 1; n <= N; n++) adj[n].sort((a, b) -> a[1] - b[1]);

        System.out.println(bfs());
    }
    
    static int bfs() {
        PriorityQueue<Truck> pq = new PriorityQueue<>();
        int[] v = new int[N + 1];
        Arrays.fill(v, Integer.MAX_VALUE);
        pq.offer(new Truck(1, 0));

        while(!pq.isEmpty()) {
            Truck t = pq.poll();

            if(t.idx == N) {
                return t.cost;
            }

            for(int i = 0; i < adj[t.idx].size(); i++) {
                // int next = adj[t.idx].get(i);
                // if(v[next] <= t.cost + adjCost[t.idx][next]) continue;
                // v[next] = t.cost + adjCost[t.idx][next];
                int[] next = adj[t.idx].get(i);
                if(v[next[0]] <= t.cost + next[1]) continue;
                v[next[0]] = t.cost + next[1];

                pq.offer(new Truck(next[0], v[next[0]]));
            }
        }

        return -1;
    }

}