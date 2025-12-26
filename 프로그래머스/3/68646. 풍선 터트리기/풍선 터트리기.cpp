#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int mini[1000001];
// 어떤 수의 오른편과 왼편에 자기보다 작은 수가 있다면 무조건 불가능 (작은 풍선을 터트리는건 1번만이므로)
// 어떤 수의 오른편 또는 왼편에 자기보다 작은 수가 있는 곳이 한 곳이라면 가능
int solution(vector<int> a) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> left;
    
    int m = a[a.size() - 1];
    for(int i = a.size() - 1; i >= 0; --i) {
        m = min(m, a[i]);
        mini[i] = m;
    }
    
    for(int i = 0; i < a.size(); ++i) {
        int cur = a[i];
        bool l = false, r = false;
        
        if(!left.empty() && left.top() < cur) l = true;
        if(mini[i] < cur) r = true;
        
        if(!(l && r)) ++answer;
        left.push(cur);
    }
    
    return answer;
}