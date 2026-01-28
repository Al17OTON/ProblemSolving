#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int,int>> pq;

void prime_factorization(int num) {
    for(int i = 2; i * i <= num; ++i) {
        pair<int,int> prime = {i, 1};
        while(num % i == 0) {
            prime.second *= i;
            num /= i;
        }
        if(prime.second > 1) pq.push(prime);
    }
    if(num > 1) pq.push({num, num});
}

int solution(vector<int> arr) {
    int answer = 1;
    
    for(int i = 0; i < arr.size(); ++i) {
        if(arr[i] > 1) {
            prime_factorization(arr[i]);
        }
    }
    
    while(!pq.empty()) {
        pair<int,int> prime = pq.top(); pq.pop();
        
        answer *= prime.second;
        
        while(!pq.empty() && pq.top().first == prime.first) pq.pop();
    }
    
    
    return answer;
}






