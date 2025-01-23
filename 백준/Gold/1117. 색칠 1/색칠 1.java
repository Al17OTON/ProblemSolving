import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static long W, H, f, c, x1, y1, x2, y2;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        W = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        f = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        x1 = Integer.parseInt(st.nextToken());
        y1 = Integer.parseInt(st.nextToken());
        x2 = Integer.parseInt(st.nextToken());
        y2 = Integer.parseInt(st.nextToken());

        long total = W * H;

        // 다 접힌 상태에서 색칠된 부분의 넓이
        long square = (x2 - x1) * (y2 - y1);

        long leftW = Math.min(f, W - f); //왼쪽 길이가 오른쪽 길이보다 큰 경우 반영
        long leftSqure = (Math.min(leftW, x2) - Math.min(leftW, x1)) * (y2 - y1);

        //왼쪽 부분과 오른쪽 부분을 합치고 C + 1 만큼 반복된다.
        total -= (square + leftSqure) * (c + 1);

        System.out.println(total); 
    }
}