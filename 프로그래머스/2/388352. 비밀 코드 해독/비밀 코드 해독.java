class Solution {
    int n, answer = 0;
    int[][] q;
    int[] ans;

    public int solution(int n, int[][] q, int[] ans) {
        this.n = n;
        this.q = q;
        this.ans = ans;
        
        dfs(0, new boolean[n + 1], 0);
        
        return answer;
    }
    
    void dfs(int idx, boolean[] sel, int pre) {
        if(idx == 5) {
            if(check(sel)) {
                ++answer;
            }
            return;
        }
        
        for(int i = pre + 1; i <= n; ++i) {
            sel[i] = true;
            dfs(idx + 1, sel, i);
            sel[i] = false;
        }
        
    }
    
    boolean check(boolean[] sel) {
        
        for(int i = 0; i < q.length; ++i) {
            int count = 0;
            for(int j = 0; j < 5; ++j) {
                if(sel[q[i][j]]) ++count;
            }
            if(count != ans[i]) return false;
        }
        return true;
    }
    

}