import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int N, M, result = 0;
    static char[] s;
    
    // I 가 나타나면 그 뒤에 OI가 몇번 붙는지를 카운트
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        s = br.readLine().toCharArray();

        for(int i = 0; i < M; i++) {
            if(s[i] == 'I') {
                int countOI = 0, idx = i + 1, tmp = 0;
                char OI = 'O';
                
                while(idx < M && s[idx] == OI) {
                    OI = OI == 'O' ? 'I' : 'O';
                    tmp++;
                    if(tmp == 2) {
                        tmp = 0;
                        countOI++;
                    }
                    idx++;
                }
                
                result += countOI >= N ? (countOI - N) + 1 : 0;

                i = idx - 1;
            }
        }

        System.out.println(result);
    }
}