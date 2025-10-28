#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    vector<int> circle;
    
    long long sum1 = 0, sum2 = 0;
    for(int i = 0; i < queue1.size(); ++i) {
        sum1 += queue1[i];
        circle.push_back(queue1[i]);
    }
    for(int i = 0; i < queue2.size(); ++i) {
        sum2 += queue2[i];
        circle.push_back(queue2[i]);
    }
    
    if((sum1 + sum2) % 2 != 0) return -1;
    
    int idx1 = 0, idx2 = queue1.size(), size1 = queue1.size(), size2 = queue2.size();
    int cnt = 0;
    
    while(sum1 != sum2) {
        if(sum1 > sum2) {
            sum1 -= circle[idx1 % circle.size()];
            sum2 += circle[idx1 % circle.size()];
            ++idx1;
            --size1;
            ++size2;
        } else {
            sum1 += circle[idx2 % circle.size()];
            sum2 -= circle[idx2 % circle.size()];
            ++idx2;
            ++size1;
            --size2;
        }
        ++cnt;
        if(size1 == 0 || size2 == 0 || (idx1 >= circle.size() && idx2 >= circle.size())) return -1;
        
    }
    
    return cnt;
}