import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int[] map = new int[101];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            map[from] = to;
        }
        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            map[from] = to;
        }

        System.out.println(bfs());
    }

    static int bfs() {
        Queue<int[]> q = new LinkedList<>();
        boolean[] v = new boolean[101];
        v[1] = true;
        q.offer(new int[] {1, 0});

        while(!q.isEmpty()) {
            int[] p = q.poll();

            if(p[0] == 100) return p[1];

            for(int i = 1; i < 7; i++) {
                int next = p[0] + i;
                if(next > 100 || v[next]) continue;
                v[next] = true;

                if(map[next] != 0) {
                    next = map[next];
                    if(v[next]) continue; 
                    v[next] = true;
                }

                q.offer(new int[] {next, p[1] + 1});
            }
        }
        return -1;
    }
}