#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int len, int r, int c, const vector<vector<string>>& park) {
    if(park.size() < r + len || park[0].size() < c + len) return false;
    for(int i = r; i < r + len; ++i) {
        for(int j = c; j < c + len; ++j) {
            if(park[i][j][0] != '-') return false;
        }
    }
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.rbegin(), mats.rend());
    int minimum = mats.size();
    for(int r = 0; r < park.size(); ++r) {
        for(int c = 0; c < park[r].size(); ++c) {
            if(park[r][c][0] != '-') continue;
            
            for(int i = 0; i < minimum; ++i) {
                if(check(mats[i], r, c, park)) {
                    minimum = i;
                    break;
                }
            }
        }
    }
    
    return minimum == mats.size() ? -1 : mats[minimum];
}