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
    static ArrayList<int[]>[] adj;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        adj = new ArrayList[N + 1];
        for(int n = 1; n <= N; n++) {
            adj[n] = new ArrayList<int[]>();
        }

        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            adj[a].add(new int[] {b, c});
            adj[b].add(new int[] {a, c});
        }

        for(int n = 1; n <= N; n++) adj[n].sort((a, b) -> a[1] - b[1]);

        System.out.println(dijkstra());
    }
    
    static int dijkstra() {
        PriorityQueue<Truck> pq = new PriorityQueue<>();
        int[] v = new int[N + 1];
        Arrays.fill(v, Integer.MAX_VALUE);
        pq.offer(new Truck(1, 0));

        while(!pq.isEmpty()) {
            Truck t = pq.poll();

            if(v[t.idx] < t.cost) continue;

            for(int i = 0; i < adj[t.idx].size(); i++) {
                int[] next = adj[t.idx].get(i);
                if(v[next[0]] <= t.cost + next[1]) continue;
                v[next[0]] = t.cost + next[1];

                pq.offer(new Truck(next[0], v[next[0]]));
            }
        }

        return v[N];
    }

}