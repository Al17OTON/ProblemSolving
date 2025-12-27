#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_map<string, int> map, window;
    for(int i = 0; i < gems.size(); ++i) {
        ++map[gems[i]];
    }
    
    int min_len = gems.size();
    int min_l = 0, min_r = gems.size() - 1;
    int l = 0, r = 0;
    int count = map.size();
    for(; r < gems.size(); ++r) {
        ++window[gems[r]];
        
        while(window.size() == count) {
            if(min_len > r - l) {
                min_len = r - l;
                min_l = l;
                min_r = r;
            }
            --window[gems[l]];
            if(window[gems[l]] == 0) window.erase(gems[l]);
            ++l;
        }
    }
    
    return {min_l + 1, min_r + 1};
}