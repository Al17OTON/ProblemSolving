#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Music {
    int start_time, end_time;
    string name;
    string melody;
    int bit;
    
    int get_length() const {
        return this->end_time - this->start_time;
    }
    
    bool operator < (const Music& o) const {
        if(this->get_length() == o.get_length()) return this->start_time > o.start_time;
        return this->get_length() < o.get_length();
    }
};

bool sliding_window(const string& A, const string& B, int b_length) {
    int limit = b_length - A.size();
    for(int i = 0; i < B.size(); ++i) {
        if(i > limit) break;
        
        int a_idx = 0;
        int b_idx = i;
        while(a_idx < A.size() && A[a_idx] == B[b_idx]) {
            ++a_idx;
            b_idx = (b_idx + 1) % B.size();
        }
        if(a_idx == A.size()) return true;
    }
    return false;
}

priority_queue<Music> pq;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    for(int i = 0; i < musicinfos.size(); ++i) {
        string& musicinfo = musicinfos[i];
        
        Music music;
        string tmp = "";
        int count = 0;
        for(int j = 0; j < musicinfo.size(); ++j) {
            char c = musicinfo[j];
            if(c == ',') {
                if(count == 0) {
                    int hour = stoi(tmp.substr(0,2));
                    int minute = stoi(tmp.substr(3, 2));
                    music.start_time = hour * 60 + minute;
                } else if(count == 1) {
                    int hour = stoi(tmp.substr(0,2));
                    int minute = stoi(tmp.substr(3, 2));
                    music.end_time = hour * 60 + minute;
                } else if(count == 2) {
                    music.name = tmp;
                }
                ++count;
                tmp = "";
            } else {
                tmp += c;
            }
        }
        
        int bit = 0;
        string melody = "";
        for(int j = 0; j < tmp.size(); ++j) {
            int num = tmp[j] - 'A';
            if(j + 1 < tmp.size() && tmp[j + 1] == '#') {
                num += 7;
                ++j;
            }
            melody.push_back(num + '0');
            bit |= 1 << num;
        }
        music.melody = melody;
        music.bit = bit;
        
        pq.push(music);
    }
    
    int bit = 0;
    string melody = "";
    for(int j = 0; j < m.size(); ++j) {
        int num = m[j] - 'A';
        if(j + 1 < m.size() && m[j + 1] == '#') {
            num += 7;
            ++j;
        }
        melody.push_back(num + '0');
        bit |= 1 << num;
    }
    
    while(!pq.empty()) {
        Music music = pq.top(); pq.pop();
        
        if((bit & music.bit) != bit || music.get_length() < melody.size()) continue;
        
        if(sliding_window(melody, music.melody, music.get_length())) return music.name;
    }
    
    return "(None)";
}