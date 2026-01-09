#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    deque<int> dq;
    for(int i = 0; i < B.size(); ++i) {
        dq.push_back(B[i]);
    }
    
    for(int i = A.size() - 1; i >= 0; --i) {
        if(A[i] >= dq.back()) {
            dq.pop_front();
        } else {
            ++answer;
            dq.pop_back();
        }
    }
    
    return answer;
}

