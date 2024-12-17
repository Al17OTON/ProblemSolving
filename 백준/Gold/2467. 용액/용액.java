import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

import java.util.StringTokenizer;

public class Main {
    
    static int N;
    static int[] arr;
    static int A, B, X = Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int n = 0; n < N; n++) {
            arr[n] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        for(int n = 0; n < N; n++) {
            int idx = getNearestIdx(n);
            int dist = Math.abs(arr[idx] + arr[n]);
            if(dist < X) {
                A = arr[idx];
                B = arr[n];
                X = dist;
            }
        }

        System.out.println((A > B ? B : A) + " " + (A > B ? A : B));
    }

    //찾고자하는 인덱스의 역원과 가장 근접한 인덱스를 이분탐색으로 찾아서 반환
    static int getNearestIdx(int targetIdx) {
        int left = 0, right = N - 1;
        int mid = (right + left) / 2;
        int inverse = -arr[targetIdx];   //역원을 구하기
        int abs = Integer.MAX_VALUE, result = targetIdx;

        while(left <= right) {
            mid = (right + left) / 2;
            if(arr[mid] > inverse) {
                right = mid - 1;
            } else if(arr[mid] < inverse) {
                left = mid + 1;
            } else {
                result = mid;
                break;
            }

            if(abs > Math.abs(inverse - arr[mid])) {
                abs = Math.abs(inverse - arr[mid]);
                result = mid;
            }
        }
        mid = result; 
        //자기자신이 역원과 근접하다면 양옆 인덱스 비교 후 가장 역원에 근접한 값으로 변경
        if(mid == targetIdx) {
            if(mid == 0) mid++;
            else if(mid == N - 1) mid--;
            else {
                if(Math.abs(inverse - arr[mid - 1]) > Math.abs(inverse - arr[mid + 1])) mid++;
                else mid--;
            }
        }

        return mid;
    }
}