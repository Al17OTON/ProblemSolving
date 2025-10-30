using System;

public class Solution {
    
    int dfs(int sum, int idx, int[] numbers, int target) {
        if(idx == numbers.Length) return sum == target ? 1 : 0;
        return dfs(sum + numbers[idx], idx + 1, numbers, target) + dfs(sum - numbers[idx], idx + 1, numbers, target);
    }
    
    public int solution(int[] numbers, int target) {
        return dfs(0, 0, numbers, target);
    }
}