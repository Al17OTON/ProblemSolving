#include <iostream>

using namespace std;

int dfs(int a, int b, int level) {
    if((a + 1) / 2 == (b + 1) / 2) return level;
    
    return dfs((a + 1) / 2, (b + 1) / 2, level + 1);
}

int solution(int n, int a, int b)
{
    return dfs(a, b, 1);
}