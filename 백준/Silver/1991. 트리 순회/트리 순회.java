import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    
    static class Node {
        char me;
        int left, right;

        public Node(char a) {
            me = a;
            this.left = -1;
            this.right = -1;
        }
    }

    static Node[] tree;
    static int N;
    static StringBuilder pre, mid, post;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        pre = new StringBuilder();
        mid = new StringBuilder();
        post = new StringBuilder();

        N = Integer.parseInt(br.readLine());

        tree = new Node[N];

        for(int n = 0; n < N; n++) {
            String node = br.readLine();
            int parent = node.charAt(0) - 'A';
            int left = node.charAt(2) - 'A';
            int right = node.charAt(4) - 'A';

            tree[parent] = new Node((char)(parent + 'A'));

            if(left != '.' - 'A') tree[parent].left = left;
            if(right != '.' - 'A') tree[parent].right = right;
        }

        dfs(0);

        System.out.println(pre);
        System.out.println(mid);
        System.out.println(post);

    }   

    static void dfs(int idx) {
        Node node = tree[idx];
        pre.append(node.me + "");

        if(node.left != -1) dfs(node.left);
        mid.append(node.me + "");

        if(node.right != -1) dfs(node.right);
        post.append(node.me + "");
    }
}