import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, S, sum = 0;
    static int[] arr;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int n = 0; n < N; n++) {
            arr[n] = Integer.parseInt(st.nextToken());
            sum += arr[n];
        }

        System.out.println(solution());
    }

    static int solution() {
        if(sum < S) return 0;

        int left = 0, right = 1, curSum = arr[0];
        int minLen = N; 

        while(right <= N && left < N && minLen != 1) {
            if(curSum >= S && right - left < minLen) minLen = right - left;

            if(curSum - arr[left] >= S && left < right - 1) {
                curSum -= arr[left++];
            }
            else if(right < N) {
                curSum += arr[right++];
            } else break;
        }
        
        return minLen;
    }
}