#include <string>
#include <vector>
#define MAX 10000

using namespace std;

class Bridge {
public:
    int q[MAX] = {0};
    int length, total_w = 0;
    
    Bridge(int l) {length = l;}
    
    void enter(const int& w) {
        total_w += w;
        q[length - 1] = w;
    }
    bool enterable() {return q[length - 1] == 0;}
    
    void run() {
        total_w -= q[0];
        for(int i = 0; i < length - 1; i++) {
            q[i] = q[i + 1];
        }
        q[length - 1] = 0;
    }
    
    
    
};


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, top = 0;
    Bridge bridge(bridge_length);
    
    while(true) {
        if(top < truck_weights.size() && bridge.enterable() && bridge.total_w + truck_weights[top] <= weight) {
            bridge.enter(truck_weights[top++]);
        }
        bridge.run();
        answer++;
        if(bridge.total_w == 0 && top == truck_weights.size()) break;
        
    }
    
    
    return answer + 1;
}