#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 12
#define MAX_K 10
#define MAX_TURN 1000
#include <iostream>
#include <vector>

using namespace std;

class Player {
public:
    int r, c, dir;

    Player(int r, int c, int dir) {
        this->r = r;
        this->c = c;
        this->dir = dir;
    }

    void setReverse() {
        if (dir == 0) dir = 1;
        else if (dir == 1) dir = 0;
        else if (dir == 2) dir = 3;
        else dir = 2;
    }
    void setRC(int r, int c) {
        this->r = r;
        this->c = c;
    }
};

class Tile {
public:
    int color;
    vector<int> stack;

    Tile(int c) {
        color = c;
    }
};

int simulation();
bool isBottom(int i);
bool move(int i, bool isBlue);

int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };
Tile* map[MAX_N][MAX_N];
int N, K;

Player* players[MAX_K];

int main() {
    Tile* t;
    int color;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &color);
            t = new Tile(color);
            map[i][j] = t;
        }
    }

    int r, c, dir;
    Player* p;
    for (int i = 0; i < K; i++) {
        scanf("%d %d %d", &r, &c, &dir);
        p = new Player(r - 1, c - 1, dir - 1);
        players[i] = p;
        map[p->r][p->c]->stack.push_back(i);
    }

    printf("%d", simulation());
}

int simulation() {
    int turn = 1;
    for (; turn <= MAX_TURN; turn++) {

        for (int k = 0; k < K; k++) {
            if (move(k, false)) return turn;
        }
    }
    return -1;
}

bool move(int i, bool isBlue) {
    if (!isBottom(i)) {
        return false;
    }
    Player* p = players[i];
    int r = p->r;
    int c = p->c;
    int nr = r + dr[p->dir];
    int nc = c + dc[p->dir];
    int size, pop;
    //map을 벗어나거나 파란 타일일 경우
    if (nr >= N || nc >= N || nr < 0 || nc < 0 || map[nr][nc]->color == 2) {
        p->setReverse();
        if (!isBlue) {
            return move(i, true);
        }
    }
    else if (map[nr][nc]->color == 0) {
        size = map[r][c]->stack.size();
        for (int i = 0; i < size; i++) {
            pop = map[r][c]->stack.at(i);
            map[nr][nc]->stack.push_back(pop);
            players[pop]->setRC(nr, nc);
        }
        map[r][c]->stack.clear();
        if (map[nr][nc]->stack.size() >= 4) return true;
    }
    else {
        size = map[r][c]->stack.size();
        for (int i = size - 1; i >= 0; i--) {
            pop = map[r][c]->stack.at(i);
            map[nr][nc]->stack.push_back(pop);
            players[pop]->setRC(nr, nc);
        }
        map[r][c]->stack.clear();
        if (map[nr][nc]->stack.size() >= 4) return true;
    }

    return false;
}

bool isBottom(int i) {
    Player* p = players[i];
    return map[p->r][p->c]->stack.front() == i;
}