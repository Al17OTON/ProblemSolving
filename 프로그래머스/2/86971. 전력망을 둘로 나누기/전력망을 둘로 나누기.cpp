#include <string>
#include <vector>
#define MAX 101

using namespace std;

bool adjarr[MAX][MAX] = {false};
vector<int> adj[MAX];
int abs(int a) {return a > 0 ? a : -a;}
int min(int a, int b) {return a > b ? b : a;}

int dfs(int node, bool v[MAX]) {
    int count = 1;
    for(int i = 0; i < adj[node].size(); i++) {
        if(!v[adj[node][i]] && adjarr[node][adj[node][i]]) {
            v[adj[node][i]] = true;
            count += dfs(adj[node][i], v);
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX * MAX;
    
    for(int i = 0; i < wires.size(); i++) {
        //양방향 연결
        adjarr[wires[i][0]][wires[i][1]] = true;
        adjarr[wires[i][1]][wires[i][0]] = true;
        adj[wires[i][0]].push_back(wires[i][1]);
        adj[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i = 0; i < wires.size(); i++) {
        adjarr[wires[i][0]][wires[i][1]] = false;
        adjarr[wires[i][1]][wires[i][0]] = false;
        bool v[MAX] = {false};
        v[wires[i][0]] = true;
        v[wires[i][1]] = true;
        int a = dfs(wires[i][0], v);
        int b = dfs(wires[i][1], v);
        answer = min(answer, abs(a - b));
        
        adjarr[wires[i][0]][wires[i][1]] = true;
        adjarr[wires[i][1]][wires[i][0]] = true;
    }
    
    
    return answer;
}