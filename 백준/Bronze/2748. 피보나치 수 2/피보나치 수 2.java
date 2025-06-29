import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int N;
    static long[] dp;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
        N = Integer.parseInt(br.readLine());
        dp = new long[N + 1];

        System.out.println(fib(N));
    }
    
    static long fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        if(dp[n] != 0) return dp[n];

        return dp[n] = fib(n - 1) + fib(n - 2);
    }
}