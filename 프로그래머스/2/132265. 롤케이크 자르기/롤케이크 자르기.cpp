#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    int left_count[10002] = {0};
    int right_count[10002] = {0};
    int left = 0, right = 0;
    
    for(int i = 0; i < topping.size(); ++i) {
        if(right_count[topping[i]] == 0) ++right;
        ++right_count[topping[i]];
    }
    
    for(int i = 0; i < topping.size(); ++i) {
        int type = topping[i];
        --right_count[type];
        if(right_count[type] == 0) --right;
        
        if(left_count[type] == 0) ++left;
        ++left_count[type];
        
        if(left == right) ++answer;
    }
    
    return answer;
}