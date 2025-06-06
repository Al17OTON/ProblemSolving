class Solution {
    public long solution(int k, int d) {
        long answer = 0;
        
        // long max = (int) Math.floor(Math.sqrt(1.0*r2*r2 - 1.0*i*i));
        
        for(int i = 0; i <= d; ++i) {
            if(i % k != 0) continue;
            long count = (int) Math.floor(Math.sqrt(1.0*d*d - 1.0*i*i));
            // System.out.println(count);
            answer += (count / k) + 1;
        }
        
        
        return answer;
    }
    

}

/*
k = 1, d = 5
.
. . . .
. . . . .
. . . . .
. . . . .
. . . . . .

k = 2, d = 4
.

.  .

.  .  .
*/