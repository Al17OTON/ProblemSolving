import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int[] dp = new int[46];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        System.out.println(fib(N));
    }

    static int fib(int n) {
        if(n == 0) return 0;
        else if(n == 1) return 1;
        else if(dp[n] != 0) return dp[n];

        return dp[n] = fib(n - 1) + fib(n - 2);
    }
}