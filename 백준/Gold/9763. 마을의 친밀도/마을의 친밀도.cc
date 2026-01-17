#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Town {
    int x, y, z;  
};

int N;
vector<Town> towns;

int calc(const Town& a, const Town& b) {
    return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    
    int x, y, z;
    for(int n = 0; n < N; ++n) {
        cin >> x >> y >> z;
        towns.push_back({x, y ,z});
    }
    
    int answer = 987654321;
    for(int i = 0; i < N; ++i) {
        int a = 987865, b = 98765321;
        for(int j = 0; j < N; ++j) {
            if(i == j) continue;
            int d = calc(towns[i], towns[j]);
            if(b > d) {
                swap(b, d);
            }
            if(a > b) {
                swap(a, b);
            }
        }
        answer = min(answer, a + b);
    }
    cout << answer;
}