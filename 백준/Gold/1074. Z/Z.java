import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, R, C;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        System.out.println(recursive(N, R, C, 0));
    }

    static int recursive(int n, int r, int c, int num) {
        if(n == 1) {
            if(r == 0 && c == 0) return num;
            if(r == 0 && c == 1) return num + 1;
            if(r == 1 && c == 0) return num + 2;
            return num + 3;
        }

        int pow = (int)Math.pow(2, n);
        int mid = pow / 2 - 1;

        boolean rpos = r > mid ? true : false;
        boolean cpos = c > mid ? true : false;
        int time = 0;
        if(rpos) time += 2;
        if(cpos) time += 1;

        return recursive(n - 1, rpos ? (r - 1) - mid : r, cpos ? (c - 1) - mid : c, num + (pow * pow / 4) * time);
        
    }
}