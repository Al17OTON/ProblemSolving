import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static ArrayDeque<Integer> stack = new ArrayDeque<>();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        StringTokenizer st;
        int count = 0;
        stack.offerLast(0);

        for(int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            if(stack.peekLast() > y) {
                while(stack.peekLast() > y) stack.pollLast();
            }

            if(stack.peekLast() != y) {
                count++;
                stack.offerLast(y);
            }
        }

        System.out.println(count);
    }
}