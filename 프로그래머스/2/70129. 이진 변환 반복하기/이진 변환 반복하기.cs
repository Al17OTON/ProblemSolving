using System;

public class Solution {
    
    int CountOne(string s) {
        int cnt = 0;
        for(int i = 0; i < s.Length; ++i) {
            if(s[i] == '1') ++cnt;
        }
        return cnt;
    }
    
    string ToBinary(int n) {
        string bin = "";
        
        while(n > 1) {
            bin = (n % 2) + bin;
            n /= 2;
        }
        return n + bin;
    }
    
    public int[] solution(string s) {
        int zero = 0;
        int turn = 0;
        while(s.Length != 1) {
            int cnt = CountOne(s);
            zero += s.Length - cnt;
            s = ToBinary(cnt);
            ++turn;
        }
        
        return new int[]{turn, zero};
    }
}