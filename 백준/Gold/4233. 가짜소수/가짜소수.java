import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        while(true) {
            st = new StringTokenizer(br.readLine());
            long p = Long.parseLong(st.nextToken());
            long a = Long.parseLong(st.nextToken());

            if(p == 0) break;

            if(isPrime(p)) {
                sb.append("no\n");
            } else {
                if(fpow(a, p, p) == a) sb.append("yes\n");
                else sb.append("no\n");
            }

        }

        System.out.println(sb);
    }

    static boolean isPrime(long p) {
        for(int i = 2; i * i <= p; ++i) {
            if(p % i == 0) return false;
        }
        return true;
    }

    static long fpow(long a, long p, long mod) {
        if(p == 0) return 1;
        else if(p % 2 == 0) {
            long pow = fpow(a, p / 2, mod) % mod;
            return pow * pow % mod;
        } else {
            long pow = fpow(a, (p - 1) / 2, mod) % mod;
            return ((pow * pow) % mod) * a % mod;
        }
    }
}