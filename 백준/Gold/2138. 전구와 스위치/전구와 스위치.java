import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int N;
    static boolean[] A, B, tmp;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        A = new boolean[N + 2];
        B = new boolean[N + 2];
        char[] a = br.readLine().toCharArray();
        char[] b = br.readLine().toCharArray();

        for(int i = 0; i < N; i++) {
            A[i] = a[i] == '1';
            B[i] = b[i] == '1';
        }
        tmp = A.clone();

        int aCount = 0, bCount = 1;
        for(int i = 0; i < N - 1; i++) {
            if(A[i] != B[i]) {
                A[i] = !A[i];
                A[i + 1] = !A[i + 1];
                A[i + 2] = !A[i + 2];
                aCount++; 
            }
        }

        for(int i = 0; i < N; i++) {
            if(A[i] != B[i]) {
                aCount = -1;
                break;
            }
        }

        A = tmp;
        A[0] = !A[0];
        A[1] = !A[1];
        
        for(int i = 0; i < N - 1; i++) {
            if(A[i] != B[i]) {
                A[i] = !A[i];
                A[i + 1] = !A[i + 1];
                A[i + 2] = !A[i + 2];
                bCount++; 
            }
        }

        for(int i = 0; i < N; i++) {
            if(A[i] != B[i]) {
                bCount = -1;
                break;
            }
        }

        if(bCount == aCount) System.out.println(aCount);
        else if(aCount == -1) System.out.println(bCount);
        else if(bCount == -1) System.out.println(aCount);
        else System.out.print(aCount > bCount ? bCount : aCount);
    }
}