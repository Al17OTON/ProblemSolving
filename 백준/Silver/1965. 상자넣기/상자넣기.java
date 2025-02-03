import java.io.*;
import java.util.*;

public class Main {
    static int N, MAX = 1;
    static int[] box, dp;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        box = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int n = 0; n < N; n++) {
            box[n] = Integer.parseInt(st.nextToken());
        }

        dp = new int[N];
        Arrays.fill(dp, 1);
        for(int n = 1; n < N; n++) {
            for(int i = n - 1; i >= 0; i--) {
                if(box[n] > box[i]) {
                    dp[n] = Math.max(dp[n], dp[i] + 1);
                    MAX = Math.max(dp[n], MAX);
                }
            }
        }

        System.out.println(MAX);
    }
}