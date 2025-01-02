import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        ArrayDeque<Integer> arr = new ArrayDeque<>();
        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t < T; t++) {
            String p = br.readLine();
            int n = Integer.parseInt(br.readLine());            
            String tmp = br.readLine();

            if(tmp.length() > 2) {
                for(String a : tmp.substring(1, tmp.length() - 1).split(",")) {
                    arr.offer(Integer.parseInt(a));
                }
            } else arr.clear();
            
            boolean isReverse = false, isError = false;
            for(int i = 0; i < p.length(); i++) {
                char c = p.charAt(i);
                if(c == 'R') isReverse = !isReverse;
                else {
                    if(arr.isEmpty()) {
                        sb.append("error\n");
                        isError = true;
                        break;
                    }
                    if(isReverse) arr.pollLast();
                    else arr.pollFirst();
                }
            }
            if(!isError) build(arr, isReverse, sb);
        }
        System.out.println(sb);
    }
    
    static void build(ArrayDeque<Integer> arr, boolean isReverse, StringBuilder sb) {
        sb.append("[");
        while(!arr.isEmpty()) {
            sb.append(isReverse ? arr.pollLast() : arr.pollFirst());
            if(!arr.isEmpty()) sb.append(",");
        }
        sb.append("]\n");
    }
}