#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {   
    istringstream iss(s);
    
    int maximum = -987654321, minimum = 987654321;
    int num;
    while(!iss.eof()) {
        iss >> num;
        minimum = min(minimum, num);
        maximum = max(maximum, num);
    }
    
    return to_string(minimum) + " " + to_string(maximum);
}