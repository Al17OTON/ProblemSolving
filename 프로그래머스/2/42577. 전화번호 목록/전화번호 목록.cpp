#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

bool compare(const string& a, const string& b) {return a.length() > b.length();}

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> hash;
    sort(phone_book.begin(), phone_book.end(), compare);
    
    for(int i = 0; i < phone_book.size(); i++) {
        if(!hash.insert(phone_book[i]).second) return false;
        
        for(int j = 1; j < phone_book[i].length(); j++) {
            hash.insert(phone_book[i].substr(0, j));
        }
    }
    
    return true;
}