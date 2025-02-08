import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static class Union {
        int[] uni;
        int[] len;

        public Union(int n) {
            uni = new int[n + 1];
            len = new int[n + 1];

            for(int i = 1; i <= n; i++) {
                uni[i] = i;
                len[i] = 1;
            } 
        }

        int find(int x) {
            if(uni[x] == x) return x;
            return uni[x] = find(uni[x]);
        }

        void setUnion(int a, int b) {
            a = find(a);
            b = find(b);

            if(a == b) return;

            uni[a] = b;
            len[b] += len[a];
        }

        int getLen(int idx) {
            return len[find(idx)];
        }
    }

    static int N;
    static Union union;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        N = Integer.parseInt(br.readLine());

        union = new Union(1000000);

        StringTokenizer st;
        for(int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            char com = st.nextToken().charAt(0);
            if(com == 'I') {
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                
                union.setUnion(a, b);
            } else {
                int c = Integer.parseInt(st.nextToken());
                
                sb.append(union.getLen(c));
                sb.append("\n");
            }
        }

        System.out.println(sb);
        
    }
}