import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    static int N;
    static int[] a;
    static PriorityQueue<Integer> pq = new PriorityQueue<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        a = new int[N + 1];

        for(int n = 1; n <= N; n++) {
            a[n] = Integer.parseInt(br.readLine());
        }

        boolean[] v = new boolean[N + 1];
        for(int n = 1; n <= N; n++) {
            v[n] = true;
            dfs(n, n, v);
            v[n] = false;
        }

        StringBuilder sb = new StringBuilder();
        sb.append(pq.size()).append("\n");

        while(!pq.isEmpty()) sb.append(pq.poll()).append("\n");
        System.out.println(sb);
        
    }

    static void dfs(int idx, int start, boolean[] v) {
        if(!v[a[idx]]) {
            v[a[idx]] = true;
            dfs(a[idx], start, v);
            v[a[idx]] = false;
        }
        if(a[idx] == start) pq.offer(start);
    }
    
}