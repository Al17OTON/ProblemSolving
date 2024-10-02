#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int idx;
    for(int i = 0; i < arr.size(); i++) {
        idx = answer.size() - 1;
        if(idx == -1 || answer[idx] != arr[i]) answer.push_back(arr[i]);
        
    }

    return answer;
}