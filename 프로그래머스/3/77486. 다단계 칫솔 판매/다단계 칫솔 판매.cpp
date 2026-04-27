#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Seller {
    string refer;
    int earn;
};

unordered_map<string, Seller> hash_map;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i = 0; i < referral.size(); ++i) {
        hash_map[enroll[i]] = {referral[i], 0};
    }
    
    for(int i = 0; i < seller.size(); ++i) {
        string s = seller[i];
        int earn = amount[i] * 100;
        
        while(s[0] != '-' && earn > 0) {
            hash_map[s].earn += earn - (earn / 10);
            earn = earn / 10;
            s = hash_map[s].refer;
        }
    }
    
    for(int i = 0; i < enroll.size(); ++i) {
        answer.push_back(hash_map[enroll[i]].earn);
    }
    
    return answer;
}