#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for(int i = 0; i < numbers.size(); ++i) {
        long long number = numbers[i];
        
        for(int j = 0; j < 64; ++j) {
            // 올리고자하는 비트가 1인 경우 다음 비트는 0이여야함.
            // 비트가 0인 경우 다음 비트는 0 또는 1이여야함.
            if(!(number & 1LL << j + 1) || !(number & 1LL << j)) {
                if(!(number & 1LL << j)) {
                    number |= 1LL << j; 
                } else {
                    number |= 1LL << j + 1;
                    number &= ~(1LL << j);
                }
                break;
            }
        }
        
        answer.push_back(number);
    }
    
    return answer;
}