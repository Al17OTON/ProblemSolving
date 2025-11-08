#include <string>
#include <vector>

using namespace std;

vector<int> dfs(const vector<vector<int>>& map, int r, int c, int level) {
    vector<int> res(2, 0), tmp;
    if(level == 1) {
        map[r][c] == 0 ? res[0] = 1 : res[1] = 1;
        return res;
    }
    
    int next_level = level / 2;
    res = dfs(map, r, c, next_level);
    
    tmp = dfs(map, r, c + next_level, next_level);
    res[0] += tmp[0];
    res[1] += tmp[1];
    
    tmp = dfs(map, r + next_level, c, next_level);
    res[0] += tmp[0];
    res[1] += tmp[1];
    
    tmp = dfs(map, r + next_level, c + next_level, next_level);
    res[0] += tmp[0];
    res[1] += tmp[1];
    
    if(res[0] == 4 && res[1] == 0) return {1, 0};
    else if(res[0] == 0 && res[1] == 4) return {0, 1};
    return res;
}

vector<int> solution(vector<vector<int>> arr) {
    return dfs(arr, 0, 0, arr.size());
}