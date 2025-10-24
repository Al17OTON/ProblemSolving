#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Union {
    int N;
    int uni[101];
    int sum[101];
    
public:
    Union(int n) {
        N = n;
        for(int i = 1; i <= N; ++i) {
            uni[i] = i;
            sum[i] = 1;
        }
    }
    
    int find(int x) {
        if(x == uni[x]) return x;
        return uni[x] = find(uni[x]);
    }
    
    bool set(int a, int b) {
        a = find(a);
        b = find(b);
        
        if(a == b) return false; 
        
        uni[b] = a;
        sum[a] += sum[b];
        return true;
    }
    
    bool is_top(int x) {
        return uni[x] == x;
    }
    
    int result() {

        bool v[101] = {false};
        int a = 0, b = 0;
        
        for(int i = 1; i <= N; ++i) {
            int idx = find(i);
            if(v[idx]) continue;
            v[idx] = true;
            if(a < sum[idx]) {
                b = a;
                a = sum[idx];
            } else if(b < sum[idx]) {
                b = sum[idx];
            }
        }
        
        return a * b;
    }
    
};


int solution(vector<int> cards) {    
    Union uni(cards.size());

    for(int i = 0; i < cards.size(); ++i) {
        int card = i;
        while(uni.set(cards[card], cards[cards[card] - 1])) {
            card = cards[card] - 1;
        }
        
    }
    
    return uni.result();
}