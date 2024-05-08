class Solution {
    public int solution(int n, int[] tops) {
        int[] dpA = new int[n];
        int[] dpB = new int[n];
        
        dpA[0] = 1;
        if(tops[0] == 1) {
            dpB[0] = 3;
        } else {
            dpB[0] = 2;
        }
        
        for(int i = 1; i < n; i++) {
            dpA[i] = (dpA[i - 1] + dpB[i - 1]) % 10007;
            if(tops[i] == 1) {
                dpB[i] = (2 * dpA[i - 1] + 3 * dpB[i - 1]) % 10007;
            } else {
                dpB[i] = (dpA[i - 1] + 2 * dpB[i - 1]) % 10007;
            }
        }
        return (dpA[n - 1] + dpB[n - 1]) % 10007;
    }
}


/*
// N = 1     [0] -> 3                [1] -> 4
// N = 2   [0,0] -> 8              [1,0] -> 11             [0,1] -> 11        [1,1] -> 15              
// N = 3 [0,0,0] -> 21           [1,0,0] -> 29           [0,1,0] -> 30
         [0,0,1] -> 29           [1,1,0] -> 41           [0,1,1] -> 41
         [1,0,1] -> 40           [1,1,1] -> 55?


f(n) = (f(n-1) + 5*(n-1) + f(n-2)) ?
*/

