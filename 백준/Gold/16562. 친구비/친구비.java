import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static class Union {
        int[] uni, cost;
        public Union(int n, int[] cost) {
            uni = new int[n + 1];
            this.cost = cost;
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

            cost[b] = Math.min(cost[a], cost[b]);
            uni[a] = b;
            
            return true;
        }

        int getCost(int a) {return cost[find(a)];}
    }

    static int N, M, K;
    static Union union;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        
        int[] costs = new int[N + 1];
        st = new StringTokenizer(br.readLine());
        for(int n = 1; n <= N; ++n) {
            costs[n] = Integer.parseInt(st.nextToken());
        }

        union = new Union(N, costs);
        for(int m = 0; m < M; ++m) {
            st = new StringTokenizer(br.readLine());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            union.setUni(v, w);
        }

        int result = greedy();
        System.out.println(result > K ? "Oh no" : result);
    }

    static int greedy() {
        int need = 0;
        
        for(int i = 1; i <= N; ++i) {
            int cost = union.getCost(i);
            if(union.setUni(0, i)) need += cost;

            if(need > K) break;
        }

        return need;
    }
}