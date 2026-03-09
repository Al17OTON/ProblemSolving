#include <deque>
#include <vector>

using namespace std;

constexpr int MAX_INT = 987654321;

int pos2idx(int r, int c, int N) {
    return r * N + c;
}

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<int> time(m * n, MAX_INT);
    for(int i = 0 ; i < drops.size(); ++i) {
        time[pos2idx(drops[i][0], drops[i][1], n)] = i + 1;
    }
    
    vector<int> row(m * (n - w + 1));
    
    for(int r = 0; r < m; ++r) {
        deque<int> dq;
        
        for(int c = 0; c < n; ++c) {
            while(!dq.empty() && time[pos2idx(r, dq.back(), n)] >= time[pos2idx(r, c, n)]) dq.pop_back();
            
            dq.push_back(c);
            
            if(dq.front() <= c - w) dq.pop_front();
            
            if(c >= w - 1) {
                row[pos2idx(r, c - w + 1, n - w + 1)] = time[pos2idx(r, dq.front(), n)];
            }
        }
    }
    
    int maximum = -1;
    vector<int> answer = {0, 0};
    for(int c = 0; c < n - w + 1; ++c) {
        deque<int> dq;
        
        for(int r = 0; r < m; ++r) {
            int t = row[pos2idx(r, c, n - w + 1)];
            
            while(!dq.empty() && row[pos2idx(dq.back(), c, n - w + 1)] >= t) dq.pop_back();
            
            dq.push_back(r);
            
            if(dq.front() <= r - h) {
                dq.pop_front();
            }
            
            if(r >= h - 1) {
                int a = row[pos2idx(dq.front(), c, n - w + 1)];
                
                if(a > maximum || (a == maximum && ((r - h + 1) < answer[0] || ((r - h + 1) == answer[0] && c < answer[1])))) {
                    maximum = a;
                    answer[0] = r - h + 1;
                    answer[1] = c;
                }
            }
        }
    }
    
    return answer;
}