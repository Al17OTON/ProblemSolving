#include <string>
#include <vector>

using namespace std;

string to_lower(const string& str) {
    string res = "";
    for(int i = 0; i < str.size(); ++i) {
        res += tolower(str[i]);
    }
    return res;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    vector<pair<string, int>> cache;
    
    for(int i = 0; i < cities.size(); ++i) {
        string city = to_lower(cities[i]);
        
        bool hit = false;
        int idx = -1, lru = 987654321;
        for(int j = 0; j < cache.size(); ++j) {
            if(!cache[j].first.compare(city)) {
                hit = true;
                cache[j].second = i;
                break;
            }
            if(cache[j].second < lru) {
                idx = j;
                lru = cache[j].second;
            }
        }
        
        if(hit) {
            ++answer;
        } else {
            answer += 5;
            if(cache.size() < cacheSize) {
                cache.push_back({city, i});
            } else if(cache.size() != 0) {
                cache[idx] = {city, i};
            }
        }
        
    }
    
    return answer;
}