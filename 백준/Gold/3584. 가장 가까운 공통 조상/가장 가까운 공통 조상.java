import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        for(int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st;

            int[] parent = new int[N + 1];
            boolean[] v = new boolean[N + 1];
            
            for(int n = 0; n < N - 1; n++) {
                st = new StringTokenizer(br.readLine());
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                parent[to] = from;
            }
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            sb.append(findCommonParent(a, b, parent, v)).append("\n");
        }

        System.out.println(sb);

    }

    static int findCommonParent(int a, int b, int[] parent, boolean[] v) {
        v[a] = true;
        v[b] = true;

        while(parent[a] != 0 || parent[b] != 0) {
            if(parent[a] != 0) {
                if(v[parent[a]]) return parent[a];
                v[parent[a]] = true;
                a = parent[a];
            }
            if(parent[b] != 0) {
                if(v[parent[b]]) return parent[b];
                v[parent[b]] = true;
                b = parent[b];
            } 
        }
        return -1;
    }
}