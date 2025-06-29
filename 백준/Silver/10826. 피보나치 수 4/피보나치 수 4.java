import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
    static BigInteger[] dp;
    static int N;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        dp = new BigInteger[N + 2];
        dp[0] = new BigInteger("0");
        dp[1] = new BigInteger("1");
        System.out.println(fib(N));
    }

    static BigInteger fib(int n) {
        if(dp[n] != null) return dp[n];

        return dp[n] = fib(n - 2).add(fib(n - 1));
    }
}