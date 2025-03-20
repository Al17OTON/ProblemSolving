import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static class Coins {
        Coin a, b;
        public Coins(Coin a, Coin b) {this.a = a; this.b = b;}
    }
    static class Coin {
        int r, c;
        public Coin(int r, int c) {this.r = r; this.c = c;}
    }

    static int N, M;
    static char[][] map;
    static Coins o;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new char[N][];
        Coin a = null, b = null;
        for(int n = 0; n < N; ++n) {
            map[n] = br.readLine().toCharArray();
            for(int m = 0; m < M; ++m) {
                if(map[n][m] == 'o') {
                    if(a == null) a = new Coin(n, m);
                    else b = new Coin(n, m);

                    map[n][m] = '.';
                } 
            }
        }

        o = new Coins(a, b);

        System.out.println(BFS());
    }

    static int BFS() {
        Queue<Coins> q = new LinkedList<>();
        q.offer(o);

        int time = 0;
        while(!q.isEmpty() && time <= 10) {
            int size = q.size();

            for(int s = 0; s < size; ++s) {
                Coins p = q.poll();

                boolean a = isOut(p.a);
                boolean b = isOut(p.b);

                if(a && b) continue;
                else if(a || b) {
                    return time;
                }

                for(int d = 0; d < 4; ++d) {
                    Coin na = new Coin(p.a.r + dr[d], p.a.c + dc[d]);
                    Coin nb = new Coin(p.b.r + dr[d], p.b.c + dc[d]);

                    if(na.r < N && na.r >= 0 && na.c < M && na.c >= 0 && map[na.r][na.c] == '#') {
                        na.r = p.a.r;
                        na.c = p.a.c;
                    }
                    if(nb.r < N && nb.r >= 0 && nb.c < M && nb.c >= 0 && map[nb.r][nb.c] == '#') {
                        nb.r = p.b.r;
                        nb.c = p.b.c;
                    }

                    q.offer(new Coins(na, nb));
                }
            }
            ++time;
        }


        return -1;
    }

    static boolean isOut(Coin c) {
        return c.r >= N || c.r < 0 || c.c >= M || c.c < 0;
    }

}