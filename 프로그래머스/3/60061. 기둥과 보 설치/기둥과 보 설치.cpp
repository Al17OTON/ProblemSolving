#include <iostream>
#include <vector>

using namespace std;

bool map[101][101][4] = {false}; // 상하좌우

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    for(int i = 0; i < build_frame.size(); ++i) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        
        if(b == 0) {
            // remove
            if(a == 0) {
                map[x][y][0] = false;
                map[x][y + 1][1] = false;
                if(map[x][y + 1][2] && !((map[x - 1][y + 1][2] && map[x][y + 1][3]) || map[x - 1][y + 1][1])) {
                    map[x][y][0] = true;
                    map[x][y + 1][1] = true;
                } else if(map[x][y + 1][3] && !((map[x + 1][y + 1][3] && map[x][y + 1][2]) || map[x + 1][y + 1][1])) {
                    map[x][y][0] = true;
                    map[x][y + 1][1] = true;
                } else if(map[x][y + 1][0] && !(map[x][y + 1][2] || map[x][y + 1][3])) {
                    map[x][y][0] = true;
                    map[x][y + 1][1] = true;
                }
            } else {
                map[x][y][3] = false;
                map[x + 1][y][2] = false;
                if(map[x][y][2] && !(map[x - 1][y][1] || map[x][y][1])) {
                    map[x][y][3] = true;
                    map[x + 1][y][2] = true;
                } else if(map[x + 1][y][3] && !(map[x + 1][y][1] || map[x + 2][y][1])) {
                    map[x][y][3] = true;
                    map[x + 1][y][2] = true;
                } else if(map[x][y][0] && !(map[x][y][1] || map[x][y][2])) {
                    map[x][y][3] = true;
                    map[x + 1][y][2] = true;
                } else if(map[x + 1][y][0] && !(map[x + 1][y][1] || map[x + 1][y][3])) {
                    map[x][y][3] = true;
                    map[x + 1][y][2] = true;
                }
            }
            
        } else {
            // build
            if(a == 0) {
                if(y == 0 || map[x][y][1] || map[x][y][2] || map[x][y][3]) {
                    map[x][y][0] = true;
                    map[x][y + 1][1] = true;
                }
            } else {
                if(map[x][y][1] || map[x + 1][y][1] || (map[x][y][2] && map[x + 1][y][3])) {
                    map[x][y][3] = true;
                    map[x + 1][y][2] = true;
                }
            }
        }
    }
    
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            if(map[i][j][0]) answer.push_back({i, j, 0});
            if(map[i][j][3]) answer.push_back({i, j, 1});
        }
    }
    
    return answer;
}