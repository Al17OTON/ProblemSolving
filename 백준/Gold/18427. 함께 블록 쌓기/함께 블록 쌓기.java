import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static class Student {
        List<Integer> blocks;
        public Student(List<Integer> blocks) {
            this.blocks = blocks;
        }
    }

    static int N, M, H;
    static int[][] dp;
    static List<Student> students = new ArrayList<>(); 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        for(int n = 0; n < N; ++n) {
            st = new StringTokenizer(br.readLine());
            List<Integer> blocks = new ArrayList<>();
            while(st.hasMoreTokens()) {
                int block = Integer.parseInt(st.nextToken());
                blocks.add(block);
            }
            students.add(new Student(blocks));
        }

        dp = new int[N + 1][H + 1];
        for(int n = 0; n <= N; ++n) dp[n][0] = 1;

        for(int n = 1; n <= N; ++n) {
            for(int h = 1; h <= H; ++h) {
                for(int block : students.get(n - 1).blocks) {
                    if(block <= h) dp[n][h] = (dp[n][h] + dp[n - 1][h - block]) % 10007;
                }
                dp[n][h] = (dp[n][h] + dp[n - 1][h]) % 10007;
            }
        }

        System.out.println(dp[N][H]);
    }

    

}