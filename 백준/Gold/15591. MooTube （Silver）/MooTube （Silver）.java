import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	static class Node {
		int to, w;
		public Node(int to, int w) {
			this.to = to;
			this.w = w;
		}
	}
	
	static List<Node>[] adjlist;
	static int[][] adj;
	static int N, Q;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());
		adj = new int[N + 1][N + 1];
		adjlist = new List[N + 1];
		
//		for(int i = 1; i <= N; i++) {
//			Arrays.fill(adj[i], Integer.MAX_VALUE);
//		}
		
		for(int n = 0; n < N - 1; n++) {
			st = new StringTokenizer(br.readLine());
			int p = Integer.parseInt(st.nextToken());
			int q = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			
			adj[p][q] = r;
			adj[q][p] = r;
			
			if(adjlist[p] == null) adjlist[p] = new ArrayList<>();
			if(adjlist[q] == null) adjlist[q] = new ArrayList<>();
			
			adjlist[p].add(new Node(q, r));
			adjlist[q].add(new Node(p, r));
			
		}	
		
		for(int n = 1; n <= N; n++) {
			for(int i = 0; i < adjlist[n].size(); i++) {
				Node node = adjlist[n].get(i);
				dfs(n, node.to, node.w, n);
			}
		}
		
		for(int n = 1; n <= N; n++) {
			for(int i = 0; i < adjlist[n].size(); i++) {
				Node node = adjlist[n].get(i);
				adj[n][node.to] = node.w;
			}
		}
		
		
		StringBuilder sb = new StringBuilder();
		for(int q = 0; q < Q; q++) {
			st = new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			
			int count = 0;
			for(int i = 1; i <= N; i++) {
				if(adj[v][i] >= k && v != i) count++;
			}
			sb.append(count + "\n");
		}
		System.out.println(sb);
	}
	
	static void dfs(int start, int cur, int min, int pre) {
		
//		if(cur < start) {
//			for(int i = 1; i < N + 1; i++) {
//				if(adj[start][i] == Integer.MAX_VALUE) adj[start][i] = Math.min(adj[cur][i], min);
//				//else adj[start][i] = Math.min(adj[start][i], adj[cur][i]);
//			}
//			return;
//		}
		
		if(adj[start][cur] == 0) adj[start][cur] = min;
//		adj[cur][start] = Math.min(min, adj[cur][start]);
		
		for(int i = 0; i < adjlist[cur].size(); i++) {
			Node n = adjlist[cur].get(i);
			if(n.to == pre) continue;
			
			dfs(start, n.to, Math.min(min, n.w), cur);
		}
	}
	
}

