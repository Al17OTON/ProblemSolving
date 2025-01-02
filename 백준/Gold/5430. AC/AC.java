import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class Main {

    static ArrayDeque<Integer> q = new ArrayDeque<>();
    static boolean reverse;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for(int t = 0; t < T; t++) {
            reverse = false;
            boolean error = false;
            String com = br.readLine();
            int N = Integer.parseInt(br.readLine());
            parseQueue(br.readLine());

            for(int i = 0; i < com.length() && !error; i++) {
                char c = com.charAt(i);
    
                switch (c) {
                    case 'R':
                        reverse = !reverse;
                        break;
                    case 'D':
                        if(q.isEmpty()) {
                            error = true;
                            break;
                        }
                        if(!reverse) {
                            q.poll();
                        } else {
                            q.removeLast();
                        }
                        break;
                }
            }

            if(error) System.out.println("error");
            else {
                StringBuilder sb = new StringBuilder();
                sb.append("[");
                while(!q.isEmpty()) {
                    if(!reverse) sb.append(q.poll());
                    else sb.append(q.removeLast());

                    if(q.size() != 0) sb.append(",");
                }
                sb.append("]");

                System.out.println(sb);
            }
        }
    }

    static void parseQueue(String a) {
        q.clear();

        if(a.length() == 2) return;

        String[] list = a.substring(1, a.length() - 1).split(",");

        for(String tmp : list) {
            q.offer(Integer.parseInt(tmp));
        }
    }
}
