#include <string>
#include <vector>

using namespace std;

long long timeline[360001] = {0};

int translate(const string& time) {
    int hour = stoi(time.substr(0, 2));
    int min = stoi(time.substr(3, 2));
    int sec = stoi(time.substr(6, 2));
    
    return hour * 3600 + min * 60 + sec;
}
string translate(int time) {
    string t = "";
    
    if(time / 3600 <= 9) t += "0";
    t += to_string(time / 3600) + ":";
    time %= 3600;
    if(time / 60 <= 9) t += "0";
    t += to_string(time / 60) + ":";
    time %= 60;
    if(time <= 9) t += "0";
    t += to_string(time);
    return t;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int playtime = translate(play_time);
    
    for(int i = 0; i < logs.size(); ++i) {
        int start = translate(logs[i].substr(0, 8));
        int end = translate(logs[i].substr(9, 8));
        ++timeline[start];
        --timeline[end];
    }
    
    for(int i = 1; i <= playtime; ++i) {
        timeline[i] += timeline[i - 1];
    }
    for(int i = 1; i <= playtime; ++i) {
        timeline[i] += timeline[i - 1];
    }
    
    int adtime = translate(adv_time);
    long long sum = timeline[adtime - 1];
    int time = 0;
    
    for(int i = adtime - 1; i < playtime; ++i) {
        if(sum < timeline[i] - timeline[i - adtime]) {
            sum = timeline[i] - timeline[i - adtime];
            time = i - adtime + 1;
        }
    }
    
    return translate(time);
}