import java.util.*;

class Main {
    static boolean[][] adj = {
        {false, true, true, true, true, false},
        {true, false, true, true, false, true},
        {true, true, false, false, true, true},
        {true, true, false, false, true, true},
        {true, false, true, true, false, true},
        {false, true, true, true, true, false},
    };
    static long N;
    static long[] dice = new long[6];
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        N = sc.nextLong();
        for(int i = 0; i < dice.length; ++i) {
            dice[i] = sc.nextLong();
        }

        long three_side = Long.MAX_VALUE, two_side = Long.MAX_VALUE, one_side = Long.MAX_VALUE;

        long max_side = 0, sum = 0;
        for(int i = 0; i < dice.length; ++i) {
            one_side = Math.min(one_side, dice[i]);
            max_side = Math.max(max_side, dice[i]);
            sum += dice[i];
            for(int j = i + 1; j < dice.length; ++j) {
                if(!adj[i][j]) continue;
                two_side = Math.min(two_side, dice[i] + dice[j]);
                for(int k = j + 1; k < dice.length; ++k) {
                    if(adj[i][k] && adj[j][k]) three_side = Math.min(three_side, dice[i] + dice[j] + dice[k]);
                }
            }
        }

        if(N == 1) {
            System.out.print(sum - max_side);
        } else {
            long answer = 0;
            answer += three_side * 4;
            answer += ((N - 1) * 4 + (N - 2) * 4) * two_side;
            answer += ((N - 1) * (N - 2) * 4 + (N - 2) * (N - 2)) * one_side;
            System.out.print(answer);
        }
    }

    
}