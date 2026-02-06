int solution(int n)
{
    int ans = 0;
    
    for(int i = 0; i < 31; ++i) {
        if(n & (1 << i)) ++ans;
    }   

    return ans;
}