import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static class Node implements Comparable<Node> {
        int idx, value;

        public Node(int idx, int value) {
            this.idx = idx;
            this.value = value;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(o.value, this.value);
        }
        
    }

    static int[] kinder;
    static int[] distance;
    static PriorityQueue<Node> pq = new PriorityQueue<>();
    static int N, K, result = 0; 

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        kinder = new int[N];
        distance = new int[N - 1];
        
        st = new StringTokenizer(br.readLine());
        kinder[0] = Integer.parseInt(st.nextToken());
        for(int n = 1; n < N; n++) {
            kinder[n] = Integer.parseInt(st.nextToken());
            distance[n - 1] = kinder[n] - kinder[n - 1];
            pq.offer(new Node(n - 1, distance[n - 1]));
        }
        result = kinder[N - 1] - kinder[0];
        
        for(int k = 0; k < K - 1; k++) {
            int idx = pq.poll().idx;
            result -= distance[idx];
            distance[idx] = -1;
        }

        System.out.println(result);

    }
}