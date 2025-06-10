import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static class Node {
		int to, w;
		public Node(int to, int w) {
			this.to = to;
			this.w = w;
		}
	}
    static int N, Q;
    static int[][] adj;
    static List<Node>[] adjlist;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        adj = new int[N + 1][N + 1];
        adjlist = new List[N + 1];
        for(int i = 0; i <= N; ++i) adjlist[i] = new ArrayList<>();

        for(int n = 0; n < N - 1; ++n) {
            st = new StringTokenizer(br.readLine());
            int p, q, r;
            p = Integer.parseInt(st.nextToken());
            q = Integer.parseInt(st.nextToken());
            r = Integer.parseInt(st.nextToken());

            adj[p][q] = r;
            adj[q][p] = r;

            adjlist[p].add(new Node(q, r));
            adjlist[q].add(new Node(p, r));
        }
        for(int q = 0; q < Q; ++q) {
            st = new StringTokenizer(br.readLine());
            int k, v;
            k = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            
            for(int i = 0; i < adjlist[v].size(); ++i) {
                dfs(v, adjlist[v].get(i).to, adjlist[v].get(i).w, v);
            }

            int count = 0;
            for(int i = 1; i <= N; ++i) {
                if(adj[v][i] >= k) {
                    ++count;
                }
            }

            sb.append(count).append("\n");
        }
        System.out.println(sb);
    }

    static void dfs(int start, int cur, int min, int pre) {
        if(adj[start][cur] == 0) adj[start][cur] = min;
        
        for(int i = 0; i < adjlist[cur].size(); ++i) {
            Node n = adjlist[cur].get(i);
            if(n.to == pre) continue;
            dfs(start, n.to, Math.min(min, n.w), cur);
        }
    }

}