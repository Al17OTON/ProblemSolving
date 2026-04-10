#include <iostream>
#include <vector>

using namespace std;

struct Type {
    char c;
    int t;
    bool undo;
};

struct Undo {
    int time, t;
    bool undo;

    int get() const {
        return t - time;
    }
};

int N;
vector<Type> type;
vector<Undo> undo;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    char com[5];
    for (int n = 0; n < N; ++n) {
        cin >> com;

        if (com[0] == 't') {
            char c;
            int t;
            cin >> c >> t;

            type.push_back({ c, t, false});
        }
        else {
            int time, t;
            cin >> time >> t;

            undo.push_back({time, t, false });
        }
    }

    for (int i = undo.size() - 1; i > 0; --i) {
        if (undo[i].undo) continue;
        for (int j = i - 1; j >= 0; --j) {
            if (undo[i].get() > undo[j].t) break;
            undo[j].undo = true;
        }
    }

    for (int i = 0; i < undo.size(); ++i) {
        if (undo[i].undo) continue;
        
        for (int j = 0; j < type.size(); ++j) {
            if (type[j].t > undo[i].t) break;
            else if (type[j].t < undo[i].get()) continue;

            type[j].undo = true;
        }
    }

    for (int i = 0; i < type.size(); ++i) {
        if (type[i].undo) continue;
        cout << type[i].c;
    }
}