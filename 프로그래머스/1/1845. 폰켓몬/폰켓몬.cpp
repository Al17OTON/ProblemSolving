#include <vector>
#include <algorithm>
#define MAX 200001
using namespace std;

int min(const int& a, const int& b) {return a > b ? b : a;} 

int solution(vector<int> nums)
{
    bool hash[MAX] = {false};
    int answer = 0;
    
    for(int i = 0; i < nums.size(); i++) {
        if(!hash[nums[i]]) {
            answer++;
            hash[nums[i]] = true;
        }
    }
    
    
    return min(answer, nums.size() / 2);
}