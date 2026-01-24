#include <vector>
#include <string>

using namespace std;

int solution(string s)
{
    vector<char> stack;

    for(int i = 0; i < s.size(); ++i) {
        char a = s[i];
        
        if(!stack.empty() && stack.back() == a) {
            stack.pop_back();
        } else stack.push_back(a);
    }

    return stack.size() == 0 ? 1 : 0;
}