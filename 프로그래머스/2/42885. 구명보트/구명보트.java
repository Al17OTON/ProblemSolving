import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue(Collections.reverseOrder());
        
        Arrays.sort(people);
        
        for(int i = people.length - 1; i >= 0; i--) {
            int w = people[i];
            if(!pq.isEmpty() && pq.peek() >= w) pq.poll();
            else {
                pq.offer(limit - w);
                answer++;
            }
        }
        
        return answer;
    }
}