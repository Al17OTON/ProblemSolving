//이전 문제로 돌아가야하므로 정렬은 불가능
//의외로 이분탐색?
class Solution {
    int[] diffs, times;
    long limit;
    
    public int solution(int[] diffs, int[] times, long limit) {
        int left = 1, right = 0, mid = 0; // 난이도는 최소 1
        int min = Integer.MAX_VALUE;
        this.diffs = diffs;
        this.times = times;
        this.limit = limit;
        
        // 최고 난이도 찾기
        for(int i = 0; i < diffs.length; i++) right = Math.max(right, diffs[i]);
        
        while(left <= right) {
            mid = (left + right) / 2;
            
            //제한시간 내로 푼 경우 = 레벨을 낮추어도 된다.
            if(isPossible(mid)) {
                right = mid - 1;
                min = Math.min(mid, min);
            } else {
                left = mid + 1;
            }
        }
        // System.out.println(left + " " + right);
        
        return min;
    }
    
    boolean isPossible(int level) {
        long time = 0;
        
        for(int i = 0; i < diffs.length; i++) {
            if(diffs[i] <= level) {
                time += times[i];
            } else {
                int diff = diffs[i] - level;
                time += (times[i - 1] + times[i]) * diff;
                time += times[i];
            }
            if(time > limit) return false;
        }
        
        return true;
    }
}