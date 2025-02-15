#include <iostream>
#include <queue>
#define MAX 100000

using namespace std;

int arr[MAX * 2] = { 0 };
int N, K;
void bfs();
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> K;

    bfs();

    vector<int> stack;
    int idx = K;
    for (int i = arr[K]; i > 1; i--) {
        stack.push_back(idx);
        if (i == 2) break;

        if (idx % 2 == 0 && arr[idx / 2] == i - 1) idx /= 2;
        else if (arr[idx + 1] == i - 1) idx += 1;
        else idx -= 1;
    }
    stack.push_back(N);

    cout << stack.size() - 1 << "\n";
    for (int i = stack.size() - 1; i >= 0; i--) {
        cout << stack[i] << " ";
    }
}

void bfs() {
    arr[N] = 1;
    queue<int> q;
    q.push(N);

    int time = 2;
    while (!q.empty()) {
        int size = q.size();
        for (int s = 0; s < size; s++) {
            int idx = q.front(); q.pop();

            if (idx == K) return;

            int next = idx + 1;
            if (next < MAX * 2 && (arr[next] == 0 || arr[next] > time)) {
                arr[next] = time;
                q.push(next);
            }
            next = idx - 1;
            if (next >= 0 && (arr[next] == 0 || arr[next] > time)) {
                arr[next] = time;
                q.push(next);
            }
            next = idx * 2;
            if (next < MAX * 2 && (arr[next] == 0 || arr[next] > time)) {
                arr[next] = time;
                q.push(next);
            }
        }
        time++;
    }

}