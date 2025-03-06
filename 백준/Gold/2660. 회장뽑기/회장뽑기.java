import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class President implements Comparable<President>{
        int no, cost;

        public President(int no, int cost) {
            this.no = no;
            this.cost = cost;
        }

        public int compareTo(President o) {
            if(this.cost == o.cost) return this.no - o.no;
            return this.cost - o.cost;
        }
        
    }

    static int N;
    static ArrayList<Integer>[] adj;
    static int[][] dist;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        StringTokenizer st;

        dist = new int[N + 1][N + 1];
        adj = new ArrayList[N + 1];
        for(int n = 1; n <= N; n++) adj[n] = new ArrayList<>();

        while(true) {
            st = new StringTokenizer(br.readLine());

            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            if(from == -1) break;

            adj[from].add(to);
            adj[to].add(from);
        }   

        for(int n = 1; n <= N; n++) {
            dijkstra(n);
        }

        PriorityQueue<President> pq = new PriorityQueue<>();
        for(int n = 1; n <= N; n++) {
            int max = 0;
            for(int nn = 1; nn <= N; nn++) {
                max = Math.max(max, dist[n][nn]);
            }
            pq.offer(new President(n, max));
        }

        StringBuilder sb = new StringBuilder();
        int min = pq.peek().cost, count = 0;
        while(!pq.isEmpty() && pq.peek().cost == min) {
            sb.append(pq.poll().no).append(" ");
            count++;
        }
        
        System.out.println(min + " " + count);
        System.out.println(sb);

    }

    static void dijkstra(int start) {
        Arrays.fill(dist[start], 1000000);
        dist[start][start] = 0;
        boolean[] v = new boolean[N + 1];

        int cur = start;
        while(true) {
            for(int i = 0; i < adj[cur].size(); i++) {
                int to = adj[cur].get(i);
                dist[start][to] = Math.min(dist[start][cur] + 1, dist[start][to]); 
            }
            v[cur] = true;
            
            int next = 0;
            for(int n = 1; n <= N; n++) {
                if(!v[n] && dist[start][next] > dist[start][n]) next = n;
            }
            if(next == 0) break;
            cur = next;
        }
    }
}