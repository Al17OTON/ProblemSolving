import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


// 오른쪽 카드만 버릴 수 있다면 무조건 버리기
// 왼쪽 카드만 버리거나 왼오 둘다 버리는 것만 선택하면 됨

public class Main {
    static int N;
    static int[] left, right;
    static int[][] dp;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        left = new int[N];
        right = new int[N];
        dp = new int[N][N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        for(int n = 0; n < N; n++) {
            left[n] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int n = 0; n < N; n++) {
            right[n] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < N; i++) {
            Arrays.fill(dp[i], -1);
        }

        System.out.println(dp(0, 0));

    }

    static int dp(int l, int r) {
        if(l == N || r == N) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        if(left[l] > right[r]) return dp[l][r] = right[r] + dp(l, r + 1);
        else return dp[l][r] = Math.max(dp(l + 1, r), dp(l + 1, r + 1));
        
    }
}