#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int counter[500001], pos[500001];

int solution(vector<int> a) {
    memset(pos, -1, sizeof(pos));
    
    for(int i = 0; i < a.size(); ++i) {
        if(i - pos[a[i]] > 1) {
            ++counter[a[i]];   
        } else if(i + 1 < a.size() && a[i + 1] != a[i]) {
            ++counter[a[i]];
            pos[a[i]] = i + 1;
            continue;
        }
        pos[a[i]] = i;
    }
    
    int result = 0;
    for(int i = 0; i < a.size(); ++i) {
        result = max(result, counter[i]);
    }
    return result * 2;
}