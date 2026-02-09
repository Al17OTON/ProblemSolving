#include <string>
#include <vector>

using namespace std;

struct Price {
    int idx;
    int p;
};

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    vector<Price> stack;
    
    for(int i = 0; i < prices.size(); ++i) {
        Price price = {i, prices[i]};
        
        while(!stack.empty() && stack.back().p > price.p) {
            Price pop = stack.back(); stack.pop_back();
            answer[pop.idx] = i - pop.idx;
        }
        stack.push_back(price);
    }
    
    while(!stack.empty()) {
        Price pop = stack.back(); stack.pop_back();
        answer[pop.idx] = prices.size() - pop.idx - 1;
    }
    
    return answer;
}