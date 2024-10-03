#include <string>
#include <vector>
#include <iostream>
#include <deque>
#define MAX 51
using namespace std;

vector<string>* w;
int len;
vector<vector<int>> adj;
int targetIdx;


int getDiff(const string& a, const string& b) {
    int count = 0;
    for(int i = 0; i < len; i++) {
        count += a[i] == b[i] ? 0 : 1;
    }
    return count;
}

int bfs() {
    deque<int> q;
    bool v[MAX] = {false};
    int beginIdx = (*w).size() - 1, count = 0;
    q.push_back(beginIdx);
    v[beginIdx] = true;
    
    while(!q.empty()) {
        int size = q.size();
        
        for(int i = 0; i < size; i++) {
            int p = q.front(); q.pop_front();
            
            if(p == targetIdx) return count;
            
            for(int j = 0; j < adj[p].size(); j++) {
                int tmp = adj[p][j];
                if(!v[tmp]) {
                    v[tmp] = true;
                    q.push_back(tmp);
                }
            }
        }
        count++;
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    w = &words;
    len = begin.length(); 
    words.push_back(begin);
    targetIdx = -1;
    // words.push_back(target);
    
    for(int i = 0; i < words.size(); i++) adj.push_back(vector<int>());
    
    for(int i = 0; i < words.size(); i++) {
        if(target == words[i]) targetIdx = i;
        for(int j = i + 1; j < words.size(); j++) {
            if(getDiff(words[i], words[j]) == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    answer = targetIdx == -1 ? 0 : bfs();
    
    return answer;
}