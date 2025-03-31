import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, K;
    static String[] words;
    static boolean[] alphabet = new boolean[26];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        words = new String[N];
        for(int n = 0; n < N; ++n) {
            words[n] = br.readLine();
        }

        if(K > 0) alphabet['a' - 'a'] = true;
        if(K > 1) alphabet['n' - 'a'] = true;
        if(K > 2) alphabet['t' - 'a'] = true;
        if(K > 3) alphabet['i' - 'a'] = true;
        if(K > 4) alphabet['c' - 'a'] = true;

        System.out.println(combination(1, 5));
    }

    static int combination(int idx, int count) {
        if(count >= K) {
            return countWord();
        }
        if(idx == 26) {
            return 0;
        }

        int max = 0;
        if(!alphabet[idx]) {
            alphabet[idx] = true;
            max = Math.max(combination(idx + 1, count + 1), max);
            alphabet[idx] = false;
        }
        max = Math.max(combination(idx + 1, count), max);

        return max;
    }

    static int countWord() {
        if(K < 5) return 0;
        int count = 0;
        for(String word : words) {
            boolean isOk = true;
            for(int i = 4; i < word.length() - 4; ++i) {
                if(!alphabet[word.charAt(i) - 'a']) {
                    isOk = false;
                    break;
                }
            }
            if(isOk) ++count;
        }
        return count;
    }
}