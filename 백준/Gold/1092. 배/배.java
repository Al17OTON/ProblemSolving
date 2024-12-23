import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int[] crane;
    static ArrayList<Integer> box = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        N = Integer.parseInt(br.readLine());
        crane = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int n = 0; n < N; n++) {
            crane[n] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(crane);

        M = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());
        for(int m = 0; m < M; m++) {
            box.add(Integer.parseInt(st.nextToken()));
        }

        box.sort((a, b) -> b - a);

        if(box.get(0) > crane[N - 1]) {
            System.out.println(-1);
            return;
        }
        int time = 0;
        while(!box.isEmpty()) {
            for(int i = N - 1; i >= 0; i--) {
                int j = 0;
                while(j < box.size() && box.get(j) > crane[i]) {
                    j++;
                }
                if(j == box.size()) continue;
                box.remove(j);
            }
            time++;
        }

        System.out.println(time);
    }  


}