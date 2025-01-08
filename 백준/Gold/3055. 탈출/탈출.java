import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static class Hadgehog {
        int r, c;
        public Hadgehog(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static int R, C;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    static char[][] map;
    static Queue<Hadgehog> q = new LinkedList<>();
    static Queue<Hadgehog> water = new LinkedList<>();
    static Hadgehog goal;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        map = new char[R][];
        for(int r = 0; r < R; r++) {
            map[r] = br.readLine().toCharArray();
            for(int c = 0; c < C; c++) {
                if(map[r][c] == 'S') {
                    q.add(new Hadgehog(r, c));
                    map[r][c] = '.';
                } else if(map[r][c] == '*') {
                    water.add(new Hadgehog(r, c));
                } else if(map[r][c] == 'D') {
                    goal = new Hadgehog(r, c);
                }
            }
        }
        int result = sim();
        System.out.println(result == -1 ? "KAKTUS" : result);
    }

    static int sim() {
        int time = 0;
        boolean[][] v = new boolean[R][C];
        v[q.peek().r][q.peek().c] = true;

        while(!q.isEmpty()) {
            int waterSize = water.size();
            for(int i = 0; i < waterSize; i++) {
                Hadgehog w = water.poll();
                for(int d = 0; d < 4; d++) {
                    int nr = w.r + dr[d];
                    int nc = w.c + dc[d];
                    if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                    if(map[nr][nc] == '.') {
                        map[nr][nc] = '*';
                        water.add(new Hadgehog(nr, nc));
                    }
                }
            }

            int qSize = q.size();
            for(int i = 0; i < qSize; i++) {
                Hadgehog h = q.poll();
                if(h.r == goal.r && h.c == goal.c) {
                    return time;
                }

                for(int d = 0; d < 4; d++) {
                    int nr = h.r + dr[d];
                    int nc = h.c + dc[d];
                    if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                    if((map[nr][nc] == '.' || map[nr][nc] == 'D') && !v[nr][nc]) {
                        v[nr][nc] = true;
                        q.add(new Hadgehog(nr, nc));
                    }
                }
            }
            time++;
        }

        return -1;
    }
}