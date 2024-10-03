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

//단어와 단어 사이의 차이 계산
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
    //시작 인덱스는 벡터의 마지막 요소
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
    
    //위 반복문에서 정답을 찾지 못한경우 0 반환
    //1을 반환해도 정답, 이 부분까지 오는 테스트 케이스가 없는 것 같다.
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    w = &words;
    len = begin.length(); 
    words.push_back(begin); //시작 단어를 words에 추가한다.
    targetIdx = -1;
    
    //인접 리스트 초기화
    for(int i = 0; i < words.size(); i++) adj.push_back(vector<int>());
    
    //인접 리스트 생성
    for(int i = 0; i < words.size(); i++) {
        if(target == words[i]) targetIdx = i;   //words안에 target이 존재하는지 검사
        for(int j = i + 1; j < words.size(); j++) {
            if(getDiff(words[i], words[j]) == 1) {  //단어가 1 알파벳만 차이나는 경우 인접리스트에서 연결한다.
                //양방향 연결
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    //words 내부에 target이 존재해야만한다.
    answer = targetIdx == -1 ? 0 : bfs();
    
    return answer;
}
