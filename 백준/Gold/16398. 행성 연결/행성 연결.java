import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[][] adj;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        adj = new int[N][N];
        StringTokenizer st;
        for(int from = 0; from < N; ++from) {
            st = new StringTokenizer(br.readLine());
            for(int to = 0; to < N; ++to) {
                adj[from][to] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(MST());
    }

    static long MST() {
        int[] dist = new int[N];
        long result = 0;
        boolean[] set = new boolean[N];
        Arrays.fill(dist, Integer.MAX_VALUE);

        set[0] = true;
        dist[0] = 0;

        int selected = 1;
        int minIdx = findMinIdx(0, set, dist);

        while(selected != N) {
            set[minIdx] = true;

            minIdx = findMinIdx(minIdx, set, dist);

            ++selected;
        }

        for(int i = 0; i < N; ++i) result += dist[i];

        return result;
    }

    static int findMinIdx(int from, boolean[] set, int[] dist) {
        int idx = 0, minDist = Integer.MAX_VALUE;

        for(int i = 0; i < N; ++i) {
            if(i != from && !set[i]) {
                dist[i] = Math.min(dist[i], adj[from][i]);
                if(dist[i] < minDist){
                    minDist = dist[i];
                    idx = i;
                }
                
            }
        }
        return idx;
    }
    
    
}