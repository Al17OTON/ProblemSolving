import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static List<Integer>[] adjHeavy, adjLight;
    static int N, M;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        adjHeavy = new List[N + 1];
        adjLight = new List[N + 1];
        for(int n = 1; n <= N; ++n) {
            adjHeavy[n] = new ArrayList<>();
            adjLight[n] = new ArrayList<>();
        }
        StringTokenizer st;
        for(int m = 0; m < M; ++m) {
            st = new StringTokenizer(br.readLine());
            int heavy = Integer.parseInt(st.nextToken());
            int light = Integer.parseInt(st.nextToken());
            
            adjHeavy[heavy].add(light);
            adjLight[light].add(heavy);
        }

        StringBuilder sb = new StringBuilder();
        for(int n = 1; n <= N; ++n) {
            boolean[] v = new boolean[N + 1];
            int res = dfs(n, v, adjHeavy);

            // 위에서 시작점을 한번 방문했으므로 다시 방문할 수 있도록 변경
            v[n] = false;
            // 위에서 시작점을 한번 방문했으므로 중복 방문한 경우를 제외하기
            res += dfs(n, v, adjLight) - 1;

            sb.append(N - res);
            sb.append("\n");
        }

        System.out.println(sb);
    }

    static int dfs(int start, boolean[] v, List<Integer>[] adj) {
        if(v[start]) return 0;
        v[start] = true;
        int res = 1;

        for(int i = 0; i < adj[start].size(); ++i) {
            int next = adj[start].get(i);
            res += dfs(next, v, adj);
        }

        return res;
    }
}