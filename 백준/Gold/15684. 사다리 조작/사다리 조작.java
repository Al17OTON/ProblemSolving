import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static class Ladder {
        int a, b;

        public Ladder(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
	
    static int[][] map;
    static boolean[][] v;
    static List<Ladder> arr = new ArrayList<>();

    static int N, M, H;
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        map = new int[N + 1][H + 1];
        v = new boolean[N + 1][H + 1];
        boolean[] check = new boolean[N * H];

        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            map[b][a] = b + 1;
            map[b + 1][a] = b;
        }

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= H; j++) {
                arr.add(new Ladder(j, i));
            }
        }


        int i = 0;
        for(i = 0; i <= 3; i++) {
            //if(makeLadder(1, 1, i)) break;
            if(permutation(new Ladder[i], 0, 0, check)) break;
        }
        System.out.println((i == 4 ? -1 : i));
    }

    static boolean permutation(Ladder[] sel, int idx, int depth, boolean[] v) {
        if(idx == sel.length) {

            for(int i = 0; i < idx; i++) {
                Ladder l = sel[i];
                map[l.b][l.a] = l.b + 1;
                map[l.b + 1][l.a] = l.b;
            }
            boolean flag = true;
            for(int i = 1; i <= N; i++) {
                if(!sim(i, 1, i)) {
                	flag = false;
                	break;
                }
            }
            
            for(int i = 0; i < idx; i++) {
                Ladder l = sel[i];
                map[l.b][l.a] = 0;
                map[l.b + 1][l.a] = 0;
            }
            
            return flag;
        }
        if(depth == arr.size()) {
            return false;
        }

        for(int i = 0; i < arr.size(); i++) {
            if(!v[i]) {
                Ladder l = arr.get(i);
                if(map[l.b][l.a] != 0 || l.b + 1 > N || map[l.b + 1][l.a] != 0) continue;
                

                v[i] = true;
                sel[idx] = arr.get(i);
                if(permutation(sel, idx + 1, depth + 1, v)) return true;
                v[i] = false;

            }
        }

        return false;
    }


    static boolean sim(int r, int c, int start) {
        if(c == H + 1) {    
            if(r == start) return true; //시작 세로선 번호와 도착 세로선 번호가 일치한다면
            return false;
        }

        v[r][c] = true;

        boolean res;

        if(map[r][c] != 0 && !v[map[r][c]][c]) {
            res = sim(map[r][c], c, start);
        } else {
            res = sim(r, c + 1, start);
        }

        v[r][c] = false;

        return res;
    }
	
}



