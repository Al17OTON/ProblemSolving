class Solution {
    public String solution(String[] survey, int[] choices) {
        int[] point = new int[8];  // RT CF JM AN
        char[] personality = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
        int[] hash = new int[26];
        hash['R' - 'A'] = 0; hash['T' - 'A'] = 1;
        hash['C' - 'A'] = 2; hash['F' - 'A'] = 3; 
        hash['J' - 'A'] = 4; hash['M' - 'A'] = 5; 
        hash['A' - 'A'] = 6; hash['N' - 'A'] = 7; 
        
        for(int i = 0; i < survey.length; i++) {
            int agree = hash[survey[i].charAt(0) - 'A'];
            int disagree = hash[survey[i].charAt(1) - 'A'];
            
            int score = 4 - choices[i];
            if(score > 0) point[agree] += score;
            else if(score < 0) point[disagree] += -score;
        }
        
        String result = "";
        for(int i = 0; i < 8; i += 2) {
            if(point[i] >= point[i + 1]) result += personality[i];
            else result += personality[i + 1];
        }
        
        return result;
    }
}