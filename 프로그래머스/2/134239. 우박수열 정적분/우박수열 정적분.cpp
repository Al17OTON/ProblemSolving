#include <string>
#include <vector>

using namespace std;

vector<double> rect;

double calc(int pre, int cur) {
    return (double)(pre + cur) / 2;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    rect.push_back(0);
    int num = k;
    int pre = k;
    while(num > 1) {
        if(num % 2 == 0) num /= 2;
        else num = num * 3 + 1;
        
        rect.push_back(rect.back() + calc(pre, num));
        pre = num;
    }

    for(int i = 0; i < ranges.size(); ++i) {
        int from = ranges[i][0];
        int to = rect.size() + ranges[i][1] - 1;
        
        if(from > to) answer.push_back(-1);
        else answer.push_back(rect[to] - rect[from]);
    }
    
    return answer;
}