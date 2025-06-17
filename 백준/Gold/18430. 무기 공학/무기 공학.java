import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static class Pos {
        int r, c;
        public Pos(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static class Weapon {
        int power;
        Pos a, b, c;
        public Weapon(int power, Pos a, Pos b, Pos c) {
            this.power = power;
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }
    static int N, M;
    static int[][] map;
    static List<Weapon> weapons = new ArrayList<>();
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    static int[][] parts = {
        {2, 1}, {2, 0}, {0, 3}, {3, 1}
    };
    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bufferedReader.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][M];

        for(int n = 0; n < N; ++n) {
            st = new StringTokenizer(bufferedReader.readLine());
            for(int m = 0; m < M; ++m) {
                map[n][m] = Integer.parseInt(st.nextToken());
            }
        }
        makeWeapon();

        System.out.println(combination(0, 0, new boolean[N][M]));

    }

    static int combination(int idx, int power, boolean[][] sel) {
        int max = power;
        for(int i = idx; i < weapons.size(); ++i) {
            Weapon weapon = weapons.get(i);
            if(sel[weapon.a.r][weapon.a.c] || sel[weapon.b.r][weapon.b.c] || sel[weapon.c.r][weapon.c.c]) continue;
            sel[weapon.a.r][weapon.a.c] = true; 
            sel[weapon.b.r][weapon.b.c] = true;
            sel[weapon.c.r][weapon.c.c] = true;
            
            max = Math.max(combination(i + 1, power + weapon.power, sel), max);

            sel[weapon.a.r][weapon.a.c] = false; 
            sel[weapon.b.r][weapon.b.c] = false;
            sel[weapon.c.r][weapon.c.c] = false;
        }
        return max;
    }

    static void makeWeapon() {
        for(int r = 0; r < N; ++r) {
            for(int c = 0; c < M; ++c) {
                for(int[] part : parts) {
                    int ar = r + dr[part[0]];
                    int ac = c + dc[part[0]];
                    int br = r + dr[part[1]];
                    int bc = c + dc[part[1]];

                    if(ar < 0 || ar >= N || ac < 0 || ac >= M || br < 0 || br >= N || bc < 0 || bc >= M) continue;
                    int power = map[r][c] * 2;
                    power += map[ar][ac] + map[br][bc];

                    weapons.add(new Weapon(power, new Pos(r, c), new Pos(ar, ac), new Pos(br, bc)));
                }
            }
        }
    }
}