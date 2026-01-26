#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int avg = s / n;
    int mod = s % n;
    if(avg == 0) return {-1};
    for(int i = 0; i < n; ++i) {
        if(n - mod <= i) answer.push_back(avg + 1);
        else answer.push_back(avg);
    }
    
    return answer;
}