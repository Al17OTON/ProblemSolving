#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    set<int> treeset;
    string oper;
    // set<int>::iterator iter;
    
    for(int i = 0; i < operations.size(); i++) {
        oper = operations[i];
        if(oper[0] == 'I') {
            treeset.insert(stoi(oper.substr(2)));
        } else if(!treeset.empty()) { 
            if(oper[2] == '-') {
                treeset.erase(treeset.begin());
            } else {
                treeset.erase(prev(treeset.end()));
            }
        }
    }
    
    if(treeset.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(*prev(treeset.end()));
        answer.push_back(*treeset.begin());
    }
    
    return answer;
}