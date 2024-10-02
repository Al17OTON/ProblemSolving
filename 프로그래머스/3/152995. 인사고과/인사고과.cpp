#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>>* vec;

//자신보다 큰 값이 있다면 false
bool check(const int& idx) {
    for(int i = idx + 1; i < vec->size(); i++) {
        if((*vec)[i][0] != (*vec)[idx][0] && (*vec)[i][1] > (*vec)[idx][1]) return false;
    }
    return true;
}

int solution(vector<vector<int>> scores) {
    int answer = 0, count = 0, wanho = scores[0][0] + scores[0][1];
    pair<int,int> arr[scores.size()];
    vec = &scores;
    
    for(int i = 0; i < vec->size(); i++) {
        (*vec)[i].push_back(i);
    }
    sort(scores.begin(), scores.end());

    for(int i = 0; i < vec->size(); i++) {
        int sum = (*vec)[i][0] + (*vec)[i][1];
        if(((*vec)[i][2] == 0 || sum > wanho) && check(i)) {
            arr[count++] = pair<int,int>(sum, (*vec)[i][2]);
        }
    }
    
    sort(arr, arr + count);
    
    // for(int i = 0 ; i < count; i++) {
    //     cout << arr[i].first << " " << arr[i].second << " , ";
    // }
    
    int pre = 200001;
    bool flag = false;
    for(int i =  count - 1; i >= 0; i--) {
        if(arr[i].first < pre) {
            answer = count - i;
            pre = arr[i].first;
        }
        if(arr[i].second == 0) {
            flag = true;
            break;
        } 
    }
    
    return flag ? answer : -1;
}