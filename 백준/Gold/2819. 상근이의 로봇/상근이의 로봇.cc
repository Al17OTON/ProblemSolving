#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
string com;
int X[2000001] = {0}, Y[2000001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    long long x_left_sum = 0, x_right_sum = 0;
    int x_left_count = 0, x_right_count = 0;
    long long y_left_sum = 0, y_right_sum = 0; 
    int y_left_count = 0, y_right_count = 0;
    for(int n = 0; n < N; ++n) {
        int x, y;
        cin >> x >> y;

        ++X[x + 1000000];
        ++Y[y + 1000000];

        if(x > 0) {
            x_right_sum += x;
            ++x_right_count;
        } else if(x < 0) {
            x_left_sum += abs(x);
            ++x_left_count;
        }

        if(y > 0) {
            y_right_sum += y;
            ++y_right_count;
        } else if(y < 0) {
            y_left_sum += abs(y);
            ++y_left_count;
        }
    }

    cin >> com;

    int x = 1000000, y = 1000000;
    for(int i = 0; i < com.size(); ++i) {
        char c = com[i];
        if(c == 'S') {
            y_right_sum -= y_right_count;
            y_right_count -= Y[y + 1];
            y_left_count += Y[y];
            y_left_sum += y_left_count;
            ++y;
        } else if(c == 'J') {
            y_left_sum -= y_left_count;
            y_left_count -= Y[y - 1];
            y_right_count += Y[y];
            y_right_sum += y_right_count;
            --y;
        } else if(c == 'Z') {
            x_left_sum -= x_left_count;
            x_left_count -= X[x - 1];
            x_right_count += X[x];
            x_right_sum += x_right_count;
            --x;
        } else {
            x_right_sum -= x_right_count;
            x_right_count -= X[x + 1];
            x_left_count += X[x];
            x_left_sum += x_left_count;
            ++x;
        }

        cout << x_left_sum + x_right_sum + y_left_sum + y_right_sum << "\n";
    }
}