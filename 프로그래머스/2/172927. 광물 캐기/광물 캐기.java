class Solution {
    int[] picks; 
    String[] minerals;
    int[][] pickCosts = {
        {1, 1, 1},
        {5, 1, 1},
        {25, 5, 1}
    };
    
    public int solution(int[] picks, String[] minerals) {
        this.picks = picks;
        this.minerals = minerals;
        
        return dfs(0, 0, 0, 0);
    }
    
    int dfs(int mineralIdx, int cost, int pickIdx, int count) {
        if(mineralIdx == minerals.length) {
            return cost;
        }
        
        int currentIdx = minerals2Idx(minerals[mineralIdx]);
        if(count == 0) {
            int result = Integer.MAX_VALUE;
            boolean flag = true;
            for(int i = 0; i < picks.length; ++i) {
                if(picks[i] > 0) {
                    flag = false;
                    --picks[i];
                    result = Math.min(result, dfs(mineralIdx, cost, i, 5));
                    ++picks[i];
                }  
            }
            if(flag) result = cost;
            return result;
        } else {
            return dfs(mineralIdx + 1, cost + pickCosts[pickIdx][currentIdx], pickIdx, count - 1);
        }
        
    }
    
//     int dfs(int mineralIdx, int cost) {
//         if(mineralIdx == minerals.length) {
//             return cost;
//         }
//         int result = Integer.MAX_VALUE;
//         int currentIdx = minerals2Idx(minerals[mineralIdx]);
//         boolean flag = true;
//         for(int i = 0; i < picks.length; ++i) {
//             if(picks[i] > 0) {
//                 flag = false;
//                 --picks[i];
//                 result = Math.min(result, dfs(mineralIdx + 1, cost + pickCosts[i][currentIdx]));
//                 ++picks[i];
//             }
//         }
        
//         // 모든 곡괭이를 사용한 경우
//         if(flag) {
//             result = cost;
//         }
//         return result;
        
//     }
    
    int minerals2Idx(String mineral) {
        if(mineral.length() == 5) return 2;
        if(mineral.length() == 4) return 1;
        return 0;
    }
    
}