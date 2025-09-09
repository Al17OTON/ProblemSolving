#include <string>
#include <vector>
#include <unordered_map>
// #include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int val = 0;
    unordered_map<string, int> map;
    vector<int> discountInt;
    vector<int> wantInt;
    int wantHash[10] = {0};
    
    for(string a : want) {
        wantHash[val] = number[val];
        map.insert({a, val});
        wantInt.push_back(val++);
    }
    
    for(string a : discount) {
        if(map.find(a) != map.end()) {
            discountInt.push_back(map.at(a));
        } 
        else {
            map.insert({a, -1});
            discountInt.push_back(-1);
        }
    }
    int answer = 0;
    
    for(int i = 0; i < discountInt.size() - 9; ++i) {
        int disHash[10] = {};
        for(int j = i; j < i + 10; ++j) {
            if(discountInt[j] == -1) break;
            ++disHash[discountInt[j]];
        }
        
        // for(int j = 0; j < 10; ++j) {
        //     cout << disHash[j] << ",";
        // }
        // cout << endl;
        
        bool flag = true;
        for(int j = 0; j < 10; ++j) {
            if(disHash[j] != wantHash[j]) {
                flag = false;
                break;
            }
        }
        
        if(flag) ++answer;
    }
    
    return answer;
}