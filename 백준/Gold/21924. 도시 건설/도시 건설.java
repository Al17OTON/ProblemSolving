import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class Union {
        int[] uni;
        public Union(int n) {
            uni = new int[n + 1];
            for(int i = 1; i <= n; i++) {
                uni[i] = i;
            }
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

    static class Road implements Comparable<Road> {
        int from, to, cost;

        public Road(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }

        public int compareTo(Road o) {
            return this.cost - o.cost;
        }

    }
    static Union union;
    static int N, M;
    static long maxCost = 0;
    static PriorityQueue<Road> pq = new PriorityQueue<>();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        union = new Union(N);
        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            pq.offer(new Road(from, to, cost));
            maxCost += cost;
        }

        long minCost = 0;
        int selected = 0;
        while(!pq.isEmpty()) {
            Road p = pq.poll();

            if(union.setUni(p.from, p.to)) {
                minCost += p.cost;
                selected++;
            }
        }

        System.out.println((selected != N - 1 ? -1 : maxCost - minCost));
    }
}