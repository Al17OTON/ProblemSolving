import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        for(int t = 0; t < T; t++) {
            int K = Integer.parseInt(br.readLine());
            TreeSet<Integer> tree = new TreeSet<>(
                new Comparator<Integer>() {
                    public int compare(Integer o1, Integer o2) {
                        return o1 > o2 ? -1 : 1;
                    }
                }
            );
            for(int k = 0; k < K; k++) {
                st = new StringTokenizer(br.readLine());
                char com = st.nextToken().charAt(0);
                int num = Integer.parseInt(st.nextToken());

                if(com == 'I') {
                    // insert
                    tree.add(num);
                } else {
                    // delete
                    if(tree.isEmpty()) continue;
                    if(num == 1) {
                        tree.pollFirst();
                    } else {
                        tree.pollLast();
                    }
                }
            }

            if(tree.isEmpty()) {
                sb.append("EMPTY\n");
            } else if(tree.size() > 1){
                sb.append(tree.pollFirst() + " " + tree.pollLast() + "\n");
            } else {
                int num = tree.pollFirst();
                sb.append(num + " " + num + "\n");
            }
        }

        System.out.println(sb);
    }   
}