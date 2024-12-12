import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, R, C;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        System.out.println(recursive(N, R, C, 0));
    }

    // 4사분면으로 나누어서 r c 값이 가리키는 값을 재귀로 찾아낸다.
    // 분할정복
    static int recursive(int n, int r, int c, int num) {
        // n == 1 인 경우가 종료 시점
        if(n == 1) {
            int a = 0;
            if(r == 1) a += 2;
            if(c == 1) a += 1;
            return num + a; 
        }

        // n의 크기에 따른 변의 길이
        int pow = (int)Math.pow(2, n);
        // 중앙 인덱스를 구한다.
        int mid = pow / 2 - 1;

        // 중앙 인덱스를 기준으로 넘어갔는지 체크
        boolean rpos = r > mid ? true : false;
        boolean cpos = c > mid ? true : false;

        // 몇번째 영역인지 체크, 왼위는 0, 오위는 1, 왼아 2, 오아 3 
        int time = 0;
        if(rpos) time += 2;
        if(cpos) time += 1;

        // n - 1으로 내려가고 r c 값도 알맞게 수정한다. 현재 단계에 맞게 값을 더 해준다.
        return recursive(n - 1, rpos ? (r - 1) - mid : r, cpos ? (c - 1) - mid : c, num + (pow * pow / 4) * time);
    }
}