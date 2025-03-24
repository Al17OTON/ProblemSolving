import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static class Union {
        int[] uni;
        public Union(int n) {
            uni = new int[n + 1];
            for(int i = 1; i <= n; ++i) uni[i] = i;
        }

        public int find(int a) {
            if(uni[a] == a) return a;
            return uni[a] = find(uni[a]);
        }

        public void setUni(int a, int b) {
            a = find(a);
            b = find(b);

            if(a == b) return;

            uni[a] = b;
        }
    }

    static int N, M;
    static Union union;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        union = new Union(N);
        StringTokenizer st;
        for(int i = 1; i <= N; ++i) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= N; ++j) {
                if(Integer.parseInt(st.nextToken()) == 1) {
                    union.setUni(i, j);
                }
            }
        }

        st = new StringTokenizer(br.readLine());
        int set = union.find(Integer.parseInt(st.nextToken()));
        boolean result = true;
        for(int m = 1; m < M; ++m) {
            if(set != union.find(Integer.parseInt(st.nextToken()))) {
                result = false;
            }
        }

        System.out.println(result ? "YES" : "NO");
    }
}