#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;
int v[51] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    
    for(int n = 0; n < N; ++n) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    
    vector<int> answer;
    for(int n = N - 1; n >= 0; --n) {
        int count = v[n];
        for(int i = n - 1; i >= 0; --i) {
            if(arr[n] < arr[i]) ++v[i];
            else ++count;
        }
        answer.push_back(count);
    }
    
    for(int n = N - 1; n >= 0; --n) {
        cout << answer[n] << " ";
    }
}