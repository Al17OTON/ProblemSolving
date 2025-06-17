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

    static int N;
    static char[][] map;
    static List<Pos> students, list;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1 ,1};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());

        map = new char[N][N];
        students = new ArrayList<>();
        list = new ArrayList<>();

        for(int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; ++j) {
                map[i][j] = st.nextToken().charAt(0);
                if(map[i][j] == 'S') {
                    students.add(new Pos(i, j));
                    // map[i][j] = 'X';
                } else if(map[i][j] == 'X') {
                    list.add(new Pos(i, j));
                }
            }
        }

        System.out.println(combination(0, 0) ? "YES" : "NO");
    }

    static boolean combination(int idx, int count) {
        if(count == 3) {
            return isGood();
        }

        for(int i = idx; i < list.size(); ++i) {
            Pos p = list.get(i);
            map[p.r][p.c] = 'O';
            if(combination(i + 1, count + 1)) return true;
            map[p.r][p.c] = 'X';
        }
        return false;
    }

    static boolean isGood() {
        for(int i = 0; i < students.size(); ++i) {
            Pos p = students.get(i);

            for(int d = 0; d < 4; ++d) {
                int nr = p.r + dr[d];
                int nc = p.c + dc[d];
                boolean flag = false;
                while(nr >= 0 && nr < N && nc >= 0 && nc < N) {
                    if(map[nr][nc] == 'T') {
                        flag = true;
                        break;
                    } else if(map[nr][nc] == 'O') {
                        break;
                    }
                    nr += dr[d];
                    nc += dc[d];
                }
                if(flag) return false;
            }
        }
        return true;
    }

   
}