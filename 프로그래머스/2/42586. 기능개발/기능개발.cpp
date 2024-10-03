#include <string>
#include <vector>

using namespace std;

int vsize, offset;
vector<int>* pro, *speed;

void work() {
    for(int i = offset; i < vsize; i++) {
        (*pro)[i] += (*speed)[i];
    }
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    offset = 0;
    vsize = progresses.size();
    pro = &progresses;
    speed = &speeds;
    int count; 
    
    while(offset < vsize) {
        count = 0;
        work();
        for(; offset < vsize; offset++) {
            if(progresses[offset] < 100) break;
            else count++;
        }
        if(count != 0) answer.push_back(count);
    }
    
    
    return answer;
}