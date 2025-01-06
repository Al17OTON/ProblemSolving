import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


// 오른쪽 카드만 버릴 수 있다면 무조건 버리기
// 왼쪽 카드만 버리거나 왼오 둘다 버리는 것만 선택하면 됨
// 가지치기?
public class Main {
    static int N, MAX = 0;
    static int[] left, right;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        left = new int[N];
        right = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        for(int n = 0; n < N; n++) {
            left[n] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int n = 0; n < N; n++) {
            right[n] = Integer.parseInt(st.nextToken());
        }

        dfs(0, 0, 0);

        System.out.println(MAX);
        
    }

    static void dfs(int l, int r, int score) {
        MAX = Math.max(MAX, score);
        if(l == N || r == N) return;

        if(left[l] > right[r]) {
            dfs(l, r+1, score+right[r]);
        } else {
            dfs(l+1, r, score);
            dfs(l+1, r+1, score);
        }
    }
}