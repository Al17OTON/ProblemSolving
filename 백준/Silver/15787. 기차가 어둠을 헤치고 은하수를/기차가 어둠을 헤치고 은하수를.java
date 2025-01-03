import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    static int[] train;
    static int N, M;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        train = new int[N + 1];
        int cmd, i, x;
        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            cmd = Integer.parseInt(st.nextToken());

            if(cmd == 1) {
                i = Integer.parseInt(st.nextToken());
                x = Integer.parseInt(st.nextToken());
                one(i, x);

            } else if(cmd == 2) {
                i = Integer.parseInt(st.nextToken());
                x = Integer.parseInt(st.nextToken());
                two(i, x);

            } else if(cmd == 3) {
                i = Integer.parseInt(st.nextToken());
                three(i);
            } else {
                i = Integer.parseInt(st.nextToken());
                four(i);
            }
        }

        // HashSet<Integer> set = new HashSet<>();
        // int result = 0;
        // for(int n = 1; n <= N; n++) {
        //     if(!set.contains(train[n])) {
        //         set.add(train[n]);
        //         result++;
        //     }
        // }

        boolean[] set = new boolean[1 << 21];
        int result = 0;
        for(int n = 1; n <= N; n++) {
            if(!set[train[n]]) {
                set[train[n]] = true;
                result++;
            }
        }

        System.out.println(result);
    }

    static void one(int i, int x) {
        train[i] |= (1 << x);
    }

    static void two(int i, int x) {
        train[i] &= ~(1 << x);
    }

    static void three(int i) {
        train[i] <<= 1;
        train[i] &= ~(1 << 21);
    }

    static void four(int i) {
        train[i] >>>= 1;
        train[i] &= ~(1);
    }
}