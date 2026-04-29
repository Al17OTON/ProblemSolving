#include <string>
#include <vector>

using namespace std;

struct Node {
    int up, down;
    bool del;
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<int> st;
    vector<Node> vec;
    
    for(int i = 0; i < n + 2; ++i) {
        vec.push_back({i - 1, i + 1, false});
    }
    
    int idx = k + 1;
    for(int i = 0; i < cmd.size(); ++i) {
        if(cmd[i][0] == 'U') {
            for(int j = stoi(cmd[i].substr(2)); j > 0; --j) {
                idx = vec[idx].up;
            }
        } else if(cmd[i][0] == 'D') {
            for(int j = stoi(cmd[i].substr(2)); j > 0; --j) {
                idx = vec[idx].down;
            }
        } else if(cmd[i][0] == 'C') {
            vec[idx].del = true;
            vec[vec[idx].up].down = vec[idx].down;
            vec[vec[idx].down].up = vec[idx].up;
            
            st.push_back(idx);
            idx = (vec[idx].down == n + 1) ? vec[idx].up : vec[idx].down;
        } else {
            int restore = st.back(); st.pop_back();
            
            vec[restore].del = false;
            vec[vec[restore].up].down = restore;
            vec[vec[restore].down].up = restore;
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        answer += vec[i].del ? 'X' : 'O';
    }
    
    return answer;
}