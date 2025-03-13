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

        public int find(int a) {
            if(uni[a] == a) return a;
            return uni[a] = find(uni[a]);
        }

        public boolean setUni(int a, int b) {
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
    static int N, M, T;
    static PriorityQueue<Road> pq = new PriorityQueue<>();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        for(int m = 0; m < M; m++) {
            int A, B, C;
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());
            pq.offer(new Road(A, B, C));
        }

        System.out.println(LST());
    }

    static int LST() {
        Union union = new Union(N);
        int cost = 0, inflation = 0;
        while(!pq.isEmpty()) {
            Road p = pq.poll();
            if(union.setUni(p.from, p.to)) {
                cost += p.cost + inflation;
                inflation += T;
            }
        }

        return cost;
    }
}