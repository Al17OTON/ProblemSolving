import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class Road implements Comparable<Road> {
        int a, b, c;
        public Road(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
        @Override
        public int compareTo(Road o) {
            return Integer.compare(this.c, o.c);
        }

    }

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

        // 같은 집합이면 false, 다른 집합이면 true 및 합치기
        boolean merge(int a, int b) {
            a = find(a);
            b = find(b);
            
            if(a == b) return false;

            uni[a] = b;
            return true;
        }


    }
    
    static int N, M;
    static PriorityQueue<Road> pq = new PriorityQueue<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
    
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            pq.add(new Road(a, b, c));
        }

        System.out.println(kruskal());
    }

    static int kruskal() {
        int cost = 0, count = 0;
        Union union = new Union(N);
        
        while(!pq.isEmpty() && count < N - 2) {
            Road r = pq.poll();
            if(union.merge(r.a, r.b)) {
                cost += r.c;
                count++;
            }
        }
        return cost;
    }
}