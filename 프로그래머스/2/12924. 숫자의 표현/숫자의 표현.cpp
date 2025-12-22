#include <string>
#include <vector>

using namespace std;

int sum[10001] = {0};
int solution(int n) {
    int answer = 0;
    for(int i = 1; i <= n; ++i) {
        sum[i] += sum[i - 1] + i;
    }
    
    int l = 0, r = 1;
    while(l != r) {
        int s = sum[r] - sum[l];
        if(s < n) {
            ++r;
        } else {
            if(s == n) ++answer;
            ++l;
        }
    }
    
    return answer;
}