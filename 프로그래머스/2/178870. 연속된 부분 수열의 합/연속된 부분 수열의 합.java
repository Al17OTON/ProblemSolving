import java.util.*;

class Solution {
    class Index implements Comparable<Index> {
        int start, end;
        public Index(int start, int end) {this.start = start; this.end = end;}
        public int compareTo(Index o) {
            if(this.getLen() == o.getLen()) {
                return this.start - o.start;
            }
            return this.getLen() - o.getLen();
        }
        public int getLen() {
            return end - start;
        }
    }
    
    HashMap<Integer, Integer> hash = new HashMap();
    PriorityQueue<Index> pq = new PriorityQueue();
    int N;
    public int[] solution(int[] sequence, int k) {
        N = sequence.length;
        
        int[] sum = new int[N];
        sum[0] = sequence[0];
        hash.put(sum[0], 0);
        
        
        for(int i = 0; i < N; ++i) {
            if(i > 0) sum[i] = sum[i - 1] + sequence[i]; 
            else sum[i] = sequence[i];
            
            if(sequence[i] == k) {
                pq.offer(new Index(i, i));
                break;
            }
            
            if(k == sum[i]) {
                pq.offer(new Index(0, i));
            } else if(k < sum[i] && hash.containsKey(sum[i] - k)) {
                int v = hash.get(sum[i] - k);
                pq.offer(new Index(v + 1, i));  
            } 
            hash.put(sum[i], i);
        }
        
        return new int[] {pq.peek().start, pq.peek().end};
    }
}