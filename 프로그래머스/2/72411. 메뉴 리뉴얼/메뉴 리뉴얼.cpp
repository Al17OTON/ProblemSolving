#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

unordered_map<string, int> map;
bool course_flag[11] = {false};

void dfs(const string& order, const int limit, int idx, const string& a, bool flag) {
    if(course_flag[a.size()] && flag) {
        map[a]++;
    }
    if(idx >= order.size() || a.size() >= limit) {
        return;
    }
    
    dfs(order, limit, idx + 1, a + order[idx], true);
    dfs(order, limit, idx + 1, a, false);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i : course) course_flag[i] = true;
    
    for(string order : orders) {
        sort(order.begin(), order.end());
        dfs(order, course[course.size() - 1], 0, "", false);   
    }
    
    priority_queue<pair<int, string>> pq;
    for(pair<string, int> m : map) {
        pq.push({m.second, m.first});
    }
    
    int memo[11] = {0};
    while(!pq.empty()) {
        pair<int, string> p = pq.top(); pq.pop();
        if(p.first >= memo[p.second.size()] && p.first >= 2) {
            memo[p.second.size()] = p.first;
            answer.push_back(p.second);
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}