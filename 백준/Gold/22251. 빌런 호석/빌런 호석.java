import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[][] cost = {
        {0, 4, 3, 3, 4, 3, 2, 3, 1, 2},
        {4, 0, 5, 3, 2, 5, 6, 1, 5, 4},
        {3, 5, 0, 2, 5, 4, 3, 4, 2, 3},
        {3, 3, 2, 0, 3, 2, 3, 2, 2, 1},
        {4, 2, 5, 3, 0, 3, 4, 3, 3, 2},
        {3, 5, 4, 2, 3, 0, 1, 4, 2, 1},
        {2, 6, 3, 3, 4, 1, 0, 5, 1, 2},
        {3, 1, 4, 2, 3, 4, 5, 0, 4, 3},
        {1, 5, 2, 2, 3, 2, 1, 4, 0, 1},
        {2, 4, 3, 1, 2, 1, 2, 3, 1, 0}
    };
    static int N, K, P, X;
    static int result = 0;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());

        System.out.println(sim() - 1);
    }

    static int sim() {
        int result = 0;
        int[] cur = int2Arr(1);
        int[] correct = int2Arr(X);
        
        for(int i = 1; i <= N; ++i) {
            int count = countChange(cur, correct);
            if(count <= P) {
                ++result;
            }
            increment(cur);
        }

        return result;
    }

    static void increment(int[] a) {
        ++a[K - 1];
        if(a[K - 1] > 9) {
            for(int i = K - 1; i > 0 && a[i] > 9; --i) {
                a[i] = 0;
                ++a[i - 1];
            }
        }
    }

    static int countChange(int[] a, int[] b) {
        int change = 0;
        for(int i = 0; i < K; ++i) change += cost[a[i]][b[i]];
        return change;
    }

    static int[] int2Arr(int num) {
        int[] nums = new int[K];
        int tmp = num;
        for(int i = K - 1; i >= 0; --i) {
            nums[i] = tmp % 10;
            tmp /= 10;
        }
        return nums;
    }
}