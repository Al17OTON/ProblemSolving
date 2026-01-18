#include <iostream>

using namespace std;

int map[10][10];
int row[10];
int col[10];
int box[3][3];

bool dfs(int r, int c) {
    if(c == 9) return dfs(r + 1, 0);
    else if(r == 9) return true;
    else if(map[r][c] != 0) return dfs(r, c + 1);
    else {
        for(int num = 1; num <= 9; ++num) {
            int bit = 1 << num;
            if((row[r] & bit) || (col[c] & bit) || (box[r / 3][c / 3] & bit)) continue;
            row[r] |= bit;
            col[c] |= bit;
            box[r / 3][c / 3] |= bit;
            map[r][c] = num;
            if(dfs(r, c + 1)) return true;
            map[r][c] = 0;
            row[r] ^= bit;
            col[c] ^= bit;
            box[r / 3][c / 3] ^= bit;
        }
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            char c;
            cin >> c;
            map[i][j] = c - '0';
            if(map[i][j] == 0) continue;
            row[i] |= (1 << map[i][j]);
            col[j] |= (1 << map[i][j]);
            box[i / 3][j / 3] |= (1 << map[i][j]);
        }
    }

    dfs(0, 0);

    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cout << map[i][j];
        }
        cout << "\n";
    }
    
}