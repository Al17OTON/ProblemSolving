#include <string>
#include <vector>

using namespace std;

void dfs(int n, int from, int to, int by, vector<vector<int>>& answer) {
    if(n == 0) return;
    dfs(n - 1, from, by, to, answer);
    answer.push_back({from, to});
    dfs(n - 1, by, to, from, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    dfs(n, 1, 3, 2, answer);
    return answer;
}