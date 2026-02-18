#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int i = 0; i < arr1.size(); ++i) {
        vector<int> tmp;
        for(int k = 0; k < arr2[0].size(); ++k) {
            int x = 0;
            for(int j = 0; j < arr1[0].size(); ++j) {
                x += arr1[i][j] * arr2[j][k];
            }   
            tmp.push_back(x);
        }
        answer.push_back(tmp);
    }
    
    return answer;
}