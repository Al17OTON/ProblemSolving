#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Score {
    int diff;
    vector<int> vec;
    
    bool operator < (const Score& o) const {
        if(this->diff == o.diff) {
            for(int i = 10; i >= 0; --i) {
                if(this->vec[i] != o.vec[i]) return this->vec[i] < o.vec[i];
            }
        }
        return this->diff < o.diff;
    }
};

priority_queue<Score> pq;
vector<int> answer(11, 0);


void dfs(int target, int arrow_left, int op_score, int score, const vector<int>& info) {
    if(arrow_left == 0 && op_score >= score) return;
    if(target == -1) {
        pq.push({score - op_score, answer});
        return;
    }
    
    for(int i = arrow_left; i >= 0; --i) {
        answer[target] = i;
        if(info[target] < i) {
            dfs(target - 1, arrow_left - i, op_score - (info[target] > 0 ? 10 - target : 0), score + (10 - target), info);   
        } else {
            dfs(target - 1, arrow_left - i, op_score, score, info);
        }
    }
    answer[target] = 0;
    
}

vector<int> solution(int n, vector<int> info) {
    int peach_score = 0;
    for(int i = 0; i < info.size(); ++i) {
        if(info[i] > 0) peach_score += 10 - i;
    }
    
    dfs(10, n, peach_score, 0, info);
    
    return pq.top().diff <= 0 ? vector(1, -1) : pq.top().vec;
}