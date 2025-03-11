import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, M, H;
    static int[][] adj;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        adj = new int[N + 1][H + 1];
        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            adj[b][a] = b + 1;
            adj[b + 1][a] = b;
        }

        int count = 0;
        boolean flag = false;
        for(; count < 4; count++) {
            flag = dfs(1, count);
            if(flag) break;
        }

        count = flag ? count : -1;
        System.out.println(count);
    }

    static boolean dfs(int i, int num) {
        if(num == 0) return sim();
        if(i == N) return false;

        for(int j = 1; j <= H; j++) {
            if(adj[i][j] == 0 && adj[i + 1][j] == 0) {
                adj[i][j] = i + 1;
                adj[i + 1][j] = i;
                if(dfs(i, num - 1)) return true;
                adj[i][j] = 0;
                adj[i + 1][j] = 0;
            }
        }

        return dfs(i + 1, num);
    }

    static boolean sim() {
        for(int i = 1; i <= N; i++) {
            int cur = i;
            for(int j = 1; j <= H; j++) {
                if(adj[cur][j] != 0) cur = adj[cur][j];
            }

            if(cur != i) return false;
        }
        return true;
    }
}