import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, Q;
    static long[] arr, segmentTree;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        arr = new long[N + 1];
        segmentTree = new long[N * 4];
        st = new StringTokenizer(br.readLine());
        for(int n = 0; n < N; ++n) {
            arr[n] = Integer.parseInt(st.nextToken());
        }
        makeSegmentTree(0, N - 1, 1);

        StringBuilder sb = new StringBuilder();

        for(int q = 0; q < Q; ++q) {
            st = new StringTokenizer(br.readLine());
            int x, y, a, b;
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            //x~y는 당연히 x번째 부터 y번째가 맞다. 하지만, 이 문제에서는 x > y인 경우 y번째 부터 x번째이다.
            int realX = Math.min(x, y);
            int realY = Math.max(x, y);
            
            sb.append(getSum(0, N - 1, 1, realX - 1, realY - 1)).append("\n");
            update(0, N - 1, 1, a - 1, b - arr[a - 1]);
            arr[a - 1] = b;
        }
        System.out.println(sb);
    }

    static long makeSegmentTree(int start, int end, int node) {
        if(start == end) return segmentTree[node] = arr[start];
        int mid = (start + end) / 2;
        return segmentTree[node] = makeSegmentTree(start, mid, node * 2) + makeSegmentTree(mid + 1, end, node * 2 + 1);  
    }

    static long getSum(int start, int end, int node, int left, int right) {
        if(left > end || right < start) return 0;
        if(left <= start && end <= right) return segmentTree[node];

        int mid = (start + end) / 2;
        return getSum(start, mid, node * 2, left, right) + getSum(mid + 1, end, node * 2 + 1, left, right);
    }

    static void update(int start, int end, int node, int target, long change) {
        if(start > target || end < target) return;
        segmentTree[node] += change;
        if(start == end) return;
        int mid = (start + end) / 2;
        update(start, mid, node * 2, target, change);
        update(mid + 1, end, node * 2 + 1, target, change);
    }
}