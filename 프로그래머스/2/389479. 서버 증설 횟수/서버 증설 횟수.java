import java.util.*;

class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        Queue<Integer> q = new LinkedList();
        
        for(int i = 0; i < players.length; i++) {
            int player = players[i];
            
            while(!q.isEmpty() && q.peek() + k == i) q.poll();
            int capacity = (q.size() + 1) * m;
            if(capacity <= player) {
                int need = (player / m) - q.size();
                answer += need;
                for(int j = 0; j < need; j++) q.offer(i);
            }
        }
        return answer;
    }
}