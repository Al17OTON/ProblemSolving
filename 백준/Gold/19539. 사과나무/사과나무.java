import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int[] arr;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int sum = 0;
        for(int n = 0; n < N; n++) {
            arr[n] = Integer.parseInt(st.nextToken());
            sum += arr[n];
        }

        boolean result = true;
        if(sum % 3 != 0) result = false;
        else {
            result = treeSim(sum / 3);
        }
    
        System.out.println(result ? "YES" : "NO");
    }

    static boolean treeSim(int three) {
        int two = 0;
        for(int n = 0; n < N; n++) {
            two += arr[n] / 2;
        }

        return two >= three;
    }
}