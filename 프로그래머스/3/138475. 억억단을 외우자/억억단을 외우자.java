import java.util.*;

class Solution {
    
    public int[] solution(int e, int[] starts) {
        int[] answer = new int[starts.length];
        int[] div = new int[e + 1];
        
        for(int i = 1; i <= Math.sqrt(e); ++i) {
            div[i * i] += 1;
            for(int j = i * (i + 1); j <= e; j += i) {
                div[j] += 2;
            }
        }
        
        int[] counter = new int[e + 1];
        int maxIdx = e;
        for(int i = e; i >= 1; --i) {
            if(div[maxIdx] <= div[i]) {
                maxIdx = i;
            }
            counter[i] = maxIdx;
        }
        
        for(int i = 0; i < starts.length; ++i) {
            answer[i] = counter[starts[i]];
        }
        
        return answer;
    }
}

/*
1 2 3 4 5 6 7 8
2 4 6 8
3 6 
4 8
5
6
7
8

*/