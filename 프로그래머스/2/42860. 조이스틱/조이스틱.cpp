#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> target;
int answer = 987654321;

int abs_func(int a) {
    return a > 0 ? a : -a;
}

int get_dist(int from, int to, int N) {
    return min({abs_func(from - to), abs_func(from + N - to), abs_func(to + N - from)});
}

void dfs(int idx, int t_s, int t_e, int cost, const string& name) {
    if(answer <= cost) return;
    if(t_s > t_e) {
        answer = cost;
        return;
    }
    
    int next = target[t_s];
    dfs(next, t_s + 1, t_e, cost + get_dist(idx, next, name.size()) + min(name[next] - 'A', 'Z' - name[next] + 1), name);
    next = target[t_e];
    dfs(next, t_s, t_e - 1, cost + get_dist(idx, next, name.size()) + min(name[next] - 'A', 'Z' - name[next] + 1), name);
}

int solution(string name) {
    for(int i = 1; i < name.size(); ++i) {
        if(name[i] != 'A') target.push_back(i);
    }
    dfs(0, 0, target.size() - 1, (name[0] == 'A' ? 0 : min(name[0] - 'A', 'Z' - name[0] + 1)), name);
    return answer;
}