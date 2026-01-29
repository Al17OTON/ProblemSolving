#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long N_limit = 10000000;

long long calc(long long num) {
    if(num == 1) return 0;
    
    long long res = 1;
    for(long long i = 2; i * i <= num; ++i) {
        long long N = num / i;
        // if(num % i == 0) res = max(N_limit >= N ? N : i, res);
        if(num % i == 0) {
            if(N_limit >= N) {
                res = N;
                break;
            } else {
                res = i;
            }
        }
    }
    return res;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for(long long i = begin; i <= end; ++i) {
        answer.push_back((int)calc(i));
    }
    
    return answer;
}