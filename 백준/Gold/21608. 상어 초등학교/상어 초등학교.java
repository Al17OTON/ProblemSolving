import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static class Seat {
        int r, c, like, blank;
        public Seat(int r, int c, int like, int blank) {
            this.r = r;
            this.c = c;
            this.like = like;
            this.blank = blank;
        }
    }

    static int N;
    static int[][] like;
    static int[][] map;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        StringTokenizer st;
        like = new int[N * N + 1][4];
        map = new int[N][N];
        for(int n = 0; n < N * N; n++) {
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            like[num][0] = Integer.parseInt(st.nextToken());
            like[num][1] = Integer.parseInt(st.nextToken());
            like[num][2] = Integer.parseInt(st.nextToken());
            like[num][3] = Integer.parseInt(st.nextToken());

            Seat seat = new Seat(-1, -1, 0, 0);
            for(int r = 0; r < N; r++) {
                for(int c = 0; c < N; c++) {
                    if(map[r][c] != 0) continue;
                    
                    int l = 0, b = 0;
                    for(int d = 0; d < 4; d++) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];

                        if(nr >= N || nr < 0 || nc >= N || nc < 0) continue;
                        if(map[nr][nc] == 0) b++;
                        else if(like[num][0] == map[nr][nc] || like[num][1] == map[nr][nc] || like[num][2] == map[nr][nc] || like[num][3] == map[nr][nc]) l++;
                    }
                    if(seat.r == -1) {
                        seat.r = r;
                        seat.c = c;
                        seat.like = l;
                        seat.blank = b;
                    }

                    if(seat.like < l) {
                        seat.r = r;
                        seat.c = c;
                        seat.like = l;
                        seat.blank = b;
                    } else if(seat.like == l && seat.blank < b) {
                        seat.r = r;
                        seat.c = c;
                        seat.blank = b;
                    }
                }
            }

            map[seat.r][seat.c] = num;
            
        }

        int result = 0;
        for(int r = 0; r < N; r++) {
            for(int c = 0; c < N; c++) {
                int l = 0;
                for(int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if(nr >= N || nr < 0 || nc >= N || nc < 0) continue;
                    else if(like[map[r][c]][0] == map[nr][nc] || like[map[r][c]][1] == map[nr][nc] || like[map[r][c]][2] == map[nr][nc] || like[map[r][c]][3] == map[nr][nc]) l++;
                }

                if(l == 1) result += 1;
                else if(l == 2) result += 10;
                else if(l == 3) result += 100;
                else if(l == 4) result += 1000;
            }
        }

        System.out.println(result);
    }
}