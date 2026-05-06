#include <vector>

using namespace std;

bool check(const vector<int>& wallet, const vector<int>& bill) {
    return (wallet[0] >= bill[0] && wallet[1] >= bill[1]) || (wallet[0] >= bill[1] && wallet[1] >= bill[0]);
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    while(!check(wallet, bill)) {
        if(bill[0] > bill[1]) {
            bill[0] /= 2;
        } else {
            bill[1] /= 2;
        }
        ++answer;
    }
    
    return answer;
}