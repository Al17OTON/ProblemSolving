// import java.util.*;
// class Solution {
//     class Element implements Comparable<Element> {
//         int idx, val;
//         public Element(int idx, int val) {
//             this.idx = idx;
//             this.val = val;
//         }
//         public int compareTo(Element o) {
//             return this.val - o.val;
//         }
//     }
    
//     PriorityQueue<Element> apq = new PriorityQueue(), bpq = new PriorityQueue();
//     long[] a, b;
//     int N;
//     public long solution(int[] sequence) {
//         N = sequence.length + 2;
//         a = new long[N];
//         b = new long[N];
        
//         // a[1] = sequence[0];
//         // b[1] = -sequence[0];
//         // apq.offer(new Element(0, a[0]));
//         // apq.offer(new Element(0, b[0]));
//         boolean flag = false;
//         for(int i = 1; i < N - 1; ++i) {
//             int aVal = sequence[i - 1] * (flag ? 1 : -1);
//             int bVal = sequence[i - 1] * (flag ? -1 : 1)
//             a[i] = a[i - 1] + aVal;
//             b[i] = b[i - 1] + bVal;
            
//             apq.offer(new Element(i, aVal));
//             bpq.offer(new Element(i, bVal));
//         }
        
//         return getMax();
//     }
    
//     long getMax() {
//         a[N - 1] = a[N - 2];
//         b[N - 1] = b[N - 2];
//         long max = a[N - 1];
        
//         long aSum = a[N - 1];
//         long bSum = b[N - 1];
        
//         int start = 0, end = N - 1;
//         while(!apq.isEmpty()) {
//             Element e = apq.poll();
            
//             if(e.idx >= start && e.idx <= end) {
//                 long left = a[e.idx - 1] - a[start];
//                 long right = a[end] - a[e.idx];
                
//                 if(left > right) {
                    
//                 }
//             }
//         }
        
//     }
// }

// // [2, 3, -6, 1, 3, -1, 2, 4]
// // a = 2, -3, -6, -1, 3, 1, 2, -4
// // b = -2, 3, 6, 1, -3, -1, -2, 4
    
// // a = 2 -1 -7 -8 -5 -4 -2 -6
// // b = -2 1 7 8 5 4 2 6


import java.util.*;
class Solution {
    
    class Sum {
        int idx;
        long val;
        public Sum(int idx, long val) {
            this.idx = idx;
            this.val = val;
        }
    }
    long[] sum;
    int N;
    Sum min, max;
    public long solution(int[] sequence) {
        N = sequence.length;
        sum = new long[N + 1];
        
        sum[0] = 0;
        min = new Sum(0, 0);
        max = new Sum(0, 0);
        
        boolean flag = false;
        for(int i = 1; i <= N; ++i) {
            sum[i] = sum[i - 1] + sequence[i - 1] * (flag ? 1 : -1);
            flag = !flag;
            if(min.val > sum[i]) {
                min.idx = i;
                min.val = sum[i];
            }
            if(max.val < sum[i]) {
                max.idx = i;
                max.val = sum[i];
            }
        }
        
        return Math.abs(min.val) + Math.abs(max.val);
    }
}















