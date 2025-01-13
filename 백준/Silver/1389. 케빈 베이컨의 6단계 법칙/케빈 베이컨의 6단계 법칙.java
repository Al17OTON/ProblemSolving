import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static ArrayList<Integer>[] adj;
    static boolean[][] hash;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        adj = new ArrayList[N + 1];
        hash = new boolean[N + 1][N + 1];
        
        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            if(hash[from][to]) continue;

            if(adj[from] == null) adj[from] = new ArrayList();
            if(adj[to] == null) adj[to] = new ArrayList<>();
            
            hash[from][to] = true;
            hash[to][from] = true;
            adj[from].add(to);
            adj[to].add(from);
        }

        int MIN = Integer.MAX_VALUE;
        int result = -1;
        for(int i = 1; i <= N; i++) {
            int kevin_bacon = getKevinBacon(i);
            if(MIN > kevin_bacon) {
                MIN = kevin_bacon;
                result = i;
            }
        }
        System.out.println(result);
    }

    static int getKevinBacon(int idx) {
        int kevin_bacon = 0;
        Queue<Integer> q = new LinkedList<>();
        q.offer(idx);
        boolean[] v = new boolean[N + 1];
        v[idx] = true;

        int level = 1;
        while(!q.isEmpty()) {
            for(int size = q.size(); size > 0; size--) {
                int p = q.poll();
            
                for(int i = 0; i < adj[p].size(); i++) {
                    int next = adj[p].get(i);
                    if(v[next]) continue;
                    v[next] = true;
                    kevin_bacon += level;
                    q.offer(next);
                }
            }

            level++;
        }
        return kevin_bacon;
    }
}