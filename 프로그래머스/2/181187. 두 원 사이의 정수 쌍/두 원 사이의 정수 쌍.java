class Solution {
    
    
    public long solution(int r1, int r2) {
        long sum = 0;
        for(int i = 1; i <= r2; ++i) {
            long minJ = (int) Math.ceil(Math.sqrt(1.0*r1*r1 - 1.0*i*i));
            long maxJ = (int) Math.floor(Math.sqrt(1.0*r2*r2 - 1.0*i*i));
 
            sum += (maxJ - minJ + 1);
        }
        
        return sum * 4;
    }
}

// 1 = 1
// 2 = 9
// 3 = 25
// 4 9 16 25 36 49