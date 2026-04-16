#include <iostream>
#include <vector>

struct Element {
    int a, b;
};

using namespace std;

int N, M;
vector<Element> vec;

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

    int answer = 0;
    for(int i = 1; i <= M - N + 1; ++i) {
        int target = vec[0].a * i + vec[0].b;
        int count = i;
        for(int j = 1; j < vec.size(); ++j) {
            count += (target - vec[j].b) / vec[j].a;
        }
        if(count == M) {
            answer = target;
            break;
        }
    }

    cout << answer;
}