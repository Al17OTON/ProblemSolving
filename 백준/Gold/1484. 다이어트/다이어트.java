import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int G;
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        G = Integer.parseInt(br.readLine());

        // G = (현재 몸무게)^2 - (다이어트 전 몸무게)^2
        // G = (현재 몸무게 + 다이어트 전 몸무게)(현재 몸무게 - 다이어트 전 몸무게)

        // i = 현재 몸무게, j = 다이어트 전 몸무게
        long i = (int)Math.sqrt(G) + 1, j = 1;

        while(true) {
            long calc = i * i - j * j;
            if(calc == G) sb.append(i).append("\n");
            else if(i == j) break;

            //더 클 경우 다이어트 전 몸무게를 늘려준다.
            if(calc > G) j++;
            else i++;
        }
        System.out.println(sb.length() == 0 ? -1 : sb);
    }
}