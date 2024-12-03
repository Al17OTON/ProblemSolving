import java.io.*;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    
    static int N;
    static int min = Integer.MAX_VALUE;
    static int[][] arr = new int[21][21];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            for(int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(dfs(0, -1, new boolean[N]));

    }

    static int dfs(int idx, int prev, boolean[] team) {
        if(idx == N / 2) {
            int A = 0, B = 0;
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(team[i] == team[j] && team[i]) A += arr[i][j];
                    else if(team[i] == team[j]) B += arr[i][j];
                }
            }
            return Math.abs(A - B);
        }

        int res = Integer.MAX_VALUE;
        for(int i = prev + 1; i < N; i++) {
            team[i] = true;
            res = Math.min(dfs(idx + 1, i, team), res);
            team[i] = false;
        }
        return res;
    }
}