import java.util.*;
import java.io.*;

public class Main {
    static int A, B, C;
    static boolean[][][] hash;
    static PriorityQueue<Integer> pq = new PriorityQueue();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        hash = new boolean[C + 1][C + 1][C + 1];  // C물통만 물이 있으므로 최대값은 C

        dfs(0, 0, C);

        while(!pq.isEmpty()) {
            sb.append(pq.poll());
            sb.append(" ");
        }
        System.out.println(sb);
    }

    static void dfs(int a, int b, int c) {
        if(hash[a][b][c]) return;
        hash[a][b][c] = true;
        if(a == 0) {
            pq.offer(c);
        } else if(a > 0) {
            int water = a + b;
            int tmp = 0;
            if(water > B) tmp = water - B;
            dfs(tmp, water - tmp, c);
            
            water = a + c;
            tmp = 0;
            if(water > C) tmp = water - C;
            dfs(tmp, b, water - tmp);
        }
        if(b > 0) {
            int water = a + b;
            int tmp = 0;
            if(water > A) tmp = water - A;
            dfs(water - tmp, tmp, c);

            water = b + c;
            tmp = 0;
            if(water > C) tmp = water - C;
            dfs(a, tmp, water - tmp);
        }
        if(c > 0) {
            int water = a + c;
            int tmp = 0;
            if(water > A) tmp = water - A;
            dfs(water - tmp, b, tmp);

            water = b + c;
            tmp = 0;
            if(water > B) tmp = water - B;
            dfs(a, water - tmp, tmp);
        }
    }
}