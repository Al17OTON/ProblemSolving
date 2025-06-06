import java.util.*;

class Solution {
    public int solution(int n, int k, int[] enemy) {
        PriorityQueue<Integer> pq = new PriorityQueue(Collections.reverseOrder());
        
        long totalEnemy = 0;
        int i;
        for(i = 0; i < enemy.length; ++i) {
            totalEnemy += enemy[i];
            pq.offer(enemy[i]);
            if(totalEnemy > n) {
                if(k > 0) {
                    totalEnemy -= pq.poll();
                    --k;
                }
                
                if(totalEnemy > n) break;
            }
        }
        
        return i;
    }
}