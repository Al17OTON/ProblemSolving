import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {

    static int N;
    static boolean flag;
    static HashSet<String> hash = new HashSet<>(), full = new HashSet<>();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        for(int t = 0; t < T; t++) {
            flag = true;
            N = Integer.parseInt(br.readLine());
            
            for(int n = 0; n < N; n++) {
                String number = br.readLine();

                if(flag) setNumber(number);
            }
            hash.clear();
            full.clear();
            sb.append(flag ? "YES\n" : "NO\n");
        }
        System.out.println(sb);
    }

    static void setNumber(String number) {
        if(hash.contains(number)) {
            flag = false;
            return;
        }
        full.add(number);

        for(int l = 1; l < number.length(); l++) {
            String sub = number.substring(0,l);
            if(full.contains(sub)) {
                flag = false;
                return;
            }
            hash.add(sub);
        }
    }
}