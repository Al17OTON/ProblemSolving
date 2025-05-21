import java.util.*;

class Solution {
    class Number implements Comparable<Number> {
        int num, idx;
        public Number(int n, int i) {
            num = n;
            idx = i;
        }
        
        public int compareTo(Number o) {
            return this.num - o.num;
        }
        
    }
    int N;
    public int[] solution(int[] numbers) {
        N = numbers.length;
        
        int[] answer = new int[N];
        PriorityQueue<Number> pq = new PriorityQueue();
        
        for(int i = 0; i < N; ++i) {
            int num = numbers[i];
            
            while(!pq.isEmpty() && pq.peek().num < num) {
                answer[pq.poll().idx] = num;
            }
            
            pq.offer(new Number(num, i));
        }
        
        while(!pq.isEmpty()) {
            answer[pq.poll().idx] = -1;
        }
        
        return answer;
    }
}