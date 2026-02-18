#include <string>
#include <vector>
#include <algorithm>
#define NOPE 10000000000

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<long long, long long>> arr;
    
    pair<long long,long long> left_top = {-NOPE, NOPE}, right_bottom = {NOPE, -NOPE};
    for(int i = 0; i < line.size(); ++i) {
        for(int j = i + 1; j < line.size(); ++j) {
            long long A = line[i][0];
            long long B = line[i][1];
            long long E = line[i][2];
            long long C = line[j][0];
            long long D = line[j][1];
            long long F = line[j][2];

            if(A * D - B * C == 0) continue;

            pair<long long, long long> pos;
            long long denominator, numerator;

            denominator = A * D - B * C;
            numerator = B * F - E * D;
            if(numerator % denominator != 0) continue;
            pos.second = numerator / denominator;

            denominator = A * D - B * C;
            numerator = E * C - A * F;
            if(numerator % denominator != 0) continue;
            pos.first = numerator / denominator;
            
            arr.push_back(pos);
            left_top.first = max(left_top.first, pos.first);
            left_top.second = min(left_top.second, pos.second);
            right_bottom.first = min(right_bottom.first, pos.first);
            right_bottom.second = max(right_bottom.second, pos.second);
            
        }
    }
    
    long long r_limit = abs(left_top.first - right_bottom.first);
    long long c_limit = abs(left_top.second - right_bottom.second);
    string l = "";
    for(long long c = 0; c <= c_limit; ++c) {
        l += '.';
    }
    for(long long r = 0; r <= r_limit; ++r) {
        answer.push_back(l);
    }
    
    for(int i = 0; i < arr.size(); ++i) {
        long long r = left_top.first - arr[i].first;
        long long c = arr[i].second - left_top.second;
        
        answer[r][c] = '*';
    }
    
    return answer;
}