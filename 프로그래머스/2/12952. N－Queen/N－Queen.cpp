#include <string>
#include <vector>

using namespace std;

int col, lr, rl;

int dfs(int idx, int n) {
    if (idx == n) return 1;

    int res = 0;
    for (int c = 0; c < n; ++c) {
        if ((col & (1 << c)) || (lr & (1 << (n + (idx - c)))) || (rl & (1 << (idx + c)))) continue;
        col |= (1 << c);
        lr |= (1 << (n + (idx - c)));
        rl |= (1 << (idx + c));
        res += dfs(idx + 1, n);
        col ^= (1 << c);
        lr ^= (1 << (n + (idx - c)));
        rl ^= (1 << (idx + c));
    }

    return res;
}

int solution(int n) {
    int answer = 0;
    col = 0;
    lr = 0;
    rl = 0;
    
    return dfs(0, n);
}