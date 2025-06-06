import java.util.*;

class Solution {
    
    static int col;
    
    class Tuple implements Comparable<Tuple> {
        int[] data;
        public Tuple(int[] data) {
            this.data = data;
        }
        
        public int compareTo(Tuple o) {
            if(this.data[col] == o.data[col]) {
                return o.data[0] - this.data[0];
            }
            return this.data[col] - o.data[col];
        }
    }
    
    public int solution(int[][] data, int col, int row_begin, int row_end) {
        int answer = 0;
        this.col = col - 1;
        
        PriorityQueue<Tuple> pq = new PriorityQueue();
        
        for(int i = 0; i < data.length; ++i) {
            pq.offer(new Tuple(data[i]));
        }
        
        int idx = 1;
        while(!pq.isEmpty()) {
            Tuple tuple = pq.poll();
            if(idx >= row_begin) {
                if(idx > row_end) break;
                
                int S_idx = 0;
                for(int i = 0; i < tuple.data.length; ++i) {
                    S_idx += tuple.data[i] % idx;
                }
                
                answer ^= S_idx;
            }
            ++idx;
        }
        
        return answer;
    }
}