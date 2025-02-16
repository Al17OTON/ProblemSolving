import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N, MAX = 0;
    static int[] arr, dp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        dp = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int n = 0; n < N; n++) {
            arr[n] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(isVisible(i, j)) {
                    dp[i] += 1;
                    dp[j] += 1;

                    if(dp[i] > dp[MAX]) MAX = i;
                    if(dp[j] > dp[MAX]) MAX = j; 
                }
            }
        }
        System.out.println(dp[MAX]);
    }

    static boolean isVisible(int from, int to) {
        int x1 = from, y1 = arr[from], x2 = to, y2 = arr[to];

        double a = ((double)(y2 - y1)) / ((double)(x2 - x1));

        for(int i = from + 1; i < to; i++) {
            double k = ((double)(arr[i] - y1)) / ((double)(i - x1));
            if(a <= k) return false;
        }

        return true;
    }
}