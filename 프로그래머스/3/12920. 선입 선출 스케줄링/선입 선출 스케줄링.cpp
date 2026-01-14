#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


int solution(int n, vector<int> cores) {
    if(n <= cores.size()) return n;
    
    int l = 0, r = 10000 * n;
    int work = 0;
    int time = 0;
    
    while(l <= r) {
        int mid = (l + r) / 2;
        
        int count = cores.size();
        for(int i = 0; i < cores.size(); ++i) {
            count += mid / cores[i];
        }
        
        if(count >= n) {
            r = mid - 1;
            time = mid;
            work = count;
        } else {
            l = mid + 1;
        }
    }
    
    int answer = 0;
    work -= n;
    for(int i = cores.size() - 1; i >= 0; --i) {
        if(time % cores[i] == 0) {
            if(work == 0) {
                answer = i + 1;
                break;  
            }
            --work;
        }
    }
    return answer;
}














