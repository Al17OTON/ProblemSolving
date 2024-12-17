import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static class Pos {
        int l, r, c;

        public Pos(int l, int r, int c) {
            this.l = l;
            this.r = r;
            this.c = c;
        }
    }

    static int L, R, C;
    static char[][][] map = new char[31][31][];
    static int[] dr = {-1, 1, 0, 0, 0, 0};
    static int[] dc = {0, 0, -1, 1, 0, 0};
    static int[] dl = {0, 0, 0, 0, -1, 1};
    static Pos start, end;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        while(true) {
            st = new StringTokenizer(br.readLine());
            L = Integer.parseInt(st.nextToken());
            R = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());
            if(L == 0) break;

            for(int l = 0; l < L; l++) {
                for(int r = 0; r < R; r++) {
                    map[l][r] = br.readLine().toCharArray();
                    for(int c = 0; c < C; c++) {
                        if(map[l][r][c] == 'S') start = new Pos(l, r, c);
                        else if(map[l][r][c] == 'E') end = new Pos(l, r, c);
                    }
                }
                br.readLine();
            }

            int res = bfs();
            if(res == -1) sb.append("Trapped!\n");
            else sb.append("Escaped in " + res + " minute(s).\n");
        }
        
        System.out.println(sb);

    }

    static int bfs() {
        boolean[][][] v = new boolean[L][R][C];
        Queue<Pos> q = new LinkedList<>();
        v[start.l][start.r][start.c] = true;
        q.offer(start);
        int time = 0;

        while(!q.isEmpty()) {
            int size = q.size();
            for(int s = 0; s < size; s++) {
                Pos p = q.poll();

                if(p.l == end.l && p.r == end.r && p.c == end.c) {
                    return time;
                }

                for(int d = 0; d < 6; d++) {
                    int nr = p.r + dr[d];
                    int nc = p.c + dc[d];
                    int nl = p.l + dl[d];

                    if(nr >= R || nr < 0 || nc >= C || nc < 0 || nl >= L || nl < 0 || v[nl][nr][nc] || map[nl][nr][nc] == '#') continue;
                    v[nl][nr][nc] = true;
                    q.offer(new Pos(nl, nr, nc));
                }
            }
            time++;
        }

        return -1;
    }
}