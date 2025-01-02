import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M, MIN = Integer.MAX_VALUE;
    static int MIN_SONG = 0;
    static long[] guitar;    

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        guitar = new long[N];

        for(int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            st.nextToken();
            String pos = st.nextToken();
            for(int i = 0; i < pos.length(); i++) {
               if(pos.charAt(i) == 'Y') guitar[n] |= (1L << i);
            }
        }

        combination(0, 0, 0L);

        System.out.println(MIN == 0 ? -1 : MIN);
    }

    static void combination(int idx, int cnt, long song) {
        int bit = Long.bitCount(song);
        if(bit == MIN_SONG && cnt < MIN) MIN = cnt;
        if(bit > MIN_SONG) {
            MIN = cnt;
            MIN_SONG = bit;
        }

        if(idx == N || bit == M) return;

        combination(idx + 1, cnt + 1, song | guitar[idx]);
        combination(idx + 1, cnt, song);
    }
}