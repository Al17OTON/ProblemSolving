import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final int COUNTRY = 6;
    static int[][] score = new int[COUNTRY][3];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        for(int f = 0; f < 4; f++) {
            st = new StringTokenizer(br.readLine());

            int totalWin = 0, totalDraw = 0, totalLoss = 0;
            boolean flag = true;
            for(int c = 0; c < COUNTRY; c++) {
                int win = Integer.parseInt(st.nextToken());
                int draw = Integer.parseInt(st.nextToken());
                int loss = Integer.parseInt(st.nextToken());

                score[c][0] = win;
                score[c][1] = draw;
                score[c][2] = loss;

                totalWin += win;
                totalDraw += draw;
                totalLoss += loss;

                if(win + draw + loss != 5) flag = false;
            }

            if(totalWin != totalLoss || totalDraw % 2 != 0) flag = false;
            if(flag) {
                flag = dfs(0, 1);
            }

            sb.append((flag ? "1 " : "0 "));
        }

        System.out.println(sb);
    }

    static boolean dfs(int country, int target) {
        if(country >= COUNTRY) return true;
        if(target >= COUNTRY) return dfs(country + 1, country + 2);

        for(int i = 0; i < 3; i++) {
            if(score[country][0 + i] > 0 && score[target][2 - i] > 0) {
                score[country][0 + i]--;
                score[target][2 - i]--;
                if(dfs(country, target + 1)) return true;
                score[country][0 + i]++;
                score[target][2 - i]++;
            }
        }

        return false;
    }
}