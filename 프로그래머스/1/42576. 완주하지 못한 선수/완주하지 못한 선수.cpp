#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#define MAX 100001
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
//     int i;
//     string answer = "";
//     unordered_set<string> complete;
//     for(i = 0; i < completion.size(); i++) {
//         complete.insert(completion[i]);
//     }
    
//     for(i = 0; i < participant.size(); i++) {
//         if(complete.find(participant[i]) == complete.end()) answer = participant[i];
//     }
    
    int i;
    string answer = "";
    unordered_map<string, int> hash_map; 
    unordered_map<string, int>::iterator player;
    int count[MAX] = {};
    for(i = 0; i < completion.size(); i++) {
        player = hash_map.find(completion[i]);
        if(player == hash_map.end()) {
            hash_map.insert(make_pair(completion[i], i));
            count[i]++;
        }
        else {
            count[player->second]++;
        } 
    }   
    
    for(i = 0; i < participant.size(); i++) {
        player = hash_map.find(participant[i]);
        if(player == hash_map.end()) {
            answer = participant[i];
            break;
        }
        else {
            count[player->second]--;
            if(count[player->second] == 0) hash_map.erase(player->first);
        }
    }
    

    return answer;
}