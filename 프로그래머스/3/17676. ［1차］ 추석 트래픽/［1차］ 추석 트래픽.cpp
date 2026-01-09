#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Log {
    int s, e;  
    
    bool operator < (const Log& o) const {
        return this->e > o.e;
    }
};

bool cmp (const Log& a, const Log& b) {
    return a.s < b.s;
}

Log time2milli(const string& time) {
    int from, to;
    int hour = stoi(time.substr(11, 2));
    int minute = stoi(time.substr(14, 2));
    double second = stod(time.substr(17, 6));
    double t = stod(time.substr(24, time.size() - 24));
    
    to = hour * 3600000;
    to += minute * 60000;
    to += (int)(second * 1000);
    
    from = to - (int)(t * 1000);
    
    return {from, to};
}

int solution(vector<string> lines) {
    int answer = 0;
    
    vector<Log> logs;
    priority_queue<Log> pq;
    
    for(int i = 0; i < lines.size(); ++i) {
        Log log = time2milli(lines[i]);
        logs.push_back(log);
    }
    
    sort(logs.begin(), logs.end(), cmp);
    
    for(int i = 0; i < logs.size(); ++i) {
        Log log = logs[i];
        while(!pq.empty() && pq.top().e - 1 <= log.s - 1000) {
            pq.pop();
        }
        
        pq.push(log);
        
        answer = max(answer, (int)pq.size());
    }
    
    return answer;
}