#include <iostream>
#include <string>

using namespace std;

struct Pos {
    int r, c;
};

Pos str2pos(const string& p) {
    return {p[0] - 'A', p[1] - '1'};
}
string pos2str(const Pos& p) {
    string res = "";
    res += (char)('A' + p.r);
    res += (char)('1' + p.c);
    return res;
}

bool check(const Pos& p) {
    return p.r < 8 && p.r >= 0 && p.c < 8 && p.c >= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    int N;
    cin >> a >> b >> N;

    Pos king = str2pos(a), stone = str2pos(b);
    for(int n = 0; n < N; ++n) {
        string com;
        cin >> com;

        Pos vec = {0, 0};
        for(int i = 0; i < com.size(); ++i) {
            if(com[i] == 'R') vec.r = 1;
            else if(com[i] == 'L') vec.r = -1;
            else if(com[i] == 'B') vec.c = -1;
            else if(com[i] == 'T') vec.c = 1;
        }

        Pos next = {king.r + vec.r, king.c + vec.c};
        if(!check(next)) continue;
        if(next.r == stone.r && next.c == stone.c) {
            Pos next_stone = {stone.r + vec.r, stone.c + vec.c};
            if(!check(next_stone)) continue;
            stone = next_stone;
        }
        king = next;
    }

    cout << pos2str(king) << "\n" << pos2str(stone);
}