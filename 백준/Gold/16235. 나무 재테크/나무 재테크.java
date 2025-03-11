import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static class Tree implements Comparable<Tree> {
		int r, c, age;

		public Tree(int r, int c, int age) {
			super();
			this.r = r;
			this.c = c;
			this.age = age;
		}

		@Override
		public int compareTo(Main.Tree o) {
			return Integer.compare(this.age, o.age);
		}
	}
	
	static int N, M, K;
	static int[][] A, map;
	static Queue<Tree> pq = new PriorityQueue<>();
	static Queue<Tree> live = new LinkedList(), dead = new LinkedList();
	
	static int[] dr = {-1, 1, 0, 0, -1, -1, 1, 1};
	static int[] dc = {0, 0, -1, 1, -1, 1, -1, 1};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		A = new int[N][N];
		map = new int[N][N];
		
		for(int i = 0; i < N; i++) {
			Arrays.fill(map[i], 5);
		}
		
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < N; j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			pq.add(new Tree(Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken())));
		}
		
		for(int k = 0; k < K; k++) {
			while(!pq.isEmpty()) {
				
				//봄
				Tree t = pq.poll();
				
				if(map[t.r][t.c] >= t.age) {
					map[t.r][t.c] -= t.age;
					t.age++;
					live.add(t);
				} else {
					dead.add(t);
				}
			}
			//여름
			while(!dead.isEmpty()) {
				Tree d = dead.poll();
				map[d.r][d.c] += d.age / 2; 
			}
				
			//가을
			while(!live.isEmpty()) {
				Tree l = live.poll();
					
				pq.add(l);
				if(l.age % 5 == 0) {
					for(int i = 0; i < dr.length; i++) {
						int nr = l.r + dr[i];
						int nc = l.c + dc[i];
							
						if(nr >= N || nr < 0 || nc >= N || nc < 0) continue;
							
						pq.add(new Tree(nr, nc, 1));
					}
				}
			}
			
			//겨울
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					map[i][j] += A[i][j];
				}
			}
			
		}
		
		System.out.println(pq.size());
		
	}
}