#include <string>
#include <vector>
#include <iostream>

using namespace std;

string target;
int answer = 0;
char c[] = { ' ', 'A', 'E', 'I', 'O', 'U' };

void print(int arr[], int end) {
    for(int i = 0; i <= end; i++) cout << c[arr[i]];
    cout << endl;
}

bool dfs(const int idx, int arr[]) {
    if(idx == target.length()) {
        bool flag = true;
        for(int i = 0; i < idx; i++) {
            if(c[arr[i]] != target[i]) {
                flag = false;
                break;
            }
        }
        if(flag) return true;
    }
    if(idx == 5) return false;
    
    for(int i = 1; i < 6; i++) {
        arr[idx] = i;
        answer++;
        // print(arr, idx);
        if(dfs(idx + 1, arr)) return true;
    }
    return false;
    
}

int solution(string word) {
    
    target = word;
    
    int arr[] = {1,0,0,0,0};
    dfs(0, arr);
    
    return answer;
}