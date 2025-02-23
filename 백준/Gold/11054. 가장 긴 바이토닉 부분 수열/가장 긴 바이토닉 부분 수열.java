import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, MAX = -1;
    static int[] arr;
    static int[][] dp;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        arr = new int[N];
        dp = new int[N][2];

        arr[0] = Integer.parseInt(st.nextToken());
        for(int n = 1; n < N; n++) {
            arr[n] = Integer.parseInt(st.nextToken());
            for(int i = n - 1; i >= 0; i--) {
                if(arr[n] > arr[i]) dp[n][0] = Math.max(dp[n][0], dp[i][0] + 1);
            }
        }


        for(int n = N - 2; n >= 0; n--) {
            for(int i = n + 1; i < N; i++) {
                if(arr[n] > arr[i]) dp[n][1] = Math.max(dp[n][1], dp[i][1] + 1);
            }
        }

        for(int n = 0; n < N; n++) {
            MAX = Math.max(MAX, dp[n][0] + dp[n][1] + 1);
        }
        
        System.out.println(MAX);
    }
}