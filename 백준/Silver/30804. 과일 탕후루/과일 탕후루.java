import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, MAX = Integer.MIN_VALUE;
    static int[] hash = new int[10], arr, dp;
    static int fruitCount = 0;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        dp = new int[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int n = 0; n < N; n++) {
            int fruit = Integer.parseInt(st.nextToken());
            if(hash[fruit] == 0) fruitCount++;
            hash[fruit]++; 
            arr[n] = fruit;
        }

        boolean flag = false;
        for(int a = 1; a < 10; a++) {
            for(int b = a + 1; b < 10; b++) {
                if(hash[a] == 0 || hash[b] == 0) continue;
                flag = true;

                MAX = Math.max(MAX, getLen(a, b));
            }
        }

        if(!flag) {
            for(int a = 1; a < 10; a++) {
                if(hash[a] == 0) continue;
                MAX = Math.max(MAX, getLen(a, a));
            }
        }
        System.out.println(MAX);
    }

    static int getLen(int a, int b) {
        int max_len = 0;
        int len = 0;
        for(int n = 0; n < N; n++) {
            if(arr[n] == a || arr[n] == b) {
                len++;
            }
            else {
                max_len = Math.max(max_len, len);
                len = 0;
            }
        }
        max_len = Math.max(max_len, len);
        return max_len;
    }
}