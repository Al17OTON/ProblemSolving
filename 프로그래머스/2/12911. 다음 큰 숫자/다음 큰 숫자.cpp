#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n;
    int n_cnt = __builtin_popcount(n);
    while(n_cnt != __builtin_popcount(++answer));
    
    return answer;
}