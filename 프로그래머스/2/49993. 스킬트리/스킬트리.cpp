#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int skills[26] = {0};
    for(int i = 0; i < skill.size(); ++i) skills[skill[i] - 'A'] = i + 1;
    
    for(string sk : skill_trees) {
        int tree_idx = 1;
        bool result = true;
        for(int i = 0; i < sk.size(); ++i) {
            int a = skills[sk[i] - 'A'];
            if(a != 0 && a != tree_idx++) {
                result = false;
                break;
            }
        }
        if(result) ++answer;
    }
    
    return answer;
}