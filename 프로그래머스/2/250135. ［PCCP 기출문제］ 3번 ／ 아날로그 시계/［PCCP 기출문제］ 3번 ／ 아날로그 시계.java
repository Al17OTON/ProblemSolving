// 초침이 한바퀴를 돌면 시침과 분침을 각각 1번씩 만나게된다.
// 시침과 분침이 겹쳐있을땐 2번이 아닌 1번 만난것으로 생각한다.
// 분침을 초침으로 환산하면 60분 * 60초 = 3600초, 분당 60초
// 시침을 초침으로 환산하면 12시간 * 60분 = 43200초, 시간당 3600초
// 속도를 구해야한다.
//
// 초침은 1초에 6도(60초 = 360도) 움직인다.
// 분침은 1초에 0.1도(3600초 = 360도) 움직인다.
// 시침은 1초에 0.008333333...도(43200초 = 360도) 움직인다.
// 위 값을 더하면서 초침이 넘어갔는지 계산하기...?

// 시침 기준으로 변환하기
// 초침은 1초에 720 움직인다?
// 분침은 1초에 12 움직인다?
// 시침은 1초에 1만큼 움직이는데 한바퀴 도는데 43200초 만큼 필요하다.

//000부터 235959까지 2852번 만난다.
//
class Solution {
    int start, end;
    int hour, min, sec;
    
    int hourCycle = 43200;
    int minMove = 12, secMove = 720;
    int preSec, preMin, preHour;
    
    public int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
        int answer = 0;
        
        setDegree(h1, m1, s1, h2, m2, s2);
        
        if(hour == sec) answer++;
        if(hour != min && min == sec) answer++;
        preSec = sec % hourCycle;
        preMin = min % hourCycle;
        preHour = hour % hourCycle;
        
        for(; start < end; start++) {
            sec = (preSec + secMove);
            min = (preMin + minMove);
            hour = (preHour + 1);
            
            if(preSec < preHour && sec >= hour) answer++;
            if(preSec < preMin && sec >= min && hour != min) answer++;
            
            preSec = sec % hourCycle;
            preMin = min % hourCycle;
            preHour = hour % hourCycle;
        }
        
        return answer;
    }
    
    void setDegree(int h1, int m1, int s1, int h2, int m2, int s2) {
        start = h1 * 3600 + m1 * 60 + s1;
        end = h2 * 3600 + m2 * 60 + s2;
        
        hour = (h1 % 12) * 3600;
        min = (m1 * 60 * minMove);
        sec = (s1 * secMove);
        
        hour += m1 * 60;
        hour += s1;
        min += s1 * 12;
        
    }
    
    
    
}