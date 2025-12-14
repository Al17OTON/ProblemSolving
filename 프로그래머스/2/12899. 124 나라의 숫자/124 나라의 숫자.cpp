#include <string>
#include <vector>

using namespace std;

/*
3진법
1 - 1 
2 - 2
3 - 10 - 4
4 - 11
5 - 12
6 - 20 - 14
7 - 21
8 - 22
9 - 100 - 24
10 - 101 - 41
11 - 102 - 42
12 - 110 - 104 - 44
13 - 111 - 111
*/
string solution(int n) {
    string answer = "";

    while(n > 0) {
        int num = n % 3;
        if(num == 0) {
            num = 4;
            n = (n / 3) - 1;
        } else {
            n /= 3;
        }
        answer = to_string(num) + answer;
    }
    
    return answer;
}