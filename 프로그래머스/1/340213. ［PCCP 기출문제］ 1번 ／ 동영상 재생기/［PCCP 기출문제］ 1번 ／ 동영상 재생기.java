// 구현문제
// 문자열로 주어지는 시간 해석해줘야함

class Solution {
    
    int[] video_len = new int[2], pos = new int[2], op_start = new int[2], op_end = new int[2];
    
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        setTime(this.video_len, video_len);
        setTime(this.pos, pos);
        setTime(this.op_start, op_start);
        setTime(this.op_end, op_end);
        
        //시작 시 오프닝 체크
        checkOp();
        for(int i = 0; i < commands.length; i++) {
            if(commands[i].charAt(0) == 'p') {
                prev();
            } else {
                next();
            }
            checkOp(); //매 순간 오프닝 체크
            // System.out.println(time2Str(this.pos));
        }
        
        return time2Str(this.pos);
    }
    
    // 오프닝 여부 체크
    void checkOp() {
        //시간 체크할때, 분이 이미 크다면 초는 계산하지 않아야 한다.
        if(op_start[0] <= pos[0] && (op_start[0] < pos[0] || op_start[1] <= pos[1]) && op_end[0] >= pos[0] && (op_end[0] > pos[0] || op_end[1] > pos[1])) {
            pos[0] = op_end[0];
            pos[1] = op_end[1];
        }
    }
    
    void next() {
        int sec = pos[1] + 10;
        int min = pos[0];
        if(sec > 59) {
            min += 1;
            sec = sec % 60;
        }
        //영상의 길이를 넘어가면
        if(min >= video_len[0] && (min > video_len[0] || sec > video_len[1])) {
            min = video_len[0];
            sec = video_len[1];
        }
        
        pos[0] = min;
        pos[1] = sec;
    }
    
    void prev() {
        int sec = pos[1] - 10;
        int min = pos[0];
        if(sec < 0) {
            min -= 1;
            sec = 60 + sec;
        }
        
        //영상의 길이를 넘어가면
        if(min < 0) {
            min = 0;
            sec = 0;
        }
        
        pos[0] = min;
        pos[1] = sec;
    }
    
    // 문자열로 주어진 시간을 정수로 변환
    void setTime(int[] time, String str_time) {
        int idx = str_time.indexOf(':');
        time[0] = Integer.parseInt(str_time.substring(0, idx));
        time[1] = Integer.parseInt(str_time.substring(idx + 1));
    }
    
    // 정수로 저장된 시간을 형식에 맞게 변환
    String time2Str(int[] time) {
        String min = String.format("%02d", time[0]);
        String sec = String.format("%02d", time[1]);
        
        return min + ":" + sec;
    }
}