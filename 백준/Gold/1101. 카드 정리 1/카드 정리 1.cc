#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Card {
    int color;
    int count;
};

int N, M;
vector<Card> box[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int n = 0; n < N; ++n) {
        for(int m = 0; m < M; ++m) {
            int card;
            cin >> card;
        
            if(card != 0) box[n].push_back({m, card});
        }
    }

    int answer = 987654321;

    for(int joker = 0; joker < N; ++joker) {
        int move = 0;
        long long v = 0;
        for(int n = 0; n < N; ++n) {
            if(joker == n || box[n].empty()) continue;
            if(box[n].size() == 1 && !(v & (1LL << box[n][0].color))) {
                v |= 1LL << box[n][0].color;
            } else {
                ++move;
            }
            
        }
        answer = min(answer, move);
    }

    cout << answer;
}