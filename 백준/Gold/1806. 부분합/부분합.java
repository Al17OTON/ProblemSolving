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

        boolean flag = false;
        for(int n = 0; n < N; n++) {
            arr[n] = Integer.parseInt(st.nextToken());
            sum += arr[n];
            if(arr[n] >= S) flag = true; // 어떤 한 원소가 S 값 이상이라면 탐색 X 
        }

        System.out.println(flag ? 1 : twoPointer());
    }

    static int twoPointer() {
        if(sum < S) return 0; // 불가능한 경우

        // 시작할 때, 첫번째 값을 가진 상태로 시작
        int left = 0, right = 1, curSum = arr[0];
        int minLen = N; 

        // 탐색이 끝나지 않았는데 최소값이 1이라면 더 탐색하지 않아도 된다.
        while(minLen != 1) {
            if(curSum >= S && right - left < minLen) minLen = right - left;

            // 만약 가장 왼쪽 값을 빼도 된다면 빼기
            if(curSum - arr[left] >= S && left < right - 1) {
                curSum -= arr[left++];
            }
            // 더 이상 왼쪽 값을 뺄 수 없다면 오른쪽 값 넣기
            else if(right < N) {
                curSum += arr[right++];
            }
            // 왼쪽 값을 뺄 수도 오른쪽 값을 더할 수도 없다면 탐색 종료 
            else break;
        }
        
        return minLen;
    }
}