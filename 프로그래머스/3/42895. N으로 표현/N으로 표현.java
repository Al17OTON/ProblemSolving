import java.util.*;

class Solution {
    
    public int solution(int N, int number) {        
        Set<Integer>[] sets = new HashSet[8];
        
        if(number == N) return 1;
        
        int start = N;
        for(int i = 0; i < 8; ++i) {
            sets[i] = new HashSet();
            sets[i].add(start);
            start = start * 10 + N;
        }
        
        for(int i = 1; i < 8; ++i) {
            for(int j = 0; j < i; ++j) {
                for(int num1 : sets[j]) {
                    for(int num2 : sets[i - j - 1]) {
                        sets[i].add(num1 + num2);
                        sets[i].add(num1 - num2);
                        sets[i].add(num1 * num2);
                        if(num2 != 0) sets[i].add(num1 / num2);
                    }
                }
            }
            if(sets[i].contains(number)) return i + 1;
        }
        
        return -1;
    }
}