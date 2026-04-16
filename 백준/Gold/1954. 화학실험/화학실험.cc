#include <iostream>
#include <vector>

struct Element {
    int a, b;
};

using namespace std;

int N, M;
vector<Element> vec;

bool dfs(int idx, const int target, int left) {
    if(idx == N) {
        return left == 0;
    }
    else if(left == 0) {
        return false;
    }
    
    for(int i = 1; i <= left; ++i) {
        if(vec[idx].a * i + vec[idx].b != target) continue;
        if(dfs(idx + 1, target, left - i)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int n = 0; n < N; ++n) {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }

    cin >> M;

    bool flag = true;
    for(int i = 1; i <= (M - N) + 1; ++i) {
        if(dfs(1, vec[0].a * i + vec[0].b, M - i)) {
            cout << vec[0].a * i + vec[0].b;
            flag = false;
            break;
        }
    }

    if(flag) cout << 0;
    
}