#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long l = 0, r = 0;
    long long answer = 0;
    
    for(int i = 0; i < times.size(); ++i) {
        r = max(r, (long long)times[i]);
    }
    r *= n;
    
    while(l <= r) {
        long long mid = (l + r) / 2;
        long long count = 0;
        for(int i = 0; i < times.size(); ++i) {
            count += mid / times[i];
        }
        
        if(count >= n) {
            r = mid - 1;
            answer = mid;
        }
        else l = mid + 1;
    }
    
    return answer;
}