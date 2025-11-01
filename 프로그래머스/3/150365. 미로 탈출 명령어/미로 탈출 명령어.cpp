#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// struct Pos {
//     int r, c, k;
//     string path = "";
    
//     bool operator<(const Pos& pos) const{
//         return this->path > pos.path;
//     }
// };
struct Pos {
    int r, c, k;
};

int get_dist(const Pos& start, const pair<int, int>& end) {
    return abs(start.r - end.first) + abs(start.c - end.second);
}

char direction[] = {'d', 'l', 'r', 'u'};
int dr[] = {1, 0, 0, -1};
int dc[] = {0, -1, 1, 0};
vector<char> path;

bool dfs(Pos cur, const Pos& target, int n, int m) {
    if(get_dist(cur, {target.r, target.c}) > target.k - cur.k) return false;
    if(cur.k == target.k) {
        if(cur.r == target.r && cur.c == target.c) return true;
        return false;
    }
    
    for(int i = 0; i < 4; ++i) {
        int nr = cur.r + dr[i];
        int nc = cur.c + dc[i];
        
        if(nr > n || nr <= 0 || nc > m || nc <= 0) continue;
        if(!dfs({nr, nc, cur.k + 1}, target, n, m)) continue;
        path.push_back(direction[i]);
        return true;
    }
    return false;
    
    
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    if((k - get_dist({x, y, 0}, {r, c})) % 2 != 0 || !dfs({x, y, 0}, {r, c, k}, n, m)) return "impossible";
    string answer = "";
    for(int i = path.size() - 1; i >= 0; --i) answer += path[i];
    return answer;
    
//     string answer = "";
    
//     priority_queue<Pos> pq;
//     pq.push({x, y, 0, ""});
    
//     while(!pq.empty()) {
//         Pos p = pq.top(); pq.pop();
        
//         if(get_dist(p, {r, c}) > k - p.k) continue;
//         if(p.k == k) {
//             if(p.r == r && p.c == c) return p.path;
//             continue;
//         }
        
//         for(int i = 0; i < 4; ++i) {
//             int nr = p.r + dr[i];
//             int nc = p.c + dc[i];
            
//             if(nr > n || nr <= 0 || nc > m || nc <= 0) continue;
            
//             pq.push({nr, nc, p.k + 1, p.path + direction[i]});
//         }
//     }
        
//     return "impossible";
}


