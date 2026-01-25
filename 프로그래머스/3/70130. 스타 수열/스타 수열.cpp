#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    vector<int> copy = a;
    vector<pair<int, int>> mode;
    sort(copy.begin(), copy.end());
    
    while(!copy.empty()) {
        int i = copy.back();
        int count = 0;
        while(!copy.empty() && copy.back() == i) {
            copy.pop_back();
            ++count;
        }
        mode.push_back({count, i});
    }
    
    sort(mode.begin(), mode.end());
    
    int max_count = 0;
    while(!mode.empty()) {
        pair<int, int> p = mode.back();
        mode.pop_back();
        
        if(max_count >= p.first) break;
        
        int count = 0;
        int pre = -1, left_idx = -1;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] == p.second) {
                // 왼쪽에 유효한 값이 있으면 우선 선택
                if(left_idx != -1 && left_idx > pre) {
                    pre = left_idx;
                    ++count;
                } else {
                    int right_idx = i;
                    while(++right_idx < a.size() && a[right_idx] == p.second);
                    if(right_idx < a.size() && a[right_idx] != p.second) {
                        pre = right_idx;
                        ++count;
                        i = pre;
                    }
                }
                
            } else {
               left_idx = i; 
            }
        }
        if(count == 0) return 0;
        max_count = max(max_count, count);
    }
    
    
    return max_count * 2;
}