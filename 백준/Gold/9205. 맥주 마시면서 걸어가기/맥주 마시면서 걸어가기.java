import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static class Shop {
		int r, c;

		public Shop(int r, int c) {
			super();
			this.r = r;
			this.c = c;
		}
	}
	
	static int N;
	static Shop[] shop;
	static int[][] dist;
	static int INF = 987654;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for(int t = 0; t < T; t++) {
			N = Integer.parseInt(br.readLine());
			shop = new Shop[N + 2];
			dist = new int[N + 2][N + 2];
			for(int n = 0; n < N + 2; n++) {
				st = new StringTokenizer(br.readLine());
				shop[n] = new Shop(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			}
			
			for(int i = 0; i < N + 2; i++) {
				for(int j = 0; j < N + 2; j++) {
					if(i != j) {
						dist[i][j] = INF;
						int len = getLen(shop[i].r, shop[i].c, shop[j].r, shop[j].c);
						if(len <= 1000) {
							dist[i][j] = len;
						}
					}
				}
			}
			
			for(int k = 0; k < N + 2; k++) {
				for(int i = 0; i < N + 2; i++) {
					for(int j = 0; j < N + 2; j++) {
						if(dist[i][j] > dist[i][k] + dist[k][j]) 
							dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
			
			if(dist[0][N + 1] != INF) System.out.println("happy");
			else System.out.println("sad");
			
		}
	}
	
	static int getLen(int ar, int ac, int br, int bc) {
		return Math.abs(ar - br) + Math.abs(ac - bc);
	}
}
