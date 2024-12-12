import java.util.Scanner;

public class Main {

	static int N, R, C;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		R = sc.nextInt();
		C = sc.nextInt();
		
		int lev = (int)Math.pow(2, N);
		
		System.out.println(recursive(0, 0, lev, 0));
		
	}

	static long recursive(int r, int c, int lev, long startNum) {
		if(lev == 2) {
			if(r == R && c == C) return startNum;
			else if(r == R && c + 1 == C) return startNum + 1;
			else if(r + 1 == R && c == C) return startNum + 2;
			else return startNum + 3;
		}
		
		int tmp = lev / 2;
		long add = (lev / 4) * lev;
		
		if(r <= R && R < r + tmp && c <= C && C < c + tmp) {
			
			return recursive(r, c, tmp, startNum);
			
		} else if(r <= R && R < r + tmp && c + tmp <= C && C < c + lev) {
			
			return recursive(r, c + tmp, tmp, startNum + add);
			
		} else if(r + tmp <= R && R < r + lev && c <= C && C < c + tmp) {
			
			return recursive(r + tmp, c, tmp, startNum + add * 2);
			
		} else {
			
			return recursive(r + tmp, c + tmp, tmp, startNum + add * 3);
			
		}
	}
}
