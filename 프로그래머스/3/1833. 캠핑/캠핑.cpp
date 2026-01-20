#include <vector>
#include <algorithm>

using namespace std;

bool is_in(const vector<int>& i, const vector<int>& j, const vector<int>& k) {
    return (i[0] < k[0] && j[0] > k[0]) && (min(i[1], j[1]) < k[1] && max(i[1], j[1]) > k[1]);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    
    sort(data.begin(), data.end());
    
    for(int i = 0; i < data.size(); ++i) {
        for(int j = i + 1; j < data.size(); ++j) {
            if(data[j][0] == data[i][0] || data[j][1] == data[i][1]) continue;
            
            bool flag = true;
            for(int k = j - 1; k >= 0; --k) {
                if(is_in(data[i], data[j], data[k])) {
                    flag = false;
                    break;
                }
            }
            if(flag) ++answer;
        }
    }
    
    return answer;
}

