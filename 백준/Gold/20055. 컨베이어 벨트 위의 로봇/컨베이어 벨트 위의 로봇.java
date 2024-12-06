import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static class Belt {
		int hp, index;
		boolean isOccupy = false;

		public Belt(int hp, int index) {
			super();
			this.hp = hp;
			this.index = index;
		}
	}
	
	static class Conveyer {
		int load, unload, n;
		Belt[] belt;
		
		public Conveyer(Belt[] b, int n) {
			load = 0;
			unload = n - 1;
			belt = b;
			this.n = n;
		}
		
		public void rotate() {
			load = load - 1 < 0 ? 2 * n - 1 : load - 1;
			unload = unload - 1 < 0 ? 2 * n - 1 : unload - 1;
		}
		
		public Belt getNext(int idx) {
			idx = idx + 1 >= 2 * n ? 0 : idx + 1;
			return belt[idx];
		}
	}
	
	static Conveyer con;
	static int N, K;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		Belt[] b = new Belt[N * 2];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N * 2; i++) {
			b[i] = new Belt(Integer.parseInt(st.nextToken()), i);
		}
		con = new Conveyer(b, N);
		
		Queue<Belt> q = new ArrayDeque<>();
		int k = 0, lev = 0;
		while(k < K) {
			lev++;
			con.rotate();
			
			int size = q.size();
			for(int i = 0; i < size; i++) {
				Belt robot = q.poll();
				if(con.unload == robot.index) {
					robot.isOccupy = false;
					continue;
				}
				
				Belt next = con.getNext(robot.index);
				if(next.hp == 0 || next.isOccupy) {
					q.offer(robot);
					continue;
				}
				robot.isOccupy = false;
				
				next.hp--;
				if(next.hp == 0) k++;
				
				if(con.unload == next.index) continue;
				
				next.isOccupy = true;
				q.offer(next);
			}
			
			Belt newRobot = con.belt[con.load];
			if(newRobot.hp > 0) {
				newRobot.hp--;
				newRobot.isOccupy = true;
				q.offer(newRobot);
				if(newRobot.hp == 0) k++;
			}
			
		}
		System.out.println(lev);
	}
}
