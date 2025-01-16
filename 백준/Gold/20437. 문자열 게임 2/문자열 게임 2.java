import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        ArrayList<Integer>[] idxList = new ArrayList[26];
        for(int i = 0; i < 26; i++) idxList[i] = new ArrayList<>();

        for(int t = 0; t < T; t++) {
            char[] W = br.readLine().toCharArray();
            int K = Integer.parseInt(br.readLine());
            int shortest = Integer.MAX_VALUE;
            int longest = Integer.MIN_VALUE;

            for(int i = 0; i < 26; i++) idxList[i].clear();
            
            for(int i = 0; i < W.length; i++) {
                idxList[W[i] - 'a'].add(i);
            }

            for(int i = 0; i < 26; i++) {
                int size = idxList[i].size();
                if(size < K) continue;

                for(int j = 0; j <= size - K; j++) {
                    int len = idxList[i].get(j + K - 1) - idxList[i].get(j) + 1;
                    shortest = Math.min(shortest, len);
                    longest = Math.max(longest, len);
                }
            }

            if(shortest == Integer.MAX_VALUE) sb.append("-1\n");
            else sb.append(shortest + " " + longest + "\n");
        }

        System.out.println(sb);
    }
}