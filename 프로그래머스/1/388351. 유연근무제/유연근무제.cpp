#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool date[] = {true, true, true, true, true, false, false};

bool check(int schedule, const vector<int>& logs, int day) {
    bool flag = true;
    int safe = (schedule / 100) * 100;
    if(schedule % 100 + 10 >= 60) {
        safe += schedule % 100 + 10 - 60;
        safe += 100;
    } else safe += schedule % 100 + 10;
    
    for(int log : logs) {
        if(log > safe && date[day % 7]) {
            flag = false;
            break;
        }
        ++day;
    } 
    return flag;
}


int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i = 0; i < schedules.size(); ++i) {
        if(check(schedules[i], timelogs[i], startday - 1)) ++answer;
    }
    
    return answer;
}