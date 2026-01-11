#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int end = 0;
    int width = 2 * w + 1;
    
    for(int i = 0; i < stations.size(); ++i) {
        int gap = (stations[i] - w) - end - 1;
        if(gap > 0) answer += ((gap + width - 1) / width);
        end = stations[i] + w;
    }
    
    if(n - end > 0) answer += ((n - end) + width - 1) / width;
    
    return answer;
}