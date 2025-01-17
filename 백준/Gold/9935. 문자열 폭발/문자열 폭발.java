import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        char[] a = br.readLine().toCharArray();
        char[] boom = br.readLine().toCharArray();

        ArrayDeque<Character> stack = new ArrayDeque<>();

        for(char c : a) {
            stack.offer(c);
            int bIdx = boom.length - 1;
            while(!stack.isEmpty() && stack.peekLast() == boom[bIdx]) {
                stack.pollLast();
                bIdx--;
                if(bIdx == -1) bIdx = boom.length - 1;
            }

            while(bIdx != boom.length - 1) {
                bIdx++;
                stack.offer(boom[bIdx]);
            }
        }
        
        if(stack.isEmpty()) sb.append("FRULA");
        while(!stack.isEmpty()) {
            sb.append(stack.pollFirst());
        }

        System.out.println(sb);
    }
}