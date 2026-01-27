#include <vector>
#include <memory.h>

using namespace std;

vector<int> answer;
int N;
long long K;

void dfs(int idx, int v, long long pre, long long range) {
    if(idx == N) return;
    
    long long gap = range / (N - idx);
    long long place = pre;
    for(int i = 1; i <= N; ++i) {
        if(v & (1 << i)) continue;
        if(place + gap >= K) {
            answer.push_back(i);
            dfs(idx + 1, v | (1 << i), place, gap);
            break;
        }
        place += gap;
    }
}

vector<int> solution(int n, long long k) {
    N = n;
    K = k;
    
    long long range = 1;
    for(int i = 1; i <= N; ++i) range *= i;
    
    dfs(0, 0, 0, range);
    
    return answer;
}