#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int n, const vector<int>& stones, int k) {
    int idx = -1;
    for(int i = 0; i < stones.size(); ++i) {
        if(idx + k >= i && stones[i] >= n) idx = i;
        else if(idx + k < i) return false;
    }
    if(idx + k < stones.size()) return false;
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int l = 200000001, r = 0, mid;
    for(int i = 0; i < stones.size(); ++i) {
        r = max(r, stones[i]);        
        l = min(l, stones[i]);
    }
    
    while(l <= r) {
        mid = (l + r) / 2;
        
        if(check(mid, stones, k)) {
            l = mid + 1;
            answer = max(answer, mid);
        } else {
            r = mid - 1;
        }
    }
    
    return answer;
}