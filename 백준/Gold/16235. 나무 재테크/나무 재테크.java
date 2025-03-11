import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static class Tree implements Comparable<Tree> {
        int r, c, age;

        public Tree(int r, int c, int age) {
            this.r = r;
            this.c = c;
            this.age = age;
        }

        public int compareTo(Tree o) {
            return this.age - o.age;
        }
        
    }

    static int N, M, K;
    static int[][] A, map;
    static int[] dr = {0, -1, -1, -1, 0, 1, 1, 1};
    static int[] dc = {-1, -1, 0, 1, 1, 1, 0, -1};
    static PriorityQueue<Tree> pq = new PriorityQueue<>();
    static Queue<Tree> alive = new LinkedList<>();
    static Queue<Tree> dead = new LinkedList<>();
    static Queue<Tree> born = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        A = new int[N][N];
        map = new int[N][N];


        for(int r = 0; r < N; r++) {
            st = new StringTokenizer(br.readLine());
            Arrays.fill(map[r], 5);
            for(int c = 0; c < N; c++) {
                A[r][c] = Integer.parseInt(st.nextToken());
            }
        }

        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());

            pq.offer(new Tree(x - 1, y - 1, z));
        }

        for(int k = 0; k < K; k++) {
            spring();
            summer();
            fall();
            winter();
        }

        System.out.println(pq.size());
    }

    static void spring() {
        while(!pq.isEmpty()) {
            Tree tree = pq.poll();
            if(map[tree.r][tree.c] >= tree.age) {
                map[tree.r][tree.c] -= tree.age;
                tree.age += 1;
                alive.offer(tree);
            } else dead.offer(tree);
        }
    }
    static void summer() {
        while(!dead.isEmpty()) {
            Tree t = dead.poll();
            map[t.r][t.c] += t.age / 2;
        }
    }
    static void fall() {
        while(!alive.isEmpty()) {
            Tree t = alive.poll();
            pq.offer(t);
            if(t.age % 5 == 0) {
                for(int d = 0; d < 8; d++) {
                    int nr = t.r + dr[d];
                    int nc = t.c + dc[d];
                    if(nr >= N || nr < 0 || nc >= N || nc < 0) continue;
                    pq.offer(new Tree(nr, nc, 1));
                }
            }
        }
    }
    static void winter() {
        for(int r = 0; r < N; r++) {
            for(int c = 0; c < N; c++) {
                map[r][c] += A[r][c];
            }
        }
    }
}