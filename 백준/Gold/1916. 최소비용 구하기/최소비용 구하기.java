import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class Node implements Comparable<Node>{
        int to, cost;
        public Node(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
        @Override
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }
    static int N, M, start, end;
    static ArrayList<Node>[] adj;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        adj = new ArrayList[N + 1];

        for(int n = 1; n <= N; n++) adj[n] = new ArrayList<>();

        StringTokenizer st;
        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            adj[from].add(new Node(to, cost));
        }
        st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());

        System.out.println(bfs());
    }

    static int bfs() {
        int[] v = new int[N + 1];
        for(int n = 1; n <= N; n++) {
            adj[n].sort((a, b) -> a.cost - b.cost);
            v[n] = -1;
        }
        PriorityQueue<Node> pq = new PriorityQueue<>();

        v[start] = 0;
        pq.offer(new Node(start, 0));

        while(!pq.isEmpty()) {
            Node n = pq.poll();

            if(n.to == end) {
                return n.cost;
            }

            for(int i = 0; i < adj[n.to].size(); i++) {
                Node tmp = adj[n.to].get(i);
                if(v[tmp.to] != -1 && v[tmp.to] <= n.cost + tmp.cost) continue;
                v[tmp.to] = n.cost + tmp.cost;
                pq.offer(new Node(tmp.to, n.cost + tmp.cost));
            }
        }
        return -1;
    }
}