#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    
    int s = routes[0][0], e = routes[0][1];
    for(int i = 1; i < routes.size(); ++i) {
        if(e < routes[i][0]) {
            s = routes[i][0];
            e = routes[i][1];
            ++answer;
        } else {
            s = max(s, routes[i][0]);
            e = min(e, routes[i][1]);
        }
    }
    
    return answer;
}