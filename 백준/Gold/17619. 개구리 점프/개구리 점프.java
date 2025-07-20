import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static class Log {
        int idx;
        long x1, x2, y;

        public Log(int idx, long x1, long x2, long y) {
            this.x1 = x1;
            this.x2 = x2;
            this.y = y;
            this.idx = idx;
        }
    }

    static class Union {
        int[] uni;

        public Union(int n) {
            uni = new int[n + 1];
            for(int i = 1; i <= n; ++i) uni[i] = i;
        }

        int find(int x) {
            if(uni[x] == x) return x;
            return uni[x] = find(uni[x]);
        }
        void setUni(int a, int b) {
            a = find(a);
            b = find(b);

            if(a == b) return;

            uni[b] = a;
        }

        boolean isUni(int a, int b) {
            return find(a) == find(b);
        }
    } 
    
    static int N, Q;
    static List<Log> logs = new ArrayList<>();
    static Union union;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
        union = new Union(N);

        for(int n = 1; n <= N; ++n) {
            st = new StringTokenizer(br.readLine());
            long x1, x2, y;
            x1 = Long.parseLong(st.nextToken());
            x2 = Long.parseLong(st.nextToken());
            y = Long.parseLong(st.nextToken());

            logs.add(new Log(n, x1, x2, y));
        }

        logs.sort((a, b) -> Long.compare(a.x1, b.x1));

        for(int n = 0; n < N; ++n) {
            Log log = logs.get(n);

            for(int i = n + 1; i < N; ++i) {
                Log log2 = logs.get(i);
                if(log.x2 < log2.x1) break;
                if(log.y == log2.y) continue;

                union.setUni(log.idx, log2.idx);
            }
        }

        StringBuilder sb = new StringBuilder();

        for(int q = 0; q < Q; ++q) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            sb.append(union.isUni(from, to) ? "1\n" : "0\n");
        }
        System.out.println(sb);
    }    
}