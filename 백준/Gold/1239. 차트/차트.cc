#include <iostream>
#include <algorithm>

using namespace std;

int arr[8];
int N, answer = 0;

int main() {
    cin >> N;
    for(int n = 0; n < N; ++n) {
        cin >> arr[n];
    }

    sort(arr, arr + N);

    do {
        int cnt = 0;
        for(int i = 0; i < N; ++i) {
            int sum = 0;
            for(int j = i; true; ++j) {
                sum += arr[j % N];
                if(sum > 50) break;
                else if(sum == 50) {
                    ++cnt;
                    break;
                }
            }
        } 
        answer = max(answer, cnt);
    } while(next_permutation(arr, arr + N));

    cout << answer / 2;
}