import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static class Union {
        int[] uni;
        public Union(int n) {
            uni = new int[n + 1];
            for(int i = 1; i <= n; i++) uni[i] = i;
        }

        int find(int a) {
            if(uni[a] == a) return a;
            return uni[a] = find(uni[a]);
        }

        void setUni(int a, int b) {
            a = find(a);
            b = find(b);

            if(a == b) return;

            uni[a] = b;
        }

        boolean isUni(int a, int b) {
            a = find(a);
            b = find(b);

            return a == b;
        }
    }

    static int N, M, MAX_LIE = 0;
    static Union uni;

    // from, to 형태로 주어지지 않으므로 Union을 형성하기 어렵다. (2명 이상이여야 하는데 1명만 주어지는 경우가 있음)
    // 따라서, 사용되지 않는 0번을 진실을 아는 그룹으로 묶자.
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        uni = new Union(N);

        st = new StringTokenizer(br.readLine());
        int truthNum = Integer.parseInt(st.nextToken());
        if(truthNum > 0) {
            for(int i = 0; i < truthNum; i++) {
                uni.setUni(Integer.parseInt(st.nextToken()), 0);
            }
        }

        ArrayList<Integer> party = new ArrayList<>();
        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());

            int first = Integer.parseInt(st.nextToken());
            party.add(first);
            num--;
            for(; num > 0; num--) {
                int member = Integer.parseInt(st.nextToken());
                uni.setUni(member, first);
            }
        }

        for(int m = 0; m < M; m++) {
            if(!uni.isUni(0, party.get(m))) MAX_LIE++;
        }

        System.out.println(MAX_LIE);
    }
}