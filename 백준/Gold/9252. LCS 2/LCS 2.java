import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static int[][] arr;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String a = br.readLine();
        String b = br.readLine();

        arr = new int[a.length() + 1][b.length() + 1];

        for(int i = 0; i <= a.length(); i++) {
            for(int j = 0; j <= b.length(); j++) {
                if(i == 0 || j == 0) {
                    arr[i][j] = 0;
                }
                else if(a.charAt(i - 1) == b.charAt(j - 1)) {
                    arr[i][j] = arr[i - 1][j - 1] + 1; 
                } else {
                    arr[i][j] = Math.max(arr[i - 1][j], arr[i][j - 1]);
                }
            }
        }
        int i = a.length(), j = b.length(), idx = arr[a.length()][b.length()];
        char[] result = new char[idx];
        while(arr[i][j] > 0) {
            if(arr[i][j] == arr[i - 1][j]) {
                i = i - 1;
            } else if(arr[i][j] == arr[i][j - 1]) {
                j = j - 1;
            } else {
                result[--idx] = a.charAt(i - 1);
                i = i - 1;
                j = j - 1;
            }
        }
        System.out.println(result.length);
        if(result.length > 0) System.out.println(result);
    }

}