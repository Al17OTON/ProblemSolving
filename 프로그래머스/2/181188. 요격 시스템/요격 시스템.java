import java.util.*;

class Solution {
    class Missile implements Comparable<Missile> {
        int s, e;
        public Missile(int s, int e) {this.s = s; this.e = e;}
        public int compareTo(Missile o) {
            if(o.s == this.s) return this.e - o.e;
            return this.s - o.s;
        }
    }
    
    PriorityQueue<Missile> pq = new PriorityQueue();
    public int solution(int[][] targets) {
        int answer = 0;
        
        for(int i = 0; i < targets.length; ++i) {
            pq.offer(new Missile(targets[i][0], targets[i][1]));
        }
        
        while(!pq.isEmpty()) {
            Missile t = pq.poll();
            
            while(!pq.isEmpty() && isDup(t, pq.peek())) {
                Missile next = pq.poll();
                t.s = Math.max(t.s, next.s);
                t.e = Math.min(t.e, next.e);
                
            }
            ++answer;
        }
        
        return answer;
    }
    
    boolean isDup(Missile a, Missile b) {
        return b.s < a.e;
    }
}