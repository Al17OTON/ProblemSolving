import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.StringTokenizer;

public class Main {

    static class Node {
        int n;
        String s;
        public Node(int n, String s) {
            this.n = n;
            this.s = s;
        }
    }

    static Random r = new Random();
    static int target, origin;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t < T; t++) {
            st = new StringTokenizer(br.readLine());
            origin = Integer.parseInt(st.nextToken());
            target = Integer.parseInt(st.nextToken());

            sb.append(bfs() + "\n");
        }
        System.out.println(sb);
    }

    static String bfs() {
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(origin, ""));
        boolean[] v = new boolean[10000];
        v[origin] = true;

        while(!q.isEmpty()) {
            Node node = q.poll();
            int n = node.n;
            if(n == target) {
                return node.s;
            }

            int D = D(n);
            if(!v[D]) {
                v[D] = true;
                q.offer(new Node(D, node.s + "D"));
            }

            int S = S(n);
            if(!v[S]) {
                v[S] = true;
                q.offer(new Node(S, node.s + "S"));
            }

            int L = L(n);
            if(!v[L]) {
                v[L] = true;
                q.offer(new Node(L, node.s + "L"));
            }

            int R = R(n);
            if(!v[R]) {
                v[R] = true;
                q.offer(new Node(R, node.s + "R"));
            }
        }
        return "";
    }

    static int D(int n) {
        return (n * 2) % 10000;
    }
    static int S(int n) {
        return n == 0 ? 9999 : n - 1;
    }
    static int L(int n) {
        return (n % 1000) * 10 + (n / 1000);
    }
    static int R(int n) {
        return (n % 10) * 1000 + (n / 10);
    }
}