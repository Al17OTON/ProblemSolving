#include <string>
#include <vector>
#include <cmath>
#include <bit>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    // 한번 반전한 행과 열은 다시 반전할 필요가 없다. 행 + 열 길이가 최대값
    int answer = 21;
    int r_len = beginning.size();
    int c_len = beginning[0].size();
    
    // 비트 마스킹으로 행과 열 반전 여부 조합을 생성한다.
    for(int row = 0; row < (1 << r_len); ++row) {
        for(int col = 0; col < (1 << c_len); ++col) {
            
            // 조합을 적용하고 목표 상태와 동일한지 체크
            bool flag = true; 
            for(int r = 0; r < r_len; ++r) {
                for(int c = 0; c < c_len; ++c) {
                    // 현재 열과 행을 반전해야하는지 체크, XOR 연산으로 중복 반전인 경우엔 반전이 없도록 한다. 
                    int bit = beginning[r][c] ^ ((row >> r) & 1) ^ ((col >> c) & 1);
                    if(bit != target[r][c]) {
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag) {
                answer = min(answer, __popcount(row) + __popcount(col));
            }       
        }
    }
    
    return answer != 21 ? answer : -1;
}