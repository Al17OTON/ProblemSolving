#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> v;

int solution(vector<int> elements) {
    int answer = 0;
    
    for(int len = 1; len <= elements.size(); ++len) {
        int sum = 0;
        int start = 0, end = len - 1;
        
        for(int i = start; i <= end; ++i) sum += elements[i];
        
        v.insert(sum);
        
        for(int i = 1; i < elements.size(); ++i) {
            sum -= elements[start];
            start = (start + 1) % elements.size();
            end = (end + 1) % elements.size();
            sum += elements[end];
            v.insert(sum);
        }
    }
    
    return v.size();
}