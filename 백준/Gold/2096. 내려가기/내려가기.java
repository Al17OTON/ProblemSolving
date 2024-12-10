import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] min, max;
    static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());

        min = new int[3];
        max = new int[3];
        st = new StringTokenizer(br.readLine());

        min[0] = Integer.parseInt(st.nextToken());
        min[1] = Integer.parseInt(st.nextToken());
        min[2] = Integer.parseInt(st.nextToken());
        max[0] = min[0];
        max[1] = min[1];
        max[2] = min[2];

        int one, two, three;
        int[] tmp;
        for(int n = 1; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            one = Integer.parseInt(st.nextToken());
            two = Integer.parseInt(st.nextToken());
            three = Integer.parseInt(st.nextToken());

            tmp = min.clone();
            min[0] = Math.min(tmp[0], tmp[1]) + one;
            min[1] = Math.min(tmp[0], Math.min(tmp[1], tmp[2])) + two;
            min[2] = Math.min(tmp[1], tmp[2]) + three;

            tmp = max.clone();
            max[0] = Math.max(tmp[0], tmp[1]) + one;
            max[1] = Math.max(tmp[0], Math.max(tmp[1], tmp[2])) + two;
            max[2] = Math.max(tmp[1], tmp[2]) + three;
        }

        System.out.println(Math.max(max[0], Math.max(max[1], max[2])) + " " + Math.min(min[0], Math.min(min[1], min[2])));
    }
}