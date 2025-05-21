import java.util.*;
class Solution {
    int N;
    long[] counter = new long[10000];
    public long solution(int[] weights) {
        long answer = 0;
        N = weights.length;
        
        for(int i = 0; i < N; ++i) {
            ++counter[weights[i]];
        }
        
        Arrays.sort(weights);
        
        // 1 : 1
        // 1 : 2
        // 2 : 3
        // 3 : 4
        for(int i = 0; i < N; ++i) {
            int target = weights[i];
            --counter[target];
            
            answer += counter[target];
            answer += counter[target * 2];
            if(target % 2 == 0) answer += counter[(target / 2) * 3];
            if(target % 3 == 0) answer += counter[(target / 3) * 4];
        }
        
        return answer;
    }
    
    int getIdx(int[] v, int target) {
        for(int i = 0; i < v.length; ++i) {
            if(v[i] == target) return 0;
        }
        return target;
    }
}