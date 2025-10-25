#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> v;

int solution(vector<int> elements) {
    
    for(int len = 0; len < elements.size(); ++len) {
        int sum = 0;
        for(int i = len; i < elements.size() + len; ++i) {
            sum += elements[i % elements.size()];
            v.insert(sum);
        }
    }
    
    return v.size();
}