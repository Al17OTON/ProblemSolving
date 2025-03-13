import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, C;
    static int[] arr;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        arr = new int[N];
        for(int n = 0; n < N; n++) {
            int x = Integer.parseInt(br.readLine());
            arr[n] = x;
        }

        Arrays.sort(arr);

        System.out.println(binarySearch());
    }

    static int binarySearch() {
        int left = 0, right = arr[N - 1];
        int mid, count, pre, result = -1;

        while(left <= right) {
            pre = 0;
            mid = (left + right) / 2;
            count = 1;

            for(int i = 0; i < N; i++) {
                if(arr[i] - arr[pre] >= mid) {
                    count++;
                    pre = i;
                }
            }

            if(count >= C) {
                result = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return result;
    }
}