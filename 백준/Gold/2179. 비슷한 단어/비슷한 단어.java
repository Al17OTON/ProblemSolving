import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

// Dynamic Segment Tree
public class Main {
    static class Node {
        Node[] child;
        int time;
        public Node(int time) {
            child = new Node[26];
            this.time = time;
        }
    }
    static class Pair {
        int m;
        int time;
        public Pair(int m, int time) {
            this.m = m;
            this.time = time;
        }
    }

    static int N;
    static Node root = new Node(-1);
    static String[] arr;
    public static void main(String[] args) throws Exception {
        // N^2 으로 못 푸는 테스트케이스, 동적 세그먼트 트리는 제한시간 내로 풀 수 있다.
        // System.setIn(new FileInputStream("C:/Users/byung/Desktop/알고리즘/2179_in.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        Pair max = new Pair(-1, N);
        String sub = "";
        arr = new String[N];
        for(int n = 0; n < N; ++n) {
            String word = br.readLine();
            arr[n] = word;

            Pair res = dfs(word, 0, root, true, n);
            if(max.m < res.m || (max.m == res.m && max.time > res.time)) {
                max = res;
                sub = word.substring(0, max.m + 1);
            }
        }

        StringBuilder sb = new StringBuilder();
        int count = 0;
        for(int n = 0; n < N && count < 2; ++n) {
            if(arr[n].length() < sub.length()) continue;
            boolean flag = true;
            for(int i = 0; i < sub.length(); ++i) {
                if(arr[n].charAt(i) != sub.charAt(i)) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ++count;
                sb.append(arr[n]).append("\n");
            }
        }

        System.out.println(sb);
    }

    static Pair dfs(String word, int idx, Node cur, boolean combo, int time) {
        Pair res = new Pair(-1, N);
        if(word.length() == idx) {
            return res;
        }
        int cIdx = char2Idx(word.charAt(idx));
        
        if(cur.child[cIdx] == null) {
            cur.child[cIdx] = new Node(time);
            combo = false;
        }
        else if(combo) {
            res.m = idx;
            res.time = cur.time;
        }
        res = max(res, dfs(word, idx + 1, cur.child[cIdx], combo, time));
        return res;
    }

    static int char2Idx(char c) {
        return Character.toLowerCase(c) - 'a';
    }

    static Pair max(Pair a, Pair b) {
        if(a.m > b.m) return a;
        return b;
    }
}