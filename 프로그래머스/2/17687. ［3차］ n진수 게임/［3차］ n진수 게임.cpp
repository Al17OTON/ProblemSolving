#include <string>
#include <vector>

using namespace std;

char arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string num2base(int num, int base) {
    string str = "";
    while(num) {
        str += arr[num % base];
        num /= base;
    }
    return str.empty() ? "0" : str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string all = "";
    int len = (m + p) * t;
    int num = 0;
    for(int i = 0; i < len; ++num) {
        string str = num2base(num, n);
        for(int j = str.size() - 1; j >= 0; --j) all += str[j];
        i += str.size();
    }
    
    for(int i = 0; i < t; ++i) {
        answer += all[(p - 1) + (m * i)];
    }
    
    return answer;
}