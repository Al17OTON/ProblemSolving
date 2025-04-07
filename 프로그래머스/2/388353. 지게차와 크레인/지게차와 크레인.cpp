#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#define MAX 54

using namespace std;

char map[MAX][MAX] = {'0'};
vector<pair<int, int>> cargo[26];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int answer = 0, N, M;
void crane(char target);
void floodfill(char target);
void print() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) printf("%c ", map[i][j]);
        
        printf("\n");
    } 
    printf("\n");
}
void reset() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) map[i][j] = '0';
    } 
}

int solution(vector<string> storage, vector<string> requests) {
    N = storage.size() + 2;
    M = storage[0].length() + 2;
    
    reset();
    
    for(int i = 0; i < storage.size(); ++i) {
        for(int j = 0; j < storage[i].length(); ++j) {
            map[i + 1][j + 1] = storage[i][j];
            cargo[map[i + 1][j + 1] - 'A'].push_back({i + 1, j + 1});
            ++answer;
        }
    }
    
    for(int i = 0; i < requests.size(); ++i) {
        if(requests[i].length() == 2) {
            crane(requests[i][0]);
        } else {
            floodfill(requests[i][0]);
        }
        // print();
    }
    
    return answer;
}

void floodfill(char target) {
    queue<pair<int,int>> q;
    bool v[MAX][MAX] = {false};
    v[0][0] = true;
    q.push({0, 0});
    
    while(!q.empty()) {
        pair p = q.front(); q.pop();
        
        for(int d = 0; d < 4; ++d) {
            int nr = p.first + dr[d];
            int nc = p.second + dc[d];
            
            if(nr >= N || nr < 0 || nc >= M || nc < 0 || v[nr][nc]) continue;
            v[nr][nc] = true;
            if(map[nr][nc] == '0') q.push({nr, nc});
            else if(map[nr][nc] == target) {
                map[nr][nc] = '0';
                --answer;
            }
        }
    }
}

void crane(char target) {
    for(int i = 0; i < cargo[target - 'A'].size(); ++i) {
        if(map[cargo[target - 'A'][i].first][cargo[target - 'A'][i].second] != '0') {
            map[cargo[target - 'A'][i].first][cargo[target - 'A'][i].second] = '0';
            --answer;
        }
        
    }
    cargo[target - 'A'].clear();
}