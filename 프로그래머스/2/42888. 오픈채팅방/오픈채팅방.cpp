#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> uid_answer;
    unordered_map<string, string> map;
    
    string event, uid, name;
    
    for(int i = 0; i < record.size(); ++i) {
        istringstream iss(record[i]);
        iss >> event >> uid;
        if(event[0] != 'L') {
            iss >> name;
            // map.insert({uid, name});
            map[uid] = name;
        }
        
        if(event[0] != 'C') {
            uid_answer.push_back(event);
            uid_answer.push_back(uid);
        }
    }
    
    for(int i = 0; i < uid_answer.size(); i += 2) {
        if(uid_answer[i][0] == 'E') {
            answer.push_back(map[uid_answer[i + 1]] + "님이 들어왔습니다.");
        } else {
            answer.push_back(map[uid_answer[i + 1]] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}