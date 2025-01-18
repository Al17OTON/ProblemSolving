import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int M, X = 1000000007;
    static long N = 1, S = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        M = Integer.parseInt(br.readLine());
        StringTokenizer st;
        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());

            S = s * N + S * n;
            N *= n;
            
            N %= X;
            S %= X;

        }

        System.out.println(S % N == 0 ? S / N : (Fermat(N, X - 2) * S) % X);
    }

    static long Fermat(long N, int index) {
        if(index == 1)
            return N;
        long temp = Fermat(N, index/2);
        if(index % 2 == 1)
            return temp * temp % X * N % X;
        else
            return temp * temp % X;
    }
}