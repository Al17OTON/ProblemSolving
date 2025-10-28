using System;

public class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int[] circle = new int[queue1.Length + queue2.Length];
        
        long sum1 = 0, sum2 = 0;
        
        for(int i = 0; i < queue1.Length; ++i) {
            circle[i] = queue1[i];
            sum1 += queue1[i];
        }
        for(int i = 0; i < queue2.Length; ++i) {
            circle[i + queue1.Length] = queue2[i];
            sum2 += queue2[i];
        }
        
        if((sum1 + sum2) % 2 != 0) return -1;
        
        int idx1 = 0, idx2 = queue1.Length, size1 = queue1.Length, size2 = queue2.Length;
        int cnt = 0;
        while(sum1 != sum2) {
            if(sum1 > sum2) {
                sum1 -= circle[idx1 % circle.Length];
                sum2 += circle[idx1++ % circle.Length];
                --size1;
                ++size2;
            } else {
                sum1 += circle[idx2 % circle.Length];
                sum2 -= circle[idx2++ % circle.Length];
                ++size1;
                --size2;
            }
            
            if(size1 == 0 || size2 == 0 || (idx1 >= circle.Length && idx2 >= circle.Length)) return -1;
            ++cnt;
        }
        
        return cnt;
    }
}