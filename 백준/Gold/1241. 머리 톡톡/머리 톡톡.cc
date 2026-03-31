#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vec;
vector<int> count(1000001, 0);

double sqrt(double target) {
    double x = target;
    for(int i = 0; i < 20; ++i) {
        x = (x + (target / x)) / 2;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;

    for(int n = 0; n < N; ++n) {
        int num;
        cin >> num;

        vec.push_back(num);
        ++count[num];
    }

    for(int n = 0; n < N; ++n) {
        int root = sqrt(vec[n]);

        int answer = 0;
        for(int i = root; i >= 1; --i) {
            if(vec[n] % i == 0) {
                answer += count[i];
                if(vec[n] != i * i) answer += count[vec[n] / i]; 
            }
        }

        cout << answer - 1 << "\n";
    }
}