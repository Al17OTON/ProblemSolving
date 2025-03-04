import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M, min = 1000000, max = -1;
    static int[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int n = 0; n < N; n++) {
            arr[n] = Integer.parseInt(st.nextToken());
            min = Math.min(min, arr[n]);
            max = Math.max(max, arr[n]);
        }

        int left = 0, right = max - min;
        while(left <= right) {
            int mid = (right + left) / 2;

            if(isPossible(mid)) {
                right = mid - 1;
            }
            else left = mid + 1;
        }
        
        System.out.println(right + 1);
    }

    static boolean isPossible(int val) {
        int min = arr[0], max = arr[0], count = 1;
        
        for(int i = 1; i < N; i++) {
            max = Math.max(max, arr[i]);
            min = Math.min(min, arr[i]);
            if(max - min <= val) {
                continue;
            } else if(count < M) {
                count++;
                max = arr[i];
                min = arr[i];
            } else {
                return false;
            }
        }

        return true;
    }
    
}