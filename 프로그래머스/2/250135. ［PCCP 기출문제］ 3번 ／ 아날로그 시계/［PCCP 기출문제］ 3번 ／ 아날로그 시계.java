// 초침이 한바퀴를 돌면 시침과 분침을 각각 1번씩 만나게된다.
// 시침과 분침이 겹쳐있을땐 2번이 아닌 1번 만난것으로 생각한다.
// 분침을 초침으로 환산하면 60분 * 60초 = 3600초, 분당 60초
// 시침을 초침으로 환산하면 12시간 * 60분 = 43200초, 시간당 3600초

// 시침 기준으로 변환하기
// 초침은 1초에 720 움직인다
// 분침은 1초에 12 움직인다
// 시침은 1초에 1만큼 움직이는데 한바퀴 도는데 43200초 만큼 필요하다.

// 시침, 분침, 초침의 위치를 시침 기준으로 변환하여 겹침을 검사한다.
// 실수를 사용하여 연산하면 순환소수 문제나 정확한 겹침을 판단하기 어렵다고고 생각해서 정수로 표현하여 푸는 방식을 택하였다.
class Solution {
    int start, end;
    int hour, min, sec;
    
    int hourCycle = 43200;      //시침이 한바퀴 회전하기 위해 필요한 초

    // 분침과 초침이 한바퀴 회전하기 위해 필요한 초(시침 기준)
    // 구하는 법 : (시침 회전 시간) / (초침 회전 시간) -> 43200 / 60 = 720 , (시침 회전 시간) / (분침 회전 시간) -> 43200 / 3600 = 12
    int minMove = 12, secMove = 720; 
    int preSec, preMin, preHour;
    
    public int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
        int answer = 0;
        
        setDegree(h1, m1, s1, h2, m2, s2);
        
        //시작할때 겹치는지 검사
        if(hour == sec) answer++;
        if(hour != min && min == sec) answer++;
        preSec = sec % hourCycle;
        preMin = min % hourCycle;
        preHour = hour % hourCycle;
        
        for(; start < end; start++) {
            sec = (preSec + secMove);
            min = (preMin + minMove);
            hour = (preHour + 1);
            
            //이전 시간과 비교하여 초침이 분침과 시침을 추월했는지 검사
            if(preSec < preHour && sec >= hour) answer++;
            if(preSec < preMin && sec >= min && hour != min) answer++;
            
            // 나머지 연산을 마지막에 해야 일부 케이스(11시 59분 -> 12시 00분)에서 추월 여부를 알 수 있다.
            preSec = sec % hourCycle;
            preMin = min % hourCycle;
            preHour = hour % hourCycle;
        }
        
        return answer;
    }
    
    // 초기값 셋팅
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