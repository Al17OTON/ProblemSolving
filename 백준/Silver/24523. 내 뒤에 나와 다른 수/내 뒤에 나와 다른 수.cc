#include <iostream>

using namespace std;

int N;
int arr[1000001], answer[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int n = 0; n < N; ++n) {
        cin >> arr[n];
    }
    
    answer[N - 1] = -1;
    for(int n = N - 2; n >= 0; --n) {
        if(arr[n] == arr[n + 1]) answer[n] = answer[n + 1];
        else answer[n] = n + 2;
    }
    
    for(int n = 0; n < N; ++n) {
        cout << answer[n] << " ";
    }
    
}