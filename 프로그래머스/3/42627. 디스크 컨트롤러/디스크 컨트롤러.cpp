#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define MAX 1001
using namespace std;

int min(const int a, const int b) {return a > b ? b : a;}
int max(const int a, const int b) {return a > b ? a : b;}

struct compare {
    bool operator() (const pair<int,int> a, const pair<int,int> b) {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, max_time = 0, min_time = MAX;
    vector<int> timeline[MAX];
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
    
    int cur = 0, i;
    
    for(i = 0; i < jobs.size(); i++) {
        timeline[jobs[i][0]].push_back(jobs[i][1]);
        min_time = min(min_time, jobs[i][0]);
        max_time = max(max_time, jobs[i][0]);
    }
    
    for(i = min_time; i <= max_time; i++) {
        if(timeline[i].size() != 0) {
            for(int j = 0; j < timeline[i].size(); j++) {
                pq.push({i, timeline[i][j]});
            }
        }
        
        if(cur == 0 && !pq.empty()) {
            cur = pq.top().second; 
            answer += i - pq.top().first;
            answer += pq.top().second;
            pq.pop();
        } 
        if(cur > 0) {
            cur--;
        }
        
    }
    
    while(!pq.empty()) {
        if(cur == 0) {
            cur = pq.top().second; 
            answer += i - pq.top().first;
            answer += pq.top().second;
            pq.pop();
        } 
        if(cur > 0) {
            cur--;
        }
        i++;
    }
    
    
//     sort(jobs.begin(), jobs.end());
    
//     for(int i = 0; i < jobs.size(); i++) { 
//         cout << '[' << jobs[i][0] << " "  << jobs[i][1] << "] ";
//     }
    
    return answer / jobs.size();
}