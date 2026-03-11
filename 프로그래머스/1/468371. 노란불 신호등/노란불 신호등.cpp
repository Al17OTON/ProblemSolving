#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<int>> signals) {
    unordered_map<int, int> map;
    int limit = 1500000;
    for(int i = 0; i < signals.size(); ++i) {
        int p = signals[i][0] + signals[i][1] + signals[i][2];
        int y = signals[i][1];
        int y_idx = signals[i][0];
        while(y_idx <= limit) {
            for(int j = 1; j <= y; ++j) {
                ++map[y_idx + j];
                if(map[y_idx + j] == signals.size()) return y_idx + j;
            }
            y_idx += p;
        }
    }
    return -1;
}