import java.util.*;

class Stair implements Comparable<Stair> {
    int cur, stone;
    public Stair(int cur, int stone) {
        this.cur = cur;
        this.stone = stone;
    }
    
    public int compareTo(Stair o) {
        return this.stone - o.stone;
    }
    
}

class Solution {
    // 가장 가까운 10의 배수의 위치로 이동
    public int solution(int storey) {
        return bfs(storey);
    }
    
    
    
    int bfs(int storey) {
        PriorityQueue<Stair> pq = new PriorityQueue();
        pq.offer(new Stair(storey, 0));
        
        while(!pq.isEmpty()) {
            Stair s = pq.poll();
            
            if(s.cur == 0) {
                return s.stone;
            }
            
            int target = s.cur % 10;
            int nextStair = s.cur / 10;
            pq.offer(new Stair(nextStair, s.stone + target));
            pq.offer(new Stair(nextStair + 1, s.stone + (10 - target)));
        }
        return -1;
    }
}


