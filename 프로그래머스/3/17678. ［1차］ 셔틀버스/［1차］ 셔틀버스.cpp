#include <string>
#include <vector>
#include <queue>

using namespace std;

int time2min(const string& str_time) {
    int time = 0;
    
    time += stoi(str_time.substr(0, 2)) * 60;
    time += stoi(str_time.substr(3, 2));
    
    return time;
}

string min2time(int minute) {
    string time = "";
    int hour = minute / 60;
    if(hour < 10) time += "0";
    time += to_string(hour);
    time += ":";
    int m = minute % 60;
    if(m < 10) time += "0";
    time += to_string(m);
    return time;
} 

string solution(int n, int t, int m, vector<string> timetable) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < timetable.size(); ++i) {
        pq.push(time2min(timetable[i]));
    }
    
    int lazy_min = 0;
    int bus_min = time2min("09:00"), bus_count = 0;
    while(bus_count != n) {
        int stack = 0;
        while(stack < m - 1 && !pq.empty() && bus_min >= pq.top()) {
            ++stack;
            pq.pop();
        }
        if(!pq.empty() && bus_min >= pq.top()) {
            lazy_min = pq.top() - 1;
            pq.pop();
        } else {
            lazy_min = bus_min;
        }
        
        ++bus_count;
        bus_min += t;
    }
    
    return min2time(lazy_min);
}