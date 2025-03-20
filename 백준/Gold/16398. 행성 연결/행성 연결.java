import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class Edge implements Comparable<Edge> {
        int from, to, cost;

        public Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }

        public int compareTo(Edge o) {
            return this.cost - o.cost;
        }
        
    }

    static class Union {
        int[] uni;
        public Union(int n) {
            uni = new int[n + 1];
            for(int i = 1; i <= n; ++i) uni[i] = i;
        }

        int find(int a) {
            if(uni[a] == a) return a;
            return uni[a] = find(uni[a]);
        }

        boolean setUni(int a, int b) {
            a = find(a);
            b = find(b);

            if(a == b) return false;
            
            uni[a] = b;
            return true;
        }
    }

    static int N;
    static PriorityQueue<Edge> pq = new PriorityQueue<>();
    static Union union;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        union = new Union(N);
        StringTokenizer st;
        for(int from = 0; from < N; ++from) {
            st = new StringTokenizer(br.readLine());
            for(int to = 0; to < N; ++to) {
                int cost = Integer.parseInt(st.nextToken());
                if(from < to) {
                    pq.offer(new Edge(from, to, cost));
                }
            }
        }

        System.out.println(MST());
    }

    static long MST() {
        long result = 0;
        int selected = 0;
        while(!pq.isEmpty() && selected != N - 1) {
            Edge edge = pq.poll();

            if(union.setUni(edge.from, edge.to)) {
                result += edge.cost;
                ++selected;
            }
        }
        
        return result;
    }
}