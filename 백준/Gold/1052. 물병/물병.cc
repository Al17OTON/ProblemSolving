#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> arr;

int main() {
    cin >> N >> K;

    arr.push_back(1);
    int n = 1;
    while(n < N) {
        n *= 2;
        arr.push_back(n);
    }

    for(int i = 0; i < K - 1; ++i) {
        for(int j = arr.size() - 1; j >= 0; --j) {
            if(arr[j] < N) {
                N -= arr[j];
                break;
            }
        }
    }

    for(int i = 0; i < arr.size(); ++i) {
        if(arr[i] >= N) {
            cout << arr[i] - N;
            break;
        }
    }
}