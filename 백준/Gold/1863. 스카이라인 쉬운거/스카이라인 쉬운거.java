import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int MAX_Y = 500000;
    static boolean[] v = new boolean[MAX_Y + 2];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        StringTokenizer st;
        v[0] = true;
        int max = 0, count = 0;

        for(int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            if(max > y) {
                Arrays.fill(v, y + 1, max + 1, false);
            }

            if(!v[y]) {
                count++;
                v[y] = true;
            }

            max = y;
        }

        System.out.println(count);
    }
}