#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int floodfill(int r, int c, bool v[100][100], const vector<vector<int>>& picture) {
    queue<pair<int,int>> q;
    q.push({r, c});
    v[r][c] = true;
    int id = picture[r][c];
    int count = 0;
    while(!q.empty()) {
        pair<int,int> p = q.front(); q.pop();
        ++count;
        for(int d = 0; d < 4; ++d) {
            int nr = p.first + dr[d];
            int nc = p.second + dc[d];
            
            if(nr >= picture.size() || nr < 0 || nc >= picture[0].size() || nc < 0 || v[nr][nc] || picture[nr][nc] != id) continue;
            
            v[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    return count;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    bool v[100][100] = {false};
    
    for(int r = 0; r < picture.size(); ++r) {
        for(int c = 0; c < picture[r].size(); ++c) {
            if(v[r][c] || picture[r][c] == 0) continue;
            ++number_of_area;
            max_size_of_one_area = max(max_size_of_one_area, floodfill(r, c, v, picture));
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}