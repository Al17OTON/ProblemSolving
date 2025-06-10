import java.util.*;

class Solution {
    
    class Tangerine implements Comparable<Tangerine> {
        int count;
        public Tangerine(int count) {
            this.count = count;
        }
        public int compareTo(Tangerine o) {
            return o.count - this.count;
        }
    }
    
    public int solution(int k, int[] tangerine) {
        Arrays.sort(tangerine);
        PriorityQueue<Tangerine> pq = new PriorityQueue();
    
        int count = 1, idx = 0;
        for(int i = 1; i < tangerine.length; ++i) {
            if(tangerine[idx] == tangerine[i]) ++count;
            else {
                pq.offer(new Tangerine(count));
                idx = i;
                count = 1;
            }
        }
        pq.offer(new Tangerine(count));
        
        int select = 0, typeCount = 0;
        while(!pq.isEmpty() && select < k) {
            select += pq.poll().count;
            ++typeCount;
        }
        
        return typeCount;
    }
}