#include <string>
#include <vector>
#include <deque>
#include <iostream>
#define MAX 104 //flood fill을 위한 양 끝 패딩추가

using namespace std;

int map[MAX][MAX] = {0};
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1}; //up down left right
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

void draw_line(const int& x, const int& y, const int& xx, const int& yy, const int& dir) {
    int nx = x * 2, ny = y * 2; 
    while(nx != xx * 2 || ny != yy * 2) {
        map[nx][ny] = 1;
        nx += dx[dir];
        ny += dy[dir];
        // if(nx >= MAX || nx < 0 || ny >= MAX || ny < 0) break;
    }
    map[xx * 2][yy * 2] = 1;
}

void draw_rect(const vector<int>& rect) {
    // cout << rect[0] << " " << rect[1] << " " << rect[2] << " " << rect[3] << " " << endl;
    draw_line(rect[0], rect[1], rect[2], rect[1], 1); //bottom left to upper left
    draw_line(rect[0], rect[1], rect[0], rect[3], 3); //bottom left to bottom right
    draw_line(rect[2], rect[3], rect[2], rect[1], 2); //upper right to upper left
    draw_line(rect[2], rect[3], rect[0], rect[3], 0); //upper right to bottom right
}

void flood_fill() {
    deque<pair<int,int>> q;
    q.push_back({0,0});
    bool v[MAX][MAX] = {false};
    v[0][0] = true;
    
    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop_front();
        
        for(int i = 0; i < 8; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            
            if(nx >= MAX || nx < 0 || ny >= MAX || ny < 0 || v[nx][ny]) continue;
            v[nx][ny] = true;
            if(map[nx][ny] == 1) {
                map[nx][ny] = 2;
            } else {
                q.push_back({nx,ny});
            }
        }
        
    }
}

int find_item(const int& sx, const int& sy, const int& ix, const int& iy) {
    deque<pair<int,int>> q;
    q.push_back({sx, sy});
    map[sx][sy] = 0;
    int travel = 0;
    bool flag = true;
    
    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop_front();
        
        if(p.first == ix && p.second == iy) {
            break;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(map[nx][ny] == 2) {
                map[nx][ny] = 0;
                q.push_back({nx,ny});
            }
        }
        if(flag) {
            travel++;
        }
        flag = !flag;

    }
    return travel / 2;
}

void print() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    for(int i = 0; i < rectangle.size(); i++) {
        draw_rect(rectangle[i]);
    }
    // print();
    flood_fill();
    // print();
    return find_item(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
}