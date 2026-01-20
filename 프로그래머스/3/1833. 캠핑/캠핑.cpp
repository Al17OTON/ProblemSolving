#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Wedge {
    int r, c;  
};

bool cmp (const vector<int>&a, const vector<int>& b) {
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    
    sort(data.begin(), data.end(), cmp);
    
    vector<vector<Wedge>> vec;
    vec.push_back(vector<Wedge>());
    for(int i = 0; i < n; ++i) {
        int r = data[i][0];
        int c = data[i][1];
        if(vec.back().empty() || vec.back().back().r == r) vec.back().push_back({r, c});
        else {
            vec.push_back(vector<Wedge>());
            vec.back().push_back({r, c});
        }
    }
    
    for(int i = 0; i < vec.size(); ++i) {
        for(int j = 0; j < vec[i].size(); ++j) {
            Wedge w = vec[i][j];
            int left = 0;
            int right = (1 << 31) - 1;
            for(int ii = i + 1; ii < vec.size(); ++ii) {
                int tmp_l = left;
                int tmp_r = right;
                for(int jj = 0; jj < vec[ii].size(); ++jj) {
                    Wedge o = vec[ii][jj];
                    
                    if(o.c > w.c) {
                        //right
                        if(right >= o.c) {
                            tmp_r = min(tmp_r, o.c);
                            ++answer;
                        } else break;
                        
                    } else if(o.c < w.c) {
                        //left
                        if(left <= o.c) {
                            tmp_l = max(tmp_l, o.c);
                            ++answer;
                        }
                    }
                }
                right = tmp_r;
                left = tmp_l;
            }
        }
    }
    
    return answer;
}

