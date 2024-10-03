#include <string>
#include <vector>
#define GIVEUP 3

using namespace std;
int a_cicle[] = {1, 2, 3, 4, 5}; 
int a = 0, a_len = 5;
int b_cicle[] = {2, 1, 2, 3, 2, 4, 2, 5};
int b = 0, b_len = 8;
int c_cicle[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int c = 0, c_len = 10;
int giveups_score[GIVEUP] = {0};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int ans;
    for(int i = 0; i < answers.size(); i++) {
        ans = answers[i];
        giveups_score[0] += a_cicle[a++ % a_len] == ans ? 1 : 0; 
        giveups_score[1] += b_cicle[b++ % b_len] == ans ? 1 : 0; 
        giveups_score[2] += c_cicle[c++ % c_len] == ans ? 1 : 0; 
    }
    
    int max = 0;
    for(int i = 0; i < GIVEUP; i++) {
        max = max > giveups_score[i] ? max : giveups_score[i];
    }
    
    for(int i = 0; i < GIVEUP; i++) {
        if(max == giveups_score[i]) answer.push_back(i + 1);
    }
    
    return answer;
}