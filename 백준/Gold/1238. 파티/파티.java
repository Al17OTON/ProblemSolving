import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class Student implements Comparable<Student> {
        int idx, cost;
        public Student(int idx, int cost) {
            this.idx = idx;
            this.cost = cost;
        }
        public int compareTo(Student o) {
            return this.cost - o.cost;
        }
    }

    static int N, M, X;
    static ArrayList<Integer>[] adj;
    static int[][] adjCost;
    static int[][] totalCost;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());
        
        adj = new ArrayList[N + 1];
        adjCost = new int[N + 1][N + 1];
        totalCost = new int[N + 1][N + 1];
        for(int n = 1; n <= N; n++) {
            adj[n] = new ArrayList<>();
            Arrays.fill(totalCost[n], Integer.MAX_VALUE);
        }

        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            
            adj[from].add(to);
            adjCost[from][to] = cost;
        }

        for(int i = 1; i <= N; i++) {
            dijkstra(i);
        }

        int MAX = 0;
        for(int i = 1; i <= N; i++) {
            MAX = Math.max(MAX, totalCost[i][X] + totalCost[X][i]);
        }
        System.out.println(MAX);
    }

    static void dijkstra(int idx) {
        PriorityQueue<Student> pq = new PriorityQueue<>();
        pq.offer(new Student(idx, 0));
        totalCost[idx][idx] = 0;

        while(!pq.isEmpty()) {
            Student s = pq.poll();

            if(s.cost > totalCost[idx][s.idx]) continue;

            for(int i = 0; i < adj[s.idx].size(); i++) {
                int next = adj[s.idx].get(i);
                if(totalCost[idx][next] <= s.cost + adjCost[s.idx][next]) continue;
                totalCost[idx][next] = s.cost + adjCost[s.idx][next];

                pq.offer(new Student(next, totalCost[idx][next]));
            }
        }
    }
}