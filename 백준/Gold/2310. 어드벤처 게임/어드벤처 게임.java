import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	static class Room {
		char type;
		int num;
		
		public Room(char type, int num) {
			super();
			this.type = type;
			this.num = num;
		}
	}
	
	static int N;
	static List<Integer>[] adj;
	static Room[] room;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		while(true) {
			N = Integer.parseInt(br.readLine());
			if(N == 0) break;
			adj = new List[N + 1];
			room = new Room[N + 1];
			
			for(int n = 1; n <= N; n++) {
				st = new StringTokenizer(br.readLine());
				adj[n] = new ArrayList<>();
				room[n] = new Room(st.nextToken().charAt(0), Integer.parseInt(st.nextToken()));
				
				while(true) {
					int in = Integer.parseInt(st.nextToken());
					if(in == 0) break;
					adj[n].add(in);
				}
			}
			
			boolean[] v = new boolean[N + 1];
			v[1] = true;
			if(dfs(1, 0, v)) System.out.println("Yes");
			else System.out.println("No");
		}
	}
	
	static boolean dfs(int idx, int money, boolean[] v) {
		Room cur = room[idx];
		
		if(cur.type == 'L') money = money < cur.num ? cur.num : money;
		else if(cur.type == 'T') {
			if(money < cur.num) return false;
			money = money - cur.num;
		}
		
		if(idx == N) {
			return true;
		}
		
		for(int i = 0; i < adj[idx].size(); i++) {
			int next = adj[idx].get(i);
			if(!v[next]) { 
				v[next] = true;
				if(dfs(next, money, v)) return true;
				v[next] = false;
			}
		}
		return false;
	}
}
