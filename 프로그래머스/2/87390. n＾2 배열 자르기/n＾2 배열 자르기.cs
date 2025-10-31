using System;

public class Solution {
    public int[] solution(int n, long left, long right) {
        long size = right - left + 1;
        int[] answer = new int[size];
        
        for(long i = left; i <= right; ++i) {
            answer[i - left] = (int)Math.Max((i / n) + 1, (i % n) + 1);
        }
        
        return answer;
    }
}

/*
i행 j열 의 값 = max(i, j)
이므로 주어진 left, right의 좌표만 구하면 됨.
좌표는 (left / n), (left % n)
*/