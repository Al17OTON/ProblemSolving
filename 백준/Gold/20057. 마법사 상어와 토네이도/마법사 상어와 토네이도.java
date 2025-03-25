import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, outTotal = 0;
    static int[][] map;
    static int[] dr = {0, 1, 0, -1};
    static int[] dc = {-1, 0, 1, 0};

    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        StringTokenizer st;

        for(int r = 0; r < N; ++r) {
            st = new StringTokenizer(br.readLine());
            for(int c = 0; c < N; ++c) {
                map[r][c] = Integer.parseInt(st.nextToken());
            }
        }
        tornado();

        System.out.println(outTotal);
    }

    static void tornado() {
        int r = N / 2;
        int c = N / 2;

        int move = 1;
        int dir = 0;
        L : while(true) {
            for(int i = 0; i < 2; ++i) {
                for(int m = 0; m < move; ++m) {
                    int nr = r + dr[dir];
                    int nc = c + dc[dir];

                    moveSand(nr, nc, dir);
                    // printMap();

                    if(nr == 0 && nc == 0) break L;
                    r = nr;
                    c = nc;
                }
                dir = (dir + 1) % 4;
            }
            ++move;
        }

    }

    static void printMap() {
        System.out.println();
        System.out.println();
        for(int r = 0; r < N; ++r) System.out.println(Arrays.toString(map[r]));
    }

    static void moveSand(int r, int c, int dir) {
        int sand = map[r][c], loss = 0;
        map[r][c] = 0;
        if(dir == 0) {
            int[] one = {r - 1, c + 1};
            int[] two = {r - 2, c};
            int[] seven = {r - 1, c};
            int[] ten = {r - 1, c - 1};
            int[] five = {r, c - 2};

            loss += sendSand(one, sand, 1);
            loss += sendSand(two, sand, 2);
            loss += sendSand(seven, sand, 7);
            loss += sendSand(ten, sand, 10);
            loss += sendSand(five, sand, 5);

            one[0] = r + 1;
            two[0] = r + 2;
            seven[0] = r + 1;
            ten[0] = r + 1;
            
            loss += sendSand(one, sand, 1);
            loss += sendSand(two, sand, 2);
            loss += sendSand(seven, sand, 7);
            loss += sendSand(ten, sand, 10);

            int[] alpha = {r, c - 1};
            if(isOut(alpha)) outTotal += sand - loss;
            else map[alpha[0]][alpha[1]] += sand - loss;

            
        } else if(dir == 2) {
            int[] one = {r - 1, c - 1};
            int[] two = {r - 2, c};
            int[] seven = {r - 1, c};
            int[] ten = {r - 1, c + 1};
            int[] five = {r, c + 2};

            loss += sendSand(one, sand, 1);
            loss += sendSand(two, sand, 2);
            loss += sendSand(seven, sand, 7);
            loss += sendSand(ten, sand, 10);
            loss += sendSand(five, sand, 5);

            one[0] = r + 1;
            two[0] = r + 2;
            seven[0] = r + 1;
            ten[0] = r + 1;

            loss += sendSand(one, sand, 1);
            loss += sendSand(two, sand, 2);
            loss += sendSand(seven, sand, 7);
            loss += sendSand(ten, sand, 10);

            int[] alpha = {r, c + 1};
            if(isOut(alpha)) outTotal += sand - loss;
            else map[alpha[0]][alpha[1]] += sand - loss;

        } else if(dir == 1) {
            int[] one = {r - 1, c - 1};
            int[] two = {r, c - 2};
            int[] seven = {r, c - 1};
            int[] ten = {r + 1, c - 1};
            int[] five = {r + 2, c};

            loss += sendSand(one, sand, 1);
            loss += sendSand(two, sand, 2);
            loss += sendSand(seven, sand, 7);
            loss += sendSand(ten, sand, 10);
            loss += sendSand(five, sand, 5);

            one[1] = c + 1;
            two[1] = c + 2;
            seven[1] = c + 1;
            ten[1] = c + 1;

            loss += sendSand(one, sand, 1);
            loss += sendSand(two, sand, 2);
            loss += sendSand(seven, sand, 7);
            loss += sendSand(ten, sand, 10);

            int[] alpha = {r + 1, c};
            if(isOut(alpha)) outTotal += sand - loss;
            else map[alpha[0]][alpha[1]] += sand - loss;

        } else {
            int[] one = {r + 1, c - 1};
            int[] two = {r, c - 2};
            int[] seven = {r, c - 1};
            int[] ten = {r - 1, c - 1};
            int[] five = {r - 2, c};

            loss += sendSand(one, sand, 1);
            loss += sendSand(two, sand, 2);
            loss += sendSand(seven, sand, 7);
            loss += sendSand(ten, sand, 10);
            loss += sendSand(five, sand, 5);

            one[1] = c + 1;
            two[1] = c + 2;
            seven[1] = c + 1;
            ten[1] = c + 1;

            loss += sendSand(one, sand, 1);
            loss += sendSand(two, sand, 2);
            loss += sendSand(seven, sand, 7);
            loss += sendSand(ten, sand, 10);

            int[] alpha = {r - 1, c};
            if(isOut(alpha)) outTotal += sand - loss;
            else map[alpha[0]][alpha[1]] += sand - loss;

        }
    } 

    static int sendSand(int[] pos, int sand, int percent) {
        // sand = (sand / 100) * percent;
        double tmp = sand * (0.01 * percent);
        sand = (int)Math.floor(tmp);
        if(isOut(pos)) {
            outTotal += sand;
            return sand;
        }
        map[pos[0]][pos[1]] += sand; 
        return sand;
    }

    static boolean isOut(int[] pos) {
        return pos[0] >= N || pos[0] < 0 || pos[1] >= N || pos[1] < 0;
    }
}